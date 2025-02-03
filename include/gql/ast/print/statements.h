// Copyright 2025 Oleg Maximenko
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "gql/ast/algorithm.h"
#include "gql/ast/nodes/statements.h"
#include "gql/ast/print/helpers.h"
#include "gql/ast/print/output_stream.h"

namespace gql::ast::print {

template <>
struct Printer<YieldItem> {
  static void Print(OutputStream& os, const YieldItem& v) {
    os << v.name;
    if (v.alias) {
      os << "AS" << *v.alias;
    }
  }
};

template <>
struct Printer<YieldClause> {
  static void Print(OutputStream& os, const YieldClause& v) {
    if (!v.empty()) {
      os << "YIELD" << Sequence(v, ",");
    }
  }
};

template <>
struct Printer<InlineProcedureCall> {
  static void Print(OutputStream& os, const InlineProcedureCall& v) {
    if (!v.vars.empty()) {
      os << "(" << Sequence(v.vars, ",") << ")";
    }
    os << "{" << *v.spec << "}";
  }
};

template <>
struct Printer<NamedProcedureCall> {
  static void Print(OutputStream& os, const NamedProcedureCall& v) {
    os << v.proc << "(" << Sequence(v.args, ",") << ")" << v.yield;
  }
};

template <>
struct Printer<CallProcedureStatement> {
  static void Print(OutputStream& os, const CallProcedureStatement& v) {
    os << (v.isOptional ? "OPTIONAL " : "") << "CALL" << v.call;
  }
};

template <>
struct Printer<SessionSetSchemaClause> {
  static void Print(OutputStream& os, const SessionSetSchemaClause& v) {
    os << "SCHEMA" << v.schema;
  }
};

template <>
struct Printer<SessionSetGraphClause> {
  static void Print(OutputStream& os, const SessionSetGraphClause& v) {
    os << "GRAPH" << v.graph;
  }
};

template <>
struct Printer<SessionSetTimeZoneClause> {
  static void Print(OutputStream& os, const SessionSetTimeZoneClause& v) {
    os << "TIME ZONE" << v.timeZoneString;
  }
};

template <>
struct Printer<SessionSetParameterName> {
  static void Print(OutputStream& os, const SessionSetParameterName& v) {
    if (v.ifNotExists) {
      os << "IF NOT EXISTS ";
    }
    os << v.param;
  }
};

template <>
struct Printer<OptTypedGraphInitializer> {
  static void Print(OutputStream& os, const OptTypedGraphInitializer& v) {
    if (v.refType) {
      os << "TYPED" << *v.refType;
    }
    os << "=" << v.initializer;
  }
};

template <>
struct Printer<OptTypedBindingTableInitializer> {
  static void Print(OutputStream& os,
                    const OptTypedBindingTableInitializer& v) {
    if (v.refType) {
      os << "TYPED" << *v.refType;
    }
    os << "=" << v.initializer;
  }
};

template <>
struct Printer<SessionSetGraphParameterClause> {
  static void Print(OutputStream& os, const SessionSetGraphParameterClause& v) {
    os << "GRAPH" << v.paramName << v.initializer;
  }
};

template <>
struct Printer<SessionSetBindingTableParameterClause> {
  static void Print(OutputStream& os,
                    const SessionSetBindingTableParameterClause& v) {
    os << "TABLE" << v.paramName << v.initializer;
  }
};

template <>
struct Printer<OptTypedValueInitializer> {
  static void Print(OutputStream& os, const OptTypedValueInitializer& v) {
    if (v.type) {
      os << "TYPED" << *v.type;
    }
    os << "=" << v.initializer;
  }
};

template <>
struct Printer<SessionSetValueParameterClause> {
  static void Print(OutputStream& os, const SessionSetValueParameterClause& v) {
    os << "VALUE" << v.paramName << v.initializer;
  }
};

template <>
struct Printer<SessionSetCommand> {
  static void Print(OutputStream& os, const SessionSetCommand& v) {
    os << "SESSION SET";
    std::visit([&](const auto& cmd) { os << cmd; }, v);
  }
};

GQL_AST_ENUM_PRINTER(SessionResetArguments,
                     (None, ""),
                     (Parameters, "PARAMETERS"),
                     (Characteristics, "CHARACTERISTICS"),
                     (Schema, "SCHEMA"),
                     (Graph, "GRAPH"),
                     (TimeZone, "TIME ZONE"))

template <>
struct Printer<SessionResetCommand> {
  static void Print(OutputStream& os, const SessionResetCommand& v) {
    os << "SESSION RESET" << v.arguments;
  }
};

GQL_AST_ENUM_PRINTER(TransactionAccessMode,
                     (ReadOnly, "READ ONLY"),
                     (ReadWrite, "READ WRITE"))

template <>
struct Printer<StartTransactionCommand> {
  static void Print(OutputStream& os, const StartTransactionCommand& v) {
    os << "START TRANSACTION" << Sequence(v.accessModes, ",");
  }
};

GQL_AST_ENUM_PRINTER_LITERAL(EndTransactionCommand, ROLLBACK, COMMIT)

template <>
struct Printer<GraphVariableDefinition> {
  static void Print(OutputStream& os, const GraphVariableDefinition& v) {
    os << "GRAPH" << v.var << v.initializer;
  }
};

template <>
struct Printer<BindingTableVariableDefinition> {
  static void Print(OutputStream& os, const BindingTableVariableDefinition& v) {
    os << "TABLE" << v.var << v.initializer;
  }
};

template <>
struct Printer<ValueVariableDefinition> {
  static void Print(OutputStream& os, const ValueVariableDefinition& v) {
    os << "VALUE" << v.var << v.initializer;
  }
};

template <>
struct Printer<NextStatement> {
  static void Print(OutputStream& os, const NextStatement& v) {
    os << "NEXT" << v.yield << *v.statement;
  }
};

template <>
struct Printer<StatementBlock> {
  static void Print(OutputStream& os, const StatementBlock& v) {
    os << *v.firstStatement << v.nextStatements;
  }
};

template <>
struct Printer<ProcedureBody> {
  static void Print(OutputStream& os, const ProcedureBody& v) {
    if (v.schema) {
      os << "AT" << *v.schema;
    }
    os << v.vars << v.statements;
  }
};

template <>
struct Printer<CreateSchemaStatement> {
  static void Print(OutputStream& os, const CreateSchemaStatement& v) {
    os << "CREATE SCHEMA";
    if (v.ifNotExists) {
      os << "IF NOT EXISTS";
    }
    os << v.schema;
  }
};

template <>
struct Printer<DropSchemaStatement> {
  static void Print(OutputStream& os, const DropSchemaStatement& v) {
    os << "DROP SCHEMA";
    if (v.ifExists) {
      os << "IF EXISTS";
    }
    os << v.schema;
  }
};

template <>
struct Printer<OfGraphType> {
  static void Print(OutputStream& os, const OfGraphType& v) {
    variant_switch(
        v, [&](const GraphExpression& v) { os << "LIKE" << v; },
        [&](const GraphTypeReference& v) { os << "TYPED" << v; },
        [&](const GraphTypeSpecificationBody& v) {
          os << "TYPED GRAPH {" << v << "}";
        });
  }
};

template <>
struct Printer<CreateGraphStatement> {
  static void Print(OutputStream& os, const CreateGraphStatement& v) {
    os << "CREATE";
    switch (v.createType) {
      case CreateGraphStatement::CreateType::Default:
        os << "GRAPH";
        break;
      case CreateGraphStatement::CreateType::IfNotExists:
        os << "GRAPH IF NOT EXISTS";
        break;
      case CreateGraphStatement::CreateType::OrReplace:
        os << "OR REPLACE GRAPH";
        break;
    }
    os << v.graph;
    if (v.graphType) {
      os << *v.graphType;
    } else {
      os << "TYPED ANY GRAPH";
    }
    if (v.source) {
      os << "AS COPY OF" << *v.source;
    }
  }
};

template <>
struct Printer<DropGraphStatement> {
  static void Print(OutputStream& os, const DropGraphStatement& v) {
    os << "DROP GRAPH";
    if (v.ifExists) {
      os << "IF EXISTS";
    }
    os << v.graph;
  }
};

template <>
struct Printer<GraphTypeSource> {
  static void Print(OutputStream& os, const GraphTypeSource& v) {
    variant_switch(
        v, [&](const CopyOfGraphType& v) { os << "AS COPY OF" << v; },
        [&](const GraphExpression& v) { os << "LIKE" << v; },
        [&](const GraphTypeSpecificationBody& v) { os << "AS {" << v << "}"; });
  }
};

template <>
struct Printer<CreateGraphTypeStatement> {
  static void Print(OutputStream& os, const CreateGraphTypeStatement& v) {
    os << "CREATE";
    switch (v.createType) {
      case CreateGraphTypeStatement::CreateType::Default:
        os << "GRAPH TYPE ";
        break;
      case CreateGraphTypeStatement::CreateType::IfNotExists:
        os << "GRAPH TYPE IF NOT EXISTS";
        break;
      case CreateGraphTypeStatement::CreateType::OrReplace:
        os << "OR REPLACE GRAPH TYPE";
        break;
    }
    os << v.graphType << v.source;
  }
};

template <>
struct Printer<DropGraphTypeStatement> {
  static void Print(OutputStream& os, const DropGraphTypeStatement& v) {
    os << "DROP GRAPH TYPE";
    if (v.ifExists) {
      os << "IF EXISTS";
    }
    os << v.graphType;
  }
};

template <>
struct Printer<LinearCatalogModifyingStatement> {
  static void Print(OutputStream& os,
                    const LinearCatalogModifyingStatement& v) {
    os << Sequence(v.statements, "\n");
  }
};

template <>
struct Printer<InsertElementPatternFiller> {
  static void Print(OutputStream& os, const InsertElementPatternFiller& v) {
    os << NoBreak() << v.var;
    if (!v.labels.labels.empty())
      os << ":" << NoBreak() << v.labels;
    if (!v.props.empty())
      os << "{" << v.props << "}";
    os << NoBreak();
  }
};

template <>
struct Printer<InsertNodePattern> {
  static void Print(OutputStream& os, const InsertNodePattern& v) {
    os << "(" << v.filler << ")";
  }
};

template <>
struct Printer<InsertEdgePattern> {
  static void Print(OutputStream& os, const InsertEdgePattern& v) {
    os << NoBreak();
    switch (v.direction) {
      case InsertEdgePattern::Direction::Left:
        os << "<-[" << v.filler << "]-";
        break;
      case InsertEdgePattern::Direction::Right:
        os << "-[" << v.filler << "]->";
        break;
      case InsertEdgePattern::Direction::Undirected:
        os << "~[" << v.filler << "]~";
        break;
    }
    os << NoBreak();
  }
};

template <>
struct Printer<InsertPathPattern> {
  static void Print(OutputStream& os, const InsertPathPattern& v) {
    auto nodeIt = v.nodes.begin();
    for (auto& edge : v.edges) {
      os << *nodeIt << edge;
      nodeIt++;
    }
    os << *nodeIt;
  }
};

template <>
struct Printer<InsertStatement> {
  static void Print(OutputStream& os, const InsertStatement& v) {
    os << "INSERT" << Sequence(v.paths, ",");
  }
};

template <>
struct Printer<SetPropertyItem> {
  static void Print(OutputStream& os, const SetPropertyItem& v) {
    os << v.var << "." << v.property << "=" << v.value;
  }
};

template <>
struct Printer<SetAllPropertiesItem> {
  static void Print(OutputStream& os, const SetAllPropertiesItem& v) {
    os << v.var << "= {" << v.properties << "}";
  }
};

template <>
struct Printer<SetLabelItem> {
  static void Print(OutputStream& os, const SetLabelItem& v) {
    os << v.var << ":" << NoBreak() << v.label;
  }
};

template <>
struct Printer<SetStatement> {
  static void Print(OutputStream& os, const SetStatement& v) {
    os << "SET" << Sequence(v.items, ",");
  }
};

template <>
struct Printer<RemovePropertyItem> {
  static void Print(OutputStream& os, const RemovePropertyItem& v) {
    os << v.var << "." << v.property;
  }
};

template <>
struct Printer<RemoveLabelItem> {
  static void Print(OutputStream& os, const RemoveLabelItem& v) {
    os << v.var << ":" << NoBreak() << v.label;
  }
};

template <>
struct Printer<RemoveStatement> {
  static void Print(OutputStream& os, const RemoveStatement& v) {
    os << "REMOVE" << Sequence(v.items, ",");
  }
};

template <>
struct Printer<DeleteStatement> {
  static void Print(OutputStream& os, const DeleteStatement& v) {
    if (v.detach)
      os << (*v.detach ? "DETACH" : "NODETACH");
    os << "DELETE" << Sequence(v.items, ",");
  }
};

GQL_AST_VALUE_PRINTER(OtherwiseConjunctionValue, "OTHERWISE")

GQL_AST_ENUM_PRINTER_LITERAL(SetOperator::Kind, UNION, EXCEPT, INTERSECT)

GQL_AST_ENUM_PRINTER(MatchMode,
                     (RepeatableElements, "REPEATABLE ELEMENTS"),
                     (DifferentEdges, "DIFFERENT EDGES"))

template <>
struct Printer<PathPatternPrefix> {
  static void Print(OutputStream& os, const PathPatternPrefix& v) {
    switch (v.search) {
      case PathPatternPrefix::Search::No:
        os << v.mode;
        break;
      case PathPatternPrefix::Search::All:
        os << "ALL" << v.mode << "PATHS";
        break;
      case PathPatternPrefix::Search::Any:
        os << "ANY" << v.number << v.mode << "PATHS";
        break;
      case PathPatternPrefix::Search::AllShortest:
        os << "ALL SHORTEST" << v.mode << "PATHS";
        break;
      case PathPatternPrefix::Search::AnyShortest:
        os << "ANY SHORTEST" << v.mode << "PATHS";
        break;
      case PathPatternPrefix::Search::CountedShortestPath:
        os << "SHORTEST" << *v.number << v.mode << "PATHS";
        break;
      case PathPatternPrefix::Search::CountedShortestGroup:
        os << "SHORTEST" << v.number << v.mode << "PATH GROUPS";
        break;
    }
  }
};

template <>
struct Printer<PathPattern> {
  static void Print(OutputStream& os, const PathPattern& v) {
    if (v.var)
      os << *v.var << "=";
    os << v.prefix << v.expr;
  }
};

template <>
struct Printer<GraphPattern> {
  static void Print(OutputStream& os, const GraphPattern& v) {
    os << v.matchMode << Sequence(v.patterns, ",");
    if (v.keep)
      os << "KEEP" << *v.keep;
    if (v.where)
      os << "WHERE" << *v.where;
  }
};

template <>
struct Printer<SimpleMatchStatement> {
  static void Print(OutputStream& os, const SimpleMatchStatement& v) {
    os << "MATCH" << v.pattern;
    if (!v.yield.empty()) {
      os << "YIELD" << Sequence(v.yield, ",");
    }
  }
};

template <>
struct Printer<OptionalMatchStatement> {
  static void Print(OutputStream& os, const OptionalMatchStatement& v) {
    os << "OPTIONAL";
    if (v.statements.size() == 1)
      os << v.statements[0];
    else {
      os << "{" << v.statements << "}";
    }
  }
};

template <>
struct Printer<LetStatement> {
  static void Print(OutputStream& os, const LetStatement& v) {
    os << "LET" << Sequence(v.definitions, ",");
  }
};

template <>
struct Printer<ForOrdinalityOrOffset> {
  static void Print(OutputStream& os, const ForOrdinalityOrOffset& v) {
    os << "WITH" << (v.isOrdinality ? "ORDINALITY" : "OFFSET") << v.var;
  }
};

template <>
struct Printer<ForStatement> {
  static void Print(OutputStream& os, const ForStatement& v) {
    os << "FOR" << v.alias << "IN" << v.source << v.ordinalityOrOffset;
  }
};

GQL_AST_ENUM_PRINTER_LITERAL(OrderingSpecification, ASCENDING, DESCENDING)

GQL_AST_ENUM_PRINTER(NullOrdering,
                     (NULLS_FIRST, "NULLS FIRST"),
                     (NULLS_LAST, "NULLS LAST"))

template <>
struct Printer<OrderByAndPageStatement> {
  static void Print(OutputStream& os, const OrderByAndPageStatement& v) {
    if (!v.orderBy.empty()) {
      os << "ORDER BY" << Sequence(v.orderBy, ",");
    }
    if (v.offset)
      os << "OFFSET" << *v.offset;
    if (v.limit)
      os << "LIMIT" << *v.limit;
  }
};

GQL_AST_VALUE_PRINTER(FinishValue, "FINISH")

template <>
struct Printer<ReturnItem> {
  static void Print(OutputStream& os, const ReturnItem& v) {
    os << v.aggregate;
    if (v.alias)
      os << "AS" << *v.alias;
  }
};

GQL_AST_VALUE_PRINTER(AsteriskValue, "*")

template <>
struct Printer<ReturnStatementBody> {
  static void Print(OutputStream& os, const ReturnStatementBody& v) {
    os << v.quantifier;
    if (v.items)
      os << Sequence(*v.items, ",");
    else
      os << "*";
    if (!v.groupBy.empty()) {
      os << "GROUP BY" << Sequence(v.groupBy, ",");
    }
  }
};

template <>
struct Printer<PrimitiveResultStatement::Return> {
  static void Print(OutputStream& os,
                    const PrimitiveResultStatement::Return& v) {
    os << "RETURN";
    if (v.stmt)
      os << v.stmt;
    else
      os << "NO BINDINGS";
    os << v.orderByAndPage;
  }
};

template <>
struct Printer<SelectItem> {
  static void Print(OutputStream& os, const SelectItem& v) {
    os << v.expr;
    if (v.alias)
      os << "AS" << *v.alias;
  }
};

template <>
struct Printer<SelectGraphMatchList> {
  static void Print(OutputStream& os, const SelectGraphMatchList& v) {
    os << Sequence(v.matches, ",");
  }
};

template <>
struct Printer<SelectQuerySpecification> {
  static void Print(OutputStream& os, const SelectQuerySpecification& v) {
    os << v.graph << "{" << v.query << "}";
  }
};

template <>
struct Printer<SelectItemList> {
  static void Print(OutputStream& os, const SelectItemList& v) {
    os << Sequence(v, ",");
  }
};

template <>
struct Printer<SelectStatement> {
  static void Print(OutputStream& os, const SelectStatement& v) {
    os << "SELECT" << v.quantifier << v.items;
    if (v.body)
      os << "\nFROM" << *v.body;
    if (v.where)
      os << "\nWHERE" << *v.where;
    if (!v.groupBy.empty())
      os << "\nGROUP BY" << Sequence(v.groupBy, ",");
    if (v.having)
      os << "\nHAVING" << *v.having;
    if (!v.orderBy.empty())
      os << "\nORDER BY" << Sequence(v.orderBy, ",");
    if (v.offset)
      os << "\nOFFSET" << *v.offset;
    if (v.limit)
      os << "\nLIMIT" << *v.limit;
  }
};

template <>
struct Printer<FilterStatement> {
  static void Print(OutputStream& os, const FilterStatement& v) {
    os << "FILTER" << v.condition;
  }
};

template <>
struct Printer<NestedQuerySpecification> {
  static void Print(OutputStream& os, const NestedQuerySpecification& v) {
    if (v.useGraph)
      os << "USE" << *v.useGraph;
    os << "{" << v.procedure << "}";
  }
};

template <>
struct Printer<FocusedLinearQueryStatementPart> {
  static void Print(OutputStream& os,
                    const FocusedLinearQueryStatementPart& v) {
    os << "USE" << v.useGraph << v.statements;
  }
};

template <>
struct Printer<LinearQueryStatementOption> {
  static void Print(OutputStream& os, const LinearQueryStatementOption& v) {
    os << v.queries;
    if (v.useGraph)
      os << "USE" << *v.useGraph;
    os << v.statements << v.result;
  }
};

template <>
struct Printer<LinearDataModifyingStatement> {
  static void Print(OutputStream& os, const LinearDataModifyingStatement& v) {
    if (v.useGraph)
      os << "USE" << *v.useGraph;
    variant_switch(
        v.option, [&os](const LinearDataModifyingStatementBody& v) { os << v; },
        [&os](const ProcedureBody& v) { os << "{" << v << "}"; });
  }
};

template <>
struct Printer<GQLProgram> {
  static void Print(OutputStream& os, const GQLProgram& v) {
    os << v.programActivity;
    if (v.sessionCloseCommand)
      os << "SESSION CLOSE";
  }
};

}  // namespace gql::ast::print
