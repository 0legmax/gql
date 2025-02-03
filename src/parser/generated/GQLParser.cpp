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





#include "GQLParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct GQLParserStaticData final {
  GQLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GQLParserStaticData(const GQLParserStaticData&) = delete;
  GQLParserStaticData(GQLParserStaticData&&) = delete;
  GQLParserStaticData& operator=(const GQLParserStaticData&) = delete;
  GQLParserStaticData& operator=(GQLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag gqlParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<GQLParserStaticData> gqlParserStaticData = nullptr;

void gqlParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (gqlParserStaticData != nullptr) {
    return;
  }
#else
  assert(gqlParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GQLParserStaticData>(
    std::vector<std::string>{
      "gqlProgram", "programActivity", "sessionActivity", "transactionActivity", 
      "endTransactionCommand", "sessionSetCommand", "sessionSetSchemaClause", 
      "sessionSetGraphClause", "sessionSetTimeZoneClause", "setTimeZoneValue", 
      "sessionSetParameterClause", "sessionSetGraphParameterClause", "sessionSetBindingTableParameterClause", 
      "sessionSetValueParameterClause", "sessionSetParameterName", "sessionResetCommand", 
      "sessionResetArguments", "sessionCloseCommand", "sessionParameterSpecification", 
      "startTransactionCommand", "transactionCharacteristics", "transactionMode", 
      "transactionAccessMode", "rollbackCommand", "commitCommand", "nestedProcedureSpecification", 
      "procedureSpecification", "nestedDataModifyingProcedureSpecification", 
      "nestedQuerySpecification", "procedureBody", "bindingVariableDefinitionBlock", 
      "bindingVariableDefinition", "statementBlock", "statement", "nextStatement", 
      "graphVariableDefinition", "optTypedGraphInitializer", "graphInitializer", 
      "bindingTableVariableDefinition", "optTypedBindingTableInitializer", 
      "bindingTableInitializer", "valueVariableDefinition", "optTypedValueInitializer", 
      "valueInitializer", "graphExpression", "currentGraph", "bindingTableExpression", 
      "nestedBindingTableQuerySpecification", "objectExpressionPrimary", 
      "linearCatalogModifyingStatement", "simpleCatalogModifyingStatement", 
      "primitiveCatalogModifyingStatement", "createSchemaStatement", "dropSchemaStatement", 
      "createGraphStatement", "openGraphType", "ofGraphType", "graphTypeLikeGraph", 
      "graphSource", "dropGraphStatement", "createGraphTypeStatement", "graphTypeSource", 
      "copyOfGraphType", "dropGraphTypeStatement", "callCatalogModifyingProcedureStatement", 
      "linearDataModifyingStatement", "focusedLinearDataModifyingStatement", 
      "focusedLinearDataModifyingStatementBody", "focusedNestedDataModifyingProcedureSpecification", 
      "ambientLinearDataModifyingStatement", "ambientLinearDataModifyingStatementBody", 
      "simpleLinearDataAccessingStatement", "simpleDataAccessingStatement", 
      "simpleDataModifyingStatement", "primitiveDataModifyingStatement", 
      "insertStatement", "setStatement", "setItemList", "setItem", "setPropertyItem", 
      "setAllPropertiesItem", "setLabelItem", "removeStatement", "removeItemList", 
      "removeItem", "removePropertyItem", "removeLabelItem", "deleteStatement", 
      "deleteItemList", "deleteItem", "callDataModifyingProcedureStatement", 
      "compositeQueryStatement", "compositeQueryExpression", "queryConjunction", 
      "setOperator", "compositeQueryPrimary", "linearQueryStatement", "focusedLinearQueryStatement", 
      "focusedLinearQueryStatementPart", "focusedLinearQueryAndPrimitiveResultStatementPart", 
      "focusedPrimitiveResultStatement", "focusedNestedQuerySpecification", 
      "ambientLinearQueryStatement", "simpleLinearQueryStatement", "simpleQueryStatement", 
      "primitiveQueryStatement", "matchStatement", "simpleMatchStatement", 
      "optionalMatchStatement", "optionalOperand", "matchStatementBlock", 
      "callQueryStatement", "filterStatement", "letStatement", "letVariableDefinitionList", 
      "letVariableDefinition", "forStatement", "forItem", "forItemAlias", 
      "forItemSource", "forOrdinalityOrOffset", "orderByAndPageStatement", 
      "primitiveResultStatement", "returnStatement", "returnStatementBody", 
      "returnItemList", "returnItem", "returnItemAlias", "selectStatement", 
      "selectItemList", "selectItem", "selectItemAlias", "havingClause", 
      "selectStatementBody", "selectGraphMatchList", "selectGraphMatch", 
      "selectQuerySpecification", "callProcedureStatement", "procedureCall", 
      "inlineProcedureCall", "variableScopeClause", "bindingVariableReferenceList", 
      "namedProcedureCall", "procedureArgumentList", "procedureArgument", 
      "atSchemaClause", "useGraphClause", "graphPatternBindingTable", "graphPatternYieldClause", 
      "graphPatternYieldItemList", "graphPatternYieldItem", "graphPattern", 
      "matchMode", "repeatableElementsMatchMode", "differentEdgesMatchMode", 
      "elementBindingsOrElements", "edgeBindingsOrEdges", "pathPatternList", 
      "pathPattern", "pathVariableDeclaration", "keepClause", "graphPatternWhereClause", 
      "insertGraphPattern", "insertPathPatternList", "insertPathPattern", 
      "insertNodePattern", "insertEdgePattern", "insertEdgePointingLeft", 
      "insertEdgePointingRight", "insertEdgeUndirected", "insertElementPatternFiller", 
      "labelAndPropertySetSpecification", "pathPatternPrefix", "pathModePrefix", 
      "pathMode", "pathSearchPrefix", "allPathSearch", "pathOrPaths", "anyPathSearch", 
      "numberOfPaths", "shortestPathSearch", "allShortestPathSearch", "anyShortestPathSearch", 
      "countedShortestPathSearch", "countedShortestGroupSearch", "numberOfGroups", 
      "pathPatternExpression", "pathTerm", "pathFactor", "pathPrimary", 
      "elementPattern", "nodePattern", "elementPatternFiller", "elementVariableDeclaration", 
      "isLabelExpression", "isOrColon", "elementPatternPredicate", "elementPatternWhereClause", 
      "elementPropertySpecification", "propertyKeyValuePairList", "propertyKeyValuePair", 
      "edgePattern", "fullEdgePattern", "fullEdgePointingLeft", "fullEdgeUndirected", 
      "fullEdgePointingRight", "fullEdgeLeftOrUndirected", "fullEdgeUndirectedOrRight", 
      "fullEdgeLeftOrRight", "fullEdgeAnyDirection", "abbreviatedEdgePattern", 
      "parenthesizedPathPatternExpression", "subpathVariableDeclaration", 
      "parenthesizedPathPatternWhereClause", "labelExpression", "pathVariableReference", 
      "elementVariableReference", "graphPatternQuantifier", "fixedQuantifier", 
      "generalQuantifier", "lowerBound", "upperBound", "simplifiedPathPatternExpression", 
      "simplifiedDefaultingLeft", "simplifiedDefaultingUndirected", "simplifiedDefaultingRight", 
      "simplifiedDefaultingLeftOrUndirected", "simplifiedDefaultingUndirectedOrRight", 
      "simplifiedDefaultingLeftOrRight", "simplifiedDefaultingAnyDirection", 
      "simplifiedContents", "simplifiedPathUnion", "simplifiedMultisetAlternation", 
      "simplifiedTerm", "simplifiedFactorLow", "simplifiedFactorHigh", "simplifiedQuantified", 
      "simplifiedQuestioned", "simplifiedTertiary", "simplifiedDirectionOverride", 
      "simplifiedOverrideLeft", "simplifiedOverrideUndirected", "simplifiedOverrideRight", 
      "simplifiedOverrideLeftOrUndirected", "simplifiedOverrideUndirectedOrRight", 
      "simplifiedOverrideLeftOrRight", "simplifiedOverrideAnyDirection", 
      "simplifiedSecondary", "simplifiedNegation", "simplifiedPrimary", 
      "whereClause", "yieldClause", "yieldItemList", "yieldItem", "yieldItemName", 
      "yieldItemAlias", "groupByClause", "groupingElementList", "groupingElement", 
      "emptyGroupingSet", "orderByClause", "sortSpecificationList", "sortSpecification", 
      "sortKey", "orderingSpecification", "nullOrdering", "limitClause", 
      "offsetClause", "offsetSynonym", "schemaReference", "absoluteCatalogSchemaReference", 
      "catalogSchemaParentAndName", "relativeCatalogSchemaReference", "predefinedSchemaReference", 
      "absoluteDirectoryPath", "relativeDirectoryPath", "simpleDirectoryPath", 
      "graphReference", "catalogGraphParentAndName", "homeGraph", "graphTypeReference", 
      "catalogGraphTypeParentAndName", "bindingTableReference", "procedureReference", 
      "catalogProcedureParentAndName", "catalogObjectParentReference", "referenceParameterSpecification", 
      "nestedGraphTypeSpecification", "graphTypeSpecificationBody", "elementTypeList", 
      "elementTypeSpecification", "nodeTypeSpecification", "nodeTypePattern", 
      "nodeTypePhrase", "nodeTypePhraseFiller", "nodeTypeFiller", "localNodeTypeAlias", 
      "nodeTypeImpliedContent", "nodeTypeKeyLabelSet", "nodeTypeLabelSet", 
      "nodeTypePropertyTypes", "edgeTypeSpecification", "edgeTypePattern", 
      "edgeTypePhrase", "edgeTypePhraseFiller", "edgeTypeFiller", "edgeTypeImpliedContent", 
      "edgeTypeKeyLabelSet", "edgeTypeLabelSet", "edgeTypePropertyTypes", 
      "edgeTypePatternDirected", "edgeTypePatternPointingRight", "edgeTypePatternPointingLeft", 
      "edgeTypePatternUndirected", "arcTypePointingRight", "arcTypePointingLeft", 
      "arcTypeUndirected", "sourceNodeTypeReference", "destinationNodeTypeReference", 
      "edgeKind", "endpointPairPhrase", "endpointPair", "endpointPairDirected", 
      "endpointPairPointingRight", "endpointPairPointingLeft", "endpointPairUndirected", 
      "connectorPointingRight", "connectorUndirected", "sourceNodeTypeAlias", 
      "destinationNodeTypeAlias", "labelSetPhrase", "labelSetSpecification", 
      "propertyTypesSpecification", "propertyTypeList", "propertyType", 
      "propertyValueType", "bindingTableType", "valueType", "typed", "predefinedType", 
      "booleanType", "characterStringType", "byteStringType", "minLength", 
      "maxLength", "fixedLength", "numericType", "exactNumericType", "binaryExactNumericType", 
      "signedBinaryExactNumericType", "unsignedBinaryExactNumericType", 
      "verboseBinaryExactNumericType", "decimalExactNumericType", "precision", 
      "scale", "approximateNumericType", "temporalType", "temporalInstantType", 
      "datetimeType", "localdatetimeType", "dateType", "timeType", "localtimeType", 
      "temporalDurationType", "temporalDurationQualifier", "referenceValueType", 
      "immaterialValueType", "nullType", "emptyType", "graphReferenceValueType", 
      "closedGraphReferenceValueType", "openGraphReferenceValueType", "bindingTableReferenceValueType", 
      "nodeReferenceValueType", "closedNodeReferenceValueType", "openNodeReferenceValueType", 
      "edgeReferenceValueType", "closedEdgeReferenceValueType", "openEdgeReferenceValueType", 
      "pathValueType", "listValueTypeName", "listValueTypeNameSynonym", 
      "recordType", "fieldTypesSpecification", "fieldTypeList", "notNull", 
      "fieldType", "searchCondition", "predicate", "compOp", "existsPredicate", 
      "nullPredicate", "nullPredicatePart2", "valueTypePredicate", "valueTypePredicatePart2", 
      "normalizedPredicatePart2", "directedPredicate", "directedPredicatePart2", 
      "labeledPredicate", "labeledPredicatePart2", "isLabeledOrColon", "sourceDestinationPredicate", 
      "nodeReference", "sourcePredicatePart2", "destinationPredicatePart2", 
      "edgeReference", "all_differentPredicate", "samePredicate", "property_existsPredicate", 
      "valueExpression", "valueFunction", "booleanValueExpression", "characterOrByteStringFunction", 
      "subCharacterOrByteString", "trimSingleCharacterOrByteString", "foldCharacterString", 
      "trimMultiCharacterCharacterString", "normalizeCharacterString", "nodeReferenceValueExpression", 
      "edgeReferenceValueExpression", "aggregatingValueExpression", "valueExpressionPrimary", 
      "parenthesizedValueExpression", "nonParenthesizedValueExpressionPrimary", 
      "nonParenthesizedValueExpressionPrimarySpecialCase", "unsignedValueSpecification", 
      "nonNegativeIntegerSpecification", "generalValueSpecification", "dynamicParameterSpecification", 
      "letValueExpression", "valueQueryExpression", "caseExpression", "caseAbbreviation", 
      "caseSpecification", "simpleCase", "searchedCase", "simpleWhenClause", 
      "searchedWhenClause", "elseClause", "caseOperand", "whenOperandList", 
      "whenOperand", "result", "resultExpression", "castSpecification", 
      "castOperand", "castTarget", "aggregateFunction", "generalSetFunction", 
      "binarySetFunction", "generalSetFunctionType", "setQuantifier", "binarySetFunctionType", 
      "dependentValueExpression", "independentValueExpression", "element_idFunction", 
      "bindingVariableReference", "pathValueExpression", "pathValueConstructor", 
      "pathValueConstructorByEnumeration", "pathElementList", "pathElementListStart", 
      "pathElementListStep", "listValueExpression", "listValueFunction", 
      "trimListFunction", "elementsFunction", "listValueConstructor", "listValueConstructorByEnumeration", 
      "listElementList", "listElement", "recordConstructor", "fieldsSpecification", 
      "fieldList", "field", "truthValue", "numericValueExpression", "numericValueFunction", 
      "lengthExpression", "cardinalityExpression", "cardinalityExpressionArgument", 
      "charLengthExpression", "byteLengthExpression", "pathLengthExpression", 
      "absoluteValueExpression", "modulusExpression", "numericValueExpressionDividend", 
      "numericValueExpressionDivisor", "trigonometricFunction", "trigonometricFunctionName", 
      "generalLogarithmFunction", "generalLogarithmBase", "generalLogarithmArgument", 
      "commonLogarithm", "naturalLogarithm", "exponentialFunction", "powerFunction", 
      "numericValueExpressionBase", "numericValueExpressionExponent", "squareRoot", 
      "floorFunction", "ceilingFunction", "characterStringValueExpression", 
      "byteStringValueExpression", "trimOperands", "trimCharacterOrByteStringSource", 
      "trimSpecification", "trimCharacterOrByteString", "normalForm", "stringLength", 
      "datetimeValueExpression", "datetimeValueFunction", "dateFunction", 
      "timeFunction", "localtimeFunction", "datetimeFunction", "localdatetimeFunction", 
      "dateFunctionParameters", "timeFunctionParameters", "datetimeFunctionParameters", 
      "durationValueExpression", "datetimeSubtraction", "datetimeSubtractionParameters", 
      "datetimeValueExpression1", "datetimeValueExpression2", "durationValueFunction", 
      "durationFunction", "durationFunctionParameters", "objectName", "objectNameOrBindingVariable", 
      "directoryName", "schemaName", "graphName", "delimitedGraphName", 
      "graphTypeName", "nodeTypeName", "edgeTypeName", "bindingTableName", 
      "delimitedBindingTableName", "procedureName", "labelName", "propertyName", 
      "fieldName", "elementVariable", "pathVariable", "subpathVariable", 
      "bindingVariable", "unsignedLiteral", "generalLiteral", "temporalLiteral", 
      "dateLiteral", "timeLiteral", "datetimeLiteral", "listLiteral", "recordLiteral", 
      "identifier", "regularIdentifier", "timeZoneString", "characterStringLiteral", 
      "unsignedNumericLiteral", "exactNumericLiteral", "approximateNumericLiteral", 
      "unsignedInteger", "unsignedDecimalInteger", "nullLiteral", "dateString", 
      "timeString", "datetimeString", "durationLiteral", "durationString", 
      "nodeSynonym", "edgesSynonym", "edgeSynonym", "nonReservedWords"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "'ABS'", "'ACOS'", "'ALL'", "'ALL_DIFFERENT'", "'AND'", 
      "'ANY'", "'ARRAY'", "'AS'", "'ASC'", "'ASCENDING'", "'ASIN'", "'AT'", 
      "'ATAN'", "'AVG'", "'BIG'", "'BIGINT'", "'BINARY'", "'BOOL'", "'BOOLEAN'", 
      "'BOTH'", "'BTRIM'", "'BY'", "'BYTE_LENGTH'", "'BYTES'", "'CALL'", 
      "'CARDINALITY'", "'CASE'", "'CAST'", "'CEIL'", "'CEILING'", "'CHAR'", 
      "'CHAR_LENGTH'", "'CHARACTER_LENGTH'", "'CHARACTERISTICS'", "'CLOSE'", 
      "'COALESCE'", "'COLLECT_LIST'", "'COMMIT'", "'COPY'", "'COS'", "'COSH'", 
      "'COT'", "'COUNT'", "'CREATE'", "'CURRENT_DATE'", "'CURRENT_GRAPH'", 
      "'CURRENT_PROPERTY_GRAPH'", "'CURRENT_SCHEMA'", "'CURRENT_TIME'", 
      "'CURRENT_TIMESTAMP'", "'DATE'", "'DATETIME'", "'DAY'", "'DEC'", "'DECIMAL'", 
      "'DEGREES'", "'DELETE'", "'DESC'", "'DESCENDING'", "'DETACH'", "'DISTINCT'", 
      "'DOUBLE'", "'DROP'", "'DURATION'", "'DURATION_BETWEEN'", "'ELEMENT_ID'", 
      "'ELSE'", "'END'", "'EXCEPT'", "'EXISTS'", "'EXP'", "'FILTER'", "'FINISH'", 
      "'FLOAT'", "'FLOAT16'", "'FLOAT32'", "'FLOAT64'", "'FLOAT128'", "'FLOAT256'", 
      "'FLOOR'", "'FOR'", "'FROM'", "'GROUP'", "'HAVING'", "'HOME_GRAPH'", 
      "'HOME_PROPERTY_GRAPH'", "'HOME_SCHEMA'", "'HOUR'", "'IF'", "'IN'", 
      "'INSERT'", "'INT'", "'INTEGER'", "'INT8'", "'INTEGER8'", "'INT16'", 
      "'INTEGER16'", "'INT32'", "'INTEGER32'", "'INT64'", "'INTEGER64'", 
      "'INT128'", "'INTEGER128'", "'INT256'", "'INTEGER256'", "'INTERSECT'", 
      "'INTERVAL'", "'IS'", "'LEADING'", "'LEFT'", "'LET'", "'LIKE'", "'LIMIT'", 
      "'LIST'", "'LN'", "'LOCAL'", "'LOCAL_DATETIME'", "'LOCAL_TIME'", "'LOCAL_TIMESTAMP'", 
      "'LOG'", "'LOG10'", "'LOWER'", "'LTRIM'", "'MATCH'", "'MAX'", "'MIN'", 
      "'MINUTE'", "'MOD'", "'MONTH'", "'NEXT'", "'NODETACH'", "'NORMALIZE'", 
      "'NOT'", "'NOTHING'", "'NULL'", "'NULLS'", "'NULLIF'", "'OCTET_LENGTH'", 
      "'OF'", "'OFFSET'", "'OPTIONAL'", "'OR'", "'ORDER'", "'OTHERWISE'", 
      "'PARAMETER'", "'PARAMETERS'", "'PATH'", "'PATH_LENGTH'", "'PATHS'", 
      "'PERCENTILE_CONT'", "'PERCENTILE_DISC'", "'POWER'", "'PRECISION'", 
      "'PROPERTY_EXISTS'", "'RADIANS'", "'REAL'", "'RECORD'", "'REMOVE'", 
      "'REPLACE'", "'RESET'", "'RETURN'", "'RIGHT'", "'ROLLBACK'", "'RTRIM'", 
      "'SAME'", "'SCHEMA'", "'SECOND'", "'SELECT'", "'SESSION'", "'SESSION_USER'", 
      "'SET'", "'SIGNED'", "'SIN'", "'SINH'", "'SIZE'", "'SKIP'", "'SMALL'", 
      "'SMALLINT'", "'SQRT'", "'START'", "'STDDEV_POP'", "'STDDEV_SAMP'", 
      "'STRING'", "'SUM'", "'TAN'", "'TANH'", "'THEN'", "'TIME'", "'TIMESTAMP'", 
      "'TRAILING'", "'TRIM'", "'TYPED'", "'UBIGINT'", "'UINT'", "'UINT8'", 
      "'UINT16'", "'UINT32'", "'UINT64'", "'UINT128'", "'UINT256'", "'UNION'", 
      "'UNSIGNED'", "'UPPER'", "'USE'", "'USMALLINT'", "'VALUE'", "'VARBINARY'", 
      "'VARCHAR'", "'VARIABLE'", "'WHEN'", "'WHERE'", "'WITH'", "'XOR'", 
      "'YEAR'", "'YIELD'", "'ZONED'", "'ZONED_DATETIME'", "'ZONED_TIME'", 
      "'ABSTRACT'", "'AGGREGATE'", "'AGGREGATES'", "'ALTER'", "'CATALOG'", 
      "'CLEAR'", "'CLONE'", "'CONSTRAINT'", "'CURRENT_ROLE'", "'CURRENT_USER'", 
      "'DATA'", "'DIRECTORY'", "'DRYRUN'", "'EXACT'", "'EXISTING'", "'FUNCTION'", 
      "'GQLSTATUS'", "'GRANT'", "'INSTANT'", "'INFINITY'", "'NUMBER'", "'NUMERIC'", 
      "'ON'", "'OPEN'", "'PARTITION'", "'PROCEDURE'", "'PRODUCT'", "'PROJECT'", 
      "'QUERY'", "'RECORDS'", "'REFERENCE'", "'RENAME'", "'REVOKE'", "'SUBSTRING'", 
      "'SYSTEM_USER'", "'TEMPORAL'", "'UNIQUE'", "'UNIT'", "'VALUES'", "'ACYCLIC'", 
      "'BINDING'", "'BINDINGS'", "'CONNECTING'", "'DESTINATION'", "'DIFFERENT'", 
      "'DIRECTED'", "'EDGE'", "'EDGES'", "'ELEMENT'", "'ELEMENTS'", "'FIRST'", 
      "'GRAPH'", "'GROUPS'", "'KEEP'", "'LABEL'", "'LABELED'", "'LABELS'", 
      "'LAST'", "'NFC'", "'NFD'", "'NFKC'", "'NFKD'", "'NO'", "'NODE'", 
      "'NORMALIZED'", "'ONLY'", "'ORDINALITY'", "'PROPERTY'", "'READ'", 
      "'RELATIONSHIP'", "'RELATIONSHIPS'", "'REPEATABLE'", "'SHORTEST'", 
      "'SIMPLE'", "'SOURCE'", "'TABLE'", "'TEMP'", "'TO'", "'TRAIL'", "'TRANSACTION'", 
      "'TYPE'", "'UNDIRECTED'", "'VERTEX'", "'WALK'", "'WITHOUT'", "'WRITE'", 
      "'ZONE'", "", "", "", "'|+|'", "']->'", "']~>'", "'||'", "'::'", "'$$'", 
      "'..'", "'>='", "'<-'", "'<~'", "'<-['", "'<~['", "'<->'", "'<-/'", 
      "'<~/'", "'<='", "'-['", "'-/'", "'<>'", "'->'", "']-'", "']~'", "'=>'", 
      "'/-'", "'/->'", "'/~'", "'/~>'", "'~['", "'~>'", "'~/'", "'&'", "'*'", 
      "':'", "','", "'@'", "'$'", "'\"'", "'='", "'!'", "'>'", "'`'", "'{'", 
      "'['", "'('", "'<'", "'-'", "'%'", "'.'", "'+'", "'\\u003F'", "'''", 
      "'\\'", "'}'", "']'", "')'", "'/'", "'~'", "'_'", "'|'"
    },
    std::vector<std::string>{
      "", "IMPLIES", "BOOLEAN_LITERAL", "SINGLE_QUOTED_CHARACTER_SEQUENCE", 
      "DOUBLE_QUOTED_CHARACTER_SEQUENCE", "ACCENT_QUOTED_CHARACTER_SEQUENCE", 
      "NO_ESCAPE", "BYTE_STRING_LITERAL", "UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX", 
      "UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX", "UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX", 
      "UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX", "UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX", 
      "UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX", 
      "UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX", "UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX", 
      "UNSIGNED_DECIMAL_INTEGER", "UNSIGNED_HEXADECIMAL_INTEGER", "UNSIGNED_OCTAL_INTEGER", 
      "UNSIGNED_BINARY_INTEGER", "ABS", "ACOS", "ALL", "ALL_DIFFERENT", 
      "AND", "ANY", "ARRAY", "AS", "ASC", "ASCENDING", "ASIN", "AT", "ATAN", 
      "AVG", "BIG", "BIGINT", "BINARY", "BOOL", "BOOLEAN", "BOTH", "BTRIM", 
      "BY", "BYTE_LENGTH", "BYTES", "CALL", "CARDINALITY", "CASE", "CAST", 
      "CEIL", "CEILING", "CHAR", "CHAR_LENGTH", "CHARACTER_LENGTH", "CHARACTERISTICS", 
      "CLOSE", "COALESCE", "COLLECT_LIST", "COMMIT", "COPY", "COS", "COSH", 
      "COT", "COUNT", "CREATE", "CURRENT_DATE", "CURRENT_GRAPH", "CURRENT_PROPERTY_GRAPH", 
      "CURRENT_SCHEMA", "CURRENT_TIME", "CURRENT_TIMESTAMP", "DATE", "DATETIME", 
      "DAY", "DEC", "DECIMAL", "DEGREES", "DELETE", "DESC", "DESCENDING", 
      "DETACH", "DISTINCT", "DOUBLE", "DROP", "DURATION", "DURATION_BETWEEN", 
      "ELEMENT_ID", "ELSE", "END", "EXCEPT", "EXISTS", "EXP", "FILTER", 
      "FINISH", "FLOAT", "FLOAT16", "FLOAT32", "FLOAT64", "FLOAT128", "FLOAT256", 
      "FLOOR", "FOR", "FROM", "GROUP", "HAVING", "HOME_GRAPH", "HOME_PROPERTY_GRAPH", 
      "HOME_SCHEMA", "HOUR", "IF", "IN", "INSERT", "INT", "INTEGER", "INT8", 
      "INTEGER8", "INT16", "INTEGER16", "INT32", "INTEGER32", "INT64", "INTEGER64", 
      "INT128", "INTEGER128", "INT256", "INTEGER256", "INTERSECT", "INTERVAL", 
      "IS", "LEADING", "LEFT", "LET", "LIKE", "LIMIT", "LIST", "LN", "LOCAL", 
      "LOCAL_DATETIME", "LOCAL_TIME", "LOCAL_TIMESTAMP", "LOG_KW", "LOG10", 
      "LOWER", "LTRIM", "MATCH", "MAX", "MIN", "MINUTE", "MOD", "MONTH", 
      "NEXT", "NODETACH", "NORMALIZE", "NOT", "NOTHING", "NULL_KW", "NULLS", 
      "NULLIF", "OCTET_LENGTH", "OF", "OFFSET", "OPTIONAL", "OR", "ORDER", 
      "OTHERWISE", "PARAMETER", "PARAMETERS", "PATH", "PATH_LENGTH", "PATHS", 
      "PERCENTILE_CONT", "PERCENTILE_DISC", "POWER", "PRECISION", "PROPERTY_EXISTS", 
      "RADIANS", "REAL", "RECORD", "REMOVE", "REPLACE", "RESET", "RETURN", 
      "RIGHT", "ROLLBACK", "RTRIM", "SAME", "SCHEMA", "SECOND", "SELECT", 
      "SESSION", "SESSION_USER", "SET", "SIGNED", "SIN", "SINH", "SIZE", 
      "SKIP_RESERVED_WORD", "SMALL", "SMALLINT", "SQRT", "START", "STDDEV_POP", 
      "STDDEV_SAMP", "STRING", "SUM", "TAN", "TANH", "THEN", "TIME", "TIMESTAMP", 
      "TRAILING", "TRIM", "TYPED", "UBIGINT", "UINT", "UINT8", "UINT16", 
      "UINT32", "UINT64", "UINT128", "UINT256", "UNION", "UNSIGNED", "UPPER", 
      "USE", "USMALLINT", "VALUE", "VARBINARY", "VARCHAR", "VARIABLE", "WHEN", 
      "WHERE", "WITH", "XOR", "YEAR", "YIELD", "ZONED", "ZONED_DATETIME", 
      "ZONED_TIME", "ABSTRACT", "AGGREGATE", "AGGREGATES", "ALTER", "CATALOG", 
      "CLEAR", "CLONE", "CONSTRAINT", "CURRENT_ROLE", "CURRENT_USER", "DATA", 
      "DIRECTORY", "DRYRUN", "EXACT", "EXISTING", "FUNCTION", "GQLSTATUS", 
      "GRANT", "INSTANT", "INFINITY_KW", "NUMBER", "NUMERIC", "ON", "OPEN", 
      "PARTITION", "PROCEDURE", "PRODUCT", "PROJECT", "QUERY", "RECORDS", 
      "REFERENCE", "RENAME", "REVOKE", "SUBSTRING", "SYSTEM_USER", "TEMPORAL", 
      "UNIQUE", "UNIT", "VALUES", "ACYCLIC", "BINDING", "BINDINGS", "CONNECTING", 
      "DESTINATION", "DIFFERENT", "DIRECTED", "EDGE", "EDGES", "ELEMENT", 
      "ELEMENTS", "FIRST", "GRAPH", "GROUPS", "KEEP", "LABEL", "LABELED", 
      "LABELS", "LAST", "NFC", "NFD", "NFKC", "NFKD", "NO", "NODE", "NORMALIZED", 
      "ONLY", "ORDINALITY", "PROPERTY", "READ", "RELATIONSHIP", "RELATIONSHIPS", 
      "REPEATABLE", "SHORTEST", "SIMPLE", "SOURCE", "TABLE", "TEMP", "TO", 
      "TRAIL", "TRANSACTION", "TYPE", "UNDIRECTED", "VERTEX", "WALK", "WITHOUT", 
      "WRITE", "ZONE", "REGULAR_IDENTIFIER", "SUBSTITUTED_PARAMETER_REFERENCE", 
      "GENERAL_PARAMETER_REFERENCE", "MULTISET_ALTERNATION_OPERATOR", "BRACKET_RIGHT_ARROW", 
      "BRACKET_TILDE_RIGHT_ARROW", "CONCATENATION_OPERATOR", "DOUBLE_COLON", 
      "DOUBLE_DOLLAR_SIGN", "DOUBLE_PERIOD", "GREATER_THAN_OR_EQUALS_OPERATOR", 
      "LEFT_ARROW", "LEFT_ARROW_TILDE", "LEFT_ARROW_BRACKET", "LEFT_ARROW_TILDE_BRACKET", 
      "LEFT_MINUS_RIGHT", "LEFT_MINUS_SLASH", "LEFT_TILDE_SLASH", "LESS_THAN_OR_EQUALS_OPERATOR", 
      "MINUS_LEFT_BRACKET", "MINUS_SLASH", "NOT_EQUALS_OPERATOR", "RIGHT_ARROW", 
      "RIGHT_BRACKET_MINUS", "RIGHT_BRACKET_TILDE", "RIGHT_DOUBLE_ARROW", 
      "SLASH_MINUS", "SLASH_MINUS_RIGHT", "SLASH_TILDE", "SLASH_TILDE_RIGHT", 
      "TILDE_LEFT_BRACKET", "TILDE_RIGHT_ARROW", "TILDE_SLASH", "AMPERSAND", 
      "ASTERISK", "COLON", "COMMA", "COMMERCIAL_AT", "DOLLAR_SIGN", "DOUBLE_QUOTE", 
      "EQUALS_OPERATOR", "EXCLAMATION_MARK", "RIGHT_ANGLE_BRACKET", "GRAVE_ACCENT", 
      "LEFT_BRACE", "LEFT_BRACKET", "LEFT_PAREN", "LEFT_ANGLE_BRACKET", 
      "MINUS_SIGN", "PERCENT", "PERIOD", "PLUS_SIGN", "QUESTION_MARK", "QUOTE", 
      "REVERSE_SOLIDUS", "RIGHT_BRACE", "RIGHT_BRACKET", "RIGHT_PAREN", 
      "SOLIDUS", "TILDE", "UNDERSCORE", "VERTICAL_BAR", "SP", "WHITESPACE", 
      "BRACKETED_COMMENT", "SIMPLE_COMMENT_SOLIDUS", "SIMPLE_COMMENT_MINUS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,391,4617,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,
  	7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,76,2,77,
  	7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,83,2,84,
  	7,84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,2,89,7,89,2,90,7,90,2,91,
  	7,91,2,92,7,92,2,93,7,93,2,94,7,94,2,95,7,95,2,96,7,96,2,97,7,97,2,98,
  	7,98,2,99,7,99,2,100,7,100,2,101,7,101,2,102,7,102,2,103,7,103,2,104,
  	7,104,2,105,7,105,2,106,7,106,2,107,7,107,2,108,7,108,2,109,7,109,2,110,
  	7,110,2,111,7,111,2,112,7,112,2,113,7,113,2,114,7,114,2,115,7,115,2,116,
  	7,116,2,117,7,117,2,118,7,118,2,119,7,119,2,120,7,120,2,121,7,121,2,122,
  	7,122,2,123,7,123,2,124,7,124,2,125,7,125,2,126,7,126,2,127,7,127,2,128,
  	7,128,2,129,7,129,2,130,7,130,2,131,7,131,2,132,7,132,2,133,7,133,2,134,
  	7,134,2,135,7,135,2,136,7,136,2,137,7,137,2,138,7,138,2,139,7,139,2,140,
  	7,140,2,141,7,141,2,142,7,142,2,143,7,143,2,144,7,144,2,145,7,145,2,146,
  	7,146,2,147,7,147,2,148,7,148,2,149,7,149,2,150,7,150,2,151,7,151,2,152,
  	7,152,2,153,7,153,2,154,7,154,2,155,7,155,2,156,7,156,2,157,7,157,2,158,
  	7,158,2,159,7,159,2,160,7,160,2,161,7,161,2,162,7,162,2,163,7,163,2,164,
  	7,164,2,165,7,165,2,166,7,166,2,167,7,167,2,168,7,168,2,169,7,169,2,170,
  	7,170,2,171,7,171,2,172,7,172,2,173,7,173,2,174,7,174,2,175,7,175,2,176,
  	7,176,2,177,7,177,2,178,7,178,2,179,7,179,2,180,7,180,2,181,7,181,2,182,
  	7,182,2,183,7,183,2,184,7,184,2,185,7,185,2,186,7,186,2,187,7,187,2,188,
  	7,188,2,189,7,189,2,190,7,190,2,191,7,191,2,192,7,192,2,193,7,193,2,194,
  	7,194,2,195,7,195,2,196,7,196,2,197,7,197,2,198,7,198,2,199,7,199,2,200,
  	7,200,2,201,7,201,2,202,7,202,2,203,7,203,2,204,7,204,2,205,7,205,2,206,
  	7,206,2,207,7,207,2,208,7,208,2,209,7,209,2,210,7,210,2,211,7,211,2,212,
  	7,212,2,213,7,213,2,214,7,214,2,215,7,215,2,216,7,216,2,217,7,217,2,218,
  	7,218,2,219,7,219,2,220,7,220,2,221,7,221,2,222,7,222,2,223,7,223,2,224,
  	7,224,2,225,7,225,2,226,7,226,2,227,7,227,2,228,7,228,2,229,7,229,2,230,
  	7,230,2,231,7,231,2,232,7,232,2,233,7,233,2,234,7,234,2,235,7,235,2,236,
  	7,236,2,237,7,237,2,238,7,238,2,239,7,239,2,240,7,240,2,241,7,241,2,242,
  	7,242,2,243,7,243,2,244,7,244,2,245,7,245,2,246,7,246,2,247,7,247,2,248,
  	7,248,2,249,7,249,2,250,7,250,2,251,7,251,2,252,7,252,2,253,7,253,2,254,
  	7,254,2,255,7,255,2,256,7,256,2,257,7,257,2,258,7,258,2,259,7,259,2,260,
  	7,260,2,261,7,261,2,262,7,262,2,263,7,263,2,264,7,264,2,265,7,265,2,266,
  	7,266,2,267,7,267,2,268,7,268,2,269,7,269,2,270,7,270,2,271,7,271,2,272,
  	7,272,2,273,7,273,2,274,7,274,2,275,7,275,2,276,7,276,2,277,7,277,2,278,
  	7,278,2,279,7,279,2,280,7,280,2,281,7,281,2,282,7,282,2,283,7,283,2,284,
  	7,284,2,285,7,285,2,286,7,286,2,287,7,287,2,288,7,288,2,289,7,289,2,290,
  	7,290,2,291,7,291,2,292,7,292,2,293,7,293,2,294,7,294,2,295,7,295,2,296,
  	7,296,2,297,7,297,2,298,7,298,2,299,7,299,2,300,7,300,2,301,7,301,2,302,
  	7,302,2,303,7,303,2,304,7,304,2,305,7,305,2,306,7,306,2,307,7,307,2,308,
  	7,308,2,309,7,309,2,310,7,310,2,311,7,311,2,312,7,312,2,313,7,313,2,314,
  	7,314,2,315,7,315,2,316,7,316,2,317,7,317,2,318,7,318,2,319,7,319,2,320,
  	7,320,2,321,7,321,2,322,7,322,2,323,7,323,2,324,7,324,2,325,7,325,2,326,
  	7,326,2,327,7,327,2,328,7,328,2,329,7,329,2,330,7,330,2,331,7,331,2,332,
  	7,332,2,333,7,333,2,334,7,334,2,335,7,335,2,336,7,336,2,337,7,337,2,338,
  	7,338,2,339,7,339,2,340,7,340,2,341,7,341,2,342,7,342,2,343,7,343,2,344,
  	7,344,2,345,7,345,2,346,7,346,2,347,7,347,2,348,7,348,2,349,7,349,2,350,
  	7,350,2,351,7,351,2,352,7,352,2,353,7,353,2,354,7,354,2,355,7,355,2,356,
  	7,356,2,357,7,357,2,358,7,358,2,359,7,359,2,360,7,360,2,361,7,361,2,362,
  	7,362,2,363,7,363,2,364,7,364,2,365,7,365,2,366,7,366,2,367,7,367,2,368,
  	7,368,2,369,7,369,2,370,7,370,2,371,7,371,2,372,7,372,2,373,7,373,2,374,
  	7,374,2,375,7,375,2,376,7,376,2,377,7,377,2,378,7,378,2,379,7,379,2,380,
  	7,380,2,381,7,381,2,382,7,382,2,383,7,383,2,384,7,384,2,385,7,385,2,386,
  	7,386,2,387,7,387,2,388,7,388,2,389,7,389,2,390,7,390,2,391,7,391,2,392,
  	7,392,2,393,7,393,2,394,7,394,2,395,7,395,2,396,7,396,2,397,7,397,2,398,
  	7,398,2,399,7,399,2,400,7,400,2,401,7,401,2,402,7,402,2,403,7,403,2,404,
  	7,404,2,405,7,405,2,406,7,406,2,407,7,407,2,408,7,408,2,409,7,409,2,410,
  	7,410,2,411,7,411,2,412,7,412,2,413,7,413,2,414,7,414,2,415,7,415,2,416,
  	7,416,2,417,7,417,2,418,7,418,2,419,7,419,2,420,7,420,2,421,7,421,2,422,
  	7,422,2,423,7,423,2,424,7,424,2,425,7,425,2,426,7,426,2,427,7,427,2,428,
  	7,428,2,429,7,429,2,430,7,430,2,431,7,431,2,432,7,432,2,433,7,433,2,434,
  	7,434,2,435,7,435,2,436,7,436,2,437,7,437,2,438,7,438,2,439,7,439,2,440,
  	7,440,2,441,7,441,2,442,7,442,2,443,7,443,2,444,7,444,2,445,7,445,2,446,
  	7,446,2,447,7,447,2,448,7,448,2,449,7,449,2,450,7,450,2,451,7,451,2,452,
  	7,452,2,453,7,453,2,454,7,454,2,455,7,455,2,456,7,456,2,457,7,457,2,458,
  	7,458,2,459,7,459,2,460,7,460,2,461,7,461,2,462,7,462,2,463,7,463,2,464,
  	7,464,2,465,7,465,2,466,7,466,2,467,7,467,2,468,7,468,2,469,7,469,2,470,
  	7,470,2,471,7,471,2,472,7,472,2,473,7,473,2,474,7,474,2,475,7,475,2,476,
  	7,476,2,477,7,477,2,478,7,478,2,479,7,479,2,480,7,480,2,481,7,481,2,482,
  	7,482,2,483,7,483,2,484,7,484,2,485,7,485,2,486,7,486,2,487,7,487,2,488,
  	7,488,2,489,7,489,2,490,7,490,2,491,7,491,2,492,7,492,2,493,7,493,2,494,
  	7,494,2,495,7,495,2,496,7,496,2,497,7,497,2,498,7,498,2,499,7,499,2,500,
  	7,500,2,501,7,501,2,502,7,502,2,503,7,503,2,504,7,504,2,505,7,505,2,506,
  	7,506,2,507,7,507,2,508,7,508,2,509,7,509,2,510,7,510,2,511,7,511,2,512,
  	7,512,2,513,7,513,2,514,7,514,2,515,7,515,2,516,7,516,2,517,7,517,2,518,
  	7,518,2,519,7,519,2,520,7,520,2,521,7,521,2,522,7,522,2,523,7,523,2,524,
  	7,524,2,525,7,525,2,526,7,526,2,527,7,527,2,528,7,528,2,529,7,529,2,530,
  	7,530,2,531,7,531,2,532,7,532,2,533,7,533,2,534,7,534,2,535,7,535,2,536,
  	7,536,2,537,7,537,2,538,7,538,2,539,7,539,2,540,7,540,2,541,7,541,2,542,
  	7,542,2,543,7,543,2,544,7,544,2,545,7,545,2,546,7,546,2,547,7,547,2,548,
  	7,548,2,549,7,549,2,550,7,550,2,551,7,551,2,552,7,552,2,553,7,553,2,554,
  	7,554,2,555,7,555,2,556,7,556,2,557,7,557,2,558,7,558,2,559,7,559,2,560,
  	7,560,2,561,7,561,2,562,7,562,2,563,7,563,2,564,7,564,2,565,7,565,2,566,
  	7,566,2,567,7,567,2,568,7,568,2,569,7,569,2,570,7,570,2,571,7,571,2,572,
  	7,572,2,573,7,573,1,0,1,0,3,0,1151,8,0,1,0,1,0,1,0,1,0,1,0,3,0,1158,8,
  	0,1,1,1,1,3,1,1162,8,1,1,2,4,2,1165,8,2,11,2,12,2,1166,1,2,4,2,1170,8,
  	2,11,2,12,2,1171,1,2,5,2,1175,8,2,10,2,12,2,1178,9,2,3,2,1180,8,2,1,3,
  	1,3,1,3,3,3,1185,8,3,3,3,1187,8,3,1,3,1,3,3,3,1191,8,3,1,3,3,3,1194,8,
  	3,1,4,1,4,3,4,1198,8,4,1,5,1,5,1,5,1,5,1,5,1,5,3,5,1206,8,5,1,6,1,6,1,
  	6,1,7,3,7,1212,8,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,10,
  	3,10,1226,8,10,1,11,3,11,1229,8,11,1,11,1,11,1,11,1,11,1,12,3,12,1236,
  	8,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,3,14,1249,
  	8,14,1,14,1,14,1,15,1,15,1,15,3,15,1256,8,15,1,16,3,16,1259,8,16,1,16,
  	1,16,1,16,3,16,1264,8,16,1,16,1,16,1,16,1,16,3,16,1270,8,16,1,16,3,16,
  	1273,8,16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,19,3,19,1283,8,19,1,20,
  	1,20,1,20,5,20,1288,8,20,10,20,12,20,1291,9,20,1,21,1,21,1,22,1,22,1,
  	22,1,22,3,22,1299,8,22,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,25,1,26,1,
  	26,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,29,3,29,1320,8,29,1,29,3,
  	29,1323,8,29,1,29,1,29,1,30,4,30,1328,8,30,11,30,12,30,1329,1,31,1,31,
  	1,31,3,31,1335,8,31,1,32,1,32,5,32,1339,8,32,10,32,12,32,1342,9,32,1,
  	33,1,33,1,33,3,33,1347,8,33,1,34,1,34,3,34,1351,8,34,1,34,1,34,1,35,3,
  	35,1356,8,35,1,35,1,35,1,35,1,35,1,36,3,36,1363,8,36,1,36,3,36,1366,8,
  	36,1,36,1,36,1,37,1,37,1,37,1,38,3,38,1374,8,38,1,38,1,38,1,38,1,38,1,
  	39,3,39,1381,8,39,1,39,3,39,1384,8,39,1,39,1,39,1,40,1,40,1,40,1,41,1,
  	41,1,41,1,41,1,42,3,42,1396,8,42,1,42,3,42,1399,8,42,1,42,1,42,1,43,1,
  	43,1,43,1,44,1,44,1,44,1,44,3,44,1410,8,44,1,45,1,45,1,46,1,46,1,46,1,
  	46,3,46,1418,8,46,1,47,1,47,1,48,1,48,1,48,1,48,3,48,1426,8,48,1,49,4,
  	49,1429,8,49,11,49,12,49,1430,1,50,1,50,3,50,1435,8,50,1,51,1,51,1,51,
  	1,51,1,51,1,51,3,51,1443,8,51,1,52,1,52,1,52,1,52,1,52,3,52,1450,8,52,
  	1,52,1,52,1,53,1,53,1,53,1,53,3,53,1458,8,53,1,53,1,53,1,54,1,54,3,54,
  	1464,8,54,1,54,1,54,1,54,1,54,3,54,1470,8,54,1,54,1,54,1,54,3,54,1475,
  	8,54,1,54,3,54,1478,8,54,1,54,1,54,1,54,3,54,1483,8,54,1,54,3,54,1486,
  	8,54,1,55,3,55,1489,8,55,1,55,1,55,3,55,1493,8,55,1,55,3,55,1496,8,55,
  	1,56,1,56,3,56,1500,8,56,1,56,1,56,3,56,1504,8,56,1,56,3,56,1507,8,56,
  	1,56,3,56,1510,8,56,1,56,3,56,1513,8,56,1,57,1,57,1,57,1,58,1,58,1,58,
  	1,58,1,58,1,59,1,59,3,59,1525,8,59,1,59,1,59,1,59,3,59,1530,8,59,1,59,
  	1,59,1,60,1,60,3,60,1536,8,60,1,60,1,60,1,60,1,60,1,60,3,60,1543,8,60,
  	1,60,1,60,1,60,3,60,1548,8,60,1,60,1,60,3,60,1552,8,60,1,60,1,60,1,60,
  	1,61,3,61,1558,8,61,1,61,1,61,1,61,3,61,1563,8,61,1,61,3,61,1566,8,61,
  	1,62,1,62,1,62,1,62,1,63,1,63,3,63,1574,8,63,1,63,1,63,1,63,1,63,3,63,
  	1580,8,63,1,63,1,63,1,64,1,64,1,65,1,65,3,65,1588,8,65,1,66,1,66,3,66,
  	1592,8,66,1,67,1,67,1,67,3,67,1597,8,67,1,68,1,68,1,68,1,69,1,69,3,69,
  	1604,8,69,1,70,1,70,3,70,1608,8,70,1,71,4,71,1611,8,71,11,71,12,71,1612,
  	1,72,1,72,3,72,1617,8,72,1,73,1,73,3,73,1621,8,73,1,74,1,74,1,74,1,74,
  	3,74,1627,8,74,1,75,1,75,1,75,1,76,1,76,1,76,1,77,1,77,1,77,5,77,1638,
  	8,77,10,77,12,77,1641,9,77,1,78,1,78,1,78,3,78,1646,8,78,1,79,1,79,1,
  	79,1,79,1,79,1,79,1,80,1,80,1,80,1,80,3,80,1658,8,80,1,80,1,80,1,81,1,
  	81,1,81,1,81,1,82,1,82,1,82,1,83,1,83,1,83,5,83,1672,8,83,10,83,12,83,
  	1675,9,83,1,84,1,84,3,84,1679,8,84,1,85,1,85,1,85,1,85,1,86,1,86,1,86,
  	1,86,1,87,3,87,1690,8,87,1,87,1,87,1,87,1,88,1,88,1,88,5,88,1698,8,88,
  	10,88,12,88,1701,9,88,1,89,1,89,1,90,1,90,1,91,1,91,1,92,1,92,1,92,1,
  	92,1,92,1,92,1,92,5,92,1716,8,92,10,92,12,92,1719,9,92,1,93,1,93,3,93,
  	1723,8,93,1,94,1,94,3,94,1727,8,94,1,94,1,94,3,94,1731,8,94,1,94,1,94,
  	3,94,1735,8,94,3,94,1737,8,94,1,95,1,95,1,96,1,96,3,96,1743,8,96,1,97,
  	5,97,1746,8,97,10,97,12,97,1749,9,97,1,97,1,97,1,97,1,97,3,97,1755,8,
  	97,1,98,1,98,1,98,1,99,1,99,1,99,1,99,1,100,1,100,1,100,1,101,1,101,1,
  	101,1,102,3,102,1771,8,102,1,102,1,102,3,102,1775,8,102,1,103,4,103,1778,
  	8,103,11,103,12,103,1779,1,104,1,104,3,104,1784,8,104,1,105,1,105,1,105,
  	1,105,1,105,3,105,1791,8,105,1,106,1,106,3,106,1795,8,106,1,107,1,107,
  	1,107,1,108,1,108,1,108,1,109,1,109,1,109,1,109,1,109,1,109,1,109,1,109,
  	1,109,3,109,1812,8,109,1,110,4,110,1815,8,110,11,110,12,110,1816,1,111,
  	1,111,1,112,1,112,1,112,3,112,1824,8,112,1,113,1,113,1,113,1,114,1,114,
  	1,114,5,114,1832,8,114,10,114,12,114,1835,9,114,1,115,1,115,1,115,1,115,
  	1,115,3,115,1842,8,115,1,116,1,116,1,116,3,116,1847,8,116,1,117,1,117,
  	1,117,1,118,1,118,1,118,1,119,1,119,1,120,1,120,1,120,1,120,1,121,1,121,
  	3,121,1863,8,121,1,121,3,121,1866,8,121,1,121,1,121,3,121,1870,8,121,
  	1,121,3,121,1873,8,121,1,122,1,122,3,122,1877,8,122,1,122,3,122,1880,
  	8,122,1,123,1,123,1,123,1,124,3,124,1886,8,124,1,124,1,124,3,124,1890,
  	8,124,1,124,3,124,1893,8,124,1,124,1,124,3,124,1897,8,124,1,125,1,125,
  	1,125,5,125,1902,8,125,10,125,12,125,1905,9,125,1,126,1,126,3,126,1909,
  	8,126,1,127,1,127,1,127,1,128,1,128,3,128,1916,8,128,1,128,1,128,3,128,
  	1920,8,128,1,128,1,128,3,128,1924,8,128,1,128,3,128,1927,8,128,1,128,
  	3,128,1930,8,128,1,128,3,128,1933,8,128,1,128,3,128,1936,8,128,1,128,
  	3,128,1939,8,128,3,128,1941,8,128,1,129,1,129,1,129,5,129,1946,8,129,
  	10,129,12,129,1949,9,129,1,130,1,130,3,130,1953,8,130,1,131,1,131,1,131,
  	1,132,1,132,1,132,1,133,1,133,1,133,3,133,1964,8,133,1,134,1,134,1,134,
  	5,134,1969,8,134,10,134,12,134,1972,9,134,1,135,1,135,1,135,1,136,1,136,
  	1,136,1,136,3,136,1981,8,136,1,137,3,137,1984,8,137,1,137,1,137,1,137,
  	1,138,1,138,3,138,1991,8,138,1,139,3,139,1994,8,139,1,139,1,139,1,140,
  	1,140,3,140,2000,8,140,1,140,1,140,1,141,1,141,1,141,5,141,2007,8,141,
  	10,141,12,141,2010,9,141,1,142,1,142,1,142,3,142,2015,8,142,1,142,1,142,
  	3,142,2019,8,142,1,143,1,143,1,143,5,143,2024,8,143,10,143,12,143,2027,
  	9,143,1,144,1,144,1,145,1,145,1,145,1,146,1,146,1,146,1,147,1,147,3,147,
  	2039,8,147,1,148,1,148,1,148,1,149,1,149,1,149,5,149,2047,8,149,10,149,
  	12,149,2050,9,149,1,149,1,149,3,149,2054,8,149,1,150,1,150,1,151,3,151,
  	2059,8,151,1,151,1,151,3,151,2063,8,151,1,151,3,151,2066,8,151,1,152,
  	1,152,3,152,2070,8,152,1,153,1,153,1,153,1,154,1,154,1,154,1,155,1,155,
  	3,155,2080,8,155,1,155,3,155,2083,8,155,1,156,1,156,3,156,2087,8,156,
  	1,156,3,156,2090,8,156,1,157,1,157,1,157,5,157,2095,8,157,10,157,12,157,
  	2098,9,157,1,158,3,158,2101,8,158,1,158,3,158,2104,8,158,1,158,1,158,
  	1,159,1,159,1,159,1,160,1,160,1,160,1,161,1,161,1,161,1,162,1,162,1,163,
  	1,163,1,163,5,163,2122,8,163,10,163,12,163,2125,9,163,1,164,1,164,1,164,
  	1,164,5,164,2131,8,164,10,164,12,164,2134,9,164,1,165,1,165,3,165,2138,
  	8,165,1,165,1,165,1,166,1,166,1,166,3,166,2145,8,166,1,167,1,167,3,167,
  	2149,8,167,1,167,1,167,1,168,1,168,3,168,2155,8,168,1,168,1,168,1,169,
  	1,169,3,169,2161,8,169,1,169,1,169,1,170,1,170,3,170,2167,8,170,1,170,
  	3,170,2170,8,170,1,170,3,170,2173,8,170,1,171,1,171,1,171,3,171,2178,
  	8,171,1,171,1,171,1,171,3,171,2183,8,171,1,171,3,171,2186,8,171,1,172,
  	1,172,3,172,2190,8,172,1,173,1,173,3,173,2194,8,173,1,174,1,174,1,175,
  	1,175,1,175,3,175,2201,8,175,1,176,1,176,3,176,2205,8,176,1,176,3,176,
  	2208,8,176,1,177,1,177,1,178,1,178,3,178,2214,8,178,1,178,3,178,2217,
  	8,178,1,178,3,178,2220,8,178,1,179,1,179,1,180,1,180,1,180,1,180,3,180,
  	2228,8,180,1,181,1,181,1,181,3,181,2233,8,181,1,181,3,181,2236,8,181,
  	1,182,1,182,1,182,3,182,2241,8,182,1,182,3,182,2244,8,182,1,183,1,183,
  	1,183,3,183,2249,8,183,1,183,3,183,2252,8,183,1,184,1,184,3,184,2256,
  	8,184,1,184,3,184,2259,8,184,1,184,3,184,2262,8,184,1,184,1,184,1,185,
  	1,185,1,186,1,186,1,186,1,186,4,186,2272,8,186,11,186,12,186,2273,1,186,
  	1,186,1,186,4,186,2279,8,186,11,186,12,186,2280,3,186,2283,8,186,1,187,
  	4,187,2286,8,187,11,187,12,187,2287,1,188,1,188,1,188,1,188,1,188,1,188,
  	1,188,3,188,2297,8,188,1,189,1,189,1,189,3,189,2302,8,189,1,190,1,190,
  	3,190,2306,8,190,1,191,1,191,1,191,1,191,1,192,3,192,2313,8,192,1,192,
  	3,192,2316,8,192,1,192,3,192,2319,8,192,1,193,3,193,2322,8,193,1,193,
  	1,193,1,194,1,194,1,194,1,195,1,195,1,196,1,196,3,196,2333,8,196,1,197,
  	1,197,1,197,1,198,1,198,1,198,1,198,1,199,1,199,1,199,5,199,2345,8,199,
  	10,199,12,199,2348,9,199,1,200,1,200,1,200,1,200,1,201,1,201,3,201,2356,
  	8,201,1,202,1,202,1,202,1,202,1,202,1,202,1,202,3,202,2365,8,202,1,203,
  	1,203,1,203,1,203,1,204,1,204,1,204,1,204,1,205,1,205,1,205,1,205,1,206,
  	1,206,1,206,1,206,1,207,1,207,1,207,1,207,1,208,1,208,1,208,1,208,1,209,
  	1,209,1,209,1,209,1,210,1,210,1,211,1,211,3,211,2399,8,211,1,211,3,211,
  	2402,8,211,1,211,1,211,3,211,2406,8,211,1,211,1,211,1,212,1,212,1,212,
  	1,213,1,213,1,213,1,214,1,214,1,214,1,214,1,214,1,214,1,214,1,214,1,214,
  	3,214,2425,8,214,1,214,1,214,1,214,1,214,1,214,1,214,5,214,2433,8,214,
  	10,214,12,214,2436,9,214,1,215,1,215,1,216,1,216,1,217,1,217,1,217,1,
  	217,3,217,2446,8,217,1,218,1,218,1,218,1,218,1,219,1,219,3,219,2454,8,
  	219,1,219,1,219,3,219,2458,8,219,1,219,1,219,1,220,1,220,1,221,1,221,
  	1,222,1,222,1,222,1,222,1,222,1,222,1,222,3,222,2473,8,222,1,223,1,223,
  	1,223,1,223,1,224,1,224,1,224,1,224,1,225,1,225,1,225,1,225,1,226,1,226,
  	1,226,1,226,1,227,1,227,1,227,1,227,1,228,1,228,1,228,1,228,1,229,1,229,
  	1,229,1,229,1,230,1,230,1,230,3,230,2506,8,230,1,231,1,231,1,231,1,231,
  	1,231,5,231,2513,8,231,10,231,12,231,2516,9,231,1,232,1,232,1,232,1,232,
  	1,232,5,232,2523,8,232,10,232,12,232,2526,9,232,1,233,1,233,1,233,1,233,
  	1,233,5,233,2533,8,233,10,233,12,233,2536,9,233,1,234,1,234,1,234,1,234,
  	1,234,1,234,5,234,2544,8,234,10,234,12,234,2547,9,234,1,235,1,235,1,235,
  	3,235,2552,8,235,1,236,1,236,1,236,1,237,1,237,1,237,1,238,1,238,3,238,
  	2562,8,238,1,239,1,239,1,239,1,239,1,239,1,239,1,239,3,239,2571,8,239,
  	1,240,1,240,1,240,1,241,1,241,1,241,1,242,1,242,1,242,1,243,1,243,1,243,
  	1,244,1,244,1,244,1,244,1,245,1,245,1,245,1,245,1,246,1,246,1,246,1,247,
  	1,247,3,247,2598,8,247,1,248,1,248,1,248,1,249,1,249,1,249,1,249,1,249,
  	3,249,2608,8,249,1,250,1,250,1,250,1,251,1,251,1,251,1,252,1,252,1,252,
  	5,252,2619,8,252,10,252,12,252,2622,9,252,1,253,1,253,3,253,2626,8,253,
  	1,254,1,254,1,255,1,255,1,255,1,256,1,256,1,256,1,256,1,257,1,257,1,257,
  	5,257,2640,8,257,10,257,12,257,2643,9,257,1,257,3,257,2646,8,257,1,258,
  	1,258,1,259,1,259,1,259,1,260,1,260,1,260,1,260,1,261,1,261,1,261,5,261,
  	2660,8,261,10,261,12,261,2663,9,261,1,262,1,262,3,262,2667,8,262,1,262,
  	3,262,2670,8,262,1,263,1,263,1,264,1,264,1,265,1,265,1,265,1,265,3,265,
  	2680,8,265,1,266,1,266,1,266,1,267,1,267,1,267,1,268,1,268,1,269,1,269,
  	1,269,3,269,2693,8,269,1,270,1,270,1,270,1,270,3,270,2699,8,270,1,271,
  	1,271,1,271,1,272,1,272,1,272,1,272,3,272,2708,8,272,1,273,1,273,1,274,
  	1,274,3,274,2714,8,274,1,275,1,275,1,275,5,275,2719,8,275,10,275,12,275,
  	2722,9,275,1,275,1,275,3,275,2726,8,275,1,276,1,276,1,276,4,276,2731,
  	8,276,11,276,12,276,2732,1,277,1,277,1,277,1,277,1,277,1,277,3,277,2741,
  	8,277,1,278,3,278,2744,8,278,1,278,1,278,1,279,1,279,1,280,1,280,3,280,
  	2752,8,280,1,281,3,281,2755,8,281,1,281,1,281,1,282,1,282,1,282,1,282,
  	1,282,3,282,2764,8,282,1,283,1,283,3,283,2768,8,283,1,284,3,284,2771,
  	8,284,1,284,1,284,1,285,1,285,3,285,2777,8,285,1,285,1,285,1,285,5,285,
  	2782,8,285,10,285,12,285,2785,9,285,1,285,1,285,1,285,4,285,2790,8,285,
  	11,285,12,285,2791,3,285,2794,8,285,1,286,1,286,1,287,1,287,1,287,1,287,
  	1,288,1,288,1,289,1,289,1,289,5,289,2807,8,289,10,289,12,289,2810,9,289,
  	1,290,1,290,3,290,2814,8,290,1,291,1,291,3,291,2818,8,291,1,292,1,292,
  	3,292,2822,8,292,1,292,1,292,3,292,2826,8,292,1,292,1,292,3,292,2830,
  	8,292,1,292,3,292,2833,8,292,1,292,1,292,1,293,1,293,3,293,2839,8,293,
  	1,293,1,293,1,293,3,293,2844,8,293,1,294,1,294,3,294,2848,8,294,1,294,
  	3,294,2851,8,294,1,295,1,295,3,295,2855,8,295,1,295,3,295,2858,8,295,
  	1,296,1,296,1,297,1,297,1,297,1,297,1,297,3,297,2867,8,297,1,298,3,298,
  	2870,8,298,1,298,1,298,1,299,1,299,1,300,1,300,1,301,1,301,3,301,2880,
  	8,301,1,302,3,302,2883,8,302,1,302,1,302,3,302,2887,8,302,1,302,1,302,
  	3,302,2891,8,302,1,302,1,302,3,302,2895,8,302,1,303,1,303,1,303,3,303,
  	2900,8,303,1,303,1,303,1,303,1,304,1,304,3,304,2907,8,304,1,304,3,304,
  	2910,8,304,1,305,1,305,3,305,2914,8,305,1,305,3,305,2917,8,305,1,306,
  	1,306,1,306,1,306,1,306,3,306,2924,8,306,1,307,3,307,2927,8,307,1,307,
  	1,307,1,308,1,308,1,309,1,309,1,310,1,310,3,310,2937,8,310,1,311,1,311,
  	1,311,1,311,1,312,1,312,1,312,1,312,1,313,1,313,1,313,1,313,1,314,1,314,
  	1,314,1,314,1,315,1,315,1,315,1,315,1,316,1,316,1,316,1,316,1,317,1,317,
  	1,317,1,317,1,317,1,317,3,317,2969,8,317,1,317,3,317,2972,8,317,1,318,
  	1,318,1,318,1,318,1,318,1,318,3,318,2980,8,318,1,318,3,318,2983,8,318,
  	1,319,1,319,1,320,1,320,1,320,1,321,1,321,3,321,2992,8,321,1,322,1,322,
  	3,322,2996,8,322,1,323,1,323,1,323,1,323,1,323,1,323,1,324,1,324,1,324,
  	1,324,1,324,1,324,1,325,1,325,1,325,1,325,1,325,1,325,1,326,1,326,1,327,
  	1,327,1,328,1,328,1,329,1,329,1,330,1,330,1,330,1,330,1,330,1,330,1,330,
  	3,330,3031,8,330,1,331,1,331,1,331,5,331,3036,8,331,10,331,12,331,3039,
  	9,331,1,332,1,332,3,332,3043,8,332,1,332,1,332,1,333,1,333,1,333,5,333,
  	3050,8,333,10,333,12,333,3053,9,333,1,334,1,334,3,334,3057,8,334,1,334,
  	1,334,1,335,1,335,1,336,3,336,3064,8,336,1,336,1,336,1,336,1,337,1,337,
  	1,337,1,337,1,337,1,337,1,337,1,337,1,337,1,337,1,337,3,337,3080,8,337,
  	1,337,3,337,3083,8,337,1,337,1,337,1,337,1,337,1,337,3,337,3090,8,337,
  	1,337,3,337,3093,8,337,1,337,1,337,1,337,3,337,3098,8,337,1,337,3,337,
  	3101,8,337,1,337,3,337,3104,8,337,1,337,1,337,1,337,3,337,3109,8,337,
  	1,337,1,337,3,337,3113,8,337,1,337,1,337,1,337,1,337,5,337,3119,8,337,
  	10,337,12,337,3122,9,337,1,337,1,337,3,337,3126,8,337,1,337,1,337,1,337,
  	1,337,1,337,1,337,1,337,1,337,1,337,3,337,3137,8,337,1,337,3,337,3140,
  	8,337,5,337,3142,8,337,10,337,12,337,3145,9,337,1,338,1,338,1,339,1,339,
  	1,339,1,339,1,339,1,339,1,339,3,339,3156,8,339,1,340,1,340,3,340,3160,
  	8,340,1,341,1,341,1,341,1,341,1,341,3,341,3167,8,341,1,341,1,341,1,341,
  	3,341,3172,8,341,1,341,3,341,3175,8,341,1,341,1,341,1,341,1,341,1,341,
  	3,341,3182,8,341,1,341,3,341,3185,8,341,1,341,1,341,1,341,1,341,1,341,
  	3,341,3192,8,341,1,341,3,341,3195,8,341,3,341,3197,8,341,1,342,1,342,
  	1,342,1,342,1,342,3,342,3204,8,342,1,342,1,342,1,342,3,342,3209,8,342,
  	1,342,3,342,3212,8,342,1,342,1,342,1,342,1,342,1,342,3,342,3219,8,342,
  	1,342,3,342,3222,8,342,1,342,1,342,1,342,1,342,1,342,3,342,3229,8,342,
  	1,342,3,342,3232,8,342,3,342,3234,8,342,1,343,1,343,1,344,1,344,1,345,
  	1,345,1,346,1,346,3,346,3244,8,346,1,347,1,347,3,347,3248,8,347,1,348,
  	1,348,3,348,3252,8,348,1,349,1,349,3,349,3256,8,349,1,349,1,349,3,349,
  	3260,8,349,1,349,1,349,3,349,3264,8,349,1,349,1,349,3,349,3268,8,349,
  	1,349,1,349,3,349,3272,8,349,1,349,1,349,3,349,3276,8,349,1,349,1,349,
  	3,349,3280,8,349,1,349,1,349,1,349,1,349,1,349,3,349,3287,8,349,1,349,
  	3,349,3290,8,349,1,349,1,349,3,349,3294,8,349,1,349,3,349,3297,8,349,
  	1,349,3,349,3300,8,349,1,350,1,350,3,350,3304,8,350,1,350,1,350,3,350,
  	3308,8,350,1,350,1,350,3,350,3312,8,350,1,350,1,350,3,350,3316,8,350,
  	1,350,1,350,3,350,3320,8,350,1,350,1,350,3,350,3324,8,350,1,350,1,350,
  	3,350,3328,8,350,1,350,1,350,1,350,1,350,1,350,3,350,3335,8,350,1,350,
  	3,350,3338,8,350,1,350,1,350,3,350,3342,8,350,1,350,1,350,3,350,3346,
  	8,350,1,351,1,351,3,351,3350,8,351,1,351,1,351,3,351,3354,8,351,1,351,
  	1,351,3,351,3358,8,351,1,351,1,351,3,351,3362,8,351,1,351,1,351,3,351,
  	3366,8,351,1,351,1,351,3,351,3370,8,351,1,351,1,351,1,351,3,351,3375,
  	8,351,1,351,1,351,1,351,1,351,1,351,3,351,3382,8,351,1,351,3,351,3385,
  	8,351,1,351,1,351,1,351,3,351,3390,8,351,3,351,3392,8,351,1,352,1,352,
  	1,352,1,352,1,352,3,352,3399,8,352,1,352,1,352,3,352,3403,8,352,3,352,
  	3405,8,352,1,353,1,353,1,354,1,354,1,355,1,355,3,355,3413,8,355,1,355,
  	1,355,3,355,3417,8,355,1,355,1,355,3,355,3421,8,355,1,355,1,355,3,355,
  	3425,8,355,1,355,1,355,3,355,3429,8,355,1,355,1,355,1,355,1,355,1,355,
  	3,355,3436,8,355,1,355,1,355,3,355,3440,8,355,1,355,3,355,3443,8,355,
  	1,355,1,355,3,355,3447,8,355,1,355,1,355,3,355,3451,8,355,1,355,3,355,
  	3454,8,355,3,355,3456,8,355,1,356,1,356,3,356,3460,8,356,1,357,1,357,
  	1,357,1,357,1,357,3,357,3467,8,357,1,358,1,358,1,358,3,358,3472,8,358,
  	1,358,1,358,1,358,1,358,1,358,3,358,3479,8,358,3,358,3481,8,358,1,359,
  	1,359,1,359,3,359,3486,8,359,1,359,1,359,1,359,1,359,3,359,3492,8,359,
  	1,359,3,359,3495,8,359,3,359,3497,8,359,1,360,1,360,3,360,3501,8,360,
  	1,361,1,361,1,361,3,361,3506,8,361,1,361,1,361,1,361,1,361,1,361,3,361,
  	3513,8,361,3,361,3515,8,361,1,362,1,362,1,362,3,362,3520,8,362,1,362,
  	1,362,1,362,1,362,1,362,3,362,3527,8,362,3,362,3529,8,362,1,363,1,363,
  	1,363,1,363,1,363,3,363,3536,8,363,1,364,1,364,1,364,1,364,1,364,1,364,
  	3,364,3544,8,364,1,365,1,365,1,365,1,365,3,365,3550,8,365,1,366,1,366,
  	3,366,3554,8,366,1,367,1,367,1,368,1,368,1,368,3,368,3561,8,368,1,369,
  	1,369,3,369,3565,8,369,1,370,3,370,3568,8,370,1,370,1,370,1,370,3,370,
  	3573,8,370,1,371,1,371,3,371,3577,8,371,1,371,1,371,3,371,3581,8,371,
  	1,372,1,372,3,372,3585,8,372,1,373,1,373,3,373,3589,8,373,1,374,1,374,
  	3,374,3593,8,374,1,375,3,375,3596,8,375,1,375,1,375,3,375,3600,8,375,
  	1,376,1,376,3,376,3604,8,376,1,377,1,377,3,377,3608,8,377,1,378,3,378,
  	3611,8,378,1,378,1,378,3,378,3615,8,378,1,379,1,379,3,379,3619,8,379,
  	1,380,3,380,3622,8,380,1,380,1,380,1,381,1,381,1,382,3,382,3629,8,382,
  	1,382,1,382,3,382,3633,8,382,1,382,3,382,3636,8,382,1,382,1,382,3,382,
  	3640,8,382,3,382,3642,8,382,1,383,1,383,3,383,3646,8,383,1,383,1,383,
  	1,384,1,384,1,384,5,384,3653,8,384,10,384,12,384,3656,9,384,1,385,1,385,
  	1,385,1,386,1,386,3,386,3663,8,386,1,386,1,386,1,387,1,387,1,388,1,388,
  	1,388,1,388,1,388,1,388,1,388,1,388,1,388,3,388,3678,8,388,1,389,1,389,
  	1,390,1,390,1,390,1,390,1,390,1,390,1,390,1,390,1,390,1,390,1,390,1,390,
  	1,390,1,390,1,390,1,390,1,390,1,390,3,390,3700,8,390,1,391,1,391,1,391,
  	1,392,1,392,3,392,3707,8,392,1,392,1,392,1,393,1,393,1,393,1,394,1,394,
  	3,394,3716,8,394,1,394,1,394,1,394,1,395,1,395,3,395,3723,8,395,1,395,
  	3,395,3726,8,395,1,395,1,395,1,396,1,396,1,396,1,397,1,397,3,397,3735,
  	8,397,1,397,1,397,1,398,1,398,1,398,1,399,1,399,1,399,1,400,1,400,3,400,
  	3747,8,400,1,400,1,400,3,400,3751,8,400,1,401,1,401,1,401,1,401,1,401,
  	1,401,3,401,3759,8,401,1,402,1,402,1,403,1,403,3,403,3765,8,403,1,403,
  	1,403,1,403,1,403,1,404,1,404,3,404,3773,8,404,1,404,1,404,1,404,1,404,
  	1,405,1,405,1,406,1,406,1,406,1,406,1,406,1,406,1,406,5,406,3788,8,406,
  	10,406,12,406,3791,9,406,1,406,1,406,1,407,1,407,1,407,1,407,1,407,1,
  	407,1,407,5,407,3802,8,407,10,407,12,407,3805,9,407,1,407,1,407,1,408,
  	1,408,1,408,1,408,1,408,1,408,1,408,1,409,1,409,1,409,1,409,1,409,1,409,
  	1,409,3,409,3823,8,409,1,409,1,409,1,409,3,409,3828,8,409,1,409,1,409,
  	1,409,1,409,3,409,3834,8,409,1,409,1,409,1,409,1,409,1,409,1,409,1,409,
  	1,409,1,409,1,409,1,409,1,409,1,409,1,409,1,409,1,409,1,409,1,409,1,409,
  	1,409,1,409,1,409,1,409,1,409,3,409,3860,8,409,1,409,5,409,3863,8,409,
  	10,409,12,409,3866,9,409,1,410,1,410,1,410,1,410,1,410,1,410,3,410,3874,
  	8,410,1,411,1,411,1,412,1,412,1,412,1,412,1,412,3,412,3883,8,412,1,413,
  	1,413,1,413,1,413,1,413,1,413,1,413,1,414,1,414,1,414,1,414,1,414,1,415,
  	1,415,1,415,1,415,1,415,1,416,1,416,1,416,1,416,1,416,3,416,3907,8,416,
  	1,416,1,416,1,417,1,417,1,417,1,417,1,417,3,417,3916,8,417,1,417,1,417,
  	1,418,1,418,1,419,1,419,1,420,1,420,1,421,1,421,1,421,1,421,1,421,1,421,
  	1,421,1,421,1,421,1,421,1,421,3,421,3937,8,421,1,421,1,421,1,421,5,421,
  	3942,8,421,10,421,12,421,3945,9,421,1,422,1,422,1,422,1,422,1,423,1,423,
  	3,423,3953,8,423,1,424,1,424,1,424,1,424,1,424,1,424,1,424,1,424,1,424,
  	1,424,1,424,1,424,3,424,3967,8,424,1,425,1,425,3,425,3971,8,425,1,426,
  	1,426,3,426,3975,8,426,1,427,1,427,3,427,3979,8,427,1,428,1,428,1,429,
  	1,429,1,429,1,429,1,429,1,429,1,430,1,430,1,430,1,431,1,431,3,431,3994,
  	8,431,1,432,1,432,1,432,1,432,1,432,1,432,1,432,1,432,1,432,1,432,1,432,
  	1,432,4,432,4008,8,432,11,432,12,432,4009,1,432,1,432,3,432,4014,8,432,
  	1,433,1,433,3,433,4018,8,433,1,434,1,434,1,434,4,434,4023,8,434,11,434,
  	12,434,4024,1,434,3,434,4028,8,434,1,434,1,434,1,435,1,435,4,435,4034,
  	8,435,11,435,12,435,4035,1,435,3,435,4039,8,435,1,435,1,435,1,436,1,436,
  	1,436,1,436,1,436,1,437,1,437,1,437,1,437,1,437,1,438,1,438,1,438,1,439,
  	1,439,3,439,4058,8,439,1,440,1,440,1,440,5,440,4063,8,440,10,440,12,440,
  	4066,9,440,1,441,1,441,1,441,1,441,1,441,1,441,1,441,1,441,1,441,1,441,
  	1,441,3,441,4079,8,441,1,442,1,442,3,442,4083,8,442,1,443,1,443,1,444,
  	1,444,1,444,1,444,1,444,1,444,1,444,1,445,1,445,3,445,4096,8,445,1,446,
  	1,446,1,447,1,447,1,447,1,447,1,447,1,447,3,447,4106,8,447,1,448,1,448,
  	1,448,3,448,4111,8,448,1,448,1,448,1,448,1,449,1,449,1,449,1,449,1,449,
  	1,449,1,449,1,450,1,450,1,451,1,451,1,452,1,452,1,453,3,453,4130,8,453,
  	1,453,1,453,1,454,1,454,1,455,1,455,1,455,1,455,1,455,1,456,1,456,1,457,
  	1,457,1,458,1,458,1,459,1,459,1,459,1,459,1,459,1,460,1,460,5,460,4154,
  	8,460,10,460,12,460,4157,9,460,1,461,1,461,1,462,1,462,1,462,1,462,1,
  	462,1,463,1,463,1,464,1,464,3,464,4170,8,464,1,465,1,465,1,465,1,465,
  	1,465,1,465,1,465,1,466,1,466,1,466,1,466,1,466,1,467,1,467,1,468,3,468,
  	4187,8,468,1,468,1,468,3,468,4191,8,468,1,468,1,468,1,469,1,469,1,469,
  	5,469,4198,8,469,10,469,12,469,4201,9,469,1,470,1,470,1,471,3,471,4206,
  	8,471,1,471,1,471,1,472,1,472,3,472,4212,8,472,1,472,1,472,1,473,1,473,
  	1,473,5,473,4219,8,473,10,473,12,473,4222,9,473,1,474,1,474,1,474,1,474,
  	1,475,1,475,1,476,1,476,1,476,1,476,1,476,3,476,4235,8,476,1,476,1,476,
  	1,476,1,476,1,476,1,476,5,476,4243,8,476,10,476,12,476,4246,9,476,1,477,
  	1,477,1,477,1,477,1,477,1,477,1,477,1,477,1,477,1,477,1,477,1,477,1,477,
  	3,477,4261,8,477,1,478,1,478,1,478,3,478,4266,8,478,1,479,1,479,1,479,
  	1,479,1,479,1,479,1,479,1,479,1,479,1,479,3,479,4278,8,479,1,480,1,480,
  	1,481,1,481,1,481,1,481,1,481,1,482,1,482,1,482,1,482,1,482,1,483,1,483,
  	1,483,1,483,1,483,1,484,1,484,1,484,1,484,1,484,1,485,1,485,1,485,1,485,
  	1,485,1,485,1,485,1,486,1,486,1,487,1,487,1,488,1,488,1,488,1,488,1,488,
  	1,489,1,489,1,490,1,490,1,490,1,490,1,490,1,490,1,490,1,491,1,491,1,492,
  	1,492,1,493,1,493,1,493,1,493,1,493,1,494,1,494,1,494,1,494,1,494,1,495,
  	1,495,1,495,1,495,1,495,1,496,1,496,1,496,1,496,1,496,1,496,1,496,1,497,
  	1,497,1,498,1,498,1,499,1,499,1,499,1,499,1,499,1,500,1,500,1,500,1,500,
  	1,500,1,501,1,501,1,501,1,501,1,501,1,502,1,502,1,503,1,503,1,504,3,504,
  	4377,8,504,1,504,3,504,4380,8,504,1,504,3,504,4383,8,504,1,504,1,504,
  	1,505,1,505,1,506,1,506,1,507,1,507,1,508,1,508,1,509,1,509,1,510,1,510,
  	1,511,1,511,1,511,1,511,1,511,3,511,4404,8,511,1,512,1,512,1,512,1,512,
  	3,512,4410,8,512,1,512,3,512,4413,8,512,1,513,1,513,1,513,1,513,3,513,
  	4419,8,513,1,513,3,513,4422,8,513,1,514,1,514,1,514,3,514,4427,8,514,
  	1,514,3,514,4430,8,514,1,515,1,515,1,515,1,515,3,515,4436,8,515,1,515,
  	3,515,4439,8,515,1,516,1,516,1,516,1,516,3,516,4445,8,516,1,516,3,516,
  	4448,8,516,1,517,1,517,3,517,4452,8,517,1,518,1,518,3,518,4456,8,518,
  	1,519,1,519,3,519,4460,8,519,1,520,1,520,1,521,1,521,1,521,1,521,1,521,
  	3,521,4469,8,521,1,522,1,522,1,522,1,522,1,523,1,523,1,524,1,524,1,525,
  	1,525,3,525,4481,8,525,1,526,1,526,1,526,1,526,1,526,1,527,1,527,3,527,
  	4490,8,527,1,528,1,528,1,529,1,529,1,530,1,530,1,531,1,531,1,532,1,532,
  	3,532,4502,8,532,1,533,1,533,1,534,1,534,1,535,1,535,1,536,1,536,1,537,
  	1,537,3,537,4514,8,537,1,538,1,538,1,539,1,539,1,540,1,540,1,541,1,541,
  	1,542,1,542,1,543,1,543,1,544,1,544,1,545,1,545,1,546,1,546,1,547,1,547,
  	3,547,4536,8,547,1,548,1,548,1,548,1,548,1,548,1,548,1,548,1,548,3,548,
  	4546,8,548,1,549,1,549,1,549,3,549,4551,8,549,1,550,1,550,1,550,1,551,
  	1,551,1,551,1,552,1,552,1,552,1,553,1,553,1,554,1,554,1,555,1,555,1,555,
  	3,555,4569,8,555,1,556,1,556,3,556,4573,8,556,1,557,1,557,1,558,1,558,
  	1,559,1,559,3,559,4581,8,559,1,560,1,560,1,560,1,560,1,560,3,560,4588,
  	8,560,1,561,1,561,1,562,1,562,1,563,1,563,1,564,1,564,1,565,1,565,1,566,
  	1,566,1,567,1,567,1,568,1,568,1,568,1,569,1,569,1,570,1,570,1,571,1,571,
  	1,572,1,572,1,573,1,573,1,573,0,8,184,428,466,468,674,818,842,952,574,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,
  	50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,
  	96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,
  	132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,
  	168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,
  	204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,
  	240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,
  	276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,
  	312,314,316,318,320,322,324,326,328,330,332,334,336,338,340,342,344,346,
  	348,350,352,354,356,358,360,362,364,366,368,370,372,374,376,378,380,382,
  	384,386,388,390,392,394,396,398,400,402,404,406,408,410,412,414,416,418,
  	420,422,424,426,428,430,432,434,436,438,440,442,444,446,448,450,452,454,
  	456,458,460,462,464,466,468,470,472,474,476,478,480,482,484,486,488,490,
  	492,494,496,498,500,502,504,506,508,510,512,514,516,518,520,522,524,526,
  	528,530,532,534,536,538,540,542,544,546,548,550,552,554,556,558,560,562,
  	564,566,568,570,572,574,576,578,580,582,584,586,588,590,592,594,596,598,
  	600,602,604,606,608,610,612,614,616,618,620,622,624,626,628,630,632,634,
  	636,638,640,642,644,646,648,650,652,654,656,658,660,662,664,666,668,670,
  	672,674,676,678,680,682,684,686,688,690,692,694,696,698,700,702,704,706,
  	708,710,712,714,716,718,720,722,724,726,728,730,732,734,736,738,740,742,
  	744,746,748,750,752,754,756,758,760,762,764,766,768,770,772,774,776,778,
  	780,782,784,786,788,790,792,794,796,798,800,802,804,806,808,810,812,814,
  	816,818,820,822,824,826,828,830,832,834,836,838,840,842,844,846,848,850,
  	852,854,856,858,860,862,864,866,868,870,872,874,876,878,880,882,884,886,
  	888,890,892,894,896,898,900,902,904,906,908,910,912,914,916,918,920,922,
  	924,926,928,930,932,934,936,938,940,942,944,946,948,950,952,954,956,958,
  	960,962,964,966,968,970,972,974,976,978,980,982,984,986,988,990,992,994,
  	996,998,1000,1002,1004,1006,1008,1010,1012,1014,1016,1018,1020,1022,1024,
  	1026,1028,1030,1032,1034,1036,1038,1040,1042,1044,1046,1048,1050,1052,
  	1054,1056,1058,1060,1062,1064,1066,1068,1070,1072,1074,1076,1078,1080,
  	1082,1084,1086,1088,1090,1092,1094,1096,1098,1100,1102,1104,1106,1108,
  	1110,1112,1114,1116,1118,1120,1122,1124,1126,1128,1130,1132,1134,1136,
  	1138,1140,1142,1144,1146,0,45,2,0,53,53,165,165,1,0,65,66,2,0,79,79,150,
  	150,2,0,159,159,304,304,4,0,277,277,311,311,316,316,321,321,2,0,166,166,
  	168,168,2,0,102,102,290,290,2,0,127,127,360,360,6,0,336,337,340,340,347,
  	347,356,356,373,373,384,384,2,0,28,29,77,78,2,0,159,159,195,195,3,0,67,
  	67,106,106,375,375,1,0,104,105,2,0,283,283,319,319,2,0,315,315,347,347,
  	2,0,315,315,384,384,2,0,211,211,332,332,1,0,37,38,1,0,73,74,2,0,26,26,
  	133,133,6,0,335,335,343,343,346,346,365,365,367,367,372,372,2,0,373,373,
  	376,376,2,0,359,359,383,383,2,0,161,161,232,232,2,0,129,129,181,181,2,
  	0,141,141,222,222,3,0,40,40,142,142,183,183,6,0,33,33,56,56,62,62,144,
  	145,200,201,203,203,2,0,22,22,80,80,1,0,169,170,1,0,51,52,2,0,42,42,157,
  	157,8,0,21,21,30,30,32,32,59,61,75,75,174,174,192,193,204,205,1,0,48,
  	49,3,0,39,39,128,128,209,209,1,0,296,299,1,0,4,5,2,0,71,71,208,208,1,
  	0,3,4,3,0,9,10,13,13,15,15,1,0,16,19,2,0,301,301,320,320,2,0,285,285,
  	308,308,2,0,284,284,307,307,1,0,277,324,4744,0,1157,1,0,0,0,2,1161,1,
  	0,0,0,4,1179,1,0,0,0,6,1193,1,0,0,0,8,1197,1,0,0,0,10,1199,1,0,0,0,12,
  	1207,1,0,0,0,14,1211,1,0,0,0,16,1216,1,0,0,0,18,1220,1,0,0,0,20,1225,
  	1,0,0,0,22,1228,1,0,0,0,24,1235,1,0,0,0,26,1241,1,0,0,0,28,1248,1,0,0,
  	0,30,1252,1,0,0,0,32,1272,1,0,0,0,34,1274,1,0,0,0,36,1277,1,0,0,0,38,
  	1279,1,0,0,0,40,1284,1,0,0,0,42,1292,1,0,0,0,44,1298,1,0,0,0,46,1300,
  	1,0,0,0,48,1302,1,0,0,0,50,1304,1,0,0,0,52,1308,1,0,0,0,54,1310,1,0,0,
  	0,56,1314,1,0,0,0,58,1319,1,0,0,0,60,1327,1,0,0,0,62,1334,1,0,0,0,64,
  	1336,1,0,0,0,66,1346,1,0,0,0,68,1348,1,0,0,0,70,1355,1,0,0,0,72,1365,
  	1,0,0,0,74,1369,1,0,0,0,76,1373,1,0,0,0,78,1383,1,0,0,0,80,1387,1,0,0,
  	0,82,1390,1,0,0,0,84,1398,1,0,0,0,86,1402,1,0,0,0,88,1409,1,0,0,0,90,
  	1411,1,0,0,0,92,1417,1,0,0,0,94,1419,1,0,0,0,96,1425,1,0,0,0,98,1428,
  	1,0,0,0,100,1434,1,0,0,0,102,1442,1,0,0,0,104,1444,1,0,0,0,106,1453,1,
  	0,0,0,108,1461,1,0,0,0,110,1488,1,0,0,0,112,1512,1,0,0,0,114,1514,1,0,
  	0,0,116,1517,1,0,0,0,118,1522,1,0,0,0,120,1533,1,0,0,0,122,1565,1,0,0,
  	0,124,1567,1,0,0,0,126,1571,1,0,0,0,128,1583,1,0,0,0,130,1587,1,0,0,0,
  	132,1591,1,0,0,0,134,1593,1,0,0,0,136,1598,1,0,0,0,138,1603,1,0,0,0,140,
  	1605,1,0,0,0,142,1610,1,0,0,0,144,1616,1,0,0,0,146,1620,1,0,0,0,148,1626,
  	1,0,0,0,150,1628,1,0,0,0,152,1631,1,0,0,0,154,1634,1,0,0,0,156,1645,1,
  	0,0,0,158,1647,1,0,0,0,160,1653,1,0,0,0,162,1661,1,0,0,0,164,1665,1,0,
  	0,0,166,1668,1,0,0,0,168,1678,1,0,0,0,170,1680,1,0,0,0,172,1684,1,0,0,
  	0,174,1689,1,0,0,0,176,1694,1,0,0,0,178,1702,1,0,0,0,180,1704,1,0,0,0,
  	182,1706,1,0,0,0,184,1708,1,0,0,0,186,1722,1,0,0,0,188,1736,1,0,0,0,190,
  	1738,1,0,0,0,192,1742,1,0,0,0,194,1754,1,0,0,0,196,1756,1,0,0,0,198,1759,
  	1,0,0,0,200,1763,1,0,0,0,202,1766,1,0,0,0,204,1774,1,0,0,0,206,1777,1,
  	0,0,0,208,1783,1,0,0,0,210,1790,1,0,0,0,212,1794,1,0,0,0,214,1796,1,0,
  	0,0,216,1799,1,0,0,0,218,1811,1,0,0,0,220,1814,1,0,0,0,222,1818,1,0,0,
  	0,224,1820,1,0,0,0,226,1825,1,0,0,0,228,1828,1,0,0,0,230,1841,1,0,0,0,
  	232,1843,1,0,0,0,234,1848,1,0,0,0,236,1851,1,0,0,0,238,1854,1,0,0,0,240,
  	1856,1,0,0,0,242,1872,1,0,0,0,244,1879,1,0,0,0,246,1881,1,0,0,0,248,1896,
  	1,0,0,0,250,1898,1,0,0,0,252,1906,1,0,0,0,254,1910,1,0,0,0,256,1913,1,
  	0,0,0,258,1942,1,0,0,0,260,1950,1,0,0,0,262,1954,1,0,0,0,264,1957,1,0,
  	0,0,266,1960,1,0,0,0,268,1965,1,0,0,0,270,1973,1,0,0,0,272,1980,1,0,0,
  	0,274,1983,1,0,0,0,276,1990,1,0,0,0,278,1993,1,0,0,0,280,1997,1,0,0,0,
  	282,2003,1,0,0,0,284,2011,1,0,0,0,286,2020,1,0,0,0,288,2028,1,0,0,0,290,
  	2030,1,0,0,0,292,2033,1,0,0,0,294,2036,1,0,0,0,296,2040,1,0,0,0,298,2053,
  	1,0,0,0,300,2055,1,0,0,0,302,2058,1,0,0,0,304,2069,1,0,0,0,306,2071,1,
  	0,0,0,308,2074,1,0,0,0,310,2082,1,0,0,0,312,2089,1,0,0,0,314,2091,1,0,
  	0,0,316,2100,1,0,0,0,318,2107,1,0,0,0,320,2110,1,0,0,0,322,2113,1,0,0,
  	0,324,2116,1,0,0,0,326,2118,1,0,0,0,328,2126,1,0,0,0,330,2135,1,0,0,0,
  	332,2144,1,0,0,0,334,2146,1,0,0,0,336,2152,1,0,0,0,338,2158,1,0,0,0,340,
  	2172,1,0,0,0,342,2185,1,0,0,0,344,2189,1,0,0,0,346,2191,1,0,0,0,348,2195,
  	1,0,0,0,350,2200,1,0,0,0,352,2202,1,0,0,0,354,2209,1,0,0,0,356,2211,1,
  	0,0,0,358,2221,1,0,0,0,360,2227,1,0,0,0,362,2229,1,0,0,0,364,2237,1,0,
  	0,0,366,2245,1,0,0,0,368,2253,1,0,0,0,370,2265,1,0,0,0,372,2282,1,0,0,
  	0,374,2285,1,0,0,0,376,2296,1,0,0,0,378,2301,1,0,0,0,380,2305,1,0,0,0,
  	382,2307,1,0,0,0,384,2312,1,0,0,0,386,2321,1,0,0,0,388,2325,1,0,0,0,390,
  	2328,1,0,0,0,392,2332,1,0,0,0,394,2334,1,0,0,0,396,2337,1,0,0,0,398,2341,
  	1,0,0,0,400,2349,1,0,0,0,402,2355,1,0,0,0,404,2364,1,0,0,0,406,2366,1,
  	0,0,0,408,2370,1,0,0,0,410,2374,1,0,0,0,412,2378,1,0,0,0,414,2382,1,0,
  	0,0,416,2386,1,0,0,0,418,2390,1,0,0,0,420,2394,1,0,0,0,422,2396,1,0,0,
  	0,424,2409,1,0,0,0,426,2412,1,0,0,0,428,2424,1,0,0,0,430,2437,1,0,0,0,
  	432,2439,1,0,0,0,434,2445,1,0,0,0,436,2447,1,0,0,0,438,2451,1,0,0,0,440,
  	2461,1,0,0,0,442,2463,1,0,0,0,444,2472,1,0,0,0,446,2474,1,0,0,0,448,2478,
  	1,0,0,0,450,2482,1,0,0,0,452,2486,1,0,0,0,454,2490,1,0,0,0,456,2494,1,
  	0,0,0,458,2498,1,0,0,0,460,2505,1,0,0,0,462,2507,1,0,0,0,464,2517,1,0,
  	0,0,466,2527,1,0,0,0,468,2537,1,0,0,0,470,2551,1,0,0,0,472,2553,1,0,0,
  	0,474,2556,1,0,0,0,476,2561,1,0,0,0,478,2570,1,0,0,0,480,2572,1,0,0,0,
  	482,2575,1,0,0,0,484,2578,1,0,0,0,486,2581,1,0,0,0,488,2584,1,0,0,0,490,
  	2588,1,0,0,0,492,2592,1,0,0,0,494,2597,1,0,0,0,496,2599,1,0,0,0,498,2607,
  	1,0,0,0,500,2609,1,0,0,0,502,2612,1,0,0,0,504,2615,1,0,0,0,506,2623,1,
  	0,0,0,508,2627,1,0,0,0,510,2629,1,0,0,0,512,2632,1,0,0,0,514,2645,1,0,
  	0,0,516,2647,1,0,0,0,518,2649,1,0,0,0,520,2652,1,0,0,0,522,2656,1,0,0,
  	0,524,2664,1,0,0,0,526,2671,1,0,0,0,528,2673,1,0,0,0,530,2679,1,0,0,0,
  	532,2681,1,0,0,0,534,2684,1,0,0,0,536,2687,1,0,0,0,538,2692,1,0,0,0,540,
  	2698,1,0,0,0,542,2700,1,0,0,0,544,2707,1,0,0,0,546,2709,1,0,0,0,548,2711,
  	1,0,0,0,550,2715,1,0,0,0,552,2730,1,0,0,0,554,2740,1,0,0,0,556,2743,1,
  	0,0,0,558,2747,1,0,0,0,560,2751,1,0,0,0,562,2754,1,0,0,0,564,2763,1,0,
  	0,0,566,2767,1,0,0,0,568,2770,1,0,0,0,570,2793,1,0,0,0,572,2795,1,0,0,
  	0,574,2797,1,0,0,0,576,2801,1,0,0,0,578,2803,1,0,0,0,580,2813,1,0,0,0,
  	582,2817,1,0,0,0,584,2825,1,0,0,0,586,2836,1,0,0,0,588,2850,1,0,0,0,590,
  	2857,1,0,0,0,592,2859,1,0,0,0,594,2866,1,0,0,0,596,2869,1,0,0,0,598,2873,
  	1,0,0,0,600,2875,1,0,0,0,602,2879,1,0,0,0,604,2890,1,0,0,0,606,2896,1,
  	0,0,0,608,2909,1,0,0,0,610,2916,1,0,0,0,612,2923,1,0,0,0,614,2926,1,0,
  	0,0,616,2930,1,0,0,0,618,2932,1,0,0,0,620,2936,1,0,0,0,622,2938,1,0,0,
  	0,624,2942,1,0,0,0,626,2946,1,0,0,0,628,2950,1,0,0,0,630,2954,1,0,0,0,
  	632,2958,1,0,0,0,634,2971,1,0,0,0,636,2982,1,0,0,0,638,2984,1,0,0,0,640,
  	2986,1,0,0,0,642,2991,1,0,0,0,644,2995,1,0,0,0,646,2997,1,0,0,0,648,3003,
  	1,0,0,0,650,3009,1,0,0,0,652,3015,1,0,0,0,654,3017,1,0,0,0,656,3019,1,
  	0,0,0,658,3021,1,0,0,0,660,3030,1,0,0,0,662,3032,1,0,0,0,664,3040,1,0,
  	0,0,666,3046,1,0,0,0,668,3054,1,0,0,0,670,3060,1,0,0,0,672,3063,1,0,0,
  	0,674,3125,1,0,0,0,676,3146,1,0,0,0,678,3155,1,0,0,0,680,3157,1,0,0,0,
  	682,3196,1,0,0,0,684,3233,1,0,0,0,686,3235,1,0,0,0,688,3237,1,0,0,0,690,
  	3239,1,0,0,0,692,3243,1,0,0,0,694,3247,1,0,0,0,696,3251,1,0,0,0,698,3299,
  	1,0,0,0,700,3345,1,0,0,0,702,3391,1,0,0,0,704,3393,1,0,0,0,706,3406,1,
  	0,0,0,708,3408,1,0,0,0,710,3455,1,0,0,0,712,3459,1,0,0,0,714,3466,1,0,
  	0,0,716,3480,1,0,0,0,718,3496,1,0,0,0,720,3498,1,0,0,0,722,3514,1,0,0,
  	0,724,3528,1,0,0,0,726,3530,1,0,0,0,728,3543,1,0,0,0,730,3549,1,0,0,0,
  	732,3553,1,0,0,0,734,3555,1,0,0,0,736,3560,1,0,0,0,738,3564,1,0,0,0,740,
  	3567,1,0,0,0,742,3574,1,0,0,0,744,3582,1,0,0,0,746,3588,1,0,0,0,748,3590,
  	1,0,0,0,750,3595,1,0,0,0,752,3603,1,0,0,0,754,3605,1,0,0,0,756,3610,1,
  	0,0,0,758,3616,1,0,0,0,760,3621,1,0,0,0,762,3625,1,0,0,0,764,3641,1,0,
  	0,0,766,3643,1,0,0,0,768,3649,1,0,0,0,770,3657,1,0,0,0,772,3660,1,0,0,
  	0,774,3666,1,0,0,0,776,3677,1,0,0,0,778,3679,1,0,0,0,780,3681,1,0,0,0,
  	782,3701,1,0,0,0,784,3704,1,0,0,0,786,3710,1,0,0,0,788,3713,1,0,0,0,790,
  	3720,1,0,0,0,792,3729,1,0,0,0,794,3732,1,0,0,0,796,3738,1,0,0,0,798,3741,
  	1,0,0,0,800,3750,1,0,0,0,802,3758,1,0,0,0,804,3760,1,0,0,0,806,3762,1,
  	0,0,0,808,3770,1,0,0,0,810,3778,1,0,0,0,812,3780,1,0,0,0,814,3794,1,0,
  	0,0,816,3808,1,0,0,0,818,3833,1,0,0,0,820,3873,1,0,0,0,822,3875,1,0,0,
  	0,824,3882,1,0,0,0,826,3884,1,0,0,0,828,3891,1,0,0,0,830,3896,1,0,0,0,
  	832,3901,1,0,0,0,834,3910,1,0,0,0,836,3919,1,0,0,0,838,3921,1,0,0,0,840,
  	3923,1,0,0,0,842,3936,1,0,0,0,844,3946,1,0,0,0,846,3952,1,0,0,0,848,3966,
  	1,0,0,0,850,3970,1,0,0,0,852,3974,1,0,0,0,854,3978,1,0,0,0,856,3980,1,
  	0,0,0,858,3982,1,0,0,0,860,3988,1,0,0,0,862,3993,1,0,0,0,864,4013,1,0,
  	0,0,866,4017,1,0,0,0,868,4019,1,0,0,0,870,4031,1,0,0,0,872,4042,1,0,0,
  	0,874,4047,1,0,0,0,876,4052,1,0,0,0,878,4057,1,0,0,0,880,4059,1,0,0,0,
  	882,4078,1,0,0,0,884,4082,1,0,0,0,886,4084,1,0,0,0,888,4086,1,0,0,0,890,
  	4095,1,0,0,0,892,4097,1,0,0,0,894,4105,1,0,0,0,896,4107,1,0,0,0,898,4115,
  	1,0,0,0,900,4122,1,0,0,0,902,4124,1,0,0,0,904,4126,1,0,0,0,906,4129,1,
  	0,0,0,908,4133,1,0,0,0,910,4135,1,0,0,0,912,4140,1,0,0,0,914,4142,1,0,
  	0,0,916,4144,1,0,0,0,918,4146,1,0,0,0,920,4151,1,0,0,0,922,4158,1,0,0,
  	0,924,4160,1,0,0,0,926,4165,1,0,0,0,928,4169,1,0,0,0,930,4171,1,0,0,0,
  	932,4178,1,0,0,0,934,4183,1,0,0,0,936,4186,1,0,0,0,938,4194,1,0,0,0,940,
  	4202,1,0,0,0,942,4205,1,0,0,0,944,4209,1,0,0,0,946,4215,1,0,0,0,948,4223,
  	1,0,0,0,950,4227,1,0,0,0,952,4234,1,0,0,0,954,4260,1,0,0,0,956,4265,1,
  	0,0,0,958,4277,1,0,0,0,960,4279,1,0,0,0,962,4281,1,0,0,0,964,4286,1,0,
  	0,0,966,4291,1,0,0,0,968,4296,1,0,0,0,970,4301,1,0,0,0,972,4308,1,0,0,
  	0,974,4310,1,0,0,0,976,4312,1,0,0,0,978,4317,1,0,0,0,980,4319,1,0,0,0,
  	982,4326,1,0,0,0,984,4328,1,0,0,0,986,4330,1,0,0,0,988,4335,1,0,0,0,990,
  	4340,1,0,0,0,992,4345,1,0,0,0,994,4352,1,0,0,0,996,4354,1,0,0,0,998,4356,
  	1,0,0,0,1000,4361,1,0,0,0,1002,4366,1,0,0,0,1004,4371,1,0,0,0,1006,4373,
  	1,0,0,0,1008,4382,1,0,0,0,1010,4386,1,0,0,0,1012,4388,1,0,0,0,1014,4390,
  	1,0,0,0,1016,4392,1,0,0,0,1018,4394,1,0,0,0,1020,4396,1,0,0,0,1022,4403,
  	1,0,0,0,1024,4412,1,0,0,0,1026,4421,1,0,0,0,1028,4423,1,0,0,0,1030,4438,
  	1,0,0,0,1032,4447,1,0,0,0,1034,4451,1,0,0,0,1036,4455,1,0,0,0,1038,4459,
  	1,0,0,0,1040,4461,1,0,0,0,1042,4463,1,0,0,0,1044,4470,1,0,0,0,1046,4474,
  	1,0,0,0,1048,4476,1,0,0,0,1050,4480,1,0,0,0,1052,4482,1,0,0,0,1054,4489,
  	1,0,0,0,1056,4491,1,0,0,0,1058,4493,1,0,0,0,1060,4495,1,0,0,0,1062,4497,
  	1,0,0,0,1064,4501,1,0,0,0,1066,4503,1,0,0,0,1068,4505,1,0,0,0,1070,4507,
  	1,0,0,0,1072,4509,1,0,0,0,1074,4513,1,0,0,0,1076,4515,1,0,0,0,1078,4517,
  	1,0,0,0,1080,4519,1,0,0,0,1082,4521,1,0,0,0,1084,4523,1,0,0,0,1086,4525,
  	1,0,0,0,1088,4527,1,0,0,0,1090,4529,1,0,0,0,1092,4531,1,0,0,0,1094,4535,
  	1,0,0,0,1096,4545,1,0,0,0,1098,4550,1,0,0,0,1100,4552,1,0,0,0,1102,4555,
  	1,0,0,0,1104,4558,1,0,0,0,1106,4561,1,0,0,0,1108,4563,1,0,0,0,1110,4568,
  	1,0,0,0,1112,4572,1,0,0,0,1114,4574,1,0,0,0,1116,4576,1,0,0,0,1118,4580,
  	1,0,0,0,1120,4587,1,0,0,0,1122,4589,1,0,0,0,1124,4591,1,0,0,0,1126,4593,
  	1,0,0,0,1128,4595,1,0,0,0,1130,4597,1,0,0,0,1132,4599,1,0,0,0,1134,4601,
  	1,0,0,0,1136,4603,1,0,0,0,1138,4606,1,0,0,0,1140,4608,1,0,0,0,1142,4610,
  	1,0,0,0,1144,4612,1,0,0,0,1146,4614,1,0,0,0,1148,1150,3,2,1,0,1149,1151,
  	3,34,17,0,1150,1149,1,0,0,0,1150,1151,1,0,0,0,1151,1152,1,0,0,0,1152,
  	1153,5,0,0,1,1153,1158,1,0,0,0,1154,1155,3,34,17,0,1155,1156,5,0,0,1,
  	1156,1158,1,0,0,0,1157,1148,1,0,0,0,1157,1154,1,0,0,0,1158,1,1,0,0,0,
  	1159,1162,3,4,2,0,1160,1162,3,6,3,0,1161,1159,1,0,0,0,1161,1160,1,0,0,
  	0,1162,3,1,0,0,0,1163,1165,3,30,15,0,1164,1163,1,0,0,0,1165,1166,1,0,
  	0,0,1166,1164,1,0,0,0,1166,1167,1,0,0,0,1167,1180,1,0,0,0,1168,1170,3,
  	10,5,0,1169,1168,1,0,0,0,1170,1171,1,0,0,0,1171,1169,1,0,0,0,1171,1172,
  	1,0,0,0,1172,1176,1,0,0,0,1173,1175,3,30,15,0,1174,1173,1,0,0,0,1175,
  	1178,1,0,0,0,1176,1174,1,0,0,0,1176,1177,1,0,0,0,1177,1180,1,0,0,0,1178,
  	1176,1,0,0,0,1179,1164,1,0,0,0,1179,1169,1,0,0,0,1180,5,1,0,0,0,1181,
  	1186,3,38,19,0,1182,1184,3,52,26,0,1183,1185,3,8,4,0,1184,1183,1,0,0,
  	0,1184,1185,1,0,0,0,1185,1187,1,0,0,0,1186,1182,1,0,0,0,1186,1187,1,0,
  	0,0,1187,1194,1,0,0,0,1188,1190,3,52,26,0,1189,1191,3,8,4,0,1190,1189,
  	1,0,0,0,1190,1191,1,0,0,0,1191,1194,1,0,0,0,1192,1194,3,8,4,0,1193,1181,
  	1,0,0,0,1193,1188,1,0,0,0,1193,1192,1,0,0,0,1194,7,1,0,0,0,1195,1198,
  	3,46,23,0,1196,1198,3,48,24,0,1197,1195,1,0,0,0,1197,1196,1,0,0,0,1198,
  	9,1,0,0,0,1199,1200,5,188,0,0,1200,1205,5,190,0,0,1201,1206,3,12,6,0,
  	1202,1206,3,14,7,0,1203,1206,3,16,8,0,1204,1206,3,20,10,0,1205,1201,1,
  	0,0,0,1205,1202,1,0,0,0,1205,1203,1,0,0,0,1205,1204,1,0,0,0,1206,11,1,
  	0,0,0,1207,1208,5,185,0,0,1208,1209,3,538,269,0,1209,13,1,0,0,0,1210,
  	1212,5,305,0,0,1211,1210,1,0,0,0,1211,1212,1,0,0,0,1212,1213,1,0,0,0,
  	1213,1214,5,289,0,0,1214,1215,3,88,44,0,1215,15,1,0,0,0,1216,1217,5,207,
  	0,0,1217,1218,5,324,0,0,1218,1219,3,18,9,0,1219,17,1,0,0,0,1220,1221,
  	3,1114,557,0,1221,19,1,0,0,0,1222,1226,3,22,11,0,1223,1226,3,24,12,0,
  	1224,1226,3,26,13,0,1225,1222,1,0,0,0,1225,1223,1,0,0,0,1225,1224,1,0,
  	0,0,1226,21,1,0,0,0,1227,1229,5,305,0,0,1228,1227,1,0,0,0,1228,1229,1,
  	0,0,0,1229,1230,1,0,0,0,1230,1231,5,289,0,0,1231,1232,3,28,14,0,1232,
  	1233,3,72,36,0,1233,23,1,0,0,0,1234,1236,5,278,0,0,1235,1234,1,0,0,0,
  	1235,1236,1,0,0,0,1236,1237,1,0,0,0,1237,1238,5,313,0,0,1238,1239,3,28,
  	14,0,1239,1240,3,78,39,0,1240,25,1,0,0,0,1241,1242,5,225,0,0,1242,1243,
  	3,28,14,0,1243,1244,3,84,42,0,1244,27,1,0,0,0,1245,1246,5,108,0,0,1246,
  	1247,5,152,0,0,1247,1249,5,89,0,0,1248,1245,1,0,0,0,1248,1249,1,0,0,0,
  	1249,1250,1,0,0,0,1250,1251,3,36,18,0,1251,29,1,0,0,0,1252,1253,5,188,
  	0,0,1253,1255,5,179,0,0,1254,1256,3,32,16,0,1255,1254,1,0,0,0,1255,1256,
  	1,0,0,0,1256,31,1,0,0,0,1257,1259,5,22,0,0,1258,1257,1,0,0,0,1258,1259,
  	1,0,0,0,1259,1260,1,0,0,0,1260,1273,7,0,0,0,1261,1273,5,185,0,0,1262,
  	1264,5,305,0,0,1263,1262,1,0,0,0,1263,1264,1,0,0,0,1264,1265,1,0,0,0,
  	1265,1273,5,289,0,0,1266,1267,5,207,0,0,1267,1273,5,324,0,0,1268,1270,
  	5,164,0,0,1269,1268,1,0,0,0,1269,1270,1,0,0,0,1270,1271,1,0,0,0,1271,
  	1273,3,36,18,0,1272,1258,1,0,0,0,1272,1261,1,0,0,0,1272,1263,1,0,0,0,
  	1272,1266,1,0,0,0,1272,1269,1,0,0,0,1273,33,1,0,0,0,1274,1275,5,188,0,
  	0,1275,1276,5,54,0,0,1276,35,1,0,0,0,1277,1278,5,327,0,0,1278,37,1,0,
  	0,0,1279,1280,5,199,0,0,1280,1282,5,317,0,0,1281,1283,3,40,20,0,1282,
  	1281,1,0,0,0,1282,1283,1,0,0,0,1283,39,1,0,0,0,1284,1289,3,42,21,0,1285,
  	1286,5,361,0,0,1286,1288,3,42,21,0,1287,1285,1,0,0,0,1288,1291,1,0,0,
  	0,1289,1287,1,0,0,0,1289,1290,1,0,0,0,1290,41,1,0,0,0,1291,1289,1,0,0,
  	0,1292,1293,3,44,22,0,1293,43,1,0,0,0,1294,1295,5,306,0,0,1295,1299,5,
  	303,0,0,1296,1297,5,306,0,0,1297,1299,5,323,0,0,1298,1294,1,0,0,0,1298,
  	1296,1,0,0,0,1299,45,1,0,0,0,1300,1301,5,182,0,0,1301,47,1,0,0,0,1302,
  	1303,5,57,0,0,1303,49,1,0,0,0,1304,1305,5,369,0,0,1305,1306,3,52,26,0,
  	1306,1307,5,380,0,0,1307,51,1,0,0,0,1308,1309,3,58,29,0,1309,53,1,0,0,
  	0,1310,1311,5,369,0,0,1311,1312,3,58,29,0,1312,1313,5,380,0,0,1313,55,
  	1,0,0,0,1314,1315,5,369,0,0,1315,1316,3,58,29,0,1316,1317,5,380,0,0,1317,
  	57,1,0,0,0,1318,1320,3,290,145,0,1319,1318,1,0,0,0,1319,1320,1,0,0,0,
  	1320,1322,1,0,0,0,1321,1323,3,60,30,0,1322,1321,1,0,0,0,1322,1323,1,0,
  	0,0,1323,1324,1,0,0,0,1324,1325,3,64,32,0,1325,59,1,0,0,0,1326,1328,3,
  	62,31,0,1327,1326,1,0,0,0,1328,1329,1,0,0,0,1329,1327,1,0,0,0,1329,1330,
  	1,0,0,0,1330,61,1,0,0,0,1331,1335,3,70,35,0,1332,1335,3,76,38,0,1333,
  	1335,3,82,41,0,1334,1331,1,0,0,0,1334,1332,1,0,0,0,1334,1333,1,0,0,0,
  	1335,63,1,0,0,0,1336,1340,3,66,33,0,1337,1339,3,68,34,0,1338,1337,1,0,
  	0,0,1339,1342,1,0,0,0,1340,1338,1,0,0,0,1340,1341,1,0,0,0,1341,65,1,0,
  	0,0,1342,1340,1,0,0,0,1343,1347,3,98,49,0,1344,1347,3,130,65,0,1345,1347,
  	3,182,91,0,1346,1343,1,0,0,0,1346,1344,1,0,0,0,1346,1345,1,0,0,0,1347,
  	67,1,0,0,0,1348,1350,5,149,0,0,1349,1351,3,502,251,0,1350,1349,1,0,0,
  	0,1350,1351,1,0,0,0,1351,1352,1,0,0,0,1352,1353,3,66,33,0,1353,69,1,0,
  	0,0,1354,1356,5,305,0,0,1355,1354,1,0,0,0,1355,1356,1,0,0,0,1356,1357,
  	1,0,0,0,1357,1358,5,289,0,0,1358,1359,3,1092,546,0,1359,1360,3,72,36,
  	0,1360,71,1,0,0,0,1361,1363,3,676,338,0,1362,1361,1,0,0,0,1362,1363,1,
  	0,0,0,1363,1364,1,0,0,0,1364,1366,3,738,369,0,1365,1362,1,0,0,0,1365,
  	1366,1,0,0,0,1366,1367,1,0,0,0,1367,1368,3,74,37,0,1368,73,1,0,0,0,1369,
  	1370,5,365,0,0,1370,1371,3,88,44,0,1371,75,1,0,0,0,1372,1374,5,278,0,
  	0,1373,1372,1,0,0,0,1373,1374,1,0,0,0,1374,1375,1,0,0,0,1375,1376,5,313,
  	0,0,1376,1377,3,1092,546,0,1377,1378,3,78,39,0,1378,77,1,0,0,0,1379,1381,
  	3,676,338,0,1380,1379,1,0,0,0,1380,1381,1,0,0,0,1381,1382,1,0,0,0,1382,
  	1384,3,744,372,0,1383,1380,1,0,0,0,1383,1384,1,0,0,0,1384,1385,1,0,0,
  	0,1385,1386,3,80,40,0,1386,79,1,0,0,0,1387,1388,5,365,0,0,1388,1389,3,
  	92,46,0,1389,81,1,0,0,0,1390,1391,5,225,0,0,1391,1392,3,1092,546,0,1392,
  	1393,3,84,42,0,1393,83,1,0,0,0,1394,1396,3,676,338,0,1395,1394,1,0,0,
  	0,1395,1396,1,0,0,0,1396,1397,1,0,0,0,1397,1399,3,674,337,0,1398,1395,
  	1,0,0,0,1398,1399,1,0,0,0,1399,1400,1,0,0,0,1400,1401,3,86,43,0,1401,
  	85,1,0,0,0,1402,1403,5,365,0,0,1403,1404,3,818,409,0,1404,87,1,0,0,0,
  	1405,1410,3,96,48,0,1406,1410,3,554,277,0,1407,1410,3,1058,529,0,1408,
  	1410,3,90,45,0,1409,1405,1,0,0,0,1409,1406,1,0,0,0,1409,1407,1,0,0,0,
  	1409,1408,1,0,0,0,1410,89,1,0,0,0,1411,1412,7,1,0,0,1412,91,1,0,0,0,1413,
  	1418,3,94,47,0,1414,1418,3,96,48,0,1415,1418,3,564,282,0,1416,1418,3,
  	1058,529,0,1417,1413,1,0,0,0,1417,1414,1,0,0,0,1417,1415,1,0,0,0,1417,
  	1416,1,0,0,0,1418,93,1,0,0,0,1419,1420,3,56,28,0,1420,95,1,0,0,0,1421,
  	1422,5,228,0,0,1422,1426,3,842,421,0,1423,1426,3,844,422,0,1424,1426,
  	3,848,424,0,1425,1421,1,0,0,0,1425,1423,1,0,0,0,1425,1424,1,0,0,0,1426,
  	97,1,0,0,0,1427,1429,3,100,50,0,1428,1427,1,0,0,0,1429,1430,1,0,0,0,1430,
  	1428,1,0,0,0,1430,1431,1,0,0,0,1431,99,1,0,0,0,1432,1435,3,102,51,0,1433,
  	1435,3,128,64,0,1434,1432,1,0,0,0,1434,1433,1,0,0,0,1435,101,1,0,0,0,
  	1436,1443,3,104,52,0,1437,1443,3,106,53,0,1438,1443,3,108,54,0,1439,1443,
  	3,118,59,0,1440,1443,3,120,60,0,1441,1443,3,126,63,0,1442,1436,1,0,0,
  	0,1442,1437,1,0,0,0,1442,1438,1,0,0,0,1442,1439,1,0,0,0,1442,1440,1,0,
  	0,0,1442,1441,1,0,0,0,1443,103,1,0,0,0,1444,1445,5,63,0,0,1445,1449,5,
  	185,0,0,1446,1447,5,108,0,0,1447,1448,5,152,0,0,1448,1450,5,89,0,0,1449,
  	1446,1,0,0,0,1449,1450,1,0,0,0,1450,1451,1,0,0,0,1451,1452,3,542,271,
  	0,1452,105,1,0,0,0,1453,1454,5,82,0,0,1454,1457,5,185,0,0,1455,1456,5,
  	108,0,0,1456,1458,5,89,0,0,1457,1455,1,0,0,0,1457,1458,1,0,0,0,1458,1459,
  	1,0,0,0,1459,1460,3,542,271,0,1460,107,1,0,0,0,1461,1477,5,63,0,0,1462,
  	1464,5,305,0,0,1463,1462,1,0,0,0,1463,1464,1,0,0,0,1464,1465,1,0,0,0,
  	1465,1469,5,289,0,0,1466,1467,5,108,0,0,1467,1468,5,152,0,0,1468,1470,
  	5,89,0,0,1469,1466,1,0,0,0,1469,1470,1,0,0,0,1470,1478,1,0,0,0,1471,1472,
  	5,161,0,0,1472,1474,5,178,0,0,1473,1475,5,305,0,0,1474,1473,1,0,0,0,1474,
  	1475,1,0,0,0,1475,1476,1,0,0,0,1476,1478,5,289,0,0,1477,1463,1,0,0,0,
  	1477,1471,1,0,0,0,1478,1479,1,0,0,0,1479,1482,3,556,278,0,1480,1483,3,
  	110,55,0,1481,1483,3,112,56,0,1482,1480,1,0,0,0,1482,1481,1,0,0,0,1483,
  	1485,1,0,0,0,1484,1486,3,116,58,0,1485,1484,1,0,0,0,1485,1486,1,0,0,0,
  	1486,109,1,0,0,0,1487,1489,3,676,338,0,1488,1487,1,0,0,0,1488,1489,1,
  	0,0,0,1489,1490,1,0,0,0,1490,1495,5,25,0,0,1491,1493,5,305,0,0,1492,1491,
  	1,0,0,0,1492,1493,1,0,0,0,1493,1494,1,0,0,0,1494,1496,5,289,0,0,1495,
  	1492,1,0,0,0,1495,1496,1,0,0,0,1496,111,1,0,0,0,1497,1513,3,114,57,0,
  	1498,1500,3,676,338,0,1499,1498,1,0,0,0,1499,1500,1,0,0,0,1500,1501,1,
  	0,0,0,1501,1513,3,560,280,0,1502,1504,3,676,338,0,1503,1502,1,0,0,0,1503,
  	1504,1,0,0,0,1504,1509,1,0,0,0,1505,1507,5,305,0,0,1506,1505,1,0,0,0,
  	1506,1507,1,0,0,0,1507,1508,1,0,0,0,1508,1510,5,289,0,0,1509,1506,1,0,
  	0,0,1509,1510,1,0,0,0,1510,1511,1,0,0,0,1511,1513,3,574,287,0,1512,1497,
  	1,0,0,0,1512,1499,1,0,0,0,1512,1503,1,0,0,0,1513,113,1,0,0,0,1514,1515,
  	5,131,0,0,1515,1516,3,88,44,0,1516,115,1,0,0,0,1517,1518,5,27,0,0,1518,
  	1519,5,58,0,0,1519,1520,5,158,0,0,1520,1521,3,88,44,0,1521,117,1,0,0,
  	0,1522,1524,5,82,0,0,1523,1525,5,305,0,0,1524,1523,1,0,0,0,1524,1525,
  	1,0,0,0,1525,1526,1,0,0,0,1526,1529,5,289,0,0,1527,1528,5,108,0,0,1528,
  	1530,5,89,0,0,1529,1527,1,0,0,0,1529,1530,1,0,0,0,1530,1531,1,0,0,0,1531,
  	1532,3,556,278,0,1532,119,1,0,0,0,1533,1551,5,63,0,0,1534,1536,5,305,
  	0,0,1535,1534,1,0,0,0,1535,1536,1,0,0,0,1536,1537,1,0,0,0,1537,1538,5,
  	289,0,0,1538,1542,5,318,0,0,1539,1540,5,108,0,0,1540,1541,5,152,0,0,1541,
  	1543,5,89,0,0,1542,1539,1,0,0,0,1542,1543,1,0,0,0,1543,1552,1,0,0,0,1544,
  	1545,5,161,0,0,1545,1547,5,178,0,0,1546,1548,5,305,0,0,1547,1546,1,0,
  	0,0,1547,1548,1,0,0,0,1548,1549,1,0,0,0,1549,1550,5,289,0,0,1550,1552,
  	5,318,0,0,1551,1535,1,0,0,0,1551,1544,1,0,0,0,1552,1553,1,0,0,0,1553,
  	1554,3,562,281,0,1554,1555,3,122,61,0,1555,121,1,0,0,0,1556,1558,5,27,
  	0,0,1557,1556,1,0,0,0,1557,1558,1,0,0,0,1558,1559,1,0,0,0,1559,1566,3,
  	124,62,0,1560,1566,3,114,57,0,1561,1563,5,27,0,0,1562,1561,1,0,0,0,1562,
  	1563,1,0,0,0,1563,1564,1,0,0,0,1564,1566,3,574,287,0,1565,1557,1,0,0,
  	0,1565,1560,1,0,0,0,1565,1562,1,0,0,0,1566,123,1,0,0,0,1567,1568,5,58,
  	0,0,1568,1569,5,158,0,0,1569,1570,3,560,280,0,1570,125,1,0,0,0,1571,1573,
  	5,82,0,0,1572,1574,5,305,0,0,1573,1572,1,0,0,0,1573,1574,1,0,0,0,1574,
  	1575,1,0,0,0,1575,1576,5,289,0,0,1576,1579,5,318,0,0,1577,1578,5,108,
  	0,0,1578,1580,5,89,0,0,1579,1577,1,0,0,0,1579,1580,1,0,0,0,1580,1581,
  	1,0,0,0,1581,1582,3,562,281,0,1582,127,1,0,0,0,1583,1584,3,274,137,0,
  	1584,129,1,0,0,0,1585,1588,3,132,66,0,1586,1588,3,138,69,0,1587,1585,
  	1,0,0,0,1587,1586,1,0,0,0,1588,131,1,0,0,0,1589,1592,3,134,67,0,1590,
  	1592,3,136,68,0,1591,1589,1,0,0,0,1591,1590,1,0,0,0,1592,133,1,0,0,0,
  	1593,1594,3,292,146,0,1594,1596,3,142,71,0,1595,1597,3,244,122,0,1596,
  	1595,1,0,0,0,1596,1597,1,0,0,0,1597,135,1,0,0,0,1598,1599,3,292,146,0,
  	1599,1600,3,54,27,0,1600,137,1,0,0,0,1601,1604,3,140,70,0,1602,1604,3,
  	54,27,0,1603,1601,1,0,0,0,1603,1602,1,0,0,0,1604,139,1,0,0,0,1605,1607,
  	3,142,71,0,1606,1608,3,244,122,0,1607,1606,1,0,0,0,1607,1608,1,0,0,0,
  	1608,141,1,0,0,0,1609,1611,3,144,72,0,1610,1609,1,0,0,0,1611,1612,1,0,
  	0,0,1612,1610,1,0,0,0,1612,1613,1,0,0,0,1613,143,1,0,0,0,1614,1617,3,
  	208,104,0,1615,1617,3,146,73,0,1616,1614,1,0,0,0,1616,1615,1,0,0,0,1617,
  	145,1,0,0,0,1618,1621,3,148,74,0,1619,1621,3,180,90,0,1620,1618,1,0,0,
  	0,1620,1619,1,0,0,0,1621,147,1,0,0,0,1622,1627,3,150,75,0,1623,1627,3,
  	152,76,0,1624,1627,3,164,82,0,1625,1627,3,174,87,0,1626,1622,1,0,0,0,
  	1626,1623,1,0,0,0,1626,1624,1,0,0,0,1626,1625,1,0,0,0,1627,149,1,0,0,
  	0,1628,1629,5,110,0,0,1629,1630,3,324,162,0,1630,151,1,0,0,0,1631,1632,
  	5,190,0,0,1632,1633,3,154,77,0,1633,153,1,0,0,0,1634,1639,3,156,78,0,
  	1635,1636,5,361,0,0,1636,1638,3,156,78,0,1637,1635,1,0,0,0,1638,1641,
  	1,0,0,0,1639,1637,1,0,0,0,1639,1640,1,0,0,0,1640,155,1,0,0,0,1641,1639,
  	1,0,0,0,1642,1646,3,158,79,0,1643,1646,3,160,80,0,1644,1646,3,162,81,
  	0,1645,1642,1,0,0,0,1645,1643,1,0,0,0,1645,1644,1,0,0,0,1646,157,1,0,
  	0,0,1647,1648,3,912,456,0,1648,1649,5,375,0,0,1649,1650,3,1082,541,0,
  	1650,1651,5,365,0,0,1651,1652,3,818,409,0,1652,159,1,0,0,0,1653,1654,
  	3,912,456,0,1654,1655,5,365,0,0,1655,1657,5,369,0,0,1656,1658,3,398,199,
  	0,1657,1656,1,0,0,0,1657,1658,1,0,0,0,1658,1659,1,0,0,0,1659,1660,5,380,
  	0,0,1660,161,1,0,0,0,1661,1662,3,912,456,0,1662,1663,3,390,195,0,1663,
  	1664,3,1080,540,0,1664,163,1,0,0,0,1665,1666,5,177,0,0,1666,1667,3,166,
  	83,0,1667,165,1,0,0,0,1668,1673,3,168,84,0,1669,1670,5,361,0,0,1670,1672,
  	3,168,84,0,1671,1669,1,0,0,0,1672,1675,1,0,0,0,1673,1671,1,0,0,0,1673,
  	1674,1,0,0,0,1674,167,1,0,0,0,1675,1673,1,0,0,0,1676,1679,3,170,85,0,
  	1677,1679,3,172,86,0,1678,1676,1,0,0,0,1678,1677,1,0,0,0,1679,169,1,0,
  	0,0,1680,1681,3,912,456,0,1681,1682,5,375,0,0,1682,1683,3,1082,541,0,
  	1683,171,1,0,0,0,1684,1685,3,912,456,0,1685,1686,3,390,195,0,1686,1687,
  	3,1080,540,0,1687,173,1,0,0,0,1688,1690,7,2,0,0,1689,1688,1,0,0,0,1689,
  	1690,1,0,0,0,1690,1691,1,0,0,0,1691,1692,5,76,0,0,1692,1693,3,176,88,
  	0,1693,175,1,0,0,0,1694,1699,3,178,89,0,1695,1696,5,361,0,0,1696,1698,
  	3,178,89,0,1697,1695,1,0,0,0,1698,1701,1,0,0,0,1699,1697,1,0,0,0,1699,
  	1700,1,0,0,0,1700,177,1,0,0,0,1701,1699,1,0,0,0,1702,1703,3,818,409,0,
  	1703,179,1,0,0,0,1704,1705,3,274,137,0,1705,181,1,0,0,0,1706,1707,3,184,
  	92,0,1707,183,1,0,0,0,1708,1709,6,92,-1,0,1709,1710,3,190,95,0,1710,1717,
  	1,0,0,0,1711,1712,10,2,0,0,1712,1713,3,186,93,0,1713,1714,3,190,95,0,
  	1714,1716,1,0,0,0,1715,1711,1,0,0,0,1716,1719,1,0,0,0,1717,1715,1,0,0,
  	0,1717,1718,1,0,0,0,1718,185,1,0,0,0,1719,1717,1,0,0,0,1720,1723,3,188,
  	94,0,1721,1723,5,163,0,0,1722,1720,1,0,0,0,1722,1721,1,0,0,0,1723,187,
  	1,0,0,0,1724,1726,5,220,0,0,1725,1727,3,902,451,0,1726,1725,1,0,0,0,1726,
  	1727,1,0,0,0,1727,1737,1,0,0,0,1728,1730,5,88,0,0,1729,1731,3,902,451,
  	0,1730,1729,1,0,0,0,1730,1731,1,0,0,0,1731,1737,1,0,0,0,1732,1734,5,125,
  	0,0,1733,1735,3,902,451,0,1734,1733,1,0,0,0,1734,1735,1,0,0,0,1735,1737,
  	1,0,0,0,1736,1724,1,0,0,0,1736,1728,1,0,0,0,1736,1732,1,0,0,0,1737,189,
  	1,0,0,0,1738,1739,3,192,96,0,1739,191,1,0,0,0,1740,1743,3,194,97,0,1741,
  	1743,3,204,102,0,1742,1740,1,0,0,0,1742,1741,1,0,0,0,1743,193,1,0,0,0,
  	1744,1746,3,196,98,0,1745,1744,1,0,0,0,1746,1749,1,0,0,0,1747,1745,1,
  	0,0,0,1747,1748,1,0,0,0,1748,1750,1,0,0,0,1749,1747,1,0,0,0,1750,1755,
  	3,198,99,0,1751,1755,3,200,100,0,1752,1755,3,202,101,0,1753,1755,3,256,
  	128,0,1754,1747,1,0,0,0,1754,1751,1,0,0,0,1754,1752,1,0,0,0,1754,1753,
  	1,0,0,0,1755,195,1,0,0,0,1756,1757,3,292,146,0,1757,1758,3,206,103,0,
  	1758,197,1,0,0,0,1759,1760,3,292,146,0,1760,1761,3,206,103,0,1761,1762,
  	3,244,122,0,1762,199,1,0,0,0,1763,1764,3,292,146,0,1764,1765,3,244,122,
  	0,1765,201,1,0,0,0,1766,1767,3,292,146,0,1767,1768,3,56,28,0,1768,203,
  	1,0,0,0,1769,1771,3,206,103,0,1770,1769,1,0,0,0,1770,1771,1,0,0,0,1771,
  	1772,1,0,0,0,1772,1775,3,244,122,0,1773,1775,3,56,28,0,1774,1770,1,0,
  	0,0,1774,1773,1,0,0,0,1775,205,1,0,0,0,1776,1778,3,208,104,0,1777,1776,
  	1,0,0,0,1778,1779,1,0,0,0,1779,1777,1,0,0,0,1779,1780,1,0,0,0,1780,207,
  	1,0,0,0,1781,1784,3,210,105,0,1782,1784,3,222,111,0,1783,1781,1,0,0,0,
  	1783,1782,1,0,0,0,1784,209,1,0,0,0,1785,1791,3,212,106,0,1786,1791,3,
  	226,113,0,1787,1791,3,232,116,0,1788,1791,3,224,112,0,1789,1791,3,242,
  	121,0,1790,1785,1,0,0,0,1790,1786,1,0,0,0,1790,1787,1,0,0,0,1790,1788,
  	1,0,0,0,1790,1789,1,0,0,0,1791,211,1,0,0,0,1792,1795,3,214,107,0,1793,
  	1795,3,216,108,0,1794,1792,1,0,0,0,1794,1793,1,0,0,0,1795,213,1,0,0,0,
  	1796,1797,5,143,0,0,1797,1798,3,294,147,0,1798,215,1,0,0,0,1799,1800,
  	5,160,0,0,1800,1801,3,218,109,0,1801,217,1,0,0,0,1802,1812,3,214,107,
  	0,1803,1804,5,369,0,0,1804,1805,3,220,110,0,1805,1806,5,380,0,0,1806,
  	1812,1,0,0,0,1807,1808,5,371,0,0,1808,1809,3,220,110,0,1809,1810,5,382,
  	0,0,1810,1812,1,0,0,0,1811,1802,1,0,0,0,1811,1803,1,0,0,0,1811,1807,1,
  	0,0,0,1812,219,1,0,0,0,1813,1815,3,212,106,0,1814,1813,1,0,0,0,1815,1816,
  	1,0,0,0,1816,1814,1,0,0,0,1816,1817,1,0,0,0,1817,221,1,0,0,0,1818,1819,
  	3,274,137,0,1819,223,1,0,0,0,1820,1823,5,91,0,0,1821,1824,3,500,250,0,
  	1822,1824,3,774,387,0,1823,1821,1,0,0,0,1823,1822,1,0,0,0,1824,225,1,
  	0,0,0,1825,1826,5,130,0,0,1826,1827,3,228,114,0,1827,227,1,0,0,0,1828,
  	1833,3,230,115,0,1829,1830,5,361,0,0,1830,1832,3,230,115,0,1831,1829,
  	1,0,0,0,1832,1835,1,0,0,0,1833,1831,1,0,0,0,1833,1834,1,0,0,0,1834,229,
  	1,0,0,0,1835,1833,1,0,0,0,1836,1842,3,82,41,0,1837,1838,3,1092,546,0,
  	1838,1839,5,365,0,0,1839,1840,3,818,409,0,1840,1842,1,0,0,0,1841,1836,
  	1,0,0,0,1841,1837,1,0,0,0,1842,231,1,0,0,0,1843,1844,5,100,0,0,1844,1846,
  	3,234,117,0,1845,1847,3,240,120,0,1846,1845,1,0,0,0,1846,1847,1,0,0,0,
  	1847,233,1,0,0,0,1848,1849,3,236,118,0,1849,1850,3,238,119,0,1850,235,
  	1,0,0,0,1851,1852,3,1092,546,0,1852,1853,5,109,0,0,1853,237,1,0,0,0,1854,
  	1855,3,818,409,0,1855,239,1,0,0,0,1856,1857,5,231,0,0,1857,1858,7,3,0,
  	0,1858,1859,3,1092,546,0,1859,241,1,0,0,0,1860,1862,3,520,260,0,1861,
  	1863,3,534,267,0,1862,1861,1,0,0,0,1862,1863,1,0,0,0,1863,1865,1,0,0,
  	0,1864,1866,3,532,266,0,1865,1864,1,0,0,0,1865,1866,1,0,0,0,1866,1873,
  	1,0,0,0,1867,1869,3,534,267,0,1868,1870,3,532,266,0,1869,1868,1,0,0,0,
  	1869,1870,1,0,0,0,1870,1873,1,0,0,0,1871,1873,3,532,266,0,1872,1860,1,
  	0,0,0,1872,1867,1,0,0,0,1872,1871,1,0,0,0,1873,243,1,0,0,0,1874,1876,
  	3,246,123,0,1875,1877,3,242,121,0,1876,1875,1,0,0,0,1876,1877,1,0,0,0,
  	1877,1880,1,0,0,0,1878,1880,5,92,0,0,1879,1874,1,0,0,0,1879,1878,1,0,
  	0,0,1880,245,1,0,0,0,1881,1882,5,180,0,0,1882,1883,3,248,124,0,1883,247,
  	1,0,0,0,1884,1886,3,902,451,0,1885,1884,1,0,0,0,1885,1886,1,0,0,0,1886,
  	1889,1,0,0,0,1887,1890,5,359,0,0,1888,1890,3,250,125,0,1889,1887,1,0,
  	0,0,1889,1888,1,0,0,0,1890,1892,1,0,0,0,1891,1893,3,512,256,0,1892,1891,
  	1,0,0,0,1892,1893,1,0,0,0,1893,1897,1,0,0,0,1894,1895,5,300,0,0,1895,
  	1897,5,279,0,0,1896,1885,1,0,0,0,1896,1894,1,0,0,0,1897,249,1,0,0,0,1898,
  	1903,3,252,126,0,1899,1900,5,361,0,0,1900,1902,3,252,126,0,1901,1899,
  	1,0,0,0,1902,1905,1,0,0,0,1903,1901,1,0,0,0,1903,1904,1,0,0,0,1904,251,
  	1,0,0,0,1905,1903,1,0,0,0,1906,1908,3,840,420,0,1907,1909,3,254,127,0,
  	1908,1907,1,0,0,0,1908,1909,1,0,0,0,1909,253,1,0,0,0,1910,1911,5,27,0,
  	0,1911,1912,3,1110,555,0,1912,255,1,0,0,0,1913,1915,5,187,0,0,1914,1916,
  	3,902,451,0,1915,1914,1,0,0,0,1915,1916,1,0,0,0,1916,1919,1,0,0,0,1917,
  	1920,5,359,0,0,1918,1920,3,258,129,0,1919,1917,1,0,0,0,1919,1918,1,0,
  	0,0,1920,1940,1,0,0,0,1921,1923,3,266,133,0,1922,1924,3,500,250,0,1923,
  	1922,1,0,0,0,1923,1924,1,0,0,0,1924,1926,1,0,0,0,1925,1927,3,512,256,
  	0,1926,1925,1,0,0,0,1926,1927,1,0,0,0,1927,1929,1,0,0,0,1928,1930,3,264,
  	132,0,1929,1928,1,0,0,0,1929,1930,1,0,0,0,1930,1932,1,0,0,0,1931,1933,
  	3,520,260,0,1932,1931,1,0,0,0,1932,1933,1,0,0,0,1933,1935,1,0,0,0,1934,
  	1936,3,534,267,0,1935,1934,1,0,0,0,1935,1936,1,0,0,0,1936,1938,1,0,0,
  	0,1937,1939,3,532,266,0,1938,1937,1,0,0,0,1938,1939,1,0,0,0,1939,1941,
  	1,0,0,0,1940,1921,1,0,0,0,1940,1941,1,0,0,0,1941,257,1,0,0,0,1942,1947,
  	3,260,130,0,1943,1944,5,361,0,0,1944,1946,3,260,130,0,1945,1943,1,0,0,
  	0,1946,1949,1,0,0,0,1947,1945,1,0,0,0,1947,1948,1,0,0,0,1948,259,1,0,
  	0,0,1949,1947,1,0,0,0,1950,1952,3,840,420,0,1951,1953,3,262,131,0,1952,
  	1951,1,0,0,0,1952,1953,1,0,0,0,1953,261,1,0,0,0,1954,1955,5,27,0,0,1955,
  	1956,3,1110,555,0,1956,263,1,0,0,0,1957,1958,5,103,0,0,1958,1959,3,774,
  	387,0,1959,265,1,0,0,0,1960,1963,5,101,0,0,1961,1964,3,268,134,0,1962,
  	1964,3,272,136,0,1963,1961,1,0,0,0,1963,1962,1,0,0,0,1964,267,1,0,0,0,
  	1965,1970,3,270,135,0,1966,1967,5,361,0,0,1967,1969,3,270,135,0,1968,
  	1966,1,0,0,0,1969,1972,1,0,0,0,1970,1968,1,0,0,0,1970,1971,1,0,0,0,1971,
  	269,1,0,0,0,1972,1970,1,0,0,0,1973,1974,3,88,44,0,1974,1975,3,212,106,
  	0,1975,271,1,0,0,0,1976,1981,3,56,28,0,1977,1978,3,88,44,0,1978,1979,
  	3,56,28,0,1979,1981,1,0,0,0,1980,1976,1,0,0,0,1980,1977,1,0,0,0,1981,
  	273,1,0,0,0,1982,1984,5,160,0,0,1983,1982,1,0,0,0,1983,1984,1,0,0,0,1984,
  	1985,1,0,0,0,1985,1986,5,44,0,0,1986,1987,3,276,138,0,1987,275,1,0,0,
  	0,1988,1991,3,278,139,0,1989,1991,3,284,142,0,1990,1988,1,0,0,0,1990,
  	1989,1,0,0,0,1991,277,1,0,0,0,1992,1994,3,280,140,0,1993,1992,1,0,0,0,
  	1993,1994,1,0,0,0,1994,1995,1,0,0,0,1995,1996,3,50,25,0,1996,279,1,0,
  	0,0,1997,1999,5,371,0,0,1998,2000,3,282,141,0,1999,1998,1,0,0,0,1999,
  	2000,1,0,0,0,2000,2001,1,0,0,0,2001,2002,5,382,0,0,2002,281,1,0,0,0,2003,
  	2008,3,912,456,0,2004,2005,5,361,0,0,2005,2007,3,912,456,0,2006,2004,
  	1,0,0,0,2007,2010,1,0,0,0,2008,2006,1,0,0,0,2008,2009,1,0,0,0,2009,283,
  	1,0,0,0,2010,2008,1,0,0,0,2011,2012,3,566,283,0,2012,2014,5,371,0,0,2013,
  	2015,3,286,143,0,2014,2013,1,0,0,0,2014,2015,1,0,0,0,2015,2016,1,0,0,
  	0,2016,2018,5,382,0,0,2017,2019,3,502,251,0,2018,2017,1,0,0,0,2018,2019,
  	1,0,0,0,2019,285,1,0,0,0,2020,2025,3,288,144,0,2021,2022,5,361,0,0,2022,
  	2024,3,288,144,0,2023,2021,1,0,0,0,2024,2027,1,0,0,0,2025,2023,1,0,0,
  	0,2025,2026,1,0,0,0,2026,287,1,0,0,0,2027,2025,1,0,0,0,2028,2029,3,818,
  	409,0,2029,289,1,0,0,0,2030,2031,5,31,0,0,2031,2032,3,538,269,0,2032,
  	291,1,0,0,0,2033,2034,5,223,0,0,2034,2035,3,88,44,0,2035,293,1,0,0,0,
  	2036,2038,3,302,151,0,2037,2039,3,296,148,0,2038,2037,1,0,0,0,2038,2039,
  	1,0,0,0,2039,295,1,0,0,0,2040,2041,5,234,0,0,2041,2042,3,298,149,0,2042,
  	297,1,0,0,0,2043,2048,3,300,150,0,2044,2045,5,361,0,0,2045,2047,3,300,
  	150,0,2046,2044,1,0,0,0,2047,2050,1,0,0,0,2048,2046,1,0,0,0,2048,2049,
  	1,0,0,0,2049,2054,1,0,0,0,2050,2048,1,0,0,0,2051,2052,5,300,0,0,2052,
  	2054,5,279,0,0,2053,2043,1,0,0,0,2053,2051,1,0,0,0,2054,299,1,0,0,0,2055,
  	2056,3,912,456,0,2056,301,1,0,0,0,2057,2059,3,304,152,0,2058,2057,1,0,
  	0,0,2058,2059,1,0,0,0,2059,2060,1,0,0,0,2060,2062,3,314,157,0,2061,2063,
  	3,320,160,0,2062,2061,1,0,0,0,2062,2063,1,0,0,0,2063,2065,1,0,0,0,2064,
  	2066,3,322,161,0,2065,2064,1,0,0,0,2065,2066,1,0,0,0,2066,303,1,0,0,0,
  	2067,2070,3,306,153,0,2068,2070,3,308,154,0,2069,2067,1,0,0,0,2069,2068,
  	1,0,0,0,2070,305,1,0,0,0,2071,2072,5,309,0,0,2072,2073,3,310,155,0,2073,
  	307,1,0,0,0,2074,2075,5,282,0,0,2075,2076,3,312,156,0,2076,309,1,0,0,
  	0,2077,2079,5,286,0,0,2078,2080,5,279,0,0,2079,2078,1,0,0,0,2079,2080,
  	1,0,0,0,2080,2083,1,0,0,0,2081,2083,5,287,0,0,2082,2077,1,0,0,0,2082,
  	2081,1,0,0,0,2083,311,1,0,0,0,2084,2086,3,1144,572,0,2085,2087,5,279,
  	0,0,2086,2085,1,0,0,0,2086,2087,1,0,0,0,2087,2090,1,0,0,0,2088,2090,3,
  	1142,571,0,2089,2084,1,0,0,0,2089,2088,1,0,0,0,2090,313,1,0,0,0,2091,
  	2096,3,316,158,0,2092,2093,5,361,0,0,2093,2095,3,316,158,0,2094,2092,
  	1,0,0,0,2095,2098,1,0,0,0,2096,2094,1,0,0,0,2096,2097,1,0,0,0,2097,315,
  	1,0,0,0,2098,2096,1,0,0,0,2099,2101,3,318,159,0,2100,2099,1,0,0,0,2100,
  	2101,1,0,0,0,2101,2103,1,0,0,0,2102,2104,3,344,172,0,2103,2102,1,0,0,
  	0,2103,2104,1,0,0,0,2104,2105,1,0,0,0,2105,2106,3,372,186,0,2106,317,
  	1,0,0,0,2107,2108,3,1088,544,0,2108,2109,5,365,0,0,2109,319,1,0,0,0,2110,
  	2111,5,291,0,0,2111,2112,3,344,172,0,2112,321,1,0,0,0,2113,2114,5,230,
  	0,0,2114,2115,3,774,387,0,2115,323,1,0,0,0,2116,2117,3,326,163,0,2117,
  	325,1,0,0,0,2118,2123,3,328,164,0,2119,2120,5,361,0,0,2120,2122,3,328,
  	164,0,2121,2119,1,0,0,0,2122,2125,1,0,0,0,2123,2121,1,0,0,0,2123,2124,
  	1,0,0,0,2124,327,1,0,0,0,2125,2123,1,0,0,0,2126,2132,3,330,165,0,2127,
  	2128,3,332,166,0,2128,2129,3,330,165,0,2129,2131,1,0,0,0,2130,2127,1,
  	0,0,0,2131,2134,1,0,0,0,2132,2130,1,0,0,0,2132,2133,1,0,0,0,2133,329,
  	1,0,0,0,2134,2132,1,0,0,0,2135,2137,5,371,0,0,2136,2138,3,340,170,0,2137,
  	2136,1,0,0,0,2137,2138,1,0,0,0,2138,2139,1,0,0,0,2139,2140,5,382,0,0,
  	2140,331,1,0,0,0,2141,2145,3,334,167,0,2142,2145,3,336,168,0,2143,2145,
  	3,338,169,0,2144,2141,1,0,0,0,2144,2142,1,0,0,0,2144,2143,1,0,0,0,2145,
  	333,1,0,0,0,2146,2148,5,338,0,0,2147,2149,3,340,170,0,2148,2147,1,0,0,
  	0,2148,2149,1,0,0,0,2149,2150,1,0,0,0,2150,2151,5,348,0,0,2151,335,1,
  	0,0,0,2152,2154,5,344,0,0,2153,2155,3,340,170,0,2154,2153,1,0,0,0,2154,
  	2155,1,0,0,0,2155,2156,1,0,0,0,2156,2157,5,329,0,0,2157,337,1,0,0,0,2158,
  	2160,5,355,0,0,2159,2161,3,340,170,0,2160,2159,1,0,0,0,2160,2161,1,0,
  	0,0,2161,2162,1,0,0,0,2162,2163,5,349,0,0,2163,339,1,0,0,0,2164,2166,
  	3,386,193,0,2165,2167,3,342,171,0,2166,2165,1,0,0,0,2166,2167,1,0,0,0,
  	2167,2173,1,0,0,0,2168,2170,3,386,193,0,2169,2168,1,0,0,0,2169,2170,1,
  	0,0,0,2170,2171,1,0,0,0,2171,2173,3,342,171,0,2172,2164,1,0,0,0,2172,
  	2169,1,0,0,0,2173,341,1,0,0,0,2174,2175,3,390,195,0,2175,2177,3,662,331,
  	0,2176,2178,3,396,198,0,2177,2176,1,0,0,0,2177,2178,1,0,0,0,2178,2186,
  	1,0,0,0,2179,2180,3,390,195,0,2180,2181,3,662,331,0,2181,2183,1,0,0,0,
  	2182,2179,1,0,0,0,2182,2183,1,0,0,0,2183,2184,1,0,0,0,2184,2186,3,396,
  	198,0,2185,2174,1,0,0,0,2185,2182,1,0,0,0,2186,343,1,0,0,0,2187,2190,
  	3,346,173,0,2188,2190,3,350,175,0,2189,2187,1,0,0,0,2189,2188,1,0,0,0,
  	2190,345,1,0,0,0,2191,2193,3,348,174,0,2192,2194,3,354,177,0,2193,2192,
  	1,0,0,0,2193,2194,1,0,0,0,2194,347,1,0,0,0,2195,2196,7,4,0,0,2196,349,
  	1,0,0,0,2197,2201,3,352,176,0,2198,2201,3,356,178,0,2199,2201,3,360,180,
  	0,2200,2197,1,0,0,0,2200,2198,1,0,0,0,2200,2199,1,0,0,0,2201,351,1,0,
  	0,0,2202,2204,5,22,0,0,2203,2205,3,348,174,0,2204,2203,1,0,0,0,2204,2205,
  	1,0,0,0,2205,2207,1,0,0,0,2206,2208,3,354,177,0,2207,2206,1,0,0,0,2207,
  	2208,1,0,0,0,2208,353,1,0,0,0,2209,2210,7,5,0,0,2210,355,1,0,0,0,2211,
  	2213,5,25,0,0,2212,2214,3,358,179,0,2213,2212,1,0,0,0,2213,2214,1,0,0,
  	0,2214,2216,1,0,0,0,2215,2217,3,348,174,0,2216,2215,1,0,0,0,2216,2217,
  	1,0,0,0,2217,2219,1,0,0,0,2218,2220,3,354,177,0,2219,2218,1,0,0,0,2219,
  	2220,1,0,0,0,2220,357,1,0,0,0,2221,2222,3,852,426,0,2222,359,1,0,0,0,
  	2223,2228,3,362,181,0,2224,2228,3,364,182,0,2225,2228,3,366,183,0,2226,
  	2228,3,368,184,0,2227,2223,1,0,0,0,2227,2224,1,0,0,0,2227,2225,1,0,0,
  	0,2227,2226,1,0,0,0,2228,361,1,0,0,0,2229,2230,5,22,0,0,2230,2232,5,310,
  	0,0,2231,2233,3,348,174,0,2232,2231,1,0,0,0,2232,2233,1,0,0,0,2233,2235,
  	1,0,0,0,2234,2236,3,354,177,0,2235,2234,1,0,0,0,2235,2236,1,0,0,0,2236,
  	363,1,0,0,0,2237,2238,5,25,0,0,2238,2240,5,310,0,0,2239,2241,3,348,174,
  	0,2240,2239,1,0,0,0,2240,2241,1,0,0,0,2241,2243,1,0,0,0,2242,2244,3,354,
  	177,0,2243,2242,1,0,0,0,2243,2244,1,0,0,0,2244,365,1,0,0,0,2245,2246,
  	5,310,0,0,2246,2248,3,358,179,0,2247,2249,3,348,174,0,2248,2247,1,0,0,
  	0,2248,2249,1,0,0,0,2249,2251,1,0,0,0,2250,2252,3,354,177,0,2251,2250,
  	1,0,0,0,2251,2252,1,0,0,0,2252,367,1,0,0,0,2253,2255,5,310,0,0,2254,2256,
  	3,370,185,0,2255,2254,1,0,0,0,2255,2256,1,0,0,0,2256,2258,1,0,0,0,2257,
  	2259,3,348,174,0,2258,2257,1,0,0,0,2258,2259,1,0,0,0,2259,2261,1,0,0,
  	0,2260,2262,3,354,177,0,2261,2260,1,0,0,0,2261,2262,1,0,0,0,2262,2263,
  	1,0,0,0,2263,2264,7,6,0,0,2264,369,1,0,0,0,2265,2266,3,852,426,0,2266,
  	371,1,0,0,0,2267,2283,3,374,187,0,2268,2271,3,374,187,0,2269,2270,5,328,
  	0,0,2270,2272,3,374,187,0,2271,2269,1,0,0,0,2272,2273,1,0,0,0,2273,2271,
  	1,0,0,0,2273,2274,1,0,0,0,2274,2283,1,0,0,0,2275,2278,3,374,187,0,2276,
  	2277,5,386,0,0,2277,2279,3,374,187,0,2278,2276,1,0,0,0,2279,2280,1,0,
  	0,0,2280,2278,1,0,0,0,2280,2281,1,0,0,0,2281,2283,1,0,0,0,2282,2267,1,
  	0,0,0,2282,2268,1,0,0,0,2282,2275,1,0,0,0,2283,373,1,0,0,0,2284,2286,
  	3,376,188,0,2285,2284,1,0,0,0,2286,2287,1,0,0,0,2287,2285,1,0,0,0,2287,
  	2288,1,0,0,0,2288,375,1,0,0,0,2289,2297,3,378,189,0,2290,2291,3,378,189,
  	0,2291,2292,3,434,217,0,2292,2297,1,0,0,0,2293,2294,3,378,189,0,2294,
  	2295,5,377,0,0,2295,2297,1,0,0,0,2296,2289,1,0,0,0,2296,2290,1,0,0,0,
  	2296,2293,1,0,0,0,2297,377,1,0,0,0,2298,2302,3,380,190,0,2299,2302,3,
  	422,211,0,2300,2302,3,444,222,0,2301,2298,1,0,0,0,2301,2299,1,0,0,0,2301,
  	2300,1,0,0,0,2302,379,1,0,0,0,2303,2306,3,382,191,0,2304,2306,3,402,201,
  	0,2305,2303,1,0,0,0,2305,2304,1,0,0,0,2306,381,1,0,0,0,2307,2308,5,371,
  	0,0,2308,2309,3,384,192,0,2309,2310,5,382,0,0,2310,383,1,0,0,0,2311,2313,
  	3,386,193,0,2312,2311,1,0,0,0,2312,2313,1,0,0,0,2313,2315,1,0,0,0,2314,
  	2316,3,388,194,0,2315,2314,1,0,0,0,2315,2316,1,0,0,0,2316,2318,1,0,0,
  	0,2317,2319,3,392,196,0,2318,2317,1,0,0,0,2318,2319,1,0,0,0,2319,385,
  	1,0,0,0,2320,2322,5,314,0,0,2321,2320,1,0,0,0,2321,2322,1,0,0,0,2322,
  	2323,1,0,0,0,2323,2324,3,1086,543,0,2324,387,1,0,0,0,2325,2326,3,390,
  	195,0,2326,2327,3,428,214,0,2327,389,1,0,0,0,2328,2329,7,7,0,0,2329,391,
  	1,0,0,0,2330,2333,3,394,197,0,2331,2333,3,396,198,0,2332,2330,1,0,0,0,
  	2332,2331,1,0,0,0,2333,393,1,0,0,0,2334,2335,5,230,0,0,2335,2336,3,774,
  	387,0,2336,395,1,0,0,0,2337,2338,5,369,0,0,2338,2339,3,398,199,0,2339,
  	2340,5,380,0,0,2340,397,1,0,0,0,2341,2346,3,400,200,0,2342,2343,5,361,
  	0,0,2343,2345,3,400,200,0,2344,2342,1,0,0,0,2345,2348,1,0,0,0,2346,2344,
  	1,0,0,0,2346,2347,1,0,0,0,2347,399,1,0,0,0,2348,2346,1,0,0,0,2349,2350,
  	3,1082,541,0,2350,2351,5,360,0,0,2351,2352,3,818,409,0,2352,401,1,0,0,
  	0,2353,2356,3,404,202,0,2354,2356,3,420,210,0,2355,2353,1,0,0,0,2355,
  	2354,1,0,0,0,2356,403,1,0,0,0,2357,2365,3,406,203,0,2358,2365,3,408,204,
  	0,2359,2365,3,410,205,0,2360,2365,3,412,206,0,2361,2365,3,414,207,0,2362,
  	2365,3,416,208,0,2363,2365,3,418,209,0,2364,2357,1,0,0,0,2364,2358,1,
  	0,0,0,2364,2359,1,0,0,0,2364,2360,1,0,0,0,2364,2361,1,0,0,0,2364,2362,
  	1,0,0,0,2364,2363,1,0,0,0,2365,405,1,0,0,0,2366,2367,5,338,0,0,2367,2368,
  	3,384,192,0,2368,2369,5,348,0,0,2369,407,1,0,0,0,2370,2371,5,355,0,0,
  	2371,2372,3,384,192,0,2372,2373,5,349,0,0,2373,409,1,0,0,0,2374,2375,
  	5,344,0,0,2375,2376,3,384,192,0,2376,2377,5,329,0,0,2377,411,1,0,0,0,
  	2378,2379,5,339,0,0,2379,2380,3,384,192,0,2380,2381,5,349,0,0,2381,413,
  	1,0,0,0,2382,2383,5,355,0,0,2383,2384,3,384,192,0,2384,2385,5,330,0,0,
  	2385,415,1,0,0,0,2386,2387,5,338,0,0,2387,2388,3,384,192,0,2388,2389,
  	5,329,0,0,2389,417,1,0,0,0,2390,2391,5,344,0,0,2391,2392,3,384,192,0,
  	2392,2393,5,348,0,0,2393,419,1,0,0,0,2394,2395,7,8,0,0,2395,421,1,0,0,
  	0,2396,2398,5,371,0,0,2397,2399,3,424,212,0,2398,2397,1,0,0,0,2398,2399,
  	1,0,0,0,2399,2401,1,0,0,0,2400,2402,3,346,173,0,2401,2400,1,0,0,0,2401,
  	2402,1,0,0,0,2402,2403,1,0,0,0,2403,2405,3,372,186,0,2404,2406,3,426,
  	213,0,2405,2404,1,0,0,0,2405,2406,1,0,0,0,2406,2407,1,0,0,0,2407,2408,
  	5,382,0,0,2408,423,1,0,0,0,2409,2410,3,1090,545,0,2410,2411,5,365,0,0,
  	2411,425,1,0,0,0,2412,2413,5,230,0,0,2413,2414,3,774,387,0,2414,427,1,
  	0,0,0,2415,2416,6,214,-1,0,2416,2417,5,366,0,0,2417,2425,3,428,214,6,
  	2418,2425,3,1080,540,0,2419,2425,5,374,0,0,2420,2421,5,371,0,0,2421,2422,
  	3,428,214,0,2422,2423,5,382,0,0,2423,2425,1,0,0,0,2424,2415,1,0,0,0,2424,
  	2418,1,0,0,0,2424,2419,1,0,0,0,2424,2420,1,0,0,0,2425,2434,1,0,0,0,2426,
  	2427,10,5,0,0,2427,2428,5,358,0,0,2428,2433,3,428,214,6,2429,2430,10,
  	4,0,0,2430,2431,5,386,0,0,2431,2433,3,428,214,5,2432,2426,1,0,0,0,2432,
  	2429,1,0,0,0,2433,2436,1,0,0,0,2434,2432,1,0,0,0,2434,2435,1,0,0,0,2435,
  	429,1,0,0,0,2436,2434,1,0,0,0,2437,2438,3,912,456,0,2438,431,1,0,0,0,
  	2439,2440,3,912,456,0,2440,433,1,0,0,0,2441,2446,5,359,0,0,2442,2446,
  	5,376,0,0,2443,2446,3,436,218,0,2444,2446,3,438,219,0,2445,2441,1,0,0,
  	0,2445,2442,1,0,0,0,2445,2443,1,0,0,0,2445,2444,1,0,0,0,2446,435,1,0,
  	0,0,2447,2448,5,369,0,0,2448,2449,3,1124,562,0,2449,2450,5,380,0,0,2450,
  	437,1,0,0,0,2451,2453,5,369,0,0,2452,2454,3,440,220,0,2453,2452,1,0,0,
  	0,2453,2454,1,0,0,0,2454,2455,1,0,0,0,2455,2457,5,361,0,0,2456,2458,3,
  	442,221,0,2457,2456,1,0,0,0,2457,2458,1,0,0,0,2458,2459,1,0,0,0,2459,
  	2460,5,380,0,0,2460,439,1,0,0,0,2461,2462,3,1124,562,0,2462,441,1,0,0,
  	0,2463,2464,3,1124,562,0,2464,443,1,0,0,0,2465,2473,3,446,223,0,2466,
  	2473,3,448,224,0,2467,2473,3,450,225,0,2468,2473,3,452,226,0,2469,2473,
  	3,454,227,0,2470,2473,3,456,228,0,2471,2473,3,458,229,0,2472,2465,1,0,
  	0,0,2472,2466,1,0,0,0,2472,2467,1,0,0,0,2472,2468,1,0,0,0,2472,2469,1,
  	0,0,0,2472,2470,1,0,0,0,2472,2471,1,0,0,0,2473,445,1,0,0,0,2474,2475,
  	5,341,0,0,2475,2476,3,460,230,0,2476,2477,5,351,0,0,2477,447,1,0,0,0,
  	2478,2479,5,357,0,0,2479,2480,3,460,230,0,2480,2481,5,353,0,0,2481,449,
  	1,0,0,0,2482,2483,5,345,0,0,2483,2484,3,460,230,0,2484,2485,5,352,0,0,
  	2485,451,1,0,0,0,2486,2487,5,342,0,0,2487,2488,3,460,230,0,2488,2489,
  	5,353,0,0,2489,453,1,0,0,0,2490,2491,5,357,0,0,2491,2492,3,460,230,0,
  	2492,2493,5,354,0,0,2493,455,1,0,0,0,2494,2495,5,341,0,0,2495,2496,3,
  	460,230,0,2496,2497,5,352,0,0,2497,457,1,0,0,0,2498,2499,5,345,0,0,2499,
  	2500,3,460,230,0,2500,2501,5,351,0,0,2501,459,1,0,0,0,2502,2506,3,466,
  	233,0,2503,2506,3,462,231,0,2504,2506,3,464,232,0,2505,2502,1,0,0,0,2505,
  	2503,1,0,0,0,2505,2504,1,0,0,0,2506,461,1,0,0,0,2507,2508,3,466,233,0,
  	2508,2509,5,386,0,0,2509,2514,3,466,233,0,2510,2511,5,386,0,0,2511,2513,
  	3,466,233,0,2512,2510,1,0,0,0,2513,2516,1,0,0,0,2514,2512,1,0,0,0,2514,
  	2515,1,0,0,0,2515,463,1,0,0,0,2516,2514,1,0,0,0,2517,2518,3,466,233,0,
  	2518,2519,5,328,0,0,2519,2524,3,466,233,0,2520,2521,5,328,0,0,2521,2523,
  	3,466,233,0,2522,2520,1,0,0,0,2523,2526,1,0,0,0,2524,2522,1,0,0,0,2524,
  	2525,1,0,0,0,2525,465,1,0,0,0,2526,2524,1,0,0,0,2527,2528,6,233,-1,0,
  	2528,2529,3,468,234,0,2529,2534,1,0,0,0,2530,2531,10,1,0,0,2531,2533,
  	3,468,234,0,2532,2530,1,0,0,0,2533,2536,1,0,0,0,2534,2532,1,0,0,0,2534,
  	2535,1,0,0,0,2535,467,1,0,0,0,2536,2534,1,0,0,0,2537,2538,6,234,-1,0,
  	2538,2539,3,470,235,0,2539,2545,1,0,0,0,2540,2541,10,1,0,0,2541,2542,
  	5,358,0,0,2542,2544,3,470,235,0,2543,2540,1,0,0,0,2544,2547,1,0,0,0,2545,
  	2543,1,0,0,0,2545,2546,1,0,0,0,2546,469,1,0,0,0,2547,2545,1,0,0,0,2548,
  	2552,3,476,238,0,2549,2552,3,472,236,0,2550,2552,3,474,237,0,2551,2548,
  	1,0,0,0,2551,2549,1,0,0,0,2551,2550,1,0,0,0,2552,471,1,0,0,0,2553,2554,
  	3,476,238,0,2554,2555,3,434,217,0,2555,473,1,0,0,0,2556,2557,3,476,238,
  	0,2557,2558,5,377,0,0,2558,475,1,0,0,0,2559,2562,3,478,239,0,2560,2562,
  	3,494,247,0,2561,2559,1,0,0,0,2561,2560,1,0,0,0,2562,477,1,0,0,0,2563,
  	2571,3,480,240,0,2564,2571,3,482,241,0,2565,2571,3,484,242,0,2566,2571,
  	3,486,243,0,2567,2571,3,488,244,0,2568,2571,3,490,245,0,2569,2571,3,492,
  	246,0,2570,2563,1,0,0,0,2570,2564,1,0,0,0,2570,2565,1,0,0,0,2570,2566,
  	1,0,0,0,2570,2567,1,0,0,0,2570,2568,1,0,0,0,2570,2569,1,0,0,0,2571,479,
  	1,0,0,0,2572,2573,5,372,0,0,2573,2574,3,494,247,0,2574,481,1,0,0,0,2575,
  	2576,5,384,0,0,2576,2577,3,494,247,0,2577,483,1,0,0,0,2578,2579,3,494,
  	247,0,2579,2580,5,367,0,0,2580,485,1,0,0,0,2581,2582,5,337,0,0,2582,2583,
  	3,494,247,0,2583,487,1,0,0,0,2584,2585,5,384,0,0,2585,2586,3,494,247,
  	0,2586,2587,5,367,0,0,2587,489,1,0,0,0,2588,2589,5,372,0,0,2589,2590,
  	3,494,247,0,2590,2591,5,367,0,0,2591,491,1,0,0,0,2592,2593,5,373,0,0,
  	2593,2594,3,494,247,0,2594,493,1,0,0,0,2595,2598,3,498,249,0,2596,2598,
  	3,496,248,0,2597,2595,1,0,0,0,2597,2596,1,0,0,0,2598,495,1,0,0,0,2599,
  	2600,5,366,0,0,2600,2601,3,498,249,0,2601,497,1,0,0,0,2602,2608,3,1080,
  	540,0,2603,2604,5,371,0,0,2604,2605,3,460,230,0,2605,2606,5,382,0,0,2606,
  	2608,1,0,0,0,2607,2602,1,0,0,0,2607,2603,1,0,0,0,2608,499,1,0,0,0,2609,
  	2610,5,230,0,0,2610,2611,3,774,387,0,2611,501,1,0,0,0,2612,2613,5,234,
  	0,0,2613,2614,3,504,252,0,2614,503,1,0,0,0,2615,2620,3,506,253,0,2616,
  	2617,5,361,0,0,2617,2619,3,506,253,0,2618,2616,1,0,0,0,2619,2622,1,0,
  	0,0,2620,2618,1,0,0,0,2620,2621,1,0,0,0,2621,505,1,0,0,0,2622,2620,1,
  	0,0,0,2623,2625,3,508,254,0,2624,2626,3,510,255,0,2625,2624,1,0,0,0,2625,
  	2626,1,0,0,0,2626,507,1,0,0,0,2627,2628,3,1084,542,0,2628,509,1,0,0,0,
  	2629,2630,5,27,0,0,2630,2631,3,1092,546,0,2631,511,1,0,0,0,2632,2633,
  	5,102,0,0,2633,2634,5,41,0,0,2634,2635,3,514,257,0,2635,513,1,0,0,0,2636,
  	2641,3,516,258,0,2637,2638,5,361,0,0,2638,2640,3,516,258,0,2639,2637,
  	1,0,0,0,2640,2643,1,0,0,0,2641,2639,1,0,0,0,2641,2642,1,0,0,0,2642,2646,
  	1,0,0,0,2643,2641,1,0,0,0,2644,2646,3,518,259,0,2645,2636,1,0,0,0,2645,
  	2644,1,0,0,0,2646,515,1,0,0,0,2647,2648,3,912,456,0,2648,517,1,0,0,0,
  	2649,2650,5,371,0,0,2650,2651,5,382,0,0,2651,519,1,0,0,0,2652,2653,5,
  	162,0,0,2653,2654,5,41,0,0,2654,2655,3,522,261,0,2655,521,1,0,0,0,2656,
  	2661,3,524,262,0,2657,2658,5,361,0,0,2658,2660,3,524,262,0,2659,2657,
  	1,0,0,0,2660,2663,1,0,0,0,2661,2659,1,0,0,0,2661,2662,1,0,0,0,2662,523,
  	1,0,0,0,2663,2661,1,0,0,0,2664,2666,3,526,263,0,2665,2667,3,528,264,0,
  	2666,2665,1,0,0,0,2666,2667,1,0,0,0,2667,2669,1,0,0,0,2668,2670,3,530,
  	265,0,2669,2668,1,0,0,0,2669,2670,1,0,0,0,2670,525,1,0,0,0,2671,2672,
  	3,840,420,0,2672,527,1,0,0,0,2673,2674,7,9,0,0,2674,529,1,0,0,0,2675,
  	2676,5,155,0,0,2676,2680,5,288,0,0,2677,2678,5,155,0,0,2678,2680,5,295,
  	0,0,2679,2675,1,0,0,0,2679,2677,1,0,0,0,2680,531,1,0,0,0,2681,2682,5,
  	132,0,0,2682,2683,3,852,426,0,2683,533,1,0,0,0,2684,2685,3,536,268,0,
  	2685,2686,3,852,426,0,2686,535,1,0,0,0,2687,2688,7,10,0,0,2688,537,1,
  	0,0,0,2689,2693,3,540,270,0,2690,2693,3,544,272,0,2691,2693,3,572,286,
  	0,2692,2689,1,0,0,0,2692,2690,1,0,0,0,2692,2691,1,0,0,0,2693,539,1,0,
  	0,0,2694,2699,5,383,0,0,2695,2696,3,548,274,0,2696,2697,3,1062,531,0,
  	2697,2699,1,0,0,0,2698,2694,1,0,0,0,2698,2695,1,0,0,0,2699,541,1,0,0,
  	0,2700,2701,3,548,274,0,2701,2702,3,1062,531,0,2702,543,1,0,0,0,2703,
  	2708,3,546,273,0,2704,2705,3,550,275,0,2705,2706,3,1062,531,0,2706,2708,
  	1,0,0,0,2707,2703,1,0,0,0,2707,2704,1,0,0,0,2708,545,1,0,0,0,2709,2710,
  	7,11,0,0,2710,547,1,0,0,0,2711,2713,5,383,0,0,2712,2714,3,552,276,0,2713,
  	2712,1,0,0,0,2713,2714,1,0,0,0,2714,549,1,0,0,0,2715,2720,5,334,0,0,2716,
  	2717,5,383,0,0,2717,2719,5,334,0,0,2718,2716,1,0,0,0,2719,2722,1,0,0,
  	0,2720,2718,1,0,0,0,2720,2721,1,0,0,0,2721,2723,1,0,0,0,2722,2720,1,0,
  	0,0,2723,2725,5,383,0,0,2724,2726,3,552,276,0,2725,2724,1,0,0,0,2725,
  	2726,1,0,0,0,2726,551,1,0,0,0,2727,2728,3,1060,530,0,2728,2729,5,383,
  	0,0,2729,2731,1,0,0,0,2730,2727,1,0,0,0,2731,2732,1,0,0,0,2732,2730,1,
  	0,0,0,2732,2733,1,0,0,0,2733,553,1,0,0,0,2734,2735,3,570,285,0,2735,2736,
  	3,1064,532,0,2736,2741,1,0,0,0,2737,2741,3,1066,533,0,2738,2741,3,558,
  	279,0,2739,2741,3,572,286,0,2740,2734,1,0,0,0,2740,2737,1,0,0,0,2740,
  	2738,1,0,0,0,2740,2739,1,0,0,0,2741,555,1,0,0,0,2742,2744,3,570,285,0,
  	2743,2742,1,0,0,0,2743,2744,1,0,0,0,2744,2745,1,0,0,0,2745,2746,3,1064,
  	532,0,2746,557,1,0,0,0,2747,2748,7,12,0,0,2748,559,1,0,0,0,2749,2752,
  	3,562,281,0,2750,2752,3,572,286,0,2751,2749,1,0,0,0,2751,2750,1,0,0,0,
  	2752,561,1,0,0,0,2753,2755,3,570,285,0,2754,2753,1,0,0,0,2754,2755,1,
  	0,0,0,2755,2756,1,0,0,0,2756,2757,3,1068,534,0,2757,563,1,0,0,0,2758,
  	2759,3,570,285,0,2759,2760,3,1074,537,0,2760,2764,1,0,0,0,2761,2764,3,
  	1076,538,0,2762,2764,3,572,286,0,2763,2758,1,0,0,0,2763,2761,1,0,0,0,
  	2763,2762,1,0,0,0,2764,565,1,0,0,0,2765,2768,3,568,284,0,2766,2768,3,
  	572,286,0,2767,2765,1,0,0,0,2767,2766,1,0,0,0,2768,567,1,0,0,0,2769,2771,
  	3,570,285,0,2770,2769,1,0,0,0,2770,2771,1,0,0,0,2771,2772,1,0,0,0,2772,
  	2773,3,1078,539,0,2773,569,1,0,0,0,2774,2776,3,538,269,0,2775,2777,5,
  	383,0,0,2776,2775,1,0,0,0,2776,2777,1,0,0,0,2777,2783,1,0,0,0,2778,2779,
  	3,1056,528,0,2779,2780,5,375,0,0,2780,2782,1,0,0,0,2781,2778,1,0,0,0,
  	2782,2785,1,0,0,0,2783,2781,1,0,0,0,2783,2784,1,0,0,0,2784,2794,1,0,0,
  	0,2785,2783,1,0,0,0,2786,2787,3,1056,528,0,2787,2788,5,375,0,0,2788,2790,
  	1,0,0,0,2789,2786,1,0,0,0,2790,2791,1,0,0,0,2791,2789,1,0,0,0,2791,2792,
  	1,0,0,0,2792,2794,1,0,0,0,2793,2774,1,0,0,0,2793,2789,1,0,0,0,2794,571,
  	1,0,0,0,2795,2796,5,326,0,0,2796,573,1,0,0,0,2797,2798,5,369,0,0,2798,
  	2799,3,576,288,0,2799,2800,5,380,0,0,2800,575,1,0,0,0,2801,2802,3,578,
  	289,0,2802,577,1,0,0,0,2803,2808,3,580,290,0,2804,2805,5,361,0,0,2805,
  	2807,3,580,290,0,2806,2804,1,0,0,0,2807,2810,1,0,0,0,2808,2806,1,0,0,
  	0,2808,2809,1,0,0,0,2809,579,1,0,0,0,2810,2808,1,0,0,0,2811,2814,3,582,
  	291,0,2812,2814,3,602,301,0,2813,2811,1,0,0,0,2813,2812,1,0,0,0,2814,
  	581,1,0,0,0,2815,2818,3,584,292,0,2816,2818,3,586,293,0,2817,2815,1,0,
  	0,0,2817,2816,1,0,0,0,2818,583,1,0,0,0,2819,2821,3,1140,570,0,2820,2822,
  	5,318,0,0,2821,2820,1,0,0,0,2821,2822,1,0,0,0,2822,2823,1,0,0,0,2823,
  	2824,3,1070,535,0,2824,2826,1,0,0,0,2825,2819,1,0,0,0,2825,2826,1,0,0,
  	0,2826,2827,1,0,0,0,2827,2829,5,371,0,0,2828,2830,3,592,296,0,2829,2828,
  	1,0,0,0,2829,2830,1,0,0,0,2830,2832,1,0,0,0,2831,2833,3,590,295,0,2832,
  	2831,1,0,0,0,2832,2833,1,0,0,0,2833,2834,1,0,0,0,2834,2835,5,382,0,0,
  	2835,585,1,0,0,0,2836,2838,3,1140,570,0,2837,2839,5,318,0,0,2838,2837,
  	1,0,0,0,2838,2839,1,0,0,0,2839,2840,1,0,0,0,2840,2843,3,588,294,0,2841,
  	2842,5,27,0,0,2842,2844,3,592,296,0,2843,2841,1,0,0,0,2843,2844,1,0,0,
  	0,2844,587,1,0,0,0,2845,2847,3,1070,535,0,2846,2848,3,590,295,0,2847,
  	2846,1,0,0,0,2847,2848,1,0,0,0,2848,2851,1,0,0,0,2849,2851,3,590,295,
  	0,2850,2845,1,0,0,0,2850,2849,1,0,0,0,2851,589,1,0,0,0,2852,2854,3,596,
  	298,0,2853,2855,3,594,297,0,2854,2853,1,0,0,0,2854,2855,1,0,0,0,2855,
  	2858,1,0,0,0,2856,2858,3,594,297,0,2857,2852,1,0,0,0,2857,2856,1,0,0,
  	0,2858,591,1,0,0,0,2859,2860,3,1112,556,0,2860,593,1,0,0,0,2861,2867,
  	3,598,299,0,2862,2867,3,600,300,0,2863,2864,3,598,299,0,2864,2865,3,600,
  	300,0,2865,2867,1,0,0,0,2866,2861,1,0,0,0,2866,2862,1,0,0,0,2866,2863,
  	1,0,0,0,2867,595,1,0,0,0,2868,2870,3,660,330,0,2869,2868,1,0,0,0,2869,
  	2870,1,0,0,0,2870,2871,1,0,0,0,2871,2872,5,1,0,0,2872,597,1,0,0,0,2873,
  	2874,3,660,330,0,2874,599,1,0,0,0,2875,2876,3,664,332,0,2876,601,1,0,
  	0,0,2877,2880,3,604,302,0,2878,2880,3,606,303,0,2879,2877,1,0,0,0,2879,
  	2878,1,0,0,0,2880,603,1,0,0,0,2881,2883,3,638,319,0,2882,2881,1,0,0,0,
  	2882,2883,1,0,0,0,2883,2884,1,0,0,0,2884,2886,3,1144,572,0,2885,2887,
  	5,318,0,0,2886,2885,1,0,0,0,2886,2887,1,0,0,0,2887,2888,1,0,0,0,2888,
  	2889,3,1072,536,0,2889,2891,1,0,0,0,2890,2882,1,0,0,0,2890,2891,1,0,0,
  	0,2891,2894,1,0,0,0,2892,2895,3,620,310,0,2893,2895,3,626,313,0,2894,
  	2892,1,0,0,0,2894,2893,1,0,0,0,2895,605,1,0,0,0,2896,2897,3,638,319,0,
  	2897,2899,3,1144,572,0,2898,2900,5,318,0,0,2899,2898,1,0,0,0,2899,2900,
  	1,0,0,0,2900,2901,1,0,0,0,2901,2902,3,608,304,0,2902,2903,3,640,320,0,
  	2903,607,1,0,0,0,2904,2906,3,1072,536,0,2905,2907,3,610,305,0,2906,2905,
  	1,0,0,0,2906,2907,1,0,0,0,2907,2910,1,0,0,0,2908,2910,3,610,305,0,2909,
  	2904,1,0,0,0,2909,2908,1,0,0,0,2910,609,1,0,0,0,2911,2913,3,614,307,0,
  	2912,2914,3,612,306,0,2913,2912,1,0,0,0,2913,2914,1,0,0,0,2914,2917,1,
  	0,0,0,2915,2917,3,612,306,0,2916,2911,1,0,0,0,2916,2915,1,0,0,0,2917,
  	611,1,0,0,0,2918,2924,3,616,308,0,2919,2924,3,618,309,0,2920,2921,3,616,
  	308,0,2921,2922,3,618,309,0,2922,2924,1,0,0,0,2923,2918,1,0,0,0,2923,
  	2919,1,0,0,0,2923,2920,1,0,0,0,2924,613,1,0,0,0,2925,2927,3,660,330,0,
  	2926,2925,1,0,0,0,2926,2927,1,0,0,0,2927,2928,1,0,0,0,2928,2929,5,1,0,
  	0,2929,615,1,0,0,0,2930,2931,3,660,330,0,2931,617,1,0,0,0,2932,2933,3,
  	664,332,0,2933,619,1,0,0,0,2934,2937,3,622,311,0,2935,2937,3,624,312,
  	0,2936,2934,1,0,0,0,2936,2935,1,0,0,0,2937,621,1,0,0,0,2938,2939,3,634,
  	317,0,2939,2940,3,628,314,0,2940,2941,3,636,318,0,2941,623,1,0,0,0,2942,
  	2943,3,636,318,0,2943,2944,3,630,315,0,2944,2945,3,634,317,0,2945,625,
  	1,0,0,0,2946,2947,3,634,317,0,2947,2948,3,632,316,0,2948,2949,3,636,318,
  	0,2949,627,1,0,0,0,2950,2951,5,344,0,0,2951,2952,3,610,305,0,2952,2953,
  	5,329,0,0,2953,629,1,0,0,0,2954,2955,5,338,0,0,2955,2956,3,610,305,0,
  	2956,2957,5,348,0,0,2957,631,1,0,0,0,2958,2959,5,355,0,0,2959,2960,3,
  	610,305,0,2960,2961,5,349,0,0,2961,633,1,0,0,0,2962,2963,5,371,0,0,2963,
  	2964,3,656,328,0,2964,2965,5,382,0,0,2965,2972,1,0,0,0,2966,2968,5,371,
  	0,0,2967,2969,3,590,295,0,2968,2967,1,0,0,0,2968,2969,1,0,0,0,2969,2970,
  	1,0,0,0,2970,2972,5,382,0,0,2971,2962,1,0,0,0,2971,2966,1,0,0,0,2972,
  	635,1,0,0,0,2973,2974,5,371,0,0,2974,2975,3,658,329,0,2975,2976,5,382,
  	0,0,2976,2983,1,0,0,0,2977,2979,5,371,0,0,2978,2980,3,590,295,0,2979,
  	2978,1,0,0,0,2979,2980,1,0,0,0,2980,2981,1,0,0,0,2981,2983,5,382,0,0,
  	2982,2973,1,0,0,0,2982,2977,1,0,0,0,2983,637,1,0,0,0,2984,2985,7,13,0,
  	0,2985,639,1,0,0,0,2986,2987,5,280,0,0,2987,2988,3,642,321,0,2988,641,
  	1,0,0,0,2989,2992,3,644,322,0,2990,2992,3,650,325,0,2991,2989,1,0,0,0,
  	2991,2990,1,0,0,0,2992,643,1,0,0,0,2993,2996,3,646,323,0,2994,2996,3,
  	648,324,0,2995,2993,1,0,0,0,2995,2994,1,0,0,0,2996,645,1,0,0,0,2997,2998,
  	5,371,0,0,2998,2999,3,656,328,0,2999,3000,3,652,326,0,3000,3001,3,658,
  	329,0,3001,3002,5,382,0,0,3002,647,1,0,0,0,3003,3004,5,371,0,0,3004,3005,
  	3,658,329,0,3005,3006,5,336,0,0,3006,3007,3,656,328,0,3007,3008,5,382,
  	0,0,3008,649,1,0,0,0,3009,3010,5,371,0,0,3010,3011,3,656,328,0,3011,3012,
  	3,654,327,0,3012,3013,3,658,329,0,3013,3014,5,382,0,0,3014,651,1,0,0,
  	0,3015,3016,7,14,0,0,3016,653,1,0,0,0,3017,3018,7,15,0,0,3018,655,1,0,
  	0,0,3019,3020,3,1112,556,0,3020,657,1,0,0,0,3021,3022,3,1112,556,0,3022,
  	659,1,0,0,0,3023,3024,5,292,0,0,3024,3031,3,1080,540,0,3025,3026,5,294,
  	0,0,3026,3031,3,662,331,0,3027,3028,3,390,195,0,3028,3029,3,662,331,0,
  	3029,3031,1,0,0,0,3030,3023,1,0,0,0,3030,3025,1,0,0,0,3030,3027,1,0,0,
  	0,3031,661,1,0,0,0,3032,3037,3,1080,540,0,3033,3034,5,358,0,0,3034,3036,
  	3,1080,540,0,3035,3033,1,0,0,0,3036,3039,1,0,0,0,3037,3035,1,0,0,0,3037,
  	3038,1,0,0,0,3038,663,1,0,0,0,3039,3037,1,0,0,0,3040,3042,5,369,0,0,3041,
  	3043,3,666,333,0,3042,3041,1,0,0,0,3042,3043,1,0,0,0,3043,3044,1,0,0,
  	0,3044,3045,5,380,0,0,3045,665,1,0,0,0,3046,3051,3,668,334,0,3047,3048,
  	5,361,0,0,3048,3050,3,668,334,0,3049,3047,1,0,0,0,3050,3053,1,0,0,0,3051,
  	3049,1,0,0,0,3051,3052,1,0,0,0,3052,667,1,0,0,0,3053,3051,1,0,0,0,3054,
  	3056,3,1082,541,0,3055,3057,3,676,338,0,3056,3055,1,0,0,0,3056,3057,1,
  	0,0,0,3057,3058,1,0,0,0,3058,3059,3,670,335,0,3059,669,1,0,0,0,3060,3061,
  	3,674,337,0,3061,671,1,0,0,0,3062,3064,5,278,0,0,3063,3062,1,0,0,0,3063,
  	3064,1,0,0,0,3064,3065,1,0,0,0,3065,3066,5,313,0,0,3066,3067,3,766,383,
  	0,3067,673,1,0,0,0,3068,3069,6,337,-1,0,3069,3126,3,678,339,0,3070,3126,
  	3,758,379,0,3071,3072,3,760,380,0,3072,3073,5,372,0,0,3073,3074,3,674,
  	337,0,3074,3079,5,367,0,0,3075,3076,5,370,0,0,3076,3077,3,688,344,0,3077,
  	3078,5,381,0,0,3078,3080,1,0,0,0,3079,3075,1,0,0,0,3079,3080,1,0,0,0,
  	3080,3082,1,0,0,0,3081,3083,3,770,385,0,3082,3081,1,0,0,0,3082,3083,1,
  	0,0,0,3083,3126,1,0,0,0,3084,3089,3,760,380,0,3085,3086,5,370,0,0,3086,
  	3087,3,688,344,0,3087,3088,5,381,0,0,3088,3090,1,0,0,0,3089,3085,1,0,
  	0,0,3089,3090,1,0,0,0,3090,3092,1,0,0,0,3091,3093,3,770,385,0,3092,3091,
  	1,0,0,0,3092,3093,1,0,0,0,3093,3126,1,0,0,0,3094,3126,3,764,382,0,3095,
  	3097,5,25,0,0,3096,3098,5,225,0,0,3097,3096,1,0,0,0,3097,3098,1,0,0,0,
  	3098,3100,1,0,0,0,3099,3101,3,770,385,0,3100,3099,1,0,0,0,3100,3101,1,
  	0,0,0,3101,3126,1,0,0,0,3102,3104,5,25,0,0,3103,3102,1,0,0,0,3103,3104,
  	1,0,0,0,3104,3105,1,0,0,0,3105,3106,5,305,0,0,3106,3108,5,225,0,0,3107,
  	3109,3,770,385,0,3108,3107,1,0,0,0,3108,3109,1,0,0,0,3109,3126,1,0,0,
  	0,3110,3112,5,25,0,0,3111,3113,5,225,0,0,3112,3111,1,0,0,0,3112,3113,
  	1,0,0,0,3113,3114,1,0,0,0,3114,3115,5,372,0,0,3115,3120,3,674,337,0,3116,
  	3117,5,386,0,0,3117,3119,3,674,337,0,3118,3116,1,0,0,0,3119,3122,1,0,
  	0,0,3120,3118,1,0,0,0,3120,3121,1,0,0,0,3121,3123,1,0,0,0,3122,3120,1,
  	0,0,0,3123,3124,5,367,0,0,3124,3126,1,0,0,0,3125,3068,1,0,0,0,3125,3070,
  	1,0,0,0,3125,3071,1,0,0,0,3125,3084,1,0,0,0,3125,3094,1,0,0,0,3125,3095,
  	1,0,0,0,3125,3103,1,0,0,0,3125,3110,1,0,0,0,3126,3143,1,0,0,0,3127,3128,
  	10,1,0,0,3128,3129,5,386,0,0,3129,3142,3,674,337,2,3130,3131,10,7,0,0,
  	3131,3136,3,760,380,0,3132,3133,5,370,0,0,3133,3134,3,688,344,0,3134,
  	3135,5,381,0,0,3135,3137,1,0,0,0,3136,3132,1,0,0,0,3136,3137,1,0,0,0,
  	3137,3139,1,0,0,0,3138,3140,3,770,385,0,3139,3138,1,0,0,0,3139,3140,1,
  	0,0,0,3140,3142,1,0,0,0,3141,3127,1,0,0,0,3141,3130,1,0,0,0,3142,3145,
  	1,0,0,0,3143,3141,1,0,0,0,3143,3144,1,0,0,0,3144,675,1,0,0,0,3145,3143,
  	1,0,0,0,3146,3147,7,16,0,0,3147,677,1,0,0,0,3148,3156,3,680,340,0,3149,
  	3156,3,682,341,0,3150,3156,3,684,342,0,3151,3156,3,692,346,0,3152,3156,
  	3,712,356,0,3153,3156,3,730,365,0,3154,3156,3,732,366,0,3155,3148,1,0,
  	0,0,3155,3149,1,0,0,0,3155,3150,1,0,0,0,3155,3151,1,0,0,0,3155,3152,1,
  	0,0,0,3155,3153,1,0,0,0,3155,3154,1,0,0,0,3156,679,1,0,0,0,3157,3159,
  	7,17,0,0,3158,3160,3,770,385,0,3159,3158,1,0,0,0,3159,3160,1,0,0,0,3160,
  	681,1,0,0,0,3161,3171,5,202,0,0,3162,3166,5,371,0,0,3163,3164,3,686,343,
  	0,3164,3165,5,361,0,0,3165,3167,1,0,0,0,3166,3163,1,0,0,0,3166,3167,1,
  	0,0,0,3167,3168,1,0,0,0,3168,3169,3,688,344,0,3169,3170,5,382,0,0,3170,
  	3172,1,0,0,0,3171,3162,1,0,0,0,3171,3172,1,0,0,0,3172,3174,1,0,0,0,3173,
  	3175,3,770,385,0,3174,3173,1,0,0,0,3174,3175,1,0,0,0,3175,3197,1,0,0,
  	0,3176,3181,5,50,0,0,3177,3178,5,371,0,0,3178,3179,3,690,345,0,3179,3180,
  	5,382,0,0,3180,3182,1,0,0,0,3181,3177,1,0,0,0,3181,3182,1,0,0,0,3182,
  	3184,1,0,0,0,3183,3185,3,770,385,0,3184,3183,1,0,0,0,3184,3185,1,0,0,
  	0,3185,3197,1,0,0,0,3186,3191,5,227,0,0,3187,3188,5,371,0,0,3188,3189,
  	3,688,344,0,3189,3190,5,382,0,0,3190,3192,1,0,0,0,3191,3187,1,0,0,0,3191,
  	3192,1,0,0,0,3192,3194,1,0,0,0,3193,3195,3,770,385,0,3194,3193,1,0,0,
  	0,3194,3195,1,0,0,0,3195,3197,1,0,0,0,3196,3161,1,0,0,0,3196,3176,1,0,
  	0,0,3196,3186,1,0,0,0,3197,683,1,0,0,0,3198,3208,5,43,0,0,3199,3203,5,
  	371,0,0,3200,3201,3,686,343,0,3201,3202,5,361,0,0,3202,3204,1,0,0,0,3203,
  	3200,1,0,0,0,3203,3204,1,0,0,0,3204,3205,1,0,0,0,3205,3206,3,688,344,
  	0,3206,3207,5,382,0,0,3207,3209,1,0,0,0,3208,3199,1,0,0,0,3208,3209,1,
  	0,0,0,3209,3211,1,0,0,0,3210,3212,3,770,385,0,3211,3210,1,0,0,0,3211,
  	3212,1,0,0,0,3212,3234,1,0,0,0,3213,3218,5,36,0,0,3214,3215,5,371,0,0,
  	3215,3216,3,690,345,0,3216,3217,5,382,0,0,3217,3219,1,0,0,0,3218,3214,
  	1,0,0,0,3218,3219,1,0,0,0,3219,3221,1,0,0,0,3220,3222,3,770,385,0,3221,
  	3220,1,0,0,0,3221,3222,1,0,0,0,3222,3234,1,0,0,0,3223,3228,5,226,0,0,
  	3224,3225,5,371,0,0,3225,3226,3,688,344,0,3226,3227,5,382,0,0,3227,3229,
  	1,0,0,0,3228,3224,1,0,0,0,3228,3229,1,0,0,0,3229,3231,1,0,0,0,3230,3232,
  	3,770,385,0,3231,3230,1,0,0,0,3231,3232,1,0,0,0,3232,3234,1,0,0,0,3233,
  	3198,1,0,0,0,3233,3213,1,0,0,0,3233,3223,1,0,0,0,3234,685,1,0,0,0,3235,
  	3236,3,1124,562,0,3236,687,1,0,0,0,3237,3238,3,1124,562,0,3238,689,1,
  	0,0,0,3239,3240,3,1124,562,0,3240,691,1,0,0,0,3241,3244,3,694,347,0,3242,
  	3244,3,710,355,0,3243,3241,1,0,0,0,3243,3242,1,0,0,0,3244,693,1,0,0,0,
  	3245,3248,3,696,348,0,3246,3248,3,704,352,0,3247,3245,1,0,0,0,3247,3246,
  	1,0,0,0,3248,695,1,0,0,0,3249,3252,3,698,349,0,3250,3252,3,700,350,0,
  	3251,3249,1,0,0,0,3251,3250,1,0,0,0,3252,697,1,0,0,0,3253,3255,5,113,
  	0,0,3254,3256,3,770,385,0,3255,3254,1,0,0,0,3255,3256,1,0,0,0,3256,3300,
  	1,0,0,0,3257,3259,5,115,0,0,3258,3260,3,770,385,0,3259,3258,1,0,0,0,3259,
  	3260,1,0,0,0,3260,3300,1,0,0,0,3261,3263,5,117,0,0,3262,3264,3,770,385,
  	0,3263,3262,1,0,0,0,3263,3264,1,0,0,0,3264,3300,1,0,0,0,3265,3267,5,119,
  	0,0,3266,3268,3,770,385,0,3267,3266,1,0,0,0,3267,3268,1,0,0,0,3268,3300,
  	1,0,0,0,3269,3271,5,121,0,0,3270,3272,3,770,385,0,3271,3270,1,0,0,0,3271,
  	3272,1,0,0,0,3272,3300,1,0,0,0,3273,3275,5,123,0,0,3274,3276,3,770,385,
  	0,3275,3274,1,0,0,0,3275,3276,1,0,0,0,3276,3300,1,0,0,0,3277,3279,5,197,
  	0,0,3278,3280,3,770,385,0,3279,3278,1,0,0,0,3279,3280,1,0,0,0,3280,3300,
  	1,0,0,0,3281,3286,5,111,0,0,3282,3283,5,371,0,0,3283,3284,3,706,353,0,
  	3284,3285,5,382,0,0,3285,3287,1,0,0,0,3286,3282,1,0,0,0,3286,3287,1,0,
  	0,0,3287,3289,1,0,0,0,3288,3290,3,770,385,0,3289,3288,1,0,0,0,3289,3290,
  	1,0,0,0,3290,3300,1,0,0,0,3291,3293,5,35,0,0,3292,3294,3,770,385,0,3293,
  	3292,1,0,0,0,3293,3294,1,0,0,0,3294,3300,1,0,0,0,3295,3297,5,191,0,0,
  	3296,3295,1,0,0,0,3296,3297,1,0,0,0,3297,3298,1,0,0,0,3298,3300,3,702,
  	351,0,3299,3253,1,0,0,0,3299,3257,1,0,0,0,3299,3261,1,0,0,0,3299,3265,
  	1,0,0,0,3299,3269,1,0,0,0,3299,3273,1,0,0,0,3299,3277,1,0,0,0,3299,3281,
  	1,0,0,0,3299,3291,1,0,0,0,3299,3296,1,0,0,0,3300,699,1,0,0,0,3301,3303,
  	5,214,0,0,3302,3304,3,770,385,0,3303,3302,1,0,0,0,3303,3304,1,0,0,0,3304,
  	3346,1,0,0,0,3305,3307,5,215,0,0,3306,3308,3,770,385,0,3307,3306,1,0,
  	0,0,3307,3308,1,0,0,0,3308,3346,1,0,0,0,3309,3311,5,216,0,0,3310,3312,
  	3,770,385,0,3311,3310,1,0,0,0,3311,3312,1,0,0,0,3312,3346,1,0,0,0,3313,
  	3315,5,217,0,0,3314,3316,3,770,385,0,3315,3314,1,0,0,0,3315,3316,1,0,
  	0,0,3316,3346,1,0,0,0,3317,3319,5,218,0,0,3318,3320,3,770,385,0,3319,
  	3318,1,0,0,0,3319,3320,1,0,0,0,3320,3346,1,0,0,0,3321,3323,5,219,0,0,
  	3322,3324,3,770,385,0,3323,3322,1,0,0,0,3323,3324,1,0,0,0,3324,3346,1,
  	0,0,0,3325,3327,5,224,0,0,3326,3328,3,770,385,0,3327,3326,1,0,0,0,3327,
  	3328,1,0,0,0,3328,3346,1,0,0,0,3329,3334,5,213,0,0,3330,3331,5,371,0,
  	0,3331,3332,3,706,353,0,3332,3333,5,382,0,0,3333,3335,1,0,0,0,3334,3330,
  	1,0,0,0,3334,3335,1,0,0,0,3335,3337,1,0,0,0,3336,3338,3,770,385,0,3337,
  	3336,1,0,0,0,3337,3338,1,0,0,0,3338,3346,1,0,0,0,3339,3341,5,212,0,0,
  	3340,3342,3,770,385,0,3341,3340,1,0,0,0,3341,3342,1,0,0,0,3342,3346,1,
  	0,0,0,3343,3344,5,221,0,0,3344,3346,3,702,351,0,3345,3301,1,0,0,0,3345,
  	3305,1,0,0,0,3345,3309,1,0,0,0,3345,3313,1,0,0,0,3345,3317,1,0,0,0,3345,
  	3321,1,0,0,0,3345,3325,1,0,0,0,3345,3329,1,0,0,0,3345,3339,1,0,0,0,3345,
  	3343,1,0,0,0,3346,701,1,0,0,0,3347,3349,5,114,0,0,3348,3350,3,770,385,
  	0,3349,3348,1,0,0,0,3349,3350,1,0,0,0,3350,3392,1,0,0,0,3351,3353,5,116,
  	0,0,3352,3354,3,770,385,0,3353,3352,1,0,0,0,3353,3354,1,0,0,0,3354,3392,
  	1,0,0,0,3355,3357,5,118,0,0,3356,3358,3,770,385,0,3357,3356,1,0,0,0,3357,
  	3358,1,0,0,0,3358,3392,1,0,0,0,3359,3361,5,120,0,0,3360,3362,3,770,385,
  	0,3361,3360,1,0,0,0,3361,3362,1,0,0,0,3362,3392,1,0,0,0,3363,3365,5,122,
  	0,0,3364,3366,3,770,385,0,3365,3364,1,0,0,0,3365,3366,1,0,0,0,3366,3392,
  	1,0,0,0,3367,3369,5,124,0,0,3368,3370,3,770,385,0,3369,3368,1,0,0,0,3369,
  	3370,1,0,0,0,3370,3392,1,0,0,0,3371,3372,5,196,0,0,3372,3374,5,112,0,
  	0,3373,3375,3,770,385,0,3374,3373,1,0,0,0,3374,3375,1,0,0,0,3375,3392,
  	1,0,0,0,3376,3381,5,112,0,0,3377,3378,5,371,0,0,3378,3379,3,706,353,0,
  	3379,3380,5,382,0,0,3380,3382,1,0,0,0,3381,3377,1,0,0,0,3381,3382,1,0,
  	0,0,3382,3384,1,0,0,0,3383,3385,3,770,385,0,3384,3383,1,0,0,0,3384,3385,
  	1,0,0,0,3385,3392,1,0,0,0,3386,3387,5,34,0,0,3387,3389,5,112,0,0,3388,
  	3390,3,770,385,0,3389,3388,1,0,0,0,3389,3390,1,0,0,0,3390,3392,1,0,0,
  	0,3391,3347,1,0,0,0,3391,3351,1,0,0,0,3391,3355,1,0,0,0,3391,3359,1,0,
  	0,0,3391,3363,1,0,0,0,3391,3367,1,0,0,0,3391,3371,1,0,0,0,3391,3376,1,
  	0,0,0,3391,3386,1,0,0,0,3392,703,1,0,0,0,3393,3404,7,18,0,0,3394,3395,
  	5,371,0,0,3395,3398,3,706,353,0,3396,3397,5,361,0,0,3397,3399,3,708,354,
  	0,3398,3396,1,0,0,0,3398,3399,1,0,0,0,3399,3400,1,0,0,0,3400,3402,5,382,
  	0,0,3401,3403,3,770,385,0,3402,3401,1,0,0,0,3402,3403,1,0,0,0,3403,3405,
  	1,0,0,0,3404,3394,1,0,0,0,3404,3405,1,0,0,0,3405,705,1,0,0,0,3406,3407,
  	3,1126,563,0,3407,707,1,0,0,0,3408,3409,3,1126,563,0,3409,709,1,0,0,0,
  	3410,3412,5,94,0,0,3411,3413,3,770,385,0,3412,3411,1,0,0,0,3412,3413,
  	1,0,0,0,3413,3456,1,0,0,0,3414,3416,5,95,0,0,3415,3417,3,770,385,0,3416,
  	3415,1,0,0,0,3416,3417,1,0,0,0,3417,3456,1,0,0,0,3418,3420,5,96,0,0,3419,
  	3421,3,770,385,0,3420,3419,1,0,0,0,3420,3421,1,0,0,0,3421,3456,1,0,0,
  	0,3422,3424,5,97,0,0,3423,3425,3,770,385,0,3424,3423,1,0,0,0,3424,3425,
  	1,0,0,0,3425,3456,1,0,0,0,3426,3428,5,98,0,0,3427,3429,3,770,385,0,3428,
  	3427,1,0,0,0,3428,3429,1,0,0,0,3429,3456,1,0,0,0,3430,3439,5,93,0,0,3431,
  	3432,5,371,0,0,3432,3435,3,706,353,0,3433,3434,5,361,0,0,3434,3436,3,
  	708,354,0,3435,3433,1,0,0,0,3435,3436,1,0,0,0,3436,3437,1,0,0,0,3437,
  	3438,5,382,0,0,3438,3440,1,0,0,0,3439,3431,1,0,0,0,3439,3440,1,0,0,0,
  	3440,3442,1,0,0,0,3441,3443,3,770,385,0,3442,3441,1,0,0,0,3442,3443,1,
  	0,0,0,3443,3456,1,0,0,0,3444,3446,5,175,0,0,3445,3447,3,770,385,0,3446,
  	3445,1,0,0,0,3446,3447,1,0,0,0,3447,3456,1,0,0,0,3448,3450,5,81,0,0,3449,
  	3451,5,172,0,0,3450,3449,1,0,0,0,3450,3451,1,0,0,0,3451,3453,1,0,0,0,
  	3452,3454,3,770,385,0,3453,3452,1,0,0,0,3453,3454,1,0,0,0,3454,3456,1,
  	0,0,0,3455,3410,1,0,0,0,3455,3414,1,0,0,0,3455,3418,1,0,0,0,3455,3422,
  	1,0,0,0,3455,3426,1,0,0,0,3455,3430,1,0,0,0,3455,3444,1,0,0,0,3455,3448,
  	1,0,0,0,3456,711,1,0,0,0,3457,3460,3,714,357,0,3458,3460,3,726,363,0,
  	3459,3457,1,0,0,0,3459,3458,1,0,0,0,3460,713,1,0,0,0,3461,3467,3,716,
  	358,0,3462,3467,3,718,359,0,3463,3467,3,720,360,0,3464,3467,3,722,361,
  	0,3465,3467,3,724,362,0,3466,3461,1,0,0,0,3466,3462,1,0,0,0,3466,3463,
  	1,0,0,0,3466,3464,1,0,0,0,3466,3465,1,0,0,0,3467,715,1,0,0,0,3468,3469,
  	5,235,0,0,3469,3471,5,71,0,0,3470,3472,3,770,385,0,3471,3470,1,0,0,0,
  	3471,3472,1,0,0,0,3472,3481,1,0,0,0,3473,3474,5,208,0,0,3474,3475,5,231,
  	0,0,3475,3476,5,207,0,0,3476,3478,5,324,0,0,3477,3479,3,770,385,0,3478,
  	3477,1,0,0,0,3478,3479,1,0,0,0,3479,3481,1,0,0,0,3480,3468,1,0,0,0,3480,
  	3473,1,0,0,0,3481,717,1,0,0,0,3482,3483,5,135,0,0,3483,3485,5,71,0,0,
  	3484,3486,3,770,385,0,3485,3484,1,0,0,0,3485,3486,1,0,0,0,3486,3497,1,
  	0,0,0,3487,3491,5,208,0,0,3488,3489,5,322,0,0,3489,3490,5,207,0,0,3490,
  	3492,5,324,0,0,3491,3488,1,0,0,0,3491,3492,1,0,0,0,3492,3494,1,0,0,0,
  	3493,3495,3,770,385,0,3494,3493,1,0,0,0,3494,3495,1,0,0,0,3495,3497,1,
  	0,0,0,3496,3482,1,0,0,0,3496,3487,1,0,0,0,3497,719,1,0,0,0,3498,3500,
  	5,70,0,0,3499,3501,3,770,385,0,3500,3499,1,0,0,0,3500,3501,1,0,0,0,3501,
  	721,1,0,0,0,3502,3503,5,235,0,0,3503,3505,5,207,0,0,3504,3506,3,770,385,
  	0,3505,3504,1,0,0,0,3505,3506,1,0,0,0,3506,3515,1,0,0,0,3507,3508,5,207,
  	0,0,3508,3509,5,231,0,0,3509,3510,5,207,0,0,3510,3512,5,324,0,0,3511,
  	3513,3,770,385,0,3512,3511,1,0,0,0,3512,3513,1,0,0,0,3513,3515,1,0,0,
  	0,3514,3502,1,0,0,0,3514,3507,1,0,0,0,3515,723,1,0,0,0,3516,3517,5,135,
  	0,0,3517,3519,5,207,0,0,3518,3520,3,770,385,0,3519,3518,1,0,0,0,3519,
  	3520,1,0,0,0,3520,3529,1,0,0,0,3521,3522,5,207,0,0,3522,3523,5,322,0,
  	0,3523,3524,5,207,0,0,3524,3526,5,324,0,0,3525,3527,3,770,385,0,3526,
  	3525,1,0,0,0,3526,3527,1,0,0,0,3527,3529,1,0,0,0,3528,3516,1,0,0,0,3528,
  	3521,1,0,0,0,3529,725,1,0,0,0,3530,3531,5,83,0,0,3531,3532,5,371,0,0,
  	3532,3533,3,728,364,0,3533,3535,5,382,0,0,3534,3536,3,770,385,0,3535,
  	3534,1,0,0,0,3535,3536,1,0,0,0,3536,727,1,0,0,0,3537,3538,5,233,0,0,3538,
  	3539,5,315,0,0,3539,3544,5,148,0,0,3540,3541,5,72,0,0,3541,3542,5,315,
  	0,0,3542,3544,5,186,0,0,3543,3537,1,0,0,0,3543,3540,1,0,0,0,3544,729,
  	1,0,0,0,3545,3550,3,738,369,0,3546,3550,3,744,372,0,3547,3550,3,746,373,
  	0,3548,3550,3,752,376,0,3549,3545,1,0,0,0,3549,3546,1,0,0,0,3549,3547,
  	1,0,0,0,3549,3548,1,0,0,0,3550,731,1,0,0,0,3551,3554,3,734,367,0,3552,
  	3554,3,736,368,0,3553,3551,1,0,0,0,3553,3552,1,0,0,0,3554,733,1,0,0,0,
  	3555,3556,5,154,0,0,3556,735,1,0,0,0,3557,3558,5,154,0,0,3558,3561,3,
  	770,385,0,3559,3561,5,153,0,0,3560,3557,1,0,0,0,3560,3559,1,0,0,0,3561,
  	737,1,0,0,0,3562,3565,3,742,371,0,3563,3565,3,740,370,0,3564,3562,1,0,
  	0,0,3564,3563,1,0,0,0,3565,739,1,0,0,0,3566,3568,5,305,0,0,3567,3566,
  	1,0,0,0,3567,3568,1,0,0,0,3568,3569,1,0,0,0,3569,3570,5,289,0,0,3570,
  	3572,3,574,287,0,3571,3573,3,770,385,0,3572,3571,1,0,0,0,3572,3573,1,
  	0,0,0,3573,741,1,0,0,0,3574,3576,5,25,0,0,3575,3577,5,305,0,0,3576,3575,
  	1,0,0,0,3576,3577,1,0,0,0,3577,3578,1,0,0,0,3578,3580,5,289,0,0,3579,
  	3581,3,770,385,0,3580,3579,1,0,0,0,3580,3581,1,0,0,0,3581,743,1,0,0,0,
  	3582,3584,3,672,336,0,3583,3585,3,770,385,0,3584,3583,1,0,0,0,3584,3585,
  	1,0,0,0,3585,745,1,0,0,0,3586,3589,3,750,375,0,3587,3589,3,748,374,0,
  	3588,3586,1,0,0,0,3588,3587,1,0,0,0,3589,747,1,0,0,0,3590,3592,3,582,
  	291,0,3591,3593,3,770,385,0,3592,3591,1,0,0,0,3592,3593,1,0,0,0,3593,
  	749,1,0,0,0,3594,3596,5,25,0,0,3595,3594,1,0,0,0,3595,3596,1,0,0,0,3596,
  	3597,1,0,0,0,3597,3599,3,1140,570,0,3598,3600,3,770,385,0,3599,3598,1,
  	0,0,0,3599,3600,1,0,0,0,3600,751,1,0,0,0,3601,3604,3,756,378,0,3602,3604,
  	3,754,377,0,3603,3601,1,0,0,0,3603,3602,1,0,0,0,3604,753,1,0,0,0,3605,
  	3607,3,602,301,0,3606,3608,3,770,385,0,3607,3606,1,0,0,0,3607,3608,1,
  	0,0,0,3608,755,1,0,0,0,3609,3611,5,25,0,0,3610,3609,1,0,0,0,3610,3611,
  	1,0,0,0,3611,3612,1,0,0,0,3612,3614,3,1144,572,0,3613,3615,3,770,385,
  	0,3614,3613,1,0,0,0,3614,3615,1,0,0,0,3615,757,1,0,0,0,3616,3618,5,166,
  	0,0,3617,3619,3,770,385,0,3618,3617,1,0,0,0,3618,3619,1,0,0,0,3619,759,
  	1,0,0,0,3620,3622,5,102,0,0,3621,3620,1,0,0,0,3621,3622,1,0,0,0,3622,
  	3623,1,0,0,0,3623,3624,3,762,381,0,3624,761,1,0,0,0,3625,3626,7,19,0,
  	0,3626,763,1,0,0,0,3627,3629,5,25,0,0,3628,3627,1,0,0,0,3628,3629,1,0,
  	0,0,3629,3630,1,0,0,0,3630,3632,5,176,0,0,3631,3633,3,770,385,0,3632,
  	3631,1,0,0,0,3632,3633,1,0,0,0,3633,3642,1,0,0,0,3634,3636,5,176,0,0,
  	3635,3634,1,0,0,0,3635,3636,1,0,0,0,3636,3637,1,0,0,0,3637,3639,3,766,
  	383,0,3638,3640,3,770,385,0,3639,3638,1,0,0,0,3639,3640,1,0,0,0,3640,
  	3642,1,0,0,0,3641,3628,1,0,0,0,3641,3635,1,0,0,0,3642,765,1,0,0,0,3643,
  	3645,5,369,0,0,3644,3646,3,768,384,0,3645,3644,1,0,0,0,3645,3646,1,0,
  	0,0,3646,3647,1,0,0,0,3647,3648,5,380,0,0,3648,767,1,0,0,0,3649,3654,
  	3,772,386,0,3650,3651,5,361,0,0,3651,3653,3,772,386,0,3652,3650,1,0,0,
  	0,3653,3656,1,0,0,0,3654,3652,1,0,0,0,3654,3655,1,0,0,0,3655,769,1,0,
  	0,0,3656,3654,1,0,0,0,3657,3658,5,152,0,0,3658,3659,5,154,0,0,3659,771,
  	1,0,0,0,3660,3662,3,1084,542,0,3661,3663,3,676,338,0,3662,3661,1,0,0,
  	0,3662,3663,1,0,0,0,3663,3664,1,0,0,0,3664,3665,3,674,337,0,3665,773,
  	1,0,0,0,3666,3667,3,822,411,0,3667,775,1,0,0,0,3668,3678,3,780,390,0,
  	3669,3678,3,782,391,0,3670,3678,3,786,393,0,3671,3678,3,792,396,0,3672,
  	3678,3,796,398,0,3673,3678,3,802,401,0,3674,3678,3,812,406,0,3675,3678,
  	3,814,407,0,3676,3678,3,816,408,0,3677,3668,1,0,0,0,3677,3669,1,0,0,0,
  	3677,3670,1,0,0,0,3677,3671,1,0,0,0,3677,3672,1,0,0,0,3677,3673,1,0,0,
  	0,3677,3674,1,0,0,0,3677,3675,1,0,0,0,3677,3676,1,0,0,0,3678,777,1,0,
  	0,0,3679,3680,7,20,0,0,3680,779,1,0,0,0,3681,3699,5,89,0,0,3682,3683,
  	5,369,0,0,3683,3684,3,302,151,0,3684,3685,5,380,0,0,3685,3700,1,0,0,0,
  	3686,3687,5,371,0,0,3687,3688,3,302,151,0,3688,3689,5,382,0,0,3689,3700,
  	1,0,0,0,3690,3691,5,369,0,0,3691,3692,3,220,110,0,3692,3693,5,380,0,0,
  	3693,3700,1,0,0,0,3694,3695,5,371,0,0,3695,3696,3,220,110,0,3696,3697,
  	5,382,0,0,3697,3700,1,0,0,0,3698,3700,3,56,28,0,3699,3682,1,0,0,0,3699,
  	3686,1,0,0,0,3699,3690,1,0,0,0,3699,3694,1,0,0,0,3699,3698,1,0,0,0,3700,
  	781,1,0,0,0,3701,3702,3,842,421,0,3702,3703,3,784,392,0,3703,783,1,0,
  	0,0,3704,3706,5,127,0,0,3705,3707,5,152,0,0,3706,3705,1,0,0,0,3706,3707,
  	1,0,0,0,3707,3708,1,0,0,0,3708,3709,5,154,0,0,3709,785,1,0,0,0,3710,3711,
  	3,842,421,0,3711,3712,3,788,394,0,3712,787,1,0,0,0,3713,3715,5,127,0,
  	0,3714,3716,5,152,0,0,3715,3714,1,0,0,0,3715,3716,1,0,0,0,3716,3717,1,
  	0,0,0,3717,3718,3,676,338,0,3718,3719,3,674,337,0,3719,789,1,0,0,0,3720,
  	3722,5,127,0,0,3721,3723,5,152,0,0,3722,3721,1,0,0,0,3722,3723,1,0,0,
  	0,3723,3725,1,0,0,0,3724,3726,3,1016,508,0,3725,3724,1,0,0,0,3725,3726,
  	1,0,0,0,3726,3727,1,0,0,0,3727,3728,5,302,0,0,3728,791,1,0,0,0,3729,3730,
  	3,432,216,0,3730,3731,3,794,397,0,3731,793,1,0,0,0,3732,3734,5,127,0,
  	0,3733,3735,5,152,0,0,3734,3733,1,0,0,0,3734,3735,1,0,0,0,3735,3736,1,
  	0,0,0,3736,3737,5,283,0,0,3737,795,1,0,0,0,3738,3739,3,432,216,0,3739,
  	3740,3,798,399,0,3740,797,1,0,0,0,3741,3742,3,800,400,0,3742,3743,3,428,
  	214,0,3743,799,1,0,0,0,3744,3746,5,127,0,0,3745,3747,5,152,0,0,3746,3745,
  	1,0,0,0,3746,3747,1,0,0,0,3747,3748,1,0,0,0,3748,3751,5,293,0,0,3749,
  	3751,5,360,0,0,3750,3744,1,0,0,0,3750,3749,1,0,0,0,3751,801,1,0,0,0,3752,
  	3753,3,804,402,0,3753,3754,3,806,403,0,3754,3759,1,0,0,0,3755,3756,3,
  	804,402,0,3756,3757,3,808,404,0,3757,3759,1,0,0,0,3758,3752,1,0,0,0,3758,
  	3755,1,0,0,0,3759,803,1,0,0,0,3760,3761,3,432,216,0,3761,805,1,0,0,0,
  	3762,3764,5,127,0,0,3763,3765,5,152,0,0,3764,3763,1,0,0,0,3764,3765,1,
  	0,0,0,3765,3766,1,0,0,0,3766,3767,5,312,0,0,3767,3768,5,158,0,0,3768,
  	3769,3,810,405,0,3769,807,1,0,0,0,3770,3772,5,127,0,0,3771,3773,5,152,
  	0,0,3772,3771,1,0,0,0,3772,3773,1,0,0,0,3773,3774,1,0,0,0,3774,3775,5,
  	281,0,0,3775,3776,5,158,0,0,3776,3777,3,810,405,0,3777,809,1,0,0,0,3778,
  	3779,3,432,216,0,3779,811,1,0,0,0,3780,3781,5,23,0,0,3781,3782,5,371,
  	0,0,3782,3783,3,432,216,0,3783,3784,5,361,0,0,3784,3789,3,432,216,0,3785,
  	3786,5,361,0,0,3786,3788,3,432,216,0,3787,3785,1,0,0,0,3788,3791,1,0,
  	0,0,3789,3787,1,0,0,0,3789,3790,1,0,0,0,3790,3792,1,0,0,0,3791,3789,1,
  	0,0,0,3792,3793,5,382,0,0,3793,813,1,0,0,0,3794,3795,5,184,0,0,3795,3796,
  	5,371,0,0,3796,3797,3,432,216,0,3797,3798,5,361,0,0,3798,3803,3,432,216,
  	0,3799,3800,5,361,0,0,3800,3802,3,432,216,0,3801,3799,1,0,0,0,3802,3805,
  	1,0,0,0,3803,3801,1,0,0,0,3803,3804,1,0,0,0,3804,3806,1,0,0,0,3805,3803,
  	1,0,0,0,3806,3807,5,382,0,0,3807,815,1,0,0,0,3808,3809,5,173,0,0,3809,
  	3810,5,371,0,0,3810,3811,3,432,216,0,3811,3812,5,361,0,0,3812,3813,3,
  	1082,541,0,3813,3814,5,382,0,0,3814,817,1,0,0,0,3815,3816,6,409,-1,0,
  	3816,3817,7,21,0,0,3817,3834,3,818,409,15,3818,3834,3,776,388,0,3819,
  	3820,5,152,0,0,3820,3834,3,818,409,8,3821,3823,5,305,0,0,3822,3821,1,
  	0,0,0,3822,3823,1,0,0,0,3823,3824,1,0,0,0,3824,3825,5,289,0,0,3825,3834,
  	3,88,44,0,3826,3828,5,278,0,0,3827,3826,1,0,0,0,3827,3828,1,0,0,0,3828,
  	3829,1,0,0,0,3829,3830,5,313,0,0,3830,3834,3,92,46,0,3831,3834,3,820,
  	410,0,3832,3834,3,842,421,0,3833,3815,1,0,0,0,3833,3818,1,0,0,0,3833,
  	3819,1,0,0,0,3833,3822,1,0,0,0,3833,3827,1,0,0,0,3833,3831,1,0,0,0,3833,
  	3832,1,0,0,0,3834,3864,1,0,0,0,3835,3836,10,14,0,0,3836,3837,7,22,0,0,
  	3837,3863,3,818,409,15,3838,3839,10,13,0,0,3839,3840,7,21,0,0,3840,3863,
  	3,818,409,14,3841,3842,10,12,0,0,3842,3843,5,331,0,0,3843,3863,3,818,
  	409,13,3844,3845,10,11,0,0,3845,3846,3,778,389,0,3846,3847,3,818,409,
  	12,3847,3863,1,0,0,0,3848,3849,10,6,0,0,3849,3850,5,24,0,0,3850,3863,
  	3,818,409,7,3851,3852,10,5,0,0,3852,3853,7,23,0,0,3853,3863,3,818,409,
  	6,3854,3855,10,9,0,0,3855,3863,3,790,395,0,3856,3857,10,7,0,0,3857,3859,
  	5,127,0,0,3858,3860,5,152,0,0,3859,3858,1,0,0,0,3859,3860,1,0,0,0,3860,
  	3861,1,0,0,0,3861,3863,3,950,475,0,3862,3835,1,0,0,0,3862,3838,1,0,0,
  	0,3862,3841,1,0,0,0,3862,3844,1,0,0,0,3862,3848,1,0,0,0,3862,3851,1,0,
  	0,0,3862,3854,1,0,0,0,3862,3856,1,0,0,0,3863,3866,1,0,0,0,3864,3862,1,
  	0,0,0,3864,3865,1,0,0,0,3865,819,1,0,0,0,3866,3864,1,0,0,0,3867,3874,
  	3,954,477,0,3868,3874,3,1042,521,0,3869,3874,3,1022,511,0,3870,3874,3,
  	1050,525,0,3871,3874,3,824,412,0,3872,3874,3,928,464,0,3873,3867,1,0,
  	0,0,3873,3868,1,0,0,0,3873,3869,1,0,0,0,3873,3870,1,0,0,0,3873,3871,1,
  	0,0,0,3873,3872,1,0,0,0,3874,821,1,0,0,0,3875,3876,3,818,409,0,3876,823,
  	1,0,0,0,3877,3883,3,826,413,0,3878,3883,3,828,414,0,3879,3883,3,830,415,
  	0,3880,3883,3,832,416,0,3881,3883,3,834,417,0,3882,3877,1,0,0,0,3882,
  	3878,1,0,0,0,3882,3879,1,0,0,0,3882,3880,1,0,0,0,3882,3881,1,0,0,0,3883,
  	825,1,0,0,0,3884,3885,7,24,0,0,3885,3886,5,371,0,0,3886,3887,3,818,409,
  	0,3887,3888,5,361,0,0,3888,3889,3,1018,509,0,3889,3890,5,382,0,0,3890,
  	827,1,0,0,0,3891,3892,5,210,0,0,3892,3893,5,371,0,0,3893,3894,3,1008,
  	504,0,3894,3895,5,382,0,0,3895,829,1,0,0,0,3896,3897,7,25,0,0,3897,3898,
  	5,371,0,0,3898,3899,3,818,409,0,3899,3900,5,382,0,0,3900,831,1,0,0,0,
  	3901,3902,7,26,0,0,3902,3903,5,371,0,0,3903,3906,3,818,409,0,3904,3905,
  	5,361,0,0,3905,3907,3,818,409,0,3906,3904,1,0,0,0,3906,3907,1,0,0,0,3907,
  	3908,1,0,0,0,3908,3909,5,382,0,0,3909,833,1,0,0,0,3910,3911,5,151,0,0,
  	3911,3912,5,371,0,0,3912,3915,3,818,409,0,3913,3914,5,361,0,0,3914,3916,
  	3,1016,508,0,3915,3913,1,0,0,0,3915,3916,1,0,0,0,3916,3917,1,0,0,0,3917,
  	3918,5,382,0,0,3918,835,1,0,0,0,3919,3920,3,842,421,0,3920,837,1,0,0,
  	0,3921,3922,3,842,421,0,3922,839,1,0,0,0,3923,3924,3,818,409,0,3924,841,
  	1,0,0,0,3925,3926,6,421,-1,0,3926,3937,3,844,422,0,3927,3937,3,894,447,
  	0,3928,3937,3,850,425,0,3929,3937,3,916,458,0,3930,3937,3,860,430,0,3931,
  	3937,3,862,431,0,3932,3937,3,888,444,0,3933,3937,3,910,455,0,3934,3937,
  	3,858,429,0,3935,3937,3,912,456,0,3936,3925,1,0,0,0,3936,3927,1,0,0,0,
  	3936,3928,1,0,0,0,3936,3929,1,0,0,0,3936,3930,1,0,0,0,3936,3931,1,0,0,
  	0,3936,3932,1,0,0,0,3936,3933,1,0,0,0,3936,3934,1,0,0,0,3936,3935,1,0,
  	0,0,3937,3943,1,0,0,0,3938,3939,10,7,0,0,3939,3940,5,375,0,0,3940,3942,
  	3,1082,541,0,3941,3938,1,0,0,0,3942,3945,1,0,0,0,3943,3941,1,0,0,0,3943,
  	3944,1,0,0,0,3944,843,1,0,0,0,3945,3943,1,0,0,0,3946,3947,5,371,0,0,3947,
  	3948,3,818,409,0,3948,3949,5,382,0,0,3949,845,1,0,0,0,3950,3953,3,848,
  	424,0,3951,3953,3,912,456,0,3952,3950,1,0,0,0,3952,3951,1,0,0,0,3953,
  	847,1,0,0,0,3954,3967,3,894,447,0,3955,3967,3,850,425,0,3956,3967,3,916,
  	458,0,3957,3958,3,842,421,0,3958,3959,5,375,0,0,3959,3960,3,1082,541,
  	0,3960,3967,1,0,0,0,3961,3967,3,860,430,0,3962,3967,3,862,431,0,3963,
  	3967,3,888,444,0,3964,3967,3,910,455,0,3965,3967,3,858,429,0,3966,3954,
  	1,0,0,0,3966,3955,1,0,0,0,3966,3956,1,0,0,0,3966,3957,1,0,0,0,3966,3961,
  	1,0,0,0,3966,3962,1,0,0,0,3966,3963,1,0,0,0,3966,3964,1,0,0,0,3966,3965,
  	1,0,0,0,3967,849,1,0,0,0,3968,3971,3,1094,547,0,3969,3971,3,854,427,0,
  	3970,3968,1,0,0,0,3970,3969,1,0,0,0,3971,851,1,0,0,0,3972,3975,3,1124,
  	562,0,3973,3975,3,856,428,0,3974,3972,1,0,0,0,3974,3973,1,0,0,0,3975,
  	853,1,0,0,0,3976,3979,3,856,428,0,3977,3979,5,189,0,0,3978,3976,1,0,0,
  	0,3978,3977,1,0,0,0,3979,855,1,0,0,0,3980,3981,5,327,0,0,3981,857,1,0,
  	0,0,3982,3983,5,130,0,0,3983,3984,3,228,114,0,3984,3985,5,109,0,0,3985,
  	3986,3,818,409,0,3986,3987,5,87,0,0,3987,859,1,0,0,0,3988,3989,5,225,
  	0,0,3989,3990,3,56,28,0,3990,861,1,0,0,0,3991,3994,3,864,432,0,3992,3994,
  	3,866,433,0,3993,3991,1,0,0,0,3993,3992,1,0,0,0,3994,863,1,0,0,0,3995,
  	3996,5,156,0,0,3996,3997,5,371,0,0,3997,3998,3,818,409,0,3998,3999,5,
  	361,0,0,3999,4000,3,818,409,0,4000,4001,5,382,0,0,4001,4014,1,0,0,0,4002,
  	4003,5,55,0,0,4003,4004,5,371,0,0,4004,4007,3,818,409,0,4005,4006,5,361,
  	0,0,4006,4008,3,818,409,0,4007,4005,1,0,0,0,4008,4009,1,0,0,0,4009,4007,
  	1,0,0,0,4009,4010,1,0,0,0,4010,4011,1,0,0,0,4011,4012,5,382,0,0,4012,
  	4014,1,0,0,0,4013,3995,1,0,0,0,4013,4002,1,0,0,0,4014,865,1,0,0,0,4015,
  	4018,3,868,434,0,4016,4018,3,870,435,0,4017,4015,1,0,0,0,4017,4016,1,
  	0,0,0,4018,867,1,0,0,0,4019,4020,5,46,0,0,4020,4022,3,878,439,0,4021,
  	4023,3,872,436,0,4022,4021,1,0,0,0,4023,4024,1,0,0,0,4024,4022,1,0,0,
  	0,4024,4025,1,0,0,0,4025,4027,1,0,0,0,4026,4028,3,876,438,0,4027,4026,
  	1,0,0,0,4027,4028,1,0,0,0,4028,4029,1,0,0,0,4029,4030,5,87,0,0,4030,869,
  	1,0,0,0,4031,4033,5,46,0,0,4032,4034,3,874,437,0,4033,4032,1,0,0,0,4034,
  	4035,1,0,0,0,4035,4033,1,0,0,0,4035,4036,1,0,0,0,4036,4038,1,0,0,0,4037,
  	4039,3,876,438,0,4038,4037,1,0,0,0,4038,4039,1,0,0,0,4039,4040,1,0,0,
  	0,4040,4041,5,87,0,0,4041,871,1,0,0,0,4042,4043,5,229,0,0,4043,4044,3,
  	880,440,0,4044,4045,5,206,0,0,4045,4046,3,884,442,0,4046,873,1,0,0,0,
  	4047,4048,5,229,0,0,4048,4049,3,774,387,0,4049,4050,5,206,0,0,4050,4051,
  	3,884,442,0,4051,875,1,0,0,0,4052,4053,5,86,0,0,4053,4054,3,884,442,0,
  	4054,877,1,0,0,0,4055,4058,3,846,423,0,4056,4058,3,432,216,0,4057,4055,
  	1,0,0,0,4057,4056,1,0,0,0,4058,879,1,0,0,0,4059,4064,3,882,441,0,4060,
  	4061,5,361,0,0,4061,4063,3,882,441,0,4062,4060,1,0,0,0,4063,4066,1,0,
  	0,0,4064,4062,1,0,0,0,4064,4065,1,0,0,0,4065,881,1,0,0,0,4066,4064,1,
  	0,0,0,4067,4079,3,846,423,0,4068,4069,3,778,389,0,4069,4070,3,818,409,
  	0,4070,4079,1,0,0,0,4071,4079,3,784,392,0,4072,4079,3,788,394,0,4073,
  	4079,3,790,395,0,4074,4079,3,794,397,0,4075,4079,3,798,399,0,4076,4079,
  	3,806,403,0,4077,4079,3,808,404,0,4078,4067,1,0,0,0,4078,4068,1,0,0,0,
  	4078,4071,1,0,0,0,4078,4072,1,0,0,0,4078,4073,1,0,0,0,4078,4074,1,0,0,
  	0,4078,4075,1,0,0,0,4078,4076,1,0,0,0,4078,4077,1,0,0,0,4079,883,1,0,
  	0,0,4080,4083,3,886,443,0,4081,4083,3,1128,564,0,4082,4080,1,0,0,0,4082,
  	4081,1,0,0,0,4083,885,1,0,0,0,4084,4085,3,818,409,0,4085,887,1,0,0,0,
  	4086,4087,5,47,0,0,4087,4088,5,371,0,0,4088,4089,3,890,445,0,4089,4090,
  	5,27,0,0,4090,4091,3,892,446,0,4091,4092,5,382,0,0,4092,889,1,0,0,0,4093,
  	4096,3,818,409,0,4094,4096,3,1128,564,0,4095,4093,1,0,0,0,4095,4094,1,
  	0,0,0,4096,891,1,0,0,0,4097,4098,3,674,337,0,4098,893,1,0,0,0,4099,4100,
  	5,62,0,0,4100,4101,5,371,0,0,4101,4102,5,359,0,0,4102,4106,5,382,0,0,
  	4103,4106,3,896,448,0,4104,4106,3,898,449,0,4105,4099,1,0,0,0,4105,4103,
  	1,0,0,0,4105,4104,1,0,0,0,4106,895,1,0,0,0,4107,4108,3,900,450,0,4108,
  	4110,5,371,0,0,4109,4111,3,902,451,0,4110,4109,1,0,0,0,4110,4111,1,0,
  	0,0,4111,4112,1,0,0,0,4112,4113,3,818,409,0,4113,4114,5,382,0,0,4114,
  	897,1,0,0,0,4115,4116,3,904,452,0,4116,4117,5,371,0,0,4117,4118,3,906,
  	453,0,4118,4119,5,361,0,0,4119,4120,3,908,454,0,4120,4121,5,382,0,0,4121,
  	899,1,0,0,0,4122,4123,7,27,0,0,4123,901,1,0,0,0,4124,4125,7,28,0,0,4125,
  	903,1,0,0,0,4126,4127,7,29,0,0,4127,905,1,0,0,0,4128,4130,3,902,451,0,
  	4129,4128,1,0,0,0,4129,4130,1,0,0,0,4130,4131,1,0,0,0,4131,4132,3,952,
  	476,0,4132,907,1,0,0,0,4133,4134,3,952,476,0,4134,909,1,0,0,0,4135,4136,
  	5,85,0,0,4136,4137,5,371,0,0,4137,4138,3,432,216,0,4138,4139,5,382,0,
  	0,4139,911,1,0,0,0,4140,4141,3,1092,546,0,4141,913,1,0,0,0,4142,4143,
  	3,818,409,0,4143,915,1,0,0,0,4144,4145,3,918,459,0,4145,917,1,0,0,0,4146,
  	4147,5,166,0,0,4147,4148,5,370,0,0,4148,4149,3,920,460,0,4149,4150,5,
  	381,0,0,4150,919,1,0,0,0,4151,4155,3,922,461,0,4152,4154,3,924,462,0,
  	4153,4152,1,0,0,0,4154,4157,1,0,0,0,4155,4153,1,0,0,0,4155,4156,1,0,0,
  	0,4156,921,1,0,0,0,4157,4155,1,0,0,0,4158,4159,3,836,418,0,4159,923,1,
  	0,0,0,4160,4161,5,361,0,0,4161,4162,3,838,419,0,4162,4163,5,361,0,0,4163,
  	4164,3,836,418,0,4164,925,1,0,0,0,4165,4166,3,818,409,0,4166,927,1,0,
  	0,0,4167,4170,3,930,465,0,4168,4170,3,932,466,0,4169,4167,1,0,0,0,4169,
  	4168,1,0,0,0,4170,929,1,0,0,0,4171,4172,5,210,0,0,4172,4173,5,371,0,0,
  	4173,4174,3,926,463,0,4174,4175,5,361,0,0,4175,4176,3,952,476,0,4176,
  	4177,5,382,0,0,4177,931,1,0,0,0,4178,4179,5,287,0,0,4179,4180,5,371,0,
  	0,4180,4181,3,914,457,0,4181,4182,5,382,0,0,4182,933,1,0,0,0,4183,4184,
  	3,936,468,0,4184,935,1,0,0,0,4185,4187,3,760,380,0,4186,4185,1,0,0,0,
  	4186,4187,1,0,0,0,4187,4188,1,0,0,0,4188,4190,5,370,0,0,4189,4191,3,938,
  	469,0,4190,4189,1,0,0,0,4190,4191,1,0,0,0,4191,4192,1,0,0,0,4192,4193,
  	5,381,0,0,4193,937,1,0,0,0,4194,4199,3,940,470,0,4195,4196,5,361,0,0,
  	4196,4198,3,940,470,0,4197,4195,1,0,0,0,4198,4201,1,0,0,0,4199,4197,1,
  	0,0,0,4199,4200,1,0,0,0,4200,939,1,0,0,0,4201,4199,1,0,0,0,4202,4203,
  	3,818,409,0,4203,941,1,0,0,0,4204,4206,5,176,0,0,4205,4204,1,0,0,0,4205,
  	4206,1,0,0,0,4206,4207,1,0,0,0,4207,4208,3,944,472,0,4208,943,1,0,0,0,
  	4209,4211,5,369,0,0,4210,4212,3,946,473,0,4211,4210,1,0,0,0,4211,4212,
  	1,0,0,0,4212,4213,1,0,0,0,4213,4214,5,380,0,0,4214,945,1,0,0,0,4215,4220,
  	3,948,474,0,4216,4217,5,361,0,0,4217,4219,3,948,474,0,4218,4216,1,0,0,
  	0,4219,4222,1,0,0,0,4220,4218,1,0,0,0,4220,4221,1,0,0,0,4221,947,1,0,
  	0,0,4222,4220,1,0,0,0,4223,4224,3,1084,542,0,4224,4225,5,360,0,0,4225,
  	4226,3,818,409,0,4226,949,1,0,0,0,4227,4228,5,2,0,0,4228,951,1,0,0,0,
  	4229,4230,6,476,-1,0,4230,4231,7,21,0,0,4231,4235,3,952,476,5,4232,4235,
  	3,842,421,0,4233,4235,3,954,477,0,4234,4229,1,0,0,0,4234,4232,1,0,0,0,
  	4234,4233,1,0,0,0,4235,4244,1,0,0,0,4236,4237,10,4,0,0,4237,4238,7,22,
  	0,0,4238,4243,3,952,476,5,4239,4240,10,3,0,0,4240,4241,7,21,0,0,4241,
  	4243,3,952,476,4,4242,4236,1,0,0,0,4242,4239,1,0,0,0,4243,4246,1,0,0,
  	0,4244,4242,1,0,0,0,4244,4245,1,0,0,0,4245,953,1,0,0,0,4246,4244,1,0,
  	0,0,4247,4261,3,956,478,0,4248,4261,3,958,479,0,4249,4261,3,968,484,0,
  	4250,4261,3,970,485,0,4251,4261,3,976,488,0,4252,4261,3,980,490,0,4253,
  	4261,3,986,493,0,4254,4261,3,988,494,0,4255,4261,3,990,495,0,4256,4261,
  	3,992,496,0,4257,4261,3,998,499,0,4258,4261,3,1000,500,0,4259,4261,3,
  	1002,501,0,4260,4247,1,0,0,0,4260,4248,1,0,0,0,4260,4249,1,0,0,0,4260,
  	4250,1,0,0,0,4260,4251,1,0,0,0,4260,4252,1,0,0,0,4260,4253,1,0,0,0,4260,
  	4254,1,0,0,0,4260,4255,1,0,0,0,4260,4256,1,0,0,0,4260,4257,1,0,0,0,4260,
  	4258,1,0,0,0,4260,4259,1,0,0,0,4261,955,1,0,0,0,4262,4266,3,962,481,0,
  	4263,4266,3,964,482,0,4264,4266,3,966,483,0,4265,4262,1,0,0,0,4265,4263,
  	1,0,0,0,4265,4264,1,0,0,0,4266,957,1,0,0,0,4267,4268,5,45,0,0,4268,4269,
  	5,371,0,0,4269,4270,3,960,480,0,4270,4271,5,382,0,0,4271,4278,1,0,0,0,
  	4272,4273,5,194,0,0,4273,4274,5,371,0,0,4274,4275,3,926,463,0,4275,4276,
  	5,382,0,0,4276,4278,1,0,0,0,4277,4267,1,0,0,0,4277,4272,1,0,0,0,4278,
  	959,1,0,0,0,4279,4280,3,818,409,0,4280,961,1,0,0,0,4281,4282,7,30,0,0,
  	4282,4283,5,371,0,0,4283,4284,3,1004,502,0,4284,4285,5,382,0,0,4285,963,
  	1,0,0,0,4286,4287,7,31,0,0,4287,4288,5,371,0,0,4288,4289,3,1006,503,0,
  	4289,4290,5,382,0,0,4290,965,1,0,0,0,4291,4292,5,167,0,0,4292,4293,5,
  	371,0,0,4293,4294,3,914,457,0,4294,4295,5,382,0,0,4295,967,1,0,0,0,4296,
  	4297,5,20,0,0,4297,4298,5,371,0,0,4298,4299,3,818,409,0,4299,4300,5,382,
  	0,0,4300,969,1,0,0,0,4301,4302,5,147,0,0,4302,4303,5,371,0,0,4303,4304,
  	3,972,486,0,4304,4305,5,361,0,0,4305,4306,3,974,487,0,4306,4307,5,382,
  	0,0,4307,971,1,0,0,0,4308,4309,3,952,476,0,4309,973,1,0,0,0,4310,4311,
  	3,952,476,0,4311,975,1,0,0,0,4312,4313,3,978,489,0,4313,4314,5,371,0,
  	0,4314,4315,3,952,476,0,4315,4316,5,382,0,0,4316,977,1,0,0,0,4317,4318,
  	7,32,0,0,4318,979,1,0,0,0,4319,4320,5,139,0,0,4320,4321,5,371,0,0,4321,
  	4322,3,982,491,0,4322,4323,5,361,0,0,4323,4324,3,984,492,0,4324,4325,
  	5,382,0,0,4325,981,1,0,0,0,4326,4327,3,952,476,0,4327,983,1,0,0,0,4328,
  	4329,3,952,476,0,4329,985,1,0,0,0,4330,4331,5,140,0,0,4331,4332,5,371,
  	0,0,4332,4333,3,952,476,0,4333,4334,5,382,0,0,4334,987,1,0,0,0,4335,4336,
  	5,134,0,0,4336,4337,5,371,0,0,4337,4338,3,952,476,0,4338,4339,5,382,0,
  	0,4339,989,1,0,0,0,4340,4341,5,90,0,0,4341,4342,5,371,0,0,4342,4343,3,
  	952,476,0,4343,4344,5,382,0,0,4344,991,1,0,0,0,4345,4346,5,171,0,0,4346,
  	4347,5,371,0,0,4347,4348,3,994,497,0,4348,4349,5,361,0,0,4349,4350,3,
  	996,498,0,4350,4351,5,382,0,0,4351,993,1,0,0,0,4352,4353,3,952,476,0,
  	4353,995,1,0,0,0,4354,4355,3,952,476,0,4355,997,1,0,0,0,4356,4357,5,198,
  	0,0,4357,4358,5,371,0,0,4358,4359,3,952,476,0,4359,4360,5,382,0,0,4360,
  	999,1,0,0,0,4361,4362,5,99,0,0,4362,4363,5,371,0,0,4363,4364,3,952,476,
  	0,4364,4365,5,382,0,0,4365,1001,1,0,0,0,4366,4367,7,33,0,0,4367,4368,
  	5,371,0,0,4368,4369,3,952,476,0,4369,4370,5,382,0,0,4370,1003,1,0,0,0,
  	4371,4372,3,818,409,0,4372,1005,1,0,0,0,4373,4374,3,818,409,0,4374,1007,
  	1,0,0,0,4375,4377,3,1012,506,0,4376,4375,1,0,0,0,4376,4377,1,0,0,0,4377,
  	4379,1,0,0,0,4378,4380,3,1014,507,0,4379,4378,1,0,0,0,4379,4380,1,0,0,
  	0,4380,4381,1,0,0,0,4381,4383,5,101,0,0,4382,4376,1,0,0,0,4382,4383,1,
  	0,0,0,4383,4384,1,0,0,0,4384,4385,3,1010,505,0,4385,1009,1,0,0,0,4386,
  	4387,3,818,409,0,4387,1011,1,0,0,0,4388,4389,7,34,0,0,4389,1013,1,0,0,
  	0,4390,4391,3,818,409,0,4391,1015,1,0,0,0,4392,4393,7,35,0,0,4393,1017,
  	1,0,0,0,4394,4395,3,952,476,0,4395,1019,1,0,0,0,4396,4397,3,818,409,0,
  	4397,1021,1,0,0,0,4398,4404,3,1024,512,0,4399,4404,3,1026,513,0,4400,
  	4404,3,1030,515,0,4401,4404,3,1028,514,0,4402,4404,3,1032,516,0,4403,
  	4398,1,0,0,0,4403,4399,1,0,0,0,4403,4400,1,0,0,0,4403,4401,1,0,0,0,4403,
  	4402,1,0,0,0,4404,1023,1,0,0,0,4405,4413,5,64,0,0,4406,4407,5,70,0,0,
  	4407,4409,5,371,0,0,4408,4410,3,1034,517,0,4409,4408,1,0,0,0,4409,4410,
  	1,0,0,0,4410,4411,1,0,0,0,4411,4413,5,382,0,0,4412,4405,1,0,0,0,4412,
  	4406,1,0,0,0,4413,1025,1,0,0,0,4414,4422,5,68,0,0,4415,4416,5,237,0,0,
  	4416,4418,5,371,0,0,4417,4419,3,1036,518,0,4418,4417,1,0,0,0,4418,4419,
  	1,0,0,0,4419,4420,1,0,0,0,4420,4422,5,382,0,0,4421,4414,1,0,0,0,4421,
  	4415,1,0,0,0,4422,1027,1,0,0,0,4423,4429,5,137,0,0,4424,4426,5,371,0,
  	0,4425,4427,3,1036,518,0,4426,4425,1,0,0,0,4426,4427,1,0,0,0,4427,4428,
  	1,0,0,0,4428,4430,5,382,0,0,4429,4424,1,0,0,0,4429,4430,1,0,0,0,4430,
  	1029,1,0,0,0,4431,4439,5,69,0,0,4432,4433,5,236,0,0,4433,4435,5,371,0,
  	0,4434,4436,3,1038,519,0,4435,4434,1,0,0,0,4435,4436,1,0,0,0,4436,4437,
  	1,0,0,0,4437,4439,5,382,0,0,4438,4431,1,0,0,0,4438,4432,1,0,0,0,4439,
  	1031,1,0,0,0,4440,4448,5,138,0,0,4441,4442,5,136,0,0,4442,4444,5,371,
  	0,0,4443,4445,3,1038,519,0,4444,4443,1,0,0,0,4444,4445,1,0,0,0,4445,4446,
  	1,0,0,0,4446,4448,5,382,0,0,4447,4440,1,0,0,0,4447,4441,1,0,0,0,4448,
  	1033,1,0,0,0,4449,4452,3,1130,565,0,4450,4452,3,942,471,0,4451,4449,1,
  	0,0,0,4451,4450,1,0,0,0,4452,1035,1,0,0,0,4453,4456,3,1132,566,0,4454,
  	4456,3,942,471,0,4455,4453,1,0,0,0,4455,4454,1,0,0,0,4456,1037,1,0,0,
  	0,4457,4460,3,1134,567,0,4458,4460,3,942,471,0,4459,4457,1,0,0,0,4459,
  	4458,1,0,0,0,4460,1039,1,0,0,0,4461,4462,3,818,409,0,4462,1041,1,0,0,
  	0,4463,4464,5,84,0,0,4464,4465,5,371,0,0,4465,4466,3,1044,522,0,4466,
  	4468,5,382,0,0,4467,4469,3,728,364,0,4468,4467,1,0,0,0,4468,4469,1,0,
  	0,0,4469,1043,1,0,0,0,4470,4471,3,1046,523,0,4471,4472,5,361,0,0,4472,
  	4473,3,1048,524,0,4473,1045,1,0,0,0,4474,4475,3,1020,510,0,4475,1047,
  	1,0,0,0,4476,4477,3,1020,510,0,4477,1049,1,0,0,0,4478,4481,3,1052,526,
  	0,4479,4481,3,968,484,0,4480,4478,1,0,0,0,4480,4479,1,0,0,0,4481,1051,
  	1,0,0,0,4482,4483,5,83,0,0,4483,4484,5,371,0,0,4484,4485,3,1054,527,0,
  	4485,4486,5,382,0,0,4486,1053,1,0,0,0,4487,4490,3,1138,569,0,4488,4490,
  	3,942,471,0,4489,4487,1,0,0,0,4489,4488,1,0,0,0,4490,1055,1,0,0,0,4491,
  	4492,3,1110,555,0,4492,1057,1,0,0,0,4493,4494,3,1112,556,0,4494,1059,
  	1,0,0,0,4495,4496,3,1110,555,0,4496,1061,1,0,0,0,4497,4498,3,1110,555,
  	0,4498,1063,1,0,0,0,4499,4502,3,1112,556,0,4500,4502,3,1066,533,0,4501,
  	4499,1,0,0,0,4501,4500,1,0,0,0,4502,1065,1,0,0,0,4503,4504,7,36,0,0,4504,
  	1067,1,0,0,0,4505,4506,3,1110,555,0,4506,1069,1,0,0,0,4507,4508,3,1110,
  	555,0,4508,1071,1,0,0,0,4509,4510,3,1110,555,0,4510,1073,1,0,0,0,4511,
  	4514,3,1112,556,0,4512,4514,3,1076,538,0,4513,4511,1,0,0,0,4513,4512,
  	1,0,0,0,4514,1075,1,0,0,0,4515,4516,7,36,0,0,4516,1077,1,0,0,0,4517,4518,
  	3,1110,555,0,4518,1079,1,0,0,0,4519,4520,3,1110,555,0,4520,1081,1,0,0,
  	0,4521,4522,3,1110,555,0,4522,1083,1,0,0,0,4523,4524,3,1110,555,0,4524,
  	1085,1,0,0,0,4525,4526,3,1092,546,0,4526,1087,1,0,0,0,4527,4528,3,1092,
  	546,0,4528,1089,1,0,0,0,4529,4530,3,1112,556,0,4530,1091,1,0,0,0,4531,
  	4532,3,1112,556,0,4532,1093,1,0,0,0,4533,4536,3,1118,559,0,4534,4536,
  	3,1096,548,0,4535,4533,1,0,0,0,4535,4534,1,0,0,0,4536,1095,1,0,0,0,4537,
  	4546,5,2,0,0,4538,4546,3,1116,558,0,4539,4546,5,7,0,0,4540,4546,3,1098,
  	549,0,4541,4546,3,1136,568,0,4542,4546,3,1128,564,0,4543,4546,3,1106,
  	553,0,4544,4546,3,1108,554,0,4545,4537,1,0,0,0,4545,4538,1,0,0,0,4545,
  	4539,1,0,0,0,4545,4540,1,0,0,0,4545,4541,1,0,0,0,4545,4542,1,0,0,0,4545,
  	4543,1,0,0,0,4545,4544,1,0,0,0,4546,1097,1,0,0,0,4547,4551,3,1100,550,
  	0,4548,4551,3,1102,551,0,4549,4551,3,1104,552,0,4550,4547,1,0,0,0,4550,
  	4548,1,0,0,0,4550,4549,1,0,0,0,4551,1099,1,0,0,0,4552,4553,5,70,0,0,4553,
  	4554,3,1130,565,0,4554,1101,1,0,0,0,4555,4556,5,207,0,0,4556,4557,3,1132,
  	566,0,4557,1103,1,0,0,0,4558,4559,7,37,0,0,4559,4560,3,1134,567,0,4560,
  	1105,1,0,0,0,4561,4562,3,936,468,0,4562,1107,1,0,0,0,4563,4564,3,942,
  	471,0,4564,1109,1,0,0,0,4565,4569,3,1112,556,0,4566,4569,5,4,0,0,4567,
  	4569,5,5,0,0,4568,4565,1,0,0,0,4568,4566,1,0,0,0,4568,4567,1,0,0,0,4569,
  	1111,1,0,0,0,4570,4573,5,325,0,0,4571,4573,3,1146,573,0,4572,4570,1,0,
  	0,0,4572,4571,1,0,0,0,4573,1113,1,0,0,0,4574,4575,3,1116,558,0,4575,1115,
  	1,0,0,0,4576,4577,7,38,0,0,4577,1117,1,0,0,0,4578,4581,3,1120,560,0,4579,
  	4581,3,1122,561,0,4580,4578,1,0,0,0,4580,4579,1,0,0,0,4581,1119,1,0,0,
  	0,4582,4588,5,8,0,0,4583,4588,5,11,0,0,4584,4588,5,12,0,0,4585,4588,5,
  	14,0,0,4586,4588,3,1124,562,0,4587,4582,1,0,0,0,4587,4583,1,0,0,0,4587,
  	4584,1,0,0,0,4587,4585,1,0,0,0,4587,4586,1,0,0,0,4588,1121,1,0,0,0,4589,
  	4590,7,39,0,0,4590,1123,1,0,0,0,4591,4592,7,40,0,0,4592,1125,1,0,0,0,
  	4593,4594,5,16,0,0,4594,1127,1,0,0,0,4595,4596,5,154,0,0,4596,1129,1,
  	0,0,0,4597,4598,3,1116,558,0,4598,1131,1,0,0,0,4599,4600,3,1116,558,0,
  	4600,1133,1,0,0,0,4601,4602,3,1116,558,0,4602,1135,1,0,0,0,4603,4604,
  	5,83,0,0,4604,4605,3,1138,569,0,4605,1137,1,0,0,0,4606,4607,3,1116,558,
  	0,4607,1139,1,0,0,0,4608,4609,7,41,0,0,4609,1141,1,0,0,0,4610,4611,7,
  	42,0,0,4611,1143,1,0,0,0,4612,4613,7,43,0,0,4613,1145,1,0,0,0,4614,4615,
  	7,44,0,0,4615,1147,1,0,0,0,511,1150,1157,1161,1166,1171,1176,1179,1184,
  	1186,1190,1193,1197,1205,1211,1225,1228,1235,1248,1255,1258,1263,1269,
  	1272,1282,1289,1298,1319,1322,1329,1334,1340,1346,1350,1355,1362,1365,
  	1373,1380,1383,1395,1398,1409,1417,1425,1430,1434,1442,1449,1457,1463,
  	1469,1474,1477,1482,1485,1488,1492,1495,1499,1503,1506,1509,1512,1524,
  	1529,1535,1542,1547,1551,1557,1562,1565,1573,1579,1587,1591,1596,1603,
  	1607,1612,1616,1620,1626,1639,1645,1657,1673,1678,1689,1699,1717,1722,
  	1726,1730,1734,1736,1742,1747,1754,1770,1774,1779,1783,1790,1794,1811,
  	1816,1823,1833,1841,1846,1862,1865,1869,1872,1876,1879,1885,1889,1892,
  	1896,1903,1908,1915,1919,1923,1926,1929,1932,1935,1938,1940,1947,1952,
  	1963,1970,1980,1983,1990,1993,1999,2008,2014,2018,2025,2038,2048,2053,
  	2058,2062,2065,2069,2079,2082,2086,2089,2096,2100,2103,2123,2132,2137,
  	2144,2148,2154,2160,2166,2169,2172,2177,2182,2185,2189,2193,2200,2204,
  	2207,2213,2216,2219,2227,2232,2235,2240,2243,2248,2251,2255,2258,2261,
  	2273,2280,2282,2287,2296,2301,2305,2312,2315,2318,2321,2332,2346,2355,
  	2364,2398,2401,2405,2424,2432,2434,2445,2453,2457,2472,2505,2514,2524,
  	2534,2545,2551,2561,2570,2597,2607,2620,2625,2641,2645,2661,2666,2669,
  	2679,2692,2698,2707,2713,2720,2725,2732,2740,2743,2751,2754,2763,2767,
  	2770,2776,2783,2791,2793,2808,2813,2817,2821,2825,2829,2832,2838,2843,
  	2847,2850,2854,2857,2866,2869,2879,2882,2886,2890,2894,2899,2906,2909,
  	2913,2916,2923,2926,2936,2968,2971,2979,2982,2991,2995,3030,3037,3042,
  	3051,3056,3063,3079,3082,3089,3092,3097,3100,3103,3108,3112,3120,3125,
  	3136,3139,3141,3143,3155,3159,3166,3171,3174,3181,3184,3191,3194,3196,
  	3203,3208,3211,3218,3221,3228,3231,3233,3243,3247,3251,3255,3259,3263,
  	3267,3271,3275,3279,3286,3289,3293,3296,3299,3303,3307,3311,3315,3319,
  	3323,3327,3334,3337,3341,3345,3349,3353,3357,3361,3365,3369,3374,3381,
  	3384,3389,3391,3398,3402,3404,3412,3416,3420,3424,3428,3435,3439,3442,
  	3446,3450,3453,3455,3459,3466,3471,3478,3480,3485,3491,3494,3496,3500,
  	3505,3512,3514,3519,3526,3528,3535,3543,3549,3553,3560,3564,3567,3572,
  	3576,3580,3584,3588,3592,3595,3599,3603,3607,3610,3614,3618,3621,3628,
  	3632,3635,3639,3641,3645,3654,3662,3677,3699,3706,3715,3722,3725,3734,
  	3746,3750,3758,3764,3772,3789,3803,3822,3827,3833,3859,3862,3864,3873,
  	3882,3906,3915,3936,3943,3952,3966,3970,3974,3978,3993,4009,4013,4017,
  	4024,4027,4035,4038,4057,4064,4078,4082,4095,4105,4110,4129,4155,4169,
  	4186,4190,4199,4205,4211,4220,4234,4242,4244,4260,4265,4277,4376,4379,
  	4382,4403,4409,4412,4418,4421,4426,4429,4435,4438,4444,4447,4451,4455,
  	4459,4468,4480,4489,4501,4513,4535,4545,4550,4568,4572,4580,4587
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  gqlParserStaticData = std::move(staticData);
}

}

GQLParser::GQLParser(TokenStream *input) : GQLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

GQLParser::GQLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  GQLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *gqlParserStaticData->atn, gqlParserStaticData->decisionToDFA, gqlParserStaticData->sharedContextCache, options);
}

GQLParser::~GQLParser() {
  delete _interpreter;
}

const atn::ATN& GQLParser::getATN() const {
  return *gqlParserStaticData->atn;
}

std::string GQLParser::getGrammarFileName() const {
  return "GQL.g4";
}

const std::vector<std::string>& GQLParser::getRuleNames() const {
  return gqlParserStaticData->ruleNames;
}

const dfa::Vocabulary& GQLParser::getVocabulary() const {
  return gqlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GQLParser::getSerializedATN() const {
  return gqlParserStaticData->serializedATN;
}


//----------------- GqlProgramContext ------------------------------------------------------------------

GQLParser::GqlProgramContext::GqlProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ProgramActivityContext* GQLParser::GqlProgramContext::programActivity() {
  return getRuleContext<GQLParser::ProgramActivityContext>(0);
}

tree::TerminalNode* GQLParser::GqlProgramContext::EOF() {
  return getToken(GQLParser::EOF, 0);
}

GQLParser::SessionCloseCommandContext* GQLParser::GqlProgramContext::sessionCloseCommand() {
  return getRuleContext<GQLParser::SessionCloseCommandContext>(0);
}


size_t GQLParser::GqlProgramContext::getRuleIndex() const {
  return GQLParser::RuleGqlProgram;
}




//----------------- ProgramActivityContext ------------------------------------------------------------------

GQLParser::ProgramActivityContext::ProgramActivityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SessionActivityContext* GQLParser::ProgramActivityContext::sessionActivity() {
  return getRuleContext<GQLParser::SessionActivityContext>(0);
}

GQLParser::TransactionActivityContext* GQLParser::ProgramActivityContext::transactionActivity() {
  return getRuleContext<GQLParser::TransactionActivityContext>(0);
}


size_t GQLParser::ProgramActivityContext::getRuleIndex() const {
  return GQLParser::RuleProgramActivity;
}




//----------------- SessionActivityContext ------------------------------------------------------------------

GQLParser::SessionActivityContext::SessionActivityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SessionResetCommandContext *> GQLParser::SessionActivityContext::sessionResetCommand() {
  return getRuleContexts<GQLParser::SessionResetCommandContext>();
}

GQLParser::SessionResetCommandContext* GQLParser::SessionActivityContext::sessionResetCommand(size_t i) {
  return getRuleContext<GQLParser::SessionResetCommandContext>(i);
}

std::vector<GQLParser::SessionSetCommandContext *> GQLParser::SessionActivityContext::sessionSetCommand() {
  return getRuleContexts<GQLParser::SessionSetCommandContext>();
}

GQLParser::SessionSetCommandContext* GQLParser::SessionActivityContext::sessionSetCommand(size_t i) {
  return getRuleContext<GQLParser::SessionSetCommandContext>(i);
}


size_t GQLParser::SessionActivityContext::getRuleIndex() const {
  return GQLParser::RuleSessionActivity;
}




//----------------- TransactionActivityContext ------------------------------------------------------------------

GQLParser::TransactionActivityContext::TransactionActivityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::StartTransactionCommandContext* GQLParser::TransactionActivityContext::startTransactionCommand() {
  return getRuleContext<GQLParser::StartTransactionCommandContext>(0);
}

GQLParser::ProcedureSpecificationContext* GQLParser::TransactionActivityContext::procedureSpecification() {
  return getRuleContext<GQLParser::ProcedureSpecificationContext>(0);
}

GQLParser::EndTransactionCommandContext* GQLParser::TransactionActivityContext::endTransactionCommand() {
  return getRuleContext<GQLParser::EndTransactionCommandContext>(0);
}


size_t GQLParser::TransactionActivityContext::getRuleIndex() const {
  return GQLParser::RuleTransactionActivity;
}




//----------------- EndTransactionCommandContext ------------------------------------------------------------------

GQLParser::EndTransactionCommandContext::EndTransactionCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RollbackCommandContext* GQLParser::EndTransactionCommandContext::rollbackCommand() {
  return getRuleContext<GQLParser::RollbackCommandContext>(0);
}

GQLParser::CommitCommandContext* GQLParser::EndTransactionCommandContext::commitCommand() {
  return getRuleContext<GQLParser::CommitCommandContext>(0);
}


size_t GQLParser::EndTransactionCommandContext::getRuleIndex() const {
  return GQLParser::RuleEndTransactionCommand;
}




//----------------- SessionSetCommandContext ------------------------------------------------------------------

GQLParser::SessionSetCommandContext::SessionSetCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionSetCommandContext::SESSION() {
  return getToken(GQLParser::SESSION, 0);
}

tree::TerminalNode* GQLParser::SessionSetCommandContext::SET() {
  return getToken(GQLParser::SET, 0);
}

GQLParser::SessionSetSchemaClauseContext* GQLParser::SessionSetCommandContext::sessionSetSchemaClause() {
  return getRuleContext<GQLParser::SessionSetSchemaClauseContext>(0);
}

GQLParser::SessionSetGraphClauseContext* GQLParser::SessionSetCommandContext::sessionSetGraphClause() {
  return getRuleContext<GQLParser::SessionSetGraphClauseContext>(0);
}

GQLParser::SessionSetTimeZoneClauseContext* GQLParser::SessionSetCommandContext::sessionSetTimeZoneClause() {
  return getRuleContext<GQLParser::SessionSetTimeZoneClauseContext>(0);
}

GQLParser::SessionSetParameterClauseContext* GQLParser::SessionSetCommandContext::sessionSetParameterClause() {
  return getRuleContext<GQLParser::SessionSetParameterClauseContext>(0);
}


size_t GQLParser::SessionSetCommandContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetCommand;
}




//----------------- SessionSetSchemaClauseContext ------------------------------------------------------------------

GQLParser::SessionSetSchemaClauseContext::SessionSetSchemaClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionSetSchemaClauseContext::SCHEMA() {
  return getToken(GQLParser::SCHEMA, 0);
}

GQLParser::SchemaReferenceContext* GQLParser::SessionSetSchemaClauseContext::schemaReference() {
  return getRuleContext<GQLParser::SchemaReferenceContext>(0);
}


size_t GQLParser::SessionSetSchemaClauseContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetSchemaClause;
}




//----------------- SessionSetGraphClauseContext ------------------------------------------------------------------

GQLParser::SessionSetGraphClauseContext::SessionSetGraphClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionSetGraphClauseContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

GQLParser::GraphExpressionContext* GQLParser::SessionSetGraphClauseContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}

tree::TerminalNode* GQLParser::SessionSetGraphClauseContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}


size_t GQLParser::SessionSetGraphClauseContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetGraphClause;
}




//----------------- SessionSetTimeZoneClauseContext ------------------------------------------------------------------

GQLParser::SessionSetTimeZoneClauseContext::SessionSetTimeZoneClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionSetTimeZoneClauseContext::TIME() {
  return getToken(GQLParser::TIME, 0);
}

tree::TerminalNode* GQLParser::SessionSetTimeZoneClauseContext::ZONE() {
  return getToken(GQLParser::ZONE, 0);
}

GQLParser::SetTimeZoneValueContext* GQLParser::SessionSetTimeZoneClauseContext::setTimeZoneValue() {
  return getRuleContext<GQLParser::SetTimeZoneValueContext>(0);
}


size_t GQLParser::SessionSetTimeZoneClauseContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetTimeZoneClause;
}




//----------------- SetTimeZoneValueContext ------------------------------------------------------------------

GQLParser::SetTimeZoneValueContext::SetTimeZoneValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::TimeZoneStringContext* GQLParser::SetTimeZoneValueContext::timeZoneString() {
  return getRuleContext<GQLParser::TimeZoneStringContext>(0);
}


size_t GQLParser::SetTimeZoneValueContext::getRuleIndex() const {
  return GQLParser::RuleSetTimeZoneValue;
}




//----------------- SessionSetParameterClauseContext ------------------------------------------------------------------

GQLParser::SessionSetParameterClauseContext::SessionSetParameterClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SessionSetGraphParameterClauseContext* GQLParser::SessionSetParameterClauseContext::sessionSetGraphParameterClause() {
  return getRuleContext<GQLParser::SessionSetGraphParameterClauseContext>(0);
}

GQLParser::SessionSetBindingTableParameterClauseContext* GQLParser::SessionSetParameterClauseContext::sessionSetBindingTableParameterClause() {
  return getRuleContext<GQLParser::SessionSetBindingTableParameterClauseContext>(0);
}

GQLParser::SessionSetValueParameterClauseContext* GQLParser::SessionSetParameterClauseContext::sessionSetValueParameterClause() {
  return getRuleContext<GQLParser::SessionSetValueParameterClauseContext>(0);
}


size_t GQLParser::SessionSetParameterClauseContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetParameterClause;
}




//----------------- SessionSetGraphParameterClauseContext ------------------------------------------------------------------

GQLParser::SessionSetGraphParameterClauseContext::SessionSetGraphParameterClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionSetGraphParameterClauseContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

GQLParser::SessionSetParameterNameContext* GQLParser::SessionSetGraphParameterClauseContext::sessionSetParameterName() {
  return getRuleContext<GQLParser::SessionSetParameterNameContext>(0);
}

GQLParser::OptTypedGraphInitializerContext* GQLParser::SessionSetGraphParameterClauseContext::optTypedGraphInitializer() {
  return getRuleContext<GQLParser::OptTypedGraphInitializerContext>(0);
}

tree::TerminalNode* GQLParser::SessionSetGraphParameterClauseContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}


size_t GQLParser::SessionSetGraphParameterClauseContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetGraphParameterClause;
}




//----------------- SessionSetBindingTableParameterClauseContext ------------------------------------------------------------------

GQLParser::SessionSetBindingTableParameterClauseContext::SessionSetBindingTableParameterClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionSetBindingTableParameterClauseContext::TABLE() {
  return getToken(GQLParser::TABLE, 0);
}

GQLParser::SessionSetParameterNameContext* GQLParser::SessionSetBindingTableParameterClauseContext::sessionSetParameterName() {
  return getRuleContext<GQLParser::SessionSetParameterNameContext>(0);
}

GQLParser::OptTypedBindingTableInitializerContext* GQLParser::SessionSetBindingTableParameterClauseContext::optTypedBindingTableInitializer() {
  return getRuleContext<GQLParser::OptTypedBindingTableInitializerContext>(0);
}

tree::TerminalNode* GQLParser::SessionSetBindingTableParameterClauseContext::BINDING() {
  return getToken(GQLParser::BINDING, 0);
}


size_t GQLParser::SessionSetBindingTableParameterClauseContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetBindingTableParameterClause;
}




//----------------- SessionSetValueParameterClauseContext ------------------------------------------------------------------

GQLParser::SessionSetValueParameterClauseContext::SessionSetValueParameterClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionSetValueParameterClauseContext::VALUE() {
  return getToken(GQLParser::VALUE, 0);
}

GQLParser::SessionSetParameterNameContext* GQLParser::SessionSetValueParameterClauseContext::sessionSetParameterName() {
  return getRuleContext<GQLParser::SessionSetParameterNameContext>(0);
}

GQLParser::OptTypedValueInitializerContext* GQLParser::SessionSetValueParameterClauseContext::optTypedValueInitializer() {
  return getRuleContext<GQLParser::OptTypedValueInitializerContext>(0);
}


size_t GQLParser::SessionSetValueParameterClauseContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetValueParameterClause;
}




//----------------- SessionSetParameterNameContext ------------------------------------------------------------------

GQLParser::SessionSetParameterNameContext::SessionSetParameterNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SessionParameterSpecificationContext* GQLParser::SessionSetParameterNameContext::sessionParameterSpecification() {
  return getRuleContext<GQLParser::SessionParameterSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::SessionSetParameterNameContext::IF() {
  return getToken(GQLParser::IF, 0);
}

tree::TerminalNode* GQLParser::SessionSetParameterNameContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

tree::TerminalNode* GQLParser::SessionSetParameterNameContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}


size_t GQLParser::SessionSetParameterNameContext::getRuleIndex() const {
  return GQLParser::RuleSessionSetParameterName;
}




//----------------- SessionResetCommandContext ------------------------------------------------------------------

GQLParser::SessionResetCommandContext::SessionResetCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionResetCommandContext::SESSION() {
  return getToken(GQLParser::SESSION, 0);
}

tree::TerminalNode* GQLParser::SessionResetCommandContext::RESET() {
  return getToken(GQLParser::RESET, 0);
}

GQLParser::SessionResetArgumentsContext* GQLParser::SessionResetCommandContext::sessionResetArguments() {
  return getRuleContext<GQLParser::SessionResetArgumentsContext>(0);
}


size_t GQLParser::SessionResetCommandContext::getRuleIndex() const {
  return GQLParser::RuleSessionResetCommand;
}




//----------------- SessionResetArgumentsContext ------------------------------------------------------------------

GQLParser::SessionResetArgumentsContext::SessionResetArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::PARAMETERS() {
  return getToken(GQLParser::PARAMETERS, 0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::CHARACTERISTICS() {
  return getToken(GQLParser::CHARACTERISTICS, 0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::ALL() {
  return getToken(GQLParser::ALL, 0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::SCHEMA() {
  return getToken(GQLParser::SCHEMA, 0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::TIME() {
  return getToken(GQLParser::TIME, 0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::ZONE() {
  return getToken(GQLParser::ZONE, 0);
}

GQLParser::SessionParameterSpecificationContext* GQLParser::SessionResetArgumentsContext::sessionParameterSpecification() {
  return getRuleContext<GQLParser::SessionParameterSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::SessionResetArgumentsContext::PARAMETER() {
  return getToken(GQLParser::PARAMETER, 0);
}


size_t GQLParser::SessionResetArgumentsContext::getRuleIndex() const {
  return GQLParser::RuleSessionResetArguments;
}




//----------------- SessionCloseCommandContext ------------------------------------------------------------------

GQLParser::SessionCloseCommandContext::SessionCloseCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionCloseCommandContext::SESSION() {
  return getToken(GQLParser::SESSION, 0);
}

tree::TerminalNode* GQLParser::SessionCloseCommandContext::CLOSE() {
  return getToken(GQLParser::CLOSE, 0);
}


size_t GQLParser::SessionCloseCommandContext::getRuleIndex() const {
  return GQLParser::RuleSessionCloseCommand;
}




//----------------- SessionParameterSpecificationContext ------------------------------------------------------------------

GQLParser::SessionParameterSpecificationContext::SessionParameterSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SessionParameterSpecificationContext::GENERAL_PARAMETER_REFERENCE() {
  return getToken(GQLParser::GENERAL_PARAMETER_REFERENCE, 0);
}


size_t GQLParser::SessionParameterSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleSessionParameterSpecification;
}




//----------------- StartTransactionCommandContext ------------------------------------------------------------------

GQLParser::StartTransactionCommandContext::StartTransactionCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::StartTransactionCommandContext::START() {
  return getToken(GQLParser::START, 0);
}

tree::TerminalNode* GQLParser::StartTransactionCommandContext::TRANSACTION() {
  return getToken(GQLParser::TRANSACTION, 0);
}

GQLParser::TransactionCharacteristicsContext* GQLParser::StartTransactionCommandContext::transactionCharacteristics() {
  return getRuleContext<GQLParser::TransactionCharacteristicsContext>(0);
}


size_t GQLParser::StartTransactionCommandContext::getRuleIndex() const {
  return GQLParser::RuleStartTransactionCommand;
}




//----------------- TransactionCharacteristicsContext ------------------------------------------------------------------

GQLParser::TransactionCharacteristicsContext::TransactionCharacteristicsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::TransactionModeContext *> GQLParser::TransactionCharacteristicsContext::transactionMode() {
  return getRuleContexts<GQLParser::TransactionModeContext>();
}

GQLParser::TransactionModeContext* GQLParser::TransactionCharacteristicsContext::transactionMode(size_t i) {
  return getRuleContext<GQLParser::TransactionModeContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::TransactionCharacteristicsContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::TransactionCharacteristicsContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::TransactionCharacteristicsContext::getRuleIndex() const {
  return GQLParser::RuleTransactionCharacteristics;
}




//----------------- TransactionModeContext ------------------------------------------------------------------

GQLParser::TransactionModeContext::TransactionModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::TransactionAccessModeContext* GQLParser::TransactionModeContext::transactionAccessMode() {
  return getRuleContext<GQLParser::TransactionAccessModeContext>(0);
}


size_t GQLParser::TransactionModeContext::getRuleIndex() const {
  return GQLParser::RuleTransactionMode;
}




//----------------- TransactionAccessModeContext ------------------------------------------------------------------

GQLParser::TransactionAccessModeContext::TransactionAccessModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TransactionAccessModeContext::READ() {
  return getToken(GQLParser::READ, 0);
}

tree::TerminalNode* GQLParser::TransactionAccessModeContext::ONLY() {
  return getToken(GQLParser::ONLY, 0);
}

tree::TerminalNode* GQLParser::TransactionAccessModeContext::WRITE() {
  return getToken(GQLParser::WRITE, 0);
}


size_t GQLParser::TransactionAccessModeContext::getRuleIndex() const {
  return GQLParser::RuleTransactionAccessMode;
}




//----------------- RollbackCommandContext ------------------------------------------------------------------

GQLParser::RollbackCommandContext::RollbackCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::RollbackCommandContext::ROLLBACK() {
  return getToken(GQLParser::ROLLBACK, 0);
}


size_t GQLParser::RollbackCommandContext::getRuleIndex() const {
  return GQLParser::RuleRollbackCommand;
}




//----------------- CommitCommandContext ------------------------------------------------------------------

GQLParser::CommitCommandContext::CommitCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CommitCommandContext::COMMIT() {
  return getToken(GQLParser::COMMIT, 0);
}


size_t GQLParser::CommitCommandContext::getRuleIndex() const {
  return GQLParser::RuleCommitCommand;
}




//----------------- NestedProcedureSpecificationContext ------------------------------------------------------------------

GQLParser::NestedProcedureSpecificationContext::NestedProcedureSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NestedProcedureSpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::ProcedureSpecificationContext* GQLParser::NestedProcedureSpecificationContext::procedureSpecification() {
  return getRuleContext<GQLParser::ProcedureSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::NestedProcedureSpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}


size_t GQLParser::NestedProcedureSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleNestedProcedureSpecification;
}




//----------------- ProcedureSpecificationContext ------------------------------------------------------------------

GQLParser::ProcedureSpecificationContext::ProcedureSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ProcedureBodyContext* GQLParser::ProcedureSpecificationContext::procedureBody() {
  return getRuleContext<GQLParser::ProcedureBodyContext>(0);
}


size_t GQLParser::ProcedureSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleProcedureSpecification;
}




//----------------- NestedDataModifyingProcedureSpecificationContext ------------------------------------------------------------------

GQLParser::NestedDataModifyingProcedureSpecificationContext::NestedDataModifyingProcedureSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NestedDataModifyingProcedureSpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::ProcedureBodyContext* GQLParser::NestedDataModifyingProcedureSpecificationContext::procedureBody() {
  return getRuleContext<GQLParser::ProcedureBodyContext>(0);
}

tree::TerminalNode* GQLParser::NestedDataModifyingProcedureSpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}


size_t GQLParser::NestedDataModifyingProcedureSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleNestedDataModifyingProcedureSpecification;
}




//----------------- NestedQuerySpecificationContext ------------------------------------------------------------------

GQLParser::NestedQuerySpecificationContext::NestedQuerySpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NestedQuerySpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::ProcedureBodyContext* GQLParser::NestedQuerySpecificationContext::procedureBody() {
  return getRuleContext<GQLParser::ProcedureBodyContext>(0);
}

tree::TerminalNode* GQLParser::NestedQuerySpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}


size_t GQLParser::NestedQuerySpecificationContext::getRuleIndex() const {
  return GQLParser::RuleNestedQuerySpecification;
}




//----------------- ProcedureBodyContext ------------------------------------------------------------------

GQLParser::ProcedureBodyContext::ProcedureBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::StatementBlockContext* GQLParser::ProcedureBodyContext::statementBlock() {
  return getRuleContext<GQLParser::StatementBlockContext>(0);
}

GQLParser::AtSchemaClauseContext* GQLParser::ProcedureBodyContext::atSchemaClause() {
  return getRuleContext<GQLParser::AtSchemaClauseContext>(0);
}

GQLParser::BindingVariableDefinitionBlockContext* GQLParser::ProcedureBodyContext::bindingVariableDefinitionBlock() {
  return getRuleContext<GQLParser::BindingVariableDefinitionBlockContext>(0);
}


size_t GQLParser::ProcedureBodyContext::getRuleIndex() const {
  return GQLParser::RuleProcedureBody;
}




//----------------- BindingVariableDefinitionBlockContext ------------------------------------------------------------------

GQLParser::BindingVariableDefinitionBlockContext::BindingVariableDefinitionBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::BindingVariableDefinitionContext *> GQLParser::BindingVariableDefinitionBlockContext::bindingVariableDefinition() {
  return getRuleContexts<GQLParser::BindingVariableDefinitionContext>();
}

GQLParser::BindingVariableDefinitionContext* GQLParser::BindingVariableDefinitionBlockContext::bindingVariableDefinition(size_t i) {
  return getRuleContext<GQLParser::BindingVariableDefinitionContext>(i);
}


size_t GQLParser::BindingVariableDefinitionBlockContext::getRuleIndex() const {
  return GQLParser::RuleBindingVariableDefinitionBlock;
}




//----------------- BindingVariableDefinitionContext ------------------------------------------------------------------

GQLParser::BindingVariableDefinitionContext::BindingVariableDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphVariableDefinitionContext* GQLParser::BindingVariableDefinitionContext::graphVariableDefinition() {
  return getRuleContext<GQLParser::GraphVariableDefinitionContext>(0);
}

GQLParser::BindingTableVariableDefinitionContext* GQLParser::BindingVariableDefinitionContext::bindingTableVariableDefinition() {
  return getRuleContext<GQLParser::BindingTableVariableDefinitionContext>(0);
}

GQLParser::ValueVariableDefinitionContext* GQLParser::BindingVariableDefinitionContext::valueVariableDefinition() {
  return getRuleContext<GQLParser::ValueVariableDefinitionContext>(0);
}


size_t GQLParser::BindingVariableDefinitionContext::getRuleIndex() const {
  return GQLParser::RuleBindingVariableDefinition;
}




//----------------- StatementBlockContext ------------------------------------------------------------------

GQLParser::StatementBlockContext::StatementBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::StatementContext* GQLParser::StatementBlockContext::statement() {
  return getRuleContext<GQLParser::StatementContext>(0);
}

std::vector<GQLParser::NextStatementContext *> GQLParser::StatementBlockContext::nextStatement() {
  return getRuleContexts<GQLParser::NextStatementContext>();
}

GQLParser::NextStatementContext* GQLParser::StatementBlockContext::nextStatement(size_t i) {
  return getRuleContext<GQLParser::NextStatementContext>(i);
}


size_t GQLParser::StatementBlockContext::getRuleIndex() const {
  return GQLParser::RuleStatementBlock;
}




//----------------- StatementContext ------------------------------------------------------------------

GQLParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::LinearCatalogModifyingStatementContext* GQLParser::StatementContext::linearCatalogModifyingStatement() {
  return getRuleContext<GQLParser::LinearCatalogModifyingStatementContext>(0);
}

GQLParser::LinearDataModifyingStatementContext* GQLParser::StatementContext::linearDataModifyingStatement() {
  return getRuleContext<GQLParser::LinearDataModifyingStatementContext>(0);
}

GQLParser::CompositeQueryStatementContext* GQLParser::StatementContext::compositeQueryStatement() {
  return getRuleContext<GQLParser::CompositeQueryStatementContext>(0);
}


size_t GQLParser::StatementContext::getRuleIndex() const {
  return GQLParser::RuleStatement;
}




//----------------- NextStatementContext ------------------------------------------------------------------

GQLParser::NextStatementContext::NextStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NextStatementContext::NEXT() {
  return getToken(GQLParser::NEXT, 0);
}

GQLParser::StatementContext* GQLParser::NextStatementContext::statement() {
  return getRuleContext<GQLParser::StatementContext>(0);
}

GQLParser::YieldClauseContext* GQLParser::NextStatementContext::yieldClause() {
  return getRuleContext<GQLParser::YieldClauseContext>(0);
}


size_t GQLParser::NextStatementContext::getRuleIndex() const {
  return GQLParser::RuleNextStatement;
}




//----------------- GraphVariableDefinitionContext ------------------------------------------------------------------

GQLParser::GraphVariableDefinitionContext::GraphVariableDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GraphVariableDefinitionContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

GQLParser::BindingVariableContext* GQLParser::GraphVariableDefinitionContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}

GQLParser::OptTypedGraphInitializerContext* GQLParser::GraphVariableDefinitionContext::optTypedGraphInitializer() {
  return getRuleContext<GQLParser::OptTypedGraphInitializerContext>(0);
}

tree::TerminalNode* GQLParser::GraphVariableDefinitionContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}


size_t GQLParser::GraphVariableDefinitionContext::getRuleIndex() const {
  return GQLParser::RuleGraphVariableDefinition;
}




//----------------- OptTypedGraphInitializerContext ------------------------------------------------------------------

GQLParser::OptTypedGraphInitializerContext::OptTypedGraphInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphInitializerContext* GQLParser::OptTypedGraphInitializerContext::graphInitializer() {
  return getRuleContext<GQLParser::GraphInitializerContext>(0);
}

GQLParser::GraphReferenceValueTypeContext* GQLParser::OptTypedGraphInitializerContext::graphReferenceValueType() {
  return getRuleContext<GQLParser::GraphReferenceValueTypeContext>(0);
}

GQLParser::TypedContext* GQLParser::OptTypedGraphInitializerContext::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}


size_t GQLParser::OptTypedGraphInitializerContext::getRuleIndex() const {
  return GQLParser::RuleOptTypedGraphInitializer;
}




//----------------- GraphInitializerContext ------------------------------------------------------------------

GQLParser::GraphInitializerContext::GraphInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GraphInitializerContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}

GQLParser::GraphExpressionContext* GQLParser::GraphInitializerContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}


size_t GQLParser::GraphInitializerContext::getRuleIndex() const {
  return GQLParser::RuleGraphInitializer;
}




//----------------- BindingTableVariableDefinitionContext ------------------------------------------------------------------

GQLParser::BindingTableVariableDefinitionContext::BindingTableVariableDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::BindingTableVariableDefinitionContext::TABLE() {
  return getToken(GQLParser::TABLE, 0);
}

GQLParser::BindingVariableContext* GQLParser::BindingTableVariableDefinitionContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}

GQLParser::OptTypedBindingTableInitializerContext* GQLParser::BindingTableVariableDefinitionContext::optTypedBindingTableInitializer() {
  return getRuleContext<GQLParser::OptTypedBindingTableInitializerContext>(0);
}

tree::TerminalNode* GQLParser::BindingTableVariableDefinitionContext::BINDING() {
  return getToken(GQLParser::BINDING, 0);
}


size_t GQLParser::BindingTableVariableDefinitionContext::getRuleIndex() const {
  return GQLParser::RuleBindingTableVariableDefinition;
}




//----------------- OptTypedBindingTableInitializerContext ------------------------------------------------------------------

GQLParser::OptTypedBindingTableInitializerContext::OptTypedBindingTableInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingTableInitializerContext* GQLParser::OptTypedBindingTableInitializerContext::bindingTableInitializer() {
  return getRuleContext<GQLParser::BindingTableInitializerContext>(0);
}

GQLParser::BindingTableReferenceValueTypeContext* GQLParser::OptTypedBindingTableInitializerContext::bindingTableReferenceValueType() {
  return getRuleContext<GQLParser::BindingTableReferenceValueTypeContext>(0);
}

GQLParser::TypedContext* GQLParser::OptTypedBindingTableInitializerContext::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}


size_t GQLParser::OptTypedBindingTableInitializerContext::getRuleIndex() const {
  return GQLParser::RuleOptTypedBindingTableInitializer;
}




//----------------- BindingTableInitializerContext ------------------------------------------------------------------

GQLParser::BindingTableInitializerContext::BindingTableInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::BindingTableInitializerContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}

GQLParser::BindingTableExpressionContext* GQLParser::BindingTableInitializerContext::bindingTableExpression() {
  return getRuleContext<GQLParser::BindingTableExpressionContext>(0);
}


size_t GQLParser::BindingTableInitializerContext::getRuleIndex() const {
  return GQLParser::RuleBindingTableInitializer;
}




//----------------- ValueVariableDefinitionContext ------------------------------------------------------------------

GQLParser::ValueVariableDefinitionContext::ValueVariableDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ValueVariableDefinitionContext::VALUE() {
  return getToken(GQLParser::VALUE, 0);
}

GQLParser::BindingVariableContext* GQLParser::ValueVariableDefinitionContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}

GQLParser::OptTypedValueInitializerContext* GQLParser::ValueVariableDefinitionContext::optTypedValueInitializer() {
  return getRuleContext<GQLParser::OptTypedValueInitializerContext>(0);
}


size_t GQLParser::ValueVariableDefinitionContext::getRuleIndex() const {
  return GQLParser::RuleValueVariableDefinition;
}




//----------------- OptTypedValueInitializerContext ------------------------------------------------------------------

GQLParser::OptTypedValueInitializerContext::OptTypedValueInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueInitializerContext* GQLParser::OptTypedValueInitializerContext::valueInitializer() {
  return getRuleContext<GQLParser::ValueInitializerContext>(0);
}

GQLParser::ValueTypeContext* GQLParser::OptTypedValueInitializerContext::valueType() {
  return getRuleContext<GQLParser::ValueTypeContext>(0);
}

GQLParser::TypedContext* GQLParser::OptTypedValueInitializerContext::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}


size_t GQLParser::OptTypedValueInitializerContext::getRuleIndex() const {
  return GQLParser::RuleOptTypedValueInitializer;
}




//----------------- ValueInitializerContext ------------------------------------------------------------------

GQLParser::ValueInitializerContext::ValueInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ValueInitializerContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}

GQLParser::ValueExpressionContext* GQLParser::ValueInitializerContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::ValueInitializerContext::getRuleIndex() const {
  return GQLParser::RuleValueInitializer;
}




//----------------- GraphExpressionContext ------------------------------------------------------------------

GQLParser::GraphExpressionContext::GraphExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ObjectExpressionPrimaryContext* GQLParser::GraphExpressionContext::objectExpressionPrimary() {
  return getRuleContext<GQLParser::ObjectExpressionPrimaryContext>(0);
}

GQLParser::GraphReferenceContext* GQLParser::GraphExpressionContext::graphReference() {
  return getRuleContext<GQLParser::GraphReferenceContext>(0);
}

GQLParser::ObjectNameOrBindingVariableContext* GQLParser::GraphExpressionContext::objectNameOrBindingVariable() {
  return getRuleContext<GQLParser::ObjectNameOrBindingVariableContext>(0);
}

GQLParser::CurrentGraphContext* GQLParser::GraphExpressionContext::currentGraph() {
  return getRuleContext<GQLParser::CurrentGraphContext>(0);
}


size_t GQLParser::GraphExpressionContext::getRuleIndex() const {
  return GQLParser::RuleGraphExpression;
}




//----------------- CurrentGraphContext ------------------------------------------------------------------

GQLParser::CurrentGraphContext::CurrentGraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CurrentGraphContext::CURRENT_PROPERTY_GRAPH() {
  return getToken(GQLParser::CURRENT_PROPERTY_GRAPH, 0);
}

tree::TerminalNode* GQLParser::CurrentGraphContext::CURRENT_GRAPH() {
  return getToken(GQLParser::CURRENT_GRAPH, 0);
}


size_t GQLParser::CurrentGraphContext::getRuleIndex() const {
  return GQLParser::RuleCurrentGraph;
}




//----------------- BindingTableExpressionContext ------------------------------------------------------------------

GQLParser::BindingTableExpressionContext::BindingTableExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NestedBindingTableQuerySpecificationContext* GQLParser::BindingTableExpressionContext::nestedBindingTableQuerySpecification() {
  return getRuleContext<GQLParser::NestedBindingTableQuerySpecificationContext>(0);
}

GQLParser::ObjectExpressionPrimaryContext* GQLParser::BindingTableExpressionContext::objectExpressionPrimary() {
  return getRuleContext<GQLParser::ObjectExpressionPrimaryContext>(0);
}

GQLParser::BindingTableReferenceContext* GQLParser::BindingTableExpressionContext::bindingTableReference() {
  return getRuleContext<GQLParser::BindingTableReferenceContext>(0);
}

GQLParser::ObjectNameOrBindingVariableContext* GQLParser::BindingTableExpressionContext::objectNameOrBindingVariable() {
  return getRuleContext<GQLParser::ObjectNameOrBindingVariableContext>(0);
}


size_t GQLParser::BindingTableExpressionContext::getRuleIndex() const {
  return GQLParser::RuleBindingTableExpression;
}




//----------------- NestedBindingTableQuerySpecificationContext ------------------------------------------------------------------

GQLParser::NestedBindingTableQuerySpecificationContext::NestedBindingTableQuerySpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NestedQuerySpecificationContext* GQLParser::NestedBindingTableQuerySpecificationContext::nestedQuerySpecification() {
  return getRuleContext<GQLParser::NestedQuerySpecificationContext>(0);
}


size_t GQLParser::NestedBindingTableQuerySpecificationContext::getRuleIndex() const {
  return GQLParser::RuleNestedBindingTableQuerySpecification;
}




//----------------- ObjectExpressionPrimaryContext ------------------------------------------------------------------

GQLParser::ObjectExpressionPrimaryContext::ObjectExpressionPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ObjectExpressionPrimaryContext::VARIABLE() {
  return getToken(GQLParser::VARIABLE, 0);
}

GQLParser::ValueExpressionPrimaryContext* GQLParser::ObjectExpressionPrimaryContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}

GQLParser::ParenthesizedValueExpressionContext* GQLParser::ObjectExpressionPrimaryContext::parenthesizedValueExpression() {
  return getRuleContext<GQLParser::ParenthesizedValueExpressionContext>(0);
}

GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext* GQLParser::ObjectExpressionPrimaryContext::nonParenthesizedValueExpressionPrimarySpecialCase() {
  return getRuleContext<GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext>(0);
}


size_t GQLParser::ObjectExpressionPrimaryContext::getRuleIndex() const {
  return GQLParser::RuleObjectExpressionPrimary;
}




//----------------- LinearCatalogModifyingStatementContext ------------------------------------------------------------------

GQLParser::LinearCatalogModifyingStatementContext::LinearCatalogModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SimpleCatalogModifyingStatementContext *> GQLParser::LinearCatalogModifyingStatementContext::simpleCatalogModifyingStatement() {
  return getRuleContexts<GQLParser::SimpleCatalogModifyingStatementContext>();
}

GQLParser::SimpleCatalogModifyingStatementContext* GQLParser::LinearCatalogModifyingStatementContext::simpleCatalogModifyingStatement(size_t i) {
  return getRuleContext<GQLParser::SimpleCatalogModifyingStatementContext>(i);
}


size_t GQLParser::LinearCatalogModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RuleLinearCatalogModifyingStatement;
}




//----------------- SimpleCatalogModifyingStatementContext ------------------------------------------------------------------

GQLParser::SimpleCatalogModifyingStatementContext::SimpleCatalogModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PrimitiveCatalogModifyingStatementContext* GQLParser::SimpleCatalogModifyingStatementContext::primitiveCatalogModifyingStatement() {
  return getRuleContext<GQLParser::PrimitiveCatalogModifyingStatementContext>(0);
}

GQLParser::CallCatalogModifyingProcedureStatementContext* GQLParser::SimpleCatalogModifyingStatementContext::callCatalogModifyingProcedureStatement() {
  return getRuleContext<GQLParser::CallCatalogModifyingProcedureStatementContext>(0);
}


size_t GQLParser::SimpleCatalogModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RuleSimpleCatalogModifyingStatement;
}




//----------------- PrimitiveCatalogModifyingStatementContext ------------------------------------------------------------------

GQLParser::PrimitiveCatalogModifyingStatementContext::PrimitiveCatalogModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CreateSchemaStatementContext* GQLParser::PrimitiveCatalogModifyingStatementContext::createSchemaStatement() {
  return getRuleContext<GQLParser::CreateSchemaStatementContext>(0);
}

GQLParser::DropSchemaStatementContext* GQLParser::PrimitiveCatalogModifyingStatementContext::dropSchemaStatement() {
  return getRuleContext<GQLParser::DropSchemaStatementContext>(0);
}

GQLParser::CreateGraphStatementContext* GQLParser::PrimitiveCatalogModifyingStatementContext::createGraphStatement() {
  return getRuleContext<GQLParser::CreateGraphStatementContext>(0);
}

GQLParser::DropGraphStatementContext* GQLParser::PrimitiveCatalogModifyingStatementContext::dropGraphStatement() {
  return getRuleContext<GQLParser::DropGraphStatementContext>(0);
}

GQLParser::CreateGraphTypeStatementContext* GQLParser::PrimitiveCatalogModifyingStatementContext::createGraphTypeStatement() {
  return getRuleContext<GQLParser::CreateGraphTypeStatementContext>(0);
}

GQLParser::DropGraphTypeStatementContext* GQLParser::PrimitiveCatalogModifyingStatementContext::dropGraphTypeStatement() {
  return getRuleContext<GQLParser::DropGraphTypeStatementContext>(0);
}


size_t GQLParser::PrimitiveCatalogModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RulePrimitiveCatalogModifyingStatement;
}




//----------------- CreateSchemaStatementContext ------------------------------------------------------------------

GQLParser::CreateSchemaStatementContext::CreateSchemaStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CreateSchemaStatementContext::CREATE() {
  return getToken(GQLParser::CREATE, 0);
}

tree::TerminalNode* GQLParser::CreateSchemaStatementContext::SCHEMA() {
  return getToken(GQLParser::SCHEMA, 0);
}

GQLParser::CatalogSchemaParentAndNameContext* GQLParser::CreateSchemaStatementContext::catalogSchemaParentAndName() {
  return getRuleContext<GQLParser::CatalogSchemaParentAndNameContext>(0);
}

tree::TerminalNode* GQLParser::CreateSchemaStatementContext::IF() {
  return getToken(GQLParser::IF, 0);
}

tree::TerminalNode* GQLParser::CreateSchemaStatementContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

tree::TerminalNode* GQLParser::CreateSchemaStatementContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}


size_t GQLParser::CreateSchemaStatementContext::getRuleIndex() const {
  return GQLParser::RuleCreateSchemaStatement;
}




//----------------- DropSchemaStatementContext ------------------------------------------------------------------

GQLParser::DropSchemaStatementContext::DropSchemaStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DropSchemaStatementContext::DROP() {
  return getToken(GQLParser::DROP, 0);
}

tree::TerminalNode* GQLParser::DropSchemaStatementContext::SCHEMA() {
  return getToken(GQLParser::SCHEMA, 0);
}

GQLParser::CatalogSchemaParentAndNameContext* GQLParser::DropSchemaStatementContext::catalogSchemaParentAndName() {
  return getRuleContext<GQLParser::CatalogSchemaParentAndNameContext>(0);
}

tree::TerminalNode* GQLParser::DropSchemaStatementContext::IF() {
  return getToken(GQLParser::IF, 0);
}

tree::TerminalNode* GQLParser::DropSchemaStatementContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}


size_t GQLParser::DropSchemaStatementContext::getRuleIndex() const {
  return GQLParser::RuleDropSchemaStatement;
}




//----------------- CreateGraphStatementContext ------------------------------------------------------------------

GQLParser::CreateGraphStatementContext::CreateGraphStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::CREATE() {
  return getToken(GQLParser::CREATE, 0);
}

GQLParser::CatalogGraphParentAndNameContext* GQLParser::CreateGraphStatementContext::catalogGraphParentAndName() {
  return getRuleContext<GQLParser::CatalogGraphParentAndNameContext>(0);
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::OR() {
  return getToken(GQLParser::OR, 0);
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::REPLACE() {
  return getToken(GQLParser::REPLACE, 0);
}

GQLParser::OpenGraphTypeContext* GQLParser::CreateGraphStatementContext::openGraphType() {
  return getRuleContext<GQLParser::OpenGraphTypeContext>(0);
}

GQLParser::OfGraphTypeContext* GQLParser::CreateGraphStatementContext::ofGraphType() {
  return getRuleContext<GQLParser::OfGraphTypeContext>(0);
}

GQLParser::GraphSourceContext* GQLParser::CreateGraphStatementContext::graphSource() {
  return getRuleContext<GQLParser::GraphSourceContext>(0);
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::IF() {
  return getToken(GQLParser::IF, 0);
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

tree::TerminalNode* GQLParser::CreateGraphStatementContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}


size_t GQLParser::CreateGraphStatementContext::getRuleIndex() const {
  return GQLParser::RuleCreateGraphStatement;
}




//----------------- OpenGraphTypeContext ------------------------------------------------------------------

GQLParser::OpenGraphTypeContext::OpenGraphTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::OpenGraphTypeContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

GQLParser::TypedContext* GQLParser::OpenGraphTypeContext::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}

tree::TerminalNode* GQLParser::OpenGraphTypeContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::OpenGraphTypeContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}


size_t GQLParser::OpenGraphTypeContext::getRuleIndex() const {
  return GQLParser::RuleOpenGraphType;
}




//----------------- OfGraphTypeContext ------------------------------------------------------------------

GQLParser::OfGraphTypeContext::OfGraphTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphTypeLikeGraphContext* GQLParser::OfGraphTypeContext::graphTypeLikeGraph() {
  return getRuleContext<GQLParser::GraphTypeLikeGraphContext>(0);
}

GQLParser::GraphTypeReferenceContext* GQLParser::OfGraphTypeContext::graphTypeReference() {
  return getRuleContext<GQLParser::GraphTypeReferenceContext>(0);
}

GQLParser::TypedContext* GQLParser::OfGraphTypeContext::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}

GQLParser::NestedGraphTypeSpecificationContext* GQLParser::OfGraphTypeContext::nestedGraphTypeSpecification() {
  return getRuleContext<GQLParser::NestedGraphTypeSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::OfGraphTypeContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::OfGraphTypeContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}


size_t GQLParser::OfGraphTypeContext::getRuleIndex() const {
  return GQLParser::RuleOfGraphType;
}




//----------------- GraphTypeLikeGraphContext ------------------------------------------------------------------

GQLParser::GraphTypeLikeGraphContext::GraphTypeLikeGraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GraphTypeLikeGraphContext::LIKE() {
  return getToken(GQLParser::LIKE, 0);
}

GQLParser::GraphExpressionContext* GQLParser::GraphTypeLikeGraphContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}


size_t GQLParser::GraphTypeLikeGraphContext::getRuleIndex() const {
  return GQLParser::RuleGraphTypeLikeGraph;
}




//----------------- GraphSourceContext ------------------------------------------------------------------

GQLParser::GraphSourceContext::GraphSourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GraphSourceContext::AS() {
  return getToken(GQLParser::AS, 0);
}

tree::TerminalNode* GQLParser::GraphSourceContext::COPY() {
  return getToken(GQLParser::COPY, 0);
}

tree::TerminalNode* GQLParser::GraphSourceContext::OF() {
  return getToken(GQLParser::OF, 0);
}

GQLParser::GraphExpressionContext* GQLParser::GraphSourceContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}


size_t GQLParser::GraphSourceContext::getRuleIndex() const {
  return GQLParser::RuleGraphSource;
}




//----------------- DropGraphStatementContext ------------------------------------------------------------------

GQLParser::DropGraphStatementContext::DropGraphStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DropGraphStatementContext::DROP() {
  return getToken(GQLParser::DROP, 0);
}

tree::TerminalNode* GQLParser::DropGraphStatementContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

GQLParser::CatalogGraphParentAndNameContext* GQLParser::DropGraphStatementContext::catalogGraphParentAndName() {
  return getRuleContext<GQLParser::CatalogGraphParentAndNameContext>(0);
}

tree::TerminalNode* GQLParser::DropGraphStatementContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

tree::TerminalNode* GQLParser::DropGraphStatementContext::IF() {
  return getToken(GQLParser::IF, 0);
}

tree::TerminalNode* GQLParser::DropGraphStatementContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}


size_t GQLParser::DropGraphStatementContext::getRuleIndex() const {
  return GQLParser::RuleDropGraphStatement;
}




//----------------- CreateGraphTypeStatementContext ------------------------------------------------------------------

GQLParser::CreateGraphTypeStatementContext::CreateGraphTypeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::CREATE() {
  return getToken(GQLParser::CREATE, 0);
}

GQLParser::CatalogGraphTypeParentAndNameContext* GQLParser::CreateGraphTypeStatementContext::catalogGraphTypeParentAndName() {
  return getRuleContext<GQLParser::CatalogGraphTypeParentAndNameContext>(0);
}

GQLParser::GraphTypeSourceContext* GQLParser::CreateGraphTypeStatementContext::graphTypeSource() {
  return getRuleContext<GQLParser::GraphTypeSourceContext>(0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::TYPE() {
  return getToken(GQLParser::TYPE, 0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::OR() {
  return getToken(GQLParser::OR, 0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::REPLACE() {
  return getToken(GQLParser::REPLACE, 0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::IF() {
  return getToken(GQLParser::IF, 0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

tree::TerminalNode* GQLParser::CreateGraphTypeStatementContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}


size_t GQLParser::CreateGraphTypeStatementContext::getRuleIndex() const {
  return GQLParser::RuleCreateGraphTypeStatement;
}




//----------------- GraphTypeSourceContext ------------------------------------------------------------------

GQLParser::GraphTypeSourceContext::GraphTypeSourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CopyOfGraphTypeContext* GQLParser::GraphTypeSourceContext::copyOfGraphType() {
  return getRuleContext<GQLParser::CopyOfGraphTypeContext>(0);
}

tree::TerminalNode* GQLParser::GraphTypeSourceContext::AS() {
  return getToken(GQLParser::AS, 0);
}

GQLParser::GraphTypeLikeGraphContext* GQLParser::GraphTypeSourceContext::graphTypeLikeGraph() {
  return getRuleContext<GQLParser::GraphTypeLikeGraphContext>(0);
}

GQLParser::NestedGraphTypeSpecificationContext* GQLParser::GraphTypeSourceContext::nestedGraphTypeSpecification() {
  return getRuleContext<GQLParser::NestedGraphTypeSpecificationContext>(0);
}


size_t GQLParser::GraphTypeSourceContext::getRuleIndex() const {
  return GQLParser::RuleGraphTypeSource;
}




//----------------- CopyOfGraphTypeContext ------------------------------------------------------------------

GQLParser::CopyOfGraphTypeContext::CopyOfGraphTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CopyOfGraphTypeContext::COPY() {
  return getToken(GQLParser::COPY, 0);
}

tree::TerminalNode* GQLParser::CopyOfGraphTypeContext::OF() {
  return getToken(GQLParser::OF, 0);
}

GQLParser::GraphTypeReferenceContext* GQLParser::CopyOfGraphTypeContext::graphTypeReference() {
  return getRuleContext<GQLParser::GraphTypeReferenceContext>(0);
}


size_t GQLParser::CopyOfGraphTypeContext::getRuleIndex() const {
  return GQLParser::RuleCopyOfGraphType;
}




//----------------- DropGraphTypeStatementContext ------------------------------------------------------------------

GQLParser::DropGraphTypeStatementContext::DropGraphTypeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DropGraphTypeStatementContext::DROP() {
  return getToken(GQLParser::DROP, 0);
}

tree::TerminalNode* GQLParser::DropGraphTypeStatementContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::DropGraphTypeStatementContext::TYPE() {
  return getToken(GQLParser::TYPE, 0);
}

GQLParser::CatalogGraphTypeParentAndNameContext* GQLParser::DropGraphTypeStatementContext::catalogGraphTypeParentAndName() {
  return getRuleContext<GQLParser::CatalogGraphTypeParentAndNameContext>(0);
}

tree::TerminalNode* GQLParser::DropGraphTypeStatementContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

tree::TerminalNode* GQLParser::DropGraphTypeStatementContext::IF() {
  return getToken(GQLParser::IF, 0);
}

tree::TerminalNode* GQLParser::DropGraphTypeStatementContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}


size_t GQLParser::DropGraphTypeStatementContext::getRuleIndex() const {
  return GQLParser::RuleDropGraphTypeStatement;
}




//----------------- CallCatalogModifyingProcedureStatementContext ------------------------------------------------------------------

GQLParser::CallCatalogModifyingProcedureStatementContext::CallCatalogModifyingProcedureStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CallProcedureStatementContext* GQLParser::CallCatalogModifyingProcedureStatementContext::callProcedureStatement() {
  return getRuleContext<GQLParser::CallProcedureStatementContext>(0);
}


size_t GQLParser::CallCatalogModifyingProcedureStatementContext::getRuleIndex() const {
  return GQLParser::RuleCallCatalogModifyingProcedureStatement;
}




//----------------- LinearDataModifyingStatementContext ------------------------------------------------------------------

GQLParser::LinearDataModifyingStatementContext::LinearDataModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FocusedLinearDataModifyingStatementContext* GQLParser::LinearDataModifyingStatementContext::focusedLinearDataModifyingStatement() {
  return getRuleContext<GQLParser::FocusedLinearDataModifyingStatementContext>(0);
}

GQLParser::AmbientLinearDataModifyingStatementContext* GQLParser::LinearDataModifyingStatementContext::ambientLinearDataModifyingStatement() {
  return getRuleContext<GQLParser::AmbientLinearDataModifyingStatementContext>(0);
}


size_t GQLParser::LinearDataModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RuleLinearDataModifyingStatement;
}




//----------------- FocusedLinearDataModifyingStatementContext ------------------------------------------------------------------

GQLParser::FocusedLinearDataModifyingStatementContext::FocusedLinearDataModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FocusedLinearDataModifyingStatementBodyContext* GQLParser::FocusedLinearDataModifyingStatementContext::focusedLinearDataModifyingStatementBody() {
  return getRuleContext<GQLParser::FocusedLinearDataModifyingStatementBodyContext>(0);
}

GQLParser::FocusedNestedDataModifyingProcedureSpecificationContext* GQLParser::FocusedLinearDataModifyingStatementContext::focusedNestedDataModifyingProcedureSpecification() {
  return getRuleContext<GQLParser::FocusedNestedDataModifyingProcedureSpecificationContext>(0);
}


size_t GQLParser::FocusedLinearDataModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RuleFocusedLinearDataModifyingStatement;
}




//----------------- FocusedLinearDataModifyingStatementBodyContext ------------------------------------------------------------------

GQLParser::FocusedLinearDataModifyingStatementBodyContext::FocusedLinearDataModifyingStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UseGraphClauseContext* GQLParser::FocusedLinearDataModifyingStatementBodyContext::useGraphClause() {
  return getRuleContext<GQLParser::UseGraphClauseContext>(0);
}

GQLParser::SimpleLinearDataAccessingStatementContext* GQLParser::FocusedLinearDataModifyingStatementBodyContext::simpleLinearDataAccessingStatement() {
  return getRuleContext<GQLParser::SimpleLinearDataAccessingStatementContext>(0);
}

GQLParser::PrimitiveResultStatementContext* GQLParser::FocusedLinearDataModifyingStatementBodyContext::primitiveResultStatement() {
  return getRuleContext<GQLParser::PrimitiveResultStatementContext>(0);
}


size_t GQLParser::FocusedLinearDataModifyingStatementBodyContext::getRuleIndex() const {
  return GQLParser::RuleFocusedLinearDataModifyingStatementBody;
}




//----------------- FocusedNestedDataModifyingProcedureSpecificationContext ------------------------------------------------------------------

GQLParser::FocusedNestedDataModifyingProcedureSpecificationContext::FocusedNestedDataModifyingProcedureSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UseGraphClauseContext* GQLParser::FocusedNestedDataModifyingProcedureSpecificationContext::useGraphClause() {
  return getRuleContext<GQLParser::UseGraphClauseContext>(0);
}

GQLParser::NestedDataModifyingProcedureSpecificationContext* GQLParser::FocusedNestedDataModifyingProcedureSpecificationContext::nestedDataModifyingProcedureSpecification() {
  return getRuleContext<GQLParser::NestedDataModifyingProcedureSpecificationContext>(0);
}


size_t GQLParser::FocusedNestedDataModifyingProcedureSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleFocusedNestedDataModifyingProcedureSpecification;
}




//----------------- AmbientLinearDataModifyingStatementContext ------------------------------------------------------------------

GQLParser::AmbientLinearDataModifyingStatementContext::AmbientLinearDataModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AmbientLinearDataModifyingStatementBodyContext* GQLParser::AmbientLinearDataModifyingStatementContext::ambientLinearDataModifyingStatementBody() {
  return getRuleContext<GQLParser::AmbientLinearDataModifyingStatementBodyContext>(0);
}

GQLParser::NestedDataModifyingProcedureSpecificationContext* GQLParser::AmbientLinearDataModifyingStatementContext::nestedDataModifyingProcedureSpecification() {
  return getRuleContext<GQLParser::NestedDataModifyingProcedureSpecificationContext>(0);
}


size_t GQLParser::AmbientLinearDataModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RuleAmbientLinearDataModifyingStatement;
}




//----------------- AmbientLinearDataModifyingStatementBodyContext ------------------------------------------------------------------

GQLParser::AmbientLinearDataModifyingStatementBodyContext::AmbientLinearDataModifyingStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimpleLinearDataAccessingStatementContext* GQLParser::AmbientLinearDataModifyingStatementBodyContext::simpleLinearDataAccessingStatement() {
  return getRuleContext<GQLParser::SimpleLinearDataAccessingStatementContext>(0);
}

GQLParser::PrimitiveResultStatementContext* GQLParser::AmbientLinearDataModifyingStatementBodyContext::primitiveResultStatement() {
  return getRuleContext<GQLParser::PrimitiveResultStatementContext>(0);
}


size_t GQLParser::AmbientLinearDataModifyingStatementBodyContext::getRuleIndex() const {
  return GQLParser::RuleAmbientLinearDataModifyingStatementBody;
}




//----------------- SimpleLinearDataAccessingStatementContext ------------------------------------------------------------------

GQLParser::SimpleLinearDataAccessingStatementContext::SimpleLinearDataAccessingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SimpleDataAccessingStatementContext *> GQLParser::SimpleLinearDataAccessingStatementContext::simpleDataAccessingStatement() {
  return getRuleContexts<GQLParser::SimpleDataAccessingStatementContext>();
}

GQLParser::SimpleDataAccessingStatementContext* GQLParser::SimpleLinearDataAccessingStatementContext::simpleDataAccessingStatement(size_t i) {
  return getRuleContext<GQLParser::SimpleDataAccessingStatementContext>(i);
}


size_t GQLParser::SimpleLinearDataAccessingStatementContext::getRuleIndex() const {
  return GQLParser::RuleSimpleLinearDataAccessingStatement;
}




//----------------- SimpleDataAccessingStatementContext ------------------------------------------------------------------

GQLParser::SimpleDataAccessingStatementContext::SimpleDataAccessingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimpleQueryStatementContext* GQLParser::SimpleDataAccessingStatementContext::simpleQueryStatement() {
  return getRuleContext<GQLParser::SimpleQueryStatementContext>(0);
}

GQLParser::SimpleDataModifyingStatementContext* GQLParser::SimpleDataAccessingStatementContext::simpleDataModifyingStatement() {
  return getRuleContext<GQLParser::SimpleDataModifyingStatementContext>(0);
}


size_t GQLParser::SimpleDataAccessingStatementContext::getRuleIndex() const {
  return GQLParser::RuleSimpleDataAccessingStatement;
}




//----------------- SimpleDataModifyingStatementContext ------------------------------------------------------------------

GQLParser::SimpleDataModifyingStatementContext::SimpleDataModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PrimitiveDataModifyingStatementContext* GQLParser::SimpleDataModifyingStatementContext::primitiveDataModifyingStatement() {
  return getRuleContext<GQLParser::PrimitiveDataModifyingStatementContext>(0);
}

GQLParser::CallDataModifyingProcedureStatementContext* GQLParser::SimpleDataModifyingStatementContext::callDataModifyingProcedureStatement() {
  return getRuleContext<GQLParser::CallDataModifyingProcedureStatementContext>(0);
}


size_t GQLParser::SimpleDataModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RuleSimpleDataModifyingStatement;
}




//----------------- PrimitiveDataModifyingStatementContext ------------------------------------------------------------------

GQLParser::PrimitiveDataModifyingStatementContext::PrimitiveDataModifyingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::InsertStatementContext* GQLParser::PrimitiveDataModifyingStatementContext::insertStatement() {
  return getRuleContext<GQLParser::InsertStatementContext>(0);
}

GQLParser::SetStatementContext* GQLParser::PrimitiveDataModifyingStatementContext::setStatement() {
  return getRuleContext<GQLParser::SetStatementContext>(0);
}

GQLParser::RemoveStatementContext* GQLParser::PrimitiveDataModifyingStatementContext::removeStatement() {
  return getRuleContext<GQLParser::RemoveStatementContext>(0);
}

GQLParser::DeleteStatementContext* GQLParser::PrimitiveDataModifyingStatementContext::deleteStatement() {
  return getRuleContext<GQLParser::DeleteStatementContext>(0);
}


size_t GQLParser::PrimitiveDataModifyingStatementContext::getRuleIndex() const {
  return GQLParser::RulePrimitiveDataModifyingStatement;
}




//----------------- InsertStatementContext ------------------------------------------------------------------

GQLParser::InsertStatementContext::InsertStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::InsertStatementContext::INSERT() {
  return getToken(GQLParser::INSERT, 0);
}

GQLParser::InsertGraphPatternContext* GQLParser::InsertStatementContext::insertGraphPattern() {
  return getRuleContext<GQLParser::InsertGraphPatternContext>(0);
}


size_t GQLParser::InsertStatementContext::getRuleIndex() const {
  return GQLParser::RuleInsertStatement;
}




//----------------- SetStatementContext ------------------------------------------------------------------

GQLParser::SetStatementContext::SetStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SetStatementContext::SET() {
  return getToken(GQLParser::SET, 0);
}

GQLParser::SetItemListContext* GQLParser::SetStatementContext::setItemList() {
  return getRuleContext<GQLParser::SetItemListContext>(0);
}


size_t GQLParser::SetStatementContext::getRuleIndex() const {
  return GQLParser::RuleSetStatement;
}




//----------------- SetItemListContext ------------------------------------------------------------------

GQLParser::SetItemListContext::SetItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SetItemContext *> GQLParser::SetItemListContext::setItem() {
  return getRuleContexts<GQLParser::SetItemContext>();
}

GQLParser::SetItemContext* GQLParser::SetItemListContext::setItem(size_t i) {
  return getRuleContext<GQLParser::SetItemContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SetItemListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::SetItemListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::SetItemListContext::getRuleIndex() const {
  return GQLParser::RuleSetItemList;
}




//----------------- SetItemContext ------------------------------------------------------------------

GQLParser::SetItemContext::SetItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SetPropertyItemContext* GQLParser::SetItemContext::setPropertyItem() {
  return getRuleContext<GQLParser::SetPropertyItemContext>(0);
}

GQLParser::SetAllPropertiesItemContext* GQLParser::SetItemContext::setAllPropertiesItem() {
  return getRuleContext<GQLParser::SetAllPropertiesItemContext>(0);
}

GQLParser::SetLabelItemContext* GQLParser::SetItemContext::setLabelItem() {
  return getRuleContext<GQLParser::SetLabelItemContext>(0);
}


size_t GQLParser::SetItemContext::getRuleIndex() const {
  return GQLParser::RuleSetItem;
}




//----------------- SetPropertyItemContext ------------------------------------------------------------------

GQLParser::SetPropertyItemContext::SetPropertyItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::SetPropertyItemContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}

tree::TerminalNode* GQLParser::SetPropertyItemContext::PERIOD() {
  return getToken(GQLParser::PERIOD, 0);
}

GQLParser::PropertyNameContext* GQLParser::SetPropertyItemContext::propertyName() {
  return getRuleContext<GQLParser::PropertyNameContext>(0);
}

tree::TerminalNode* GQLParser::SetPropertyItemContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}

GQLParser::ValueExpressionContext* GQLParser::SetPropertyItemContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::SetPropertyItemContext::getRuleIndex() const {
  return GQLParser::RuleSetPropertyItem;
}




//----------------- SetAllPropertiesItemContext ------------------------------------------------------------------

GQLParser::SetAllPropertiesItemContext::SetAllPropertiesItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::SetAllPropertiesItemContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}

tree::TerminalNode* GQLParser::SetAllPropertiesItemContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}

tree::TerminalNode* GQLParser::SetAllPropertiesItemContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

tree::TerminalNode* GQLParser::SetAllPropertiesItemContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}

GQLParser::PropertyKeyValuePairListContext* GQLParser::SetAllPropertiesItemContext::propertyKeyValuePairList() {
  return getRuleContext<GQLParser::PropertyKeyValuePairListContext>(0);
}


size_t GQLParser::SetAllPropertiesItemContext::getRuleIndex() const {
  return GQLParser::RuleSetAllPropertiesItem;
}




//----------------- SetLabelItemContext ------------------------------------------------------------------

GQLParser::SetLabelItemContext::SetLabelItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::SetLabelItemContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}

GQLParser::IsOrColonContext* GQLParser::SetLabelItemContext::isOrColon() {
  return getRuleContext<GQLParser::IsOrColonContext>(0);
}

GQLParser::LabelNameContext* GQLParser::SetLabelItemContext::labelName() {
  return getRuleContext<GQLParser::LabelNameContext>(0);
}


size_t GQLParser::SetLabelItemContext::getRuleIndex() const {
  return GQLParser::RuleSetLabelItem;
}




//----------------- RemoveStatementContext ------------------------------------------------------------------

GQLParser::RemoveStatementContext::RemoveStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::RemoveStatementContext::REMOVE() {
  return getToken(GQLParser::REMOVE, 0);
}

GQLParser::RemoveItemListContext* GQLParser::RemoveStatementContext::removeItemList() {
  return getRuleContext<GQLParser::RemoveItemListContext>(0);
}


size_t GQLParser::RemoveStatementContext::getRuleIndex() const {
  return GQLParser::RuleRemoveStatement;
}




//----------------- RemoveItemListContext ------------------------------------------------------------------

GQLParser::RemoveItemListContext::RemoveItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::RemoveItemContext *> GQLParser::RemoveItemListContext::removeItem() {
  return getRuleContexts<GQLParser::RemoveItemContext>();
}

GQLParser::RemoveItemContext* GQLParser::RemoveItemListContext::removeItem(size_t i) {
  return getRuleContext<GQLParser::RemoveItemContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::RemoveItemListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::RemoveItemListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::RemoveItemListContext::getRuleIndex() const {
  return GQLParser::RuleRemoveItemList;
}




//----------------- RemoveItemContext ------------------------------------------------------------------

GQLParser::RemoveItemContext::RemoveItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RemovePropertyItemContext* GQLParser::RemoveItemContext::removePropertyItem() {
  return getRuleContext<GQLParser::RemovePropertyItemContext>(0);
}

GQLParser::RemoveLabelItemContext* GQLParser::RemoveItemContext::removeLabelItem() {
  return getRuleContext<GQLParser::RemoveLabelItemContext>(0);
}


size_t GQLParser::RemoveItemContext::getRuleIndex() const {
  return GQLParser::RuleRemoveItem;
}




//----------------- RemovePropertyItemContext ------------------------------------------------------------------

GQLParser::RemovePropertyItemContext::RemovePropertyItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::RemovePropertyItemContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}

tree::TerminalNode* GQLParser::RemovePropertyItemContext::PERIOD() {
  return getToken(GQLParser::PERIOD, 0);
}

GQLParser::PropertyNameContext* GQLParser::RemovePropertyItemContext::propertyName() {
  return getRuleContext<GQLParser::PropertyNameContext>(0);
}


size_t GQLParser::RemovePropertyItemContext::getRuleIndex() const {
  return GQLParser::RuleRemovePropertyItem;
}




//----------------- RemoveLabelItemContext ------------------------------------------------------------------

GQLParser::RemoveLabelItemContext::RemoveLabelItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::RemoveLabelItemContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}

GQLParser::IsOrColonContext* GQLParser::RemoveLabelItemContext::isOrColon() {
  return getRuleContext<GQLParser::IsOrColonContext>(0);
}

GQLParser::LabelNameContext* GQLParser::RemoveLabelItemContext::labelName() {
  return getRuleContext<GQLParser::LabelNameContext>(0);
}


size_t GQLParser::RemoveLabelItemContext::getRuleIndex() const {
  return GQLParser::RuleRemoveLabelItem;
}




//----------------- DeleteStatementContext ------------------------------------------------------------------

GQLParser::DeleteStatementContext::DeleteStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DeleteStatementContext::DELETE() {
  return getToken(GQLParser::DELETE, 0);
}

GQLParser::DeleteItemListContext* GQLParser::DeleteStatementContext::deleteItemList() {
  return getRuleContext<GQLParser::DeleteItemListContext>(0);
}

tree::TerminalNode* GQLParser::DeleteStatementContext::DETACH() {
  return getToken(GQLParser::DETACH, 0);
}

tree::TerminalNode* GQLParser::DeleteStatementContext::NODETACH() {
  return getToken(GQLParser::NODETACH, 0);
}


size_t GQLParser::DeleteStatementContext::getRuleIndex() const {
  return GQLParser::RuleDeleteStatement;
}




//----------------- DeleteItemListContext ------------------------------------------------------------------

GQLParser::DeleteItemListContext::DeleteItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::DeleteItemContext *> GQLParser::DeleteItemListContext::deleteItem() {
  return getRuleContexts<GQLParser::DeleteItemContext>();
}

GQLParser::DeleteItemContext* GQLParser::DeleteItemListContext::deleteItem(size_t i) {
  return getRuleContext<GQLParser::DeleteItemContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::DeleteItemListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::DeleteItemListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::DeleteItemListContext::getRuleIndex() const {
  return GQLParser::RuleDeleteItemList;
}




//----------------- DeleteItemContext ------------------------------------------------------------------

GQLParser::DeleteItemContext::DeleteItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::DeleteItemContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::DeleteItemContext::getRuleIndex() const {
  return GQLParser::RuleDeleteItem;
}




//----------------- CallDataModifyingProcedureStatementContext ------------------------------------------------------------------

GQLParser::CallDataModifyingProcedureStatementContext::CallDataModifyingProcedureStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CallProcedureStatementContext* GQLParser::CallDataModifyingProcedureStatementContext::callProcedureStatement() {
  return getRuleContext<GQLParser::CallProcedureStatementContext>(0);
}


size_t GQLParser::CallDataModifyingProcedureStatementContext::getRuleIndex() const {
  return GQLParser::RuleCallDataModifyingProcedureStatement;
}




//----------------- CompositeQueryStatementContext ------------------------------------------------------------------

GQLParser::CompositeQueryStatementContext::CompositeQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CompositeQueryExpressionContext* GQLParser::CompositeQueryStatementContext::compositeQueryExpression() {
  return getRuleContext<GQLParser::CompositeQueryExpressionContext>(0);
}


size_t GQLParser::CompositeQueryStatementContext::getRuleIndex() const {
  return GQLParser::RuleCompositeQueryStatement;
}




//----------------- CompositeQueryExpressionContext ------------------------------------------------------------------

GQLParser::CompositeQueryExpressionContext::CompositeQueryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CompositeQueryPrimaryContext* GQLParser::CompositeQueryExpressionContext::compositeQueryPrimary() {
  return getRuleContext<GQLParser::CompositeQueryPrimaryContext>(0);
}

GQLParser::CompositeQueryExpressionContext* GQLParser::CompositeQueryExpressionContext::compositeQueryExpression() {
  return getRuleContext<GQLParser::CompositeQueryExpressionContext>(0);
}

GQLParser::QueryConjunctionContext* GQLParser::CompositeQueryExpressionContext::queryConjunction() {
  return getRuleContext<GQLParser::QueryConjunctionContext>(0);
}


size_t GQLParser::CompositeQueryExpressionContext::getRuleIndex() const {
  return GQLParser::RuleCompositeQueryExpression;
}




//----------------- QueryConjunctionContext ------------------------------------------------------------------

GQLParser::QueryConjunctionContext::QueryConjunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SetOperatorContext* GQLParser::QueryConjunctionContext::setOperator() {
  return getRuleContext<GQLParser::SetOperatorContext>(0);
}

tree::TerminalNode* GQLParser::QueryConjunctionContext::OTHERWISE() {
  return getToken(GQLParser::OTHERWISE, 0);
}


size_t GQLParser::QueryConjunctionContext::getRuleIndex() const {
  return GQLParser::RuleQueryConjunction;
}




//----------------- SetOperatorContext ------------------------------------------------------------------

GQLParser::SetOperatorContext::SetOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SetOperatorContext::UNION() {
  return getToken(GQLParser::UNION, 0);
}

GQLParser::SetQuantifierContext* GQLParser::SetOperatorContext::setQuantifier() {
  return getRuleContext<GQLParser::SetQuantifierContext>(0);
}

tree::TerminalNode* GQLParser::SetOperatorContext::EXCEPT() {
  return getToken(GQLParser::EXCEPT, 0);
}

tree::TerminalNode* GQLParser::SetOperatorContext::INTERSECT() {
  return getToken(GQLParser::INTERSECT, 0);
}


size_t GQLParser::SetOperatorContext::getRuleIndex() const {
  return GQLParser::RuleSetOperator;
}




//----------------- CompositeQueryPrimaryContext ------------------------------------------------------------------

GQLParser::CompositeQueryPrimaryContext::CompositeQueryPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::LinearQueryStatementContext* GQLParser::CompositeQueryPrimaryContext::linearQueryStatement() {
  return getRuleContext<GQLParser::LinearQueryStatementContext>(0);
}


size_t GQLParser::CompositeQueryPrimaryContext::getRuleIndex() const {
  return GQLParser::RuleCompositeQueryPrimary;
}




//----------------- LinearQueryStatementContext ------------------------------------------------------------------

GQLParser::LinearQueryStatementContext::LinearQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FocusedLinearQueryStatementContext* GQLParser::LinearQueryStatementContext::focusedLinearQueryStatement() {
  return getRuleContext<GQLParser::FocusedLinearQueryStatementContext>(0);
}

GQLParser::AmbientLinearQueryStatementContext* GQLParser::LinearQueryStatementContext::ambientLinearQueryStatement() {
  return getRuleContext<GQLParser::AmbientLinearQueryStatementContext>(0);
}


size_t GQLParser::LinearQueryStatementContext::getRuleIndex() const {
  return GQLParser::RuleLinearQueryStatement;
}




//----------------- FocusedLinearQueryStatementContext ------------------------------------------------------------------

GQLParser::FocusedLinearQueryStatementContext::FocusedLinearQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FocusedLinearQueryAndPrimitiveResultStatementPartContext* GQLParser::FocusedLinearQueryStatementContext::focusedLinearQueryAndPrimitiveResultStatementPart() {
  return getRuleContext<GQLParser::FocusedLinearQueryAndPrimitiveResultStatementPartContext>(0);
}

std::vector<GQLParser::FocusedLinearQueryStatementPartContext *> GQLParser::FocusedLinearQueryStatementContext::focusedLinearQueryStatementPart() {
  return getRuleContexts<GQLParser::FocusedLinearQueryStatementPartContext>();
}

GQLParser::FocusedLinearQueryStatementPartContext* GQLParser::FocusedLinearQueryStatementContext::focusedLinearQueryStatementPart(size_t i) {
  return getRuleContext<GQLParser::FocusedLinearQueryStatementPartContext>(i);
}

GQLParser::FocusedPrimitiveResultStatementContext* GQLParser::FocusedLinearQueryStatementContext::focusedPrimitiveResultStatement() {
  return getRuleContext<GQLParser::FocusedPrimitiveResultStatementContext>(0);
}

GQLParser::FocusedNestedQuerySpecificationContext* GQLParser::FocusedLinearQueryStatementContext::focusedNestedQuerySpecification() {
  return getRuleContext<GQLParser::FocusedNestedQuerySpecificationContext>(0);
}

GQLParser::SelectStatementContext* GQLParser::FocusedLinearQueryStatementContext::selectStatement() {
  return getRuleContext<GQLParser::SelectStatementContext>(0);
}


size_t GQLParser::FocusedLinearQueryStatementContext::getRuleIndex() const {
  return GQLParser::RuleFocusedLinearQueryStatement;
}




//----------------- FocusedLinearQueryStatementPartContext ------------------------------------------------------------------

GQLParser::FocusedLinearQueryStatementPartContext::FocusedLinearQueryStatementPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UseGraphClauseContext* GQLParser::FocusedLinearQueryStatementPartContext::useGraphClause() {
  return getRuleContext<GQLParser::UseGraphClauseContext>(0);
}

GQLParser::SimpleLinearQueryStatementContext* GQLParser::FocusedLinearQueryStatementPartContext::simpleLinearQueryStatement() {
  return getRuleContext<GQLParser::SimpleLinearQueryStatementContext>(0);
}


size_t GQLParser::FocusedLinearQueryStatementPartContext::getRuleIndex() const {
  return GQLParser::RuleFocusedLinearQueryStatementPart;
}




//----------------- FocusedLinearQueryAndPrimitiveResultStatementPartContext ------------------------------------------------------------------

GQLParser::FocusedLinearQueryAndPrimitiveResultStatementPartContext::FocusedLinearQueryAndPrimitiveResultStatementPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UseGraphClauseContext* GQLParser::FocusedLinearQueryAndPrimitiveResultStatementPartContext::useGraphClause() {
  return getRuleContext<GQLParser::UseGraphClauseContext>(0);
}

GQLParser::SimpleLinearQueryStatementContext* GQLParser::FocusedLinearQueryAndPrimitiveResultStatementPartContext::simpleLinearQueryStatement() {
  return getRuleContext<GQLParser::SimpleLinearQueryStatementContext>(0);
}

GQLParser::PrimitiveResultStatementContext* GQLParser::FocusedLinearQueryAndPrimitiveResultStatementPartContext::primitiveResultStatement() {
  return getRuleContext<GQLParser::PrimitiveResultStatementContext>(0);
}


size_t GQLParser::FocusedLinearQueryAndPrimitiveResultStatementPartContext::getRuleIndex() const {
  return GQLParser::RuleFocusedLinearQueryAndPrimitiveResultStatementPart;
}




//----------------- FocusedPrimitiveResultStatementContext ------------------------------------------------------------------

GQLParser::FocusedPrimitiveResultStatementContext::FocusedPrimitiveResultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UseGraphClauseContext* GQLParser::FocusedPrimitiveResultStatementContext::useGraphClause() {
  return getRuleContext<GQLParser::UseGraphClauseContext>(0);
}

GQLParser::PrimitiveResultStatementContext* GQLParser::FocusedPrimitiveResultStatementContext::primitiveResultStatement() {
  return getRuleContext<GQLParser::PrimitiveResultStatementContext>(0);
}


size_t GQLParser::FocusedPrimitiveResultStatementContext::getRuleIndex() const {
  return GQLParser::RuleFocusedPrimitiveResultStatement;
}




//----------------- FocusedNestedQuerySpecificationContext ------------------------------------------------------------------

GQLParser::FocusedNestedQuerySpecificationContext::FocusedNestedQuerySpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UseGraphClauseContext* GQLParser::FocusedNestedQuerySpecificationContext::useGraphClause() {
  return getRuleContext<GQLParser::UseGraphClauseContext>(0);
}

GQLParser::NestedQuerySpecificationContext* GQLParser::FocusedNestedQuerySpecificationContext::nestedQuerySpecification() {
  return getRuleContext<GQLParser::NestedQuerySpecificationContext>(0);
}


size_t GQLParser::FocusedNestedQuerySpecificationContext::getRuleIndex() const {
  return GQLParser::RuleFocusedNestedQuerySpecification;
}




//----------------- AmbientLinearQueryStatementContext ------------------------------------------------------------------

GQLParser::AmbientLinearQueryStatementContext::AmbientLinearQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PrimitiveResultStatementContext* GQLParser::AmbientLinearQueryStatementContext::primitiveResultStatement() {
  return getRuleContext<GQLParser::PrimitiveResultStatementContext>(0);
}

GQLParser::SimpleLinearQueryStatementContext* GQLParser::AmbientLinearQueryStatementContext::simpleLinearQueryStatement() {
  return getRuleContext<GQLParser::SimpleLinearQueryStatementContext>(0);
}

GQLParser::NestedQuerySpecificationContext* GQLParser::AmbientLinearQueryStatementContext::nestedQuerySpecification() {
  return getRuleContext<GQLParser::NestedQuerySpecificationContext>(0);
}


size_t GQLParser::AmbientLinearQueryStatementContext::getRuleIndex() const {
  return GQLParser::RuleAmbientLinearQueryStatement;
}




//----------------- SimpleLinearQueryStatementContext ------------------------------------------------------------------

GQLParser::SimpleLinearQueryStatementContext::SimpleLinearQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SimpleQueryStatementContext *> GQLParser::SimpleLinearQueryStatementContext::simpleQueryStatement() {
  return getRuleContexts<GQLParser::SimpleQueryStatementContext>();
}

GQLParser::SimpleQueryStatementContext* GQLParser::SimpleLinearQueryStatementContext::simpleQueryStatement(size_t i) {
  return getRuleContext<GQLParser::SimpleQueryStatementContext>(i);
}


size_t GQLParser::SimpleLinearQueryStatementContext::getRuleIndex() const {
  return GQLParser::RuleSimpleLinearQueryStatement;
}




//----------------- SimpleQueryStatementContext ------------------------------------------------------------------

GQLParser::SimpleQueryStatementContext::SimpleQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PrimitiveQueryStatementContext* GQLParser::SimpleQueryStatementContext::primitiveQueryStatement() {
  return getRuleContext<GQLParser::PrimitiveQueryStatementContext>(0);
}

GQLParser::CallQueryStatementContext* GQLParser::SimpleQueryStatementContext::callQueryStatement() {
  return getRuleContext<GQLParser::CallQueryStatementContext>(0);
}


size_t GQLParser::SimpleQueryStatementContext::getRuleIndex() const {
  return GQLParser::RuleSimpleQueryStatement;
}




//----------------- PrimitiveQueryStatementContext ------------------------------------------------------------------

GQLParser::PrimitiveQueryStatementContext::PrimitiveQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::MatchStatementContext* GQLParser::PrimitiveQueryStatementContext::matchStatement() {
  return getRuleContext<GQLParser::MatchStatementContext>(0);
}

GQLParser::LetStatementContext* GQLParser::PrimitiveQueryStatementContext::letStatement() {
  return getRuleContext<GQLParser::LetStatementContext>(0);
}

GQLParser::ForStatementContext* GQLParser::PrimitiveQueryStatementContext::forStatement() {
  return getRuleContext<GQLParser::ForStatementContext>(0);
}

GQLParser::FilterStatementContext* GQLParser::PrimitiveQueryStatementContext::filterStatement() {
  return getRuleContext<GQLParser::FilterStatementContext>(0);
}

GQLParser::OrderByAndPageStatementContext* GQLParser::PrimitiveQueryStatementContext::orderByAndPageStatement() {
  return getRuleContext<GQLParser::OrderByAndPageStatementContext>(0);
}


size_t GQLParser::PrimitiveQueryStatementContext::getRuleIndex() const {
  return GQLParser::RulePrimitiveQueryStatement;
}




//----------------- MatchStatementContext ------------------------------------------------------------------

GQLParser::MatchStatementContext::MatchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimpleMatchStatementContext* GQLParser::MatchStatementContext::simpleMatchStatement() {
  return getRuleContext<GQLParser::SimpleMatchStatementContext>(0);
}

GQLParser::OptionalMatchStatementContext* GQLParser::MatchStatementContext::optionalMatchStatement() {
  return getRuleContext<GQLParser::OptionalMatchStatementContext>(0);
}


size_t GQLParser::MatchStatementContext::getRuleIndex() const {
  return GQLParser::RuleMatchStatement;
}




//----------------- SimpleMatchStatementContext ------------------------------------------------------------------

GQLParser::SimpleMatchStatementContext::SimpleMatchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimpleMatchStatementContext::MATCH() {
  return getToken(GQLParser::MATCH, 0);
}

GQLParser::GraphPatternBindingTableContext* GQLParser::SimpleMatchStatementContext::graphPatternBindingTable() {
  return getRuleContext<GQLParser::GraphPatternBindingTableContext>(0);
}


size_t GQLParser::SimpleMatchStatementContext::getRuleIndex() const {
  return GQLParser::RuleSimpleMatchStatement;
}




//----------------- OptionalMatchStatementContext ------------------------------------------------------------------

GQLParser::OptionalMatchStatementContext::OptionalMatchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::OptionalMatchStatementContext::OPTIONAL() {
  return getToken(GQLParser::OPTIONAL, 0);
}

GQLParser::OptionalOperandContext* GQLParser::OptionalMatchStatementContext::optionalOperand() {
  return getRuleContext<GQLParser::OptionalOperandContext>(0);
}


size_t GQLParser::OptionalMatchStatementContext::getRuleIndex() const {
  return GQLParser::RuleOptionalMatchStatement;
}




//----------------- OptionalOperandContext ------------------------------------------------------------------

GQLParser::OptionalOperandContext::OptionalOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimpleMatchStatementContext* GQLParser::OptionalOperandContext::simpleMatchStatement() {
  return getRuleContext<GQLParser::SimpleMatchStatementContext>(0);
}

tree::TerminalNode* GQLParser::OptionalOperandContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::MatchStatementBlockContext* GQLParser::OptionalOperandContext::matchStatementBlock() {
  return getRuleContext<GQLParser::MatchStatementBlockContext>(0);
}

tree::TerminalNode* GQLParser::OptionalOperandContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}

tree::TerminalNode* GQLParser::OptionalOperandContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::OptionalOperandContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::OptionalOperandContext::getRuleIndex() const {
  return GQLParser::RuleOptionalOperand;
}




//----------------- MatchStatementBlockContext ------------------------------------------------------------------

GQLParser::MatchStatementBlockContext::MatchStatementBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::MatchStatementContext *> GQLParser::MatchStatementBlockContext::matchStatement() {
  return getRuleContexts<GQLParser::MatchStatementContext>();
}

GQLParser::MatchStatementContext* GQLParser::MatchStatementBlockContext::matchStatement(size_t i) {
  return getRuleContext<GQLParser::MatchStatementContext>(i);
}


size_t GQLParser::MatchStatementBlockContext::getRuleIndex() const {
  return GQLParser::RuleMatchStatementBlock;
}




//----------------- CallQueryStatementContext ------------------------------------------------------------------

GQLParser::CallQueryStatementContext::CallQueryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CallProcedureStatementContext* GQLParser::CallQueryStatementContext::callProcedureStatement() {
  return getRuleContext<GQLParser::CallProcedureStatementContext>(0);
}


size_t GQLParser::CallQueryStatementContext::getRuleIndex() const {
  return GQLParser::RuleCallQueryStatement;
}




//----------------- FilterStatementContext ------------------------------------------------------------------

GQLParser::FilterStatementContext::FilterStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FilterStatementContext::FILTER() {
  return getToken(GQLParser::FILTER, 0);
}

GQLParser::WhereClauseContext* GQLParser::FilterStatementContext::whereClause() {
  return getRuleContext<GQLParser::WhereClauseContext>(0);
}

GQLParser::SearchConditionContext* GQLParser::FilterStatementContext::searchCondition() {
  return getRuleContext<GQLParser::SearchConditionContext>(0);
}


size_t GQLParser::FilterStatementContext::getRuleIndex() const {
  return GQLParser::RuleFilterStatement;
}




//----------------- LetStatementContext ------------------------------------------------------------------

GQLParser::LetStatementContext::LetStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LetStatementContext::LET() {
  return getToken(GQLParser::LET, 0);
}

GQLParser::LetVariableDefinitionListContext* GQLParser::LetStatementContext::letVariableDefinitionList() {
  return getRuleContext<GQLParser::LetVariableDefinitionListContext>(0);
}


size_t GQLParser::LetStatementContext::getRuleIndex() const {
  return GQLParser::RuleLetStatement;
}




//----------------- LetVariableDefinitionListContext ------------------------------------------------------------------

GQLParser::LetVariableDefinitionListContext::LetVariableDefinitionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::LetVariableDefinitionContext *> GQLParser::LetVariableDefinitionListContext::letVariableDefinition() {
  return getRuleContexts<GQLParser::LetVariableDefinitionContext>();
}

GQLParser::LetVariableDefinitionContext* GQLParser::LetVariableDefinitionListContext::letVariableDefinition(size_t i) {
  return getRuleContext<GQLParser::LetVariableDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::LetVariableDefinitionListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::LetVariableDefinitionListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::LetVariableDefinitionListContext::getRuleIndex() const {
  return GQLParser::RuleLetVariableDefinitionList;
}




//----------------- LetVariableDefinitionContext ------------------------------------------------------------------

GQLParser::LetVariableDefinitionContext::LetVariableDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueVariableDefinitionContext* GQLParser::LetVariableDefinitionContext::valueVariableDefinition() {
  return getRuleContext<GQLParser::ValueVariableDefinitionContext>(0);
}

GQLParser::BindingVariableContext* GQLParser::LetVariableDefinitionContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}

tree::TerminalNode* GQLParser::LetVariableDefinitionContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}

GQLParser::ValueExpressionContext* GQLParser::LetVariableDefinitionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::LetVariableDefinitionContext::getRuleIndex() const {
  return GQLParser::RuleLetVariableDefinition;
}




//----------------- ForStatementContext ------------------------------------------------------------------

GQLParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ForStatementContext::FOR() {
  return getToken(GQLParser::FOR, 0);
}

GQLParser::ForItemContext* GQLParser::ForStatementContext::forItem() {
  return getRuleContext<GQLParser::ForItemContext>(0);
}

GQLParser::ForOrdinalityOrOffsetContext* GQLParser::ForStatementContext::forOrdinalityOrOffset() {
  return getRuleContext<GQLParser::ForOrdinalityOrOffsetContext>(0);
}


size_t GQLParser::ForStatementContext::getRuleIndex() const {
  return GQLParser::RuleForStatement;
}




//----------------- ForItemContext ------------------------------------------------------------------

GQLParser::ForItemContext::ForItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ForItemAliasContext* GQLParser::ForItemContext::forItemAlias() {
  return getRuleContext<GQLParser::ForItemAliasContext>(0);
}

GQLParser::ForItemSourceContext* GQLParser::ForItemContext::forItemSource() {
  return getRuleContext<GQLParser::ForItemSourceContext>(0);
}


size_t GQLParser::ForItemContext::getRuleIndex() const {
  return GQLParser::RuleForItem;
}




//----------------- ForItemAliasContext ------------------------------------------------------------------

GQLParser::ForItemAliasContext::ForItemAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableContext* GQLParser::ForItemAliasContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}

tree::TerminalNode* GQLParser::ForItemAliasContext::IN() {
  return getToken(GQLParser::IN, 0);
}


size_t GQLParser::ForItemAliasContext::getRuleIndex() const {
  return GQLParser::RuleForItemAlias;
}




//----------------- ForItemSourceContext ------------------------------------------------------------------

GQLParser::ForItemSourceContext::ForItemSourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::ForItemSourceContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::ForItemSourceContext::getRuleIndex() const {
  return GQLParser::RuleForItemSource;
}




//----------------- ForOrdinalityOrOffsetContext ------------------------------------------------------------------

GQLParser::ForOrdinalityOrOffsetContext::ForOrdinalityOrOffsetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ForOrdinalityOrOffsetContext::WITH() {
  return getToken(GQLParser::WITH, 0);
}

GQLParser::BindingVariableContext* GQLParser::ForOrdinalityOrOffsetContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}

tree::TerminalNode* GQLParser::ForOrdinalityOrOffsetContext::ORDINALITY() {
  return getToken(GQLParser::ORDINALITY, 0);
}

tree::TerminalNode* GQLParser::ForOrdinalityOrOffsetContext::OFFSET() {
  return getToken(GQLParser::OFFSET, 0);
}


size_t GQLParser::ForOrdinalityOrOffsetContext::getRuleIndex() const {
  return GQLParser::RuleForOrdinalityOrOffset;
}




//----------------- OrderByAndPageStatementContext ------------------------------------------------------------------

GQLParser::OrderByAndPageStatementContext::OrderByAndPageStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::OrderByClauseContext* GQLParser::OrderByAndPageStatementContext::orderByClause() {
  return getRuleContext<GQLParser::OrderByClauseContext>(0);
}

GQLParser::OffsetClauseContext* GQLParser::OrderByAndPageStatementContext::offsetClause() {
  return getRuleContext<GQLParser::OffsetClauseContext>(0);
}

GQLParser::LimitClauseContext* GQLParser::OrderByAndPageStatementContext::limitClause() {
  return getRuleContext<GQLParser::LimitClauseContext>(0);
}


size_t GQLParser::OrderByAndPageStatementContext::getRuleIndex() const {
  return GQLParser::RuleOrderByAndPageStatement;
}




//----------------- PrimitiveResultStatementContext ------------------------------------------------------------------

GQLParser::PrimitiveResultStatementContext::PrimitiveResultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ReturnStatementContext* GQLParser::PrimitiveResultStatementContext::returnStatement() {
  return getRuleContext<GQLParser::ReturnStatementContext>(0);
}

GQLParser::OrderByAndPageStatementContext* GQLParser::PrimitiveResultStatementContext::orderByAndPageStatement() {
  return getRuleContext<GQLParser::OrderByAndPageStatementContext>(0);
}

tree::TerminalNode* GQLParser::PrimitiveResultStatementContext::FINISH() {
  return getToken(GQLParser::FINISH, 0);
}


size_t GQLParser::PrimitiveResultStatementContext::getRuleIndex() const {
  return GQLParser::RulePrimitiveResultStatement;
}




//----------------- ReturnStatementContext ------------------------------------------------------------------

GQLParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ReturnStatementContext::RETURN() {
  return getToken(GQLParser::RETURN, 0);
}

GQLParser::ReturnStatementBodyContext* GQLParser::ReturnStatementContext::returnStatementBody() {
  return getRuleContext<GQLParser::ReturnStatementBodyContext>(0);
}


size_t GQLParser::ReturnStatementContext::getRuleIndex() const {
  return GQLParser::RuleReturnStatement;
}




//----------------- ReturnStatementBodyContext ------------------------------------------------------------------

GQLParser::ReturnStatementBodyContext::ReturnStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ReturnStatementBodyContext::ASTERISK() {
  return getToken(GQLParser::ASTERISK, 0);
}

GQLParser::ReturnItemListContext* GQLParser::ReturnStatementBodyContext::returnItemList() {
  return getRuleContext<GQLParser::ReturnItemListContext>(0);
}

GQLParser::SetQuantifierContext* GQLParser::ReturnStatementBodyContext::setQuantifier() {
  return getRuleContext<GQLParser::SetQuantifierContext>(0);
}

GQLParser::GroupByClauseContext* GQLParser::ReturnStatementBodyContext::groupByClause() {
  return getRuleContext<GQLParser::GroupByClauseContext>(0);
}

tree::TerminalNode* GQLParser::ReturnStatementBodyContext::NO() {
  return getToken(GQLParser::NO, 0);
}

tree::TerminalNode* GQLParser::ReturnStatementBodyContext::BINDINGS() {
  return getToken(GQLParser::BINDINGS, 0);
}


size_t GQLParser::ReturnStatementBodyContext::getRuleIndex() const {
  return GQLParser::RuleReturnStatementBody;
}




//----------------- ReturnItemListContext ------------------------------------------------------------------

GQLParser::ReturnItemListContext::ReturnItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::ReturnItemContext *> GQLParser::ReturnItemListContext::returnItem() {
  return getRuleContexts<GQLParser::ReturnItemContext>();
}

GQLParser::ReturnItemContext* GQLParser::ReturnItemListContext::returnItem(size_t i) {
  return getRuleContext<GQLParser::ReturnItemContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::ReturnItemListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::ReturnItemListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::ReturnItemListContext::getRuleIndex() const {
  return GQLParser::RuleReturnItemList;
}




//----------------- ReturnItemContext ------------------------------------------------------------------

GQLParser::ReturnItemContext::ReturnItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AggregatingValueExpressionContext* GQLParser::ReturnItemContext::aggregatingValueExpression() {
  return getRuleContext<GQLParser::AggregatingValueExpressionContext>(0);
}

GQLParser::ReturnItemAliasContext* GQLParser::ReturnItemContext::returnItemAlias() {
  return getRuleContext<GQLParser::ReturnItemAliasContext>(0);
}


size_t GQLParser::ReturnItemContext::getRuleIndex() const {
  return GQLParser::RuleReturnItem;
}




//----------------- ReturnItemAliasContext ------------------------------------------------------------------

GQLParser::ReturnItemAliasContext::ReturnItemAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ReturnItemAliasContext::AS() {
  return getToken(GQLParser::AS, 0);
}

GQLParser::IdentifierContext* GQLParser::ReturnItemAliasContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::ReturnItemAliasContext::getRuleIndex() const {
  return GQLParser::RuleReturnItemAlias;
}




//----------------- SelectStatementContext ------------------------------------------------------------------

GQLParser::SelectStatementContext::SelectStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SelectStatementContext::SELECT() {
  return getToken(GQLParser::SELECT, 0);
}

tree::TerminalNode* GQLParser::SelectStatementContext::ASTERISK() {
  return getToken(GQLParser::ASTERISK, 0);
}

GQLParser::SelectItemListContext* GQLParser::SelectStatementContext::selectItemList() {
  return getRuleContext<GQLParser::SelectItemListContext>(0);
}

GQLParser::SetQuantifierContext* GQLParser::SelectStatementContext::setQuantifier() {
  return getRuleContext<GQLParser::SetQuantifierContext>(0);
}

GQLParser::SelectStatementBodyContext* GQLParser::SelectStatementContext::selectStatementBody() {
  return getRuleContext<GQLParser::SelectStatementBodyContext>(0);
}

GQLParser::WhereClauseContext* GQLParser::SelectStatementContext::whereClause() {
  return getRuleContext<GQLParser::WhereClauseContext>(0);
}

GQLParser::GroupByClauseContext* GQLParser::SelectStatementContext::groupByClause() {
  return getRuleContext<GQLParser::GroupByClauseContext>(0);
}

GQLParser::HavingClauseContext* GQLParser::SelectStatementContext::havingClause() {
  return getRuleContext<GQLParser::HavingClauseContext>(0);
}

GQLParser::OrderByClauseContext* GQLParser::SelectStatementContext::orderByClause() {
  return getRuleContext<GQLParser::OrderByClauseContext>(0);
}

GQLParser::OffsetClauseContext* GQLParser::SelectStatementContext::offsetClause() {
  return getRuleContext<GQLParser::OffsetClauseContext>(0);
}

GQLParser::LimitClauseContext* GQLParser::SelectStatementContext::limitClause() {
  return getRuleContext<GQLParser::LimitClauseContext>(0);
}


size_t GQLParser::SelectStatementContext::getRuleIndex() const {
  return GQLParser::RuleSelectStatement;
}




//----------------- SelectItemListContext ------------------------------------------------------------------

GQLParser::SelectItemListContext::SelectItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SelectItemContext *> GQLParser::SelectItemListContext::selectItem() {
  return getRuleContexts<GQLParser::SelectItemContext>();
}

GQLParser::SelectItemContext* GQLParser::SelectItemListContext::selectItem(size_t i) {
  return getRuleContext<GQLParser::SelectItemContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SelectItemListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::SelectItemListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::SelectItemListContext::getRuleIndex() const {
  return GQLParser::RuleSelectItemList;
}




//----------------- SelectItemContext ------------------------------------------------------------------

GQLParser::SelectItemContext::SelectItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AggregatingValueExpressionContext* GQLParser::SelectItemContext::aggregatingValueExpression() {
  return getRuleContext<GQLParser::AggregatingValueExpressionContext>(0);
}

GQLParser::SelectItemAliasContext* GQLParser::SelectItemContext::selectItemAlias() {
  return getRuleContext<GQLParser::SelectItemAliasContext>(0);
}


size_t GQLParser::SelectItemContext::getRuleIndex() const {
  return GQLParser::RuleSelectItem;
}




//----------------- SelectItemAliasContext ------------------------------------------------------------------

GQLParser::SelectItemAliasContext::SelectItemAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SelectItemAliasContext::AS() {
  return getToken(GQLParser::AS, 0);
}

GQLParser::IdentifierContext* GQLParser::SelectItemAliasContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::SelectItemAliasContext::getRuleIndex() const {
  return GQLParser::RuleSelectItemAlias;
}




//----------------- HavingClauseContext ------------------------------------------------------------------

GQLParser::HavingClauseContext::HavingClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::HavingClauseContext::HAVING() {
  return getToken(GQLParser::HAVING, 0);
}

GQLParser::SearchConditionContext* GQLParser::HavingClauseContext::searchCondition() {
  return getRuleContext<GQLParser::SearchConditionContext>(0);
}


size_t GQLParser::HavingClauseContext::getRuleIndex() const {
  return GQLParser::RuleHavingClause;
}




//----------------- SelectStatementBodyContext ------------------------------------------------------------------

GQLParser::SelectStatementBodyContext::SelectStatementBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SelectStatementBodyContext::FROM() {
  return getToken(GQLParser::FROM, 0);
}

GQLParser::SelectGraphMatchListContext* GQLParser::SelectStatementBodyContext::selectGraphMatchList() {
  return getRuleContext<GQLParser::SelectGraphMatchListContext>(0);
}

GQLParser::SelectQuerySpecificationContext* GQLParser::SelectStatementBodyContext::selectQuerySpecification() {
  return getRuleContext<GQLParser::SelectQuerySpecificationContext>(0);
}


size_t GQLParser::SelectStatementBodyContext::getRuleIndex() const {
  return GQLParser::RuleSelectStatementBody;
}




//----------------- SelectGraphMatchListContext ------------------------------------------------------------------

GQLParser::SelectGraphMatchListContext::SelectGraphMatchListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SelectGraphMatchContext *> GQLParser::SelectGraphMatchListContext::selectGraphMatch() {
  return getRuleContexts<GQLParser::SelectGraphMatchContext>();
}

GQLParser::SelectGraphMatchContext* GQLParser::SelectGraphMatchListContext::selectGraphMatch(size_t i) {
  return getRuleContext<GQLParser::SelectGraphMatchContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SelectGraphMatchListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::SelectGraphMatchListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::SelectGraphMatchListContext::getRuleIndex() const {
  return GQLParser::RuleSelectGraphMatchList;
}




//----------------- SelectGraphMatchContext ------------------------------------------------------------------

GQLParser::SelectGraphMatchContext::SelectGraphMatchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphExpressionContext* GQLParser::SelectGraphMatchContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}

GQLParser::MatchStatementContext* GQLParser::SelectGraphMatchContext::matchStatement() {
  return getRuleContext<GQLParser::MatchStatementContext>(0);
}


size_t GQLParser::SelectGraphMatchContext::getRuleIndex() const {
  return GQLParser::RuleSelectGraphMatch;
}




//----------------- SelectQuerySpecificationContext ------------------------------------------------------------------

GQLParser::SelectQuerySpecificationContext::SelectQuerySpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NestedQuerySpecificationContext* GQLParser::SelectQuerySpecificationContext::nestedQuerySpecification() {
  return getRuleContext<GQLParser::NestedQuerySpecificationContext>(0);
}

GQLParser::GraphExpressionContext* GQLParser::SelectQuerySpecificationContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}


size_t GQLParser::SelectQuerySpecificationContext::getRuleIndex() const {
  return GQLParser::RuleSelectQuerySpecification;
}




//----------------- CallProcedureStatementContext ------------------------------------------------------------------

GQLParser::CallProcedureStatementContext::CallProcedureStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CallProcedureStatementContext::CALL() {
  return getToken(GQLParser::CALL, 0);
}

GQLParser::ProcedureCallContext* GQLParser::CallProcedureStatementContext::procedureCall() {
  return getRuleContext<GQLParser::ProcedureCallContext>(0);
}

tree::TerminalNode* GQLParser::CallProcedureStatementContext::OPTIONAL() {
  return getToken(GQLParser::OPTIONAL, 0);
}


size_t GQLParser::CallProcedureStatementContext::getRuleIndex() const {
  return GQLParser::RuleCallProcedureStatement;
}




//----------------- ProcedureCallContext ------------------------------------------------------------------

GQLParser::ProcedureCallContext::ProcedureCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::InlineProcedureCallContext* GQLParser::ProcedureCallContext::inlineProcedureCall() {
  return getRuleContext<GQLParser::InlineProcedureCallContext>(0);
}

GQLParser::NamedProcedureCallContext* GQLParser::ProcedureCallContext::namedProcedureCall() {
  return getRuleContext<GQLParser::NamedProcedureCallContext>(0);
}


size_t GQLParser::ProcedureCallContext::getRuleIndex() const {
  return GQLParser::RuleProcedureCall;
}




//----------------- InlineProcedureCallContext ------------------------------------------------------------------

GQLParser::InlineProcedureCallContext::InlineProcedureCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NestedProcedureSpecificationContext* GQLParser::InlineProcedureCallContext::nestedProcedureSpecification() {
  return getRuleContext<GQLParser::NestedProcedureSpecificationContext>(0);
}

GQLParser::VariableScopeClauseContext* GQLParser::InlineProcedureCallContext::variableScopeClause() {
  return getRuleContext<GQLParser::VariableScopeClauseContext>(0);
}


size_t GQLParser::InlineProcedureCallContext::getRuleIndex() const {
  return GQLParser::RuleInlineProcedureCall;
}




//----------------- VariableScopeClauseContext ------------------------------------------------------------------

GQLParser::VariableScopeClauseContext::VariableScopeClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::VariableScopeClauseContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::VariableScopeClauseContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::BindingVariableReferenceListContext* GQLParser::VariableScopeClauseContext::bindingVariableReferenceList() {
  return getRuleContext<GQLParser::BindingVariableReferenceListContext>(0);
}


size_t GQLParser::VariableScopeClauseContext::getRuleIndex() const {
  return GQLParser::RuleVariableScopeClause;
}




//----------------- BindingVariableReferenceListContext ------------------------------------------------------------------

GQLParser::BindingVariableReferenceListContext::BindingVariableReferenceListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::BindingVariableReferenceContext *> GQLParser::BindingVariableReferenceListContext::bindingVariableReference() {
  return getRuleContexts<GQLParser::BindingVariableReferenceContext>();
}

GQLParser::BindingVariableReferenceContext* GQLParser::BindingVariableReferenceListContext::bindingVariableReference(size_t i) {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::BindingVariableReferenceListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::BindingVariableReferenceListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::BindingVariableReferenceListContext::getRuleIndex() const {
  return GQLParser::RuleBindingVariableReferenceList;
}




//----------------- NamedProcedureCallContext ------------------------------------------------------------------

GQLParser::NamedProcedureCallContext::NamedProcedureCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ProcedureReferenceContext* GQLParser::NamedProcedureCallContext::procedureReference() {
  return getRuleContext<GQLParser::ProcedureReferenceContext>(0);
}

tree::TerminalNode* GQLParser::NamedProcedureCallContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::NamedProcedureCallContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::ProcedureArgumentListContext* GQLParser::NamedProcedureCallContext::procedureArgumentList() {
  return getRuleContext<GQLParser::ProcedureArgumentListContext>(0);
}

GQLParser::YieldClauseContext* GQLParser::NamedProcedureCallContext::yieldClause() {
  return getRuleContext<GQLParser::YieldClauseContext>(0);
}


size_t GQLParser::NamedProcedureCallContext::getRuleIndex() const {
  return GQLParser::RuleNamedProcedureCall;
}




//----------------- ProcedureArgumentListContext ------------------------------------------------------------------

GQLParser::ProcedureArgumentListContext::ProcedureArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::ProcedureArgumentContext *> GQLParser::ProcedureArgumentListContext::procedureArgument() {
  return getRuleContexts<GQLParser::ProcedureArgumentContext>();
}

GQLParser::ProcedureArgumentContext* GQLParser::ProcedureArgumentListContext::procedureArgument(size_t i) {
  return getRuleContext<GQLParser::ProcedureArgumentContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::ProcedureArgumentListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::ProcedureArgumentListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::ProcedureArgumentListContext::getRuleIndex() const {
  return GQLParser::RuleProcedureArgumentList;
}




//----------------- ProcedureArgumentContext ------------------------------------------------------------------

GQLParser::ProcedureArgumentContext::ProcedureArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::ProcedureArgumentContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::ProcedureArgumentContext::getRuleIndex() const {
  return GQLParser::RuleProcedureArgument;
}




//----------------- AtSchemaClauseContext ------------------------------------------------------------------

GQLParser::AtSchemaClauseContext::AtSchemaClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AtSchemaClauseContext::AT() {
  return getToken(GQLParser::AT, 0);
}

GQLParser::SchemaReferenceContext* GQLParser::AtSchemaClauseContext::schemaReference() {
  return getRuleContext<GQLParser::SchemaReferenceContext>(0);
}


size_t GQLParser::AtSchemaClauseContext::getRuleIndex() const {
  return GQLParser::RuleAtSchemaClause;
}




//----------------- UseGraphClauseContext ------------------------------------------------------------------

GQLParser::UseGraphClauseContext::UseGraphClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::UseGraphClauseContext::USE() {
  return getToken(GQLParser::USE, 0);
}

GQLParser::GraphExpressionContext* GQLParser::UseGraphClauseContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}


size_t GQLParser::UseGraphClauseContext::getRuleIndex() const {
  return GQLParser::RuleUseGraphClause;
}




//----------------- GraphPatternBindingTableContext ------------------------------------------------------------------

GQLParser::GraphPatternBindingTableContext::GraphPatternBindingTableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphPatternContext* GQLParser::GraphPatternBindingTableContext::graphPattern() {
  return getRuleContext<GQLParser::GraphPatternContext>(0);
}

GQLParser::GraphPatternYieldClauseContext* GQLParser::GraphPatternBindingTableContext::graphPatternYieldClause() {
  return getRuleContext<GQLParser::GraphPatternYieldClauseContext>(0);
}


size_t GQLParser::GraphPatternBindingTableContext::getRuleIndex() const {
  return GQLParser::RuleGraphPatternBindingTable;
}




//----------------- GraphPatternYieldClauseContext ------------------------------------------------------------------

GQLParser::GraphPatternYieldClauseContext::GraphPatternYieldClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GraphPatternYieldClauseContext::YIELD() {
  return getToken(GQLParser::YIELD, 0);
}

GQLParser::GraphPatternYieldItemListContext* GQLParser::GraphPatternYieldClauseContext::graphPatternYieldItemList() {
  return getRuleContext<GQLParser::GraphPatternYieldItemListContext>(0);
}


size_t GQLParser::GraphPatternYieldClauseContext::getRuleIndex() const {
  return GQLParser::RuleGraphPatternYieldClause;
}




//----------------- GraphPatternYieldItemListContext ------------------------------------------------------------------

GQLParser::GraphPatternYieldItemListContext::GraphPatternYieldItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::GraphPatternYieldItemContext *> GQLParser::GraphPatternYieldItemListContext::graphPatternYieldItem() {
  return getRuleContexts<GQLParser::GraphPatternYieldItemContext>();
}

GQLParser::GraphPatternYieldItemContext* GQLParser::GraphPatternYieldItemListContext::graphPatternYieldItem(size_t i) {
  return getRuleContext<GQLParser::GraphPatternYieldItemContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::GraphPatternYieldItemListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::GraphPatternYieldItemListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}

tree::TerminalNode* GQLParser::GraphPatternYieldItemListContext::NO() {
  return getToken(GQLParser::NO, 0);
}

tree::TerminalNode* GQLParser::GraphPatternYieldItemListContext::BINDINGS() {
  return getToken(GQLParser::BINDINGS, 0);
}


size_t GQLParser::GraphPatternYieldItemListContext::getRuleIndex() const {
  return GQLParser::RuleGraphPatternYieldItemList;
}




//----------------- GraphPatternYieldItemContext ------------------------------------------------------------------

GQLParser::GraphPatternYieldItemContext::GraphPatternYieldItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::GraphPatternYieldItemContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}


size_t GQLParser::GraphPatternYieldItemContext::getRuleIndex() const {
  return GQLParser::RuleGraphPatternYieldItem;
}




//----------------- GraphPatternContext ------------------------------------------------------------------

GQLParser::GraphPatternContext::GraphPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PathPatternListContext* GQLParser::GraphPatternContext::pathPatternList() {
  return getRuleContext<GQLParser::PathPatternListContext>(0);
}

GQLParser::MatchModeContext* GQLParser::GraphPatternContext::matchMode() {
  return getRuleContext<GQLParser::MatchModeContext>(0);
}

GQLParser::KeepClauseContext* GQLParser::GraphPatternContext::keepClause() {
  return getRuleContext<GQLParser::KeepClauseContext>(0);
}

GQLParser::GraphPatternWhereClauseContext* GQLParser::GraphPatternContext::graphPatternWhereClause() {
  return getRuleContext<GQLParser::GraphPatternWhereClauseContext>(0);
}


size_t GQLParser::GraphPatternContext::getRuleIndex() const {
  return GQLParser::RuleGraphPattern;
}




//----------------- MatchModeContext ------------------------------------------------------------------

GQLParser::MatchModeContext::MatchModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RepeatableElementsMatchModeContext* GQLParser::MatchModeContext::repeatableElementsMatchMode() {
  return getRuleContext<GQLParser::RepeatableElementsMatchModeContext>(0);
}

GQLParser::DifferentEdgesMatchModeContext* GQLParser::MatchModeContext::differentEdgesMatchMode() {
  return getRuleContext<GQLParser::DifferentEdgesMatchModeContext>(0);
}


size_t GQLParser::MatchModeContext::getRuleIndex() const {
  return GQLParser::RuleMatchMode;
}




//----------------- RepeatableElementsMatchModeContext ------------------------------------------------------------------

GQLParser::RepeatableElementsMatchModeContext::RepeatableElementsMatchModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::RepeatableElementsMatchModeContext::REPEATABLE() {
  return getToken(GQLParser::REPEATABLE, 0);
}

GQLParser::ElementBindingsOrElementsContext* GQLParser::RepeatableElementsMatchModeContext::elementBindingsOrElements() {
  return getRuleContext<GQLParser::ElementBindingsOrElementsContext>(0);
}


size_t GQLParser::RepeatableElementsMatchModeContext::getRuleIndex() const {
  return GQLParser::RuleRepeatableElementsMatchMode;
}




//----------------- DifferentEdgesMatchModeContext ------------------------------------------------------------------

GQLParser::DifferentEdgesMatchModeContext::DifferentEdgesMatchModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DifferentEdgesMatchModeContext::DIFFERENT() {
  return getToken(GQLParser::DIFFERENT, 0);
}

GQLParser::EdgeBindingsOrEdgesContext* GQLParser::DifferentEdgesMatchModeContext::edgeBindingsOrEdges() {
  return getRuleContext<GQLParser::EdgeBindingsOrEdgesContext>(0);
}


size_t GQLParser::DifferentEdgesMatchModeContext::getRuleIndex() const {
  return GQLParser::RuleDifferentEdgesMatchMode;
}




//----------------- ElementBindingsOrElementsContext ------------------------------------------------------------------

GQLParser::ElementBindingsOrElementsContext::ElementBindingsOrElementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ElementBindingsOrElementsContext::ELEMENT() {
  return getToken(GQLParser::ELEMENT, 0);
}

tree::TerminalNode* GQLParser::ElementBindingsOrElementsContext::BINDINGS() {
  return getToken(GQLParser::BINDINGS, 0);
}

tree::TerminalNode* GQLParser::ElementBindingsOrElementsContext::ELEMENTS() {
  return getToken(GQLParser::ELEMENTS, 0);
}


size_t GQLParser::ElementBindingsOrElementsContext::getRuleIndex() const {
  return GQLParser::RuleElementBindingsOrElements;
}




//----------------- EdgeBindingsOrEdgesContext ------------------------------------------------------------------

GQLParser::EdgeBindingsOrEdgesContext::EdgeBindingsOrEdgesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeSynonymContext* GQLParser::EdgeBindingsOrEdgesContext::edgeSynonym() {
  return getRuleContext<GQLParser::EdgeSynonymContext>(0);
}

tree::TerminalNode* GQLParser::EdgeBindingsOrEdgesContext::BINDINGS() {
  return getToken(GQLParser::BINDINGS, 0);
}

GQLParser::EdgesSynonymContext* GQLParser::EdgeBindingsOrEdgesContext::edgesSynonym() {
  return getRuleContext<GQLParser::EdgesSynonymContext>(0);
}


size_t GQLParser::EdgeBindingsOrEdgesContext::getRuleIndex() const {
  return GQLParser::RuleEdgeBindingsOrEdges;
}




//----------------- PathPatternListContext ------------------------------------------------------------------

GQLParser::PathPatternListContext::PathPatternListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::PathPatternContext *> GQLParser::PathPatternListContext::pathPattern() {
  return getRuleContexts<GQLParser::PathPatternContext>();
}

GQLParser::PathPatternContext* GQLParser::PathPatternListContext::pathPattern(size_t i) {
  return getRuleContext<GQLParser::PathPatternContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::PathPatternListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::PathPatternListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::PathPatternListContext::getRuleIndex() const {
  return GQLParser::RulePathPatternList;
}




//----------------- PathPatternContext ------------------------------------------------------------------

GQLParser::PathPatternContext::PathPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PathPatternExpressionContext* GQLParser::PathPatternContext::pathPatternExpression() {
  return getRuleContext<GQLParser::PathPatternExpressionContext>(0);
}

GQLParser::PathVariableDeclarationContext* GQLParser::PathPatternContext::pathVariableDeclaration() {
  return getRuleContext<GQLParser::PathVariableDeclarationContext>(0);
}

GQLParser::PathPatternPrefixContext* GQLParser::PathPatternContext::pathPatternPrefix() {
  return getRuleContext<GQLParser::PathPatternPrefixContext>(0);
}


size_t GQLParser::PathPatternContext::getRuleIndex() const {
  return GQLParser::RulePathPattern;
}




//----------------- PathVariableDeclarationContext ------------------------------------------------------------------

GQLParser::PathVariableDeclarationContext::PathVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PathVariableContext* GQLParser::PathVariableDeclarationContext::pathVariable() {
  return getRuleContext<GQLParser::PathVariableContext>(0);
}

tree::TerminalNode* GQLParser::PathVariableDeclarationContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}


size_t GQLParser::PathVariableDeclarationContext::getRuleIndex() const {
  return GQLParser::RulePathVariableDeclaration;
}




//----------------- KeepClauseContext ------------------------------------------------------------------

GQLParser::KeepClauseContext::KeepClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::KeepClauseContext::KEEP() {
  return getToken(GQLParser::KEEP, 0);
}

GQLParser::PathPatternPrefixContext* GQLParser::KeepClauseContext::pathPatternPrefix() {
  return getRuleContext<GQLParser::PathPatternPrefixContext>(0);
}


size_t GQLParser::KeepClauseContext::getRuleIndex() const {
  return GQLParser::RuleKeepClause;
}




//----------------- GraphPatternWhereClauseContext ------------------------------------------------------------------

GQLParser::GraphPatternWhereClauseContext::GraphPatternWhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GraphPatternWhereClauseContext::WHERE() {
  return getToken(GQLParser::WHERE, 0);
}

GQLParser::SearchConditionContext* GQLParser::GraphPatternWhereClauseContext::searchCondition() {
  return getRuleContext<GQLParser::SearchConditionContext>(0);
}


size_t GQLParser::GraphPatternWhereClauseContext::getRuleIndex() const {
  return GQLParser::RuleGraphPatternWhereClause;
}




//----------------- InsertGraphPatternContext ------------------------------------------------------------------

GQLParser::InsertGraphPatternContext::InsertGraphPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::InsertPathPatternListContext* GQLParser::InsertGraphPatternContext::insertPathPatternList() {
  return getRuleContext<GQLParser::InsertPathPatternListContext>(0);
}


size_t GQLParser::InsertGraphPatternContext::getRuleIndex() const {
  return GQLParser::RuleInsertGraphPattern;
}




//----------------- InsertPathPatternListContext ------------------------------------------------------------------

GQLParser::InsertPathPatternListContext::InsertPathPatternListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::InsertPathPatternContext *> GQLParser::InsertPathPatternListContext::insertPathPattern() {
  return getRuleContexts<GQLParser::InsertPathPatternContext>();
}

GQLParser::InsertPathPatternContext* GQLParser::InsertPathPatternListContext::insertPathPattern(size_t i) {
  return getRuleContext<GQLParser::InsertPathPatternContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::InsertPathPatternListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::InsertPathPatternListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::InsertPathPatternListContext::getRuleIndex() const {
  return GQLParser::RuleInsertPathPatternList;
}




//----------------- InsertPathPatternContext ------------------------------------------------------------------

GQLParser::InsertPathPatternContext::InsertPathPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::InsertNodePatternContext *> GQLParser::InsertPathPatternContext::insertNodePattern() {
  return getRuleContexts<GQLParser::InsertNodePatternContext>();
}

GQLParser::InsertNodePatternContext* GQLParser::InsertPathPatternContext::insertNodePattern(size_t i) {
  return getRuleContext<GQLParser::InsertNodePatternContext>(i);
}

std::vector<GQLParser::InsertEdgePatternContext *> GQLParser::InsertPathPatternContext::insertEdgePattern() {
  return getRuleContexts<GQLParser::InsertEdgePatternContext>();
}

GQLParser::InsertEdgePatternContext* GQLParser::InsertPathPatternContext::insertEdgePattern(size_t i) {
  return getRuleContext<GQLParser::InsertEdgePatternContext>(i);
}


size_t GQLParser::InsertPathPatternContext::getRuleIndex() const {
  return GQLParser::RuleInsertPathPattern;
}




//----------------- InsertNodePatternContext ------------------------------------------------------------------

GQLParser::InsertNodePatternContext::InsertNodePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::InsertNodePatternContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::InsertNodePatternContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::InsertElementPatternFillerContext* GQLParser::InsertNodePatternContext::insertElementPatternFiller() {
  return getRuleContext<GQLParser::InsertElementPatternFillerContext>(0);
}


size_t GQLParser::InsertNodePatternContext::getRuleIndex() const {
  return GQLParser::RuleInsertNodePattern;
}




//----------------- InsertEdgePatternContext ------------------------------------------------------------------

GQLParser::InsertEdgePatternContext::InsertEdgePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::InsertEdgePointingLeftContext* GQLParser::InsertEdgePatternContext::insertEdgePointingLeft() {
  return getRuleContext<GQLParser::InsertEdgePointingLeftContext>(0);
}

GQLParser::InsertEdgePointingRightContext* GQLParser::InsertEdgePatternContext::insertEdgePointingRight() {
  return getRuleContext<GQLParser::InsertEdgePointingRightContext>(0);
}

GQLParser::InsertEdgeUndirectedContext* GQLParser::InsertEdgePatternContext::insertEdgeUndirected() {
  return getRuleContext<GQLParser::InsertEdgeUndirectedContext>(0);
}


size_t GQLParser::InsertEdgePatternContext::getRuleIndex() const {
  return GQLParser::RuleInsertEdgePattern;
}




//----------------- InsertEdgePointingLeftContext ------------------------------------------------------------------

GQLParser::InsertEdgePointingLeftContext::InsertEdgePointingLeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::InsertEdgePointingLeftContext::LEFT_ARROW_BRACKET() {
  return getToken(GQLParser::LEFT_ARROW_BRACKET, 0);
}

tree::TerminalNode* GQLParser::InsertEdgePointingLeftContext::RIGHT_BRACKET_MINUS() {
  return getToken(GQLParser::RIGHT_BRACKET_MINUS, 0);
}

GQLParser::InsertElementPatternFillerContext* GQLParser::InsertEdgePointingLeftContext::insertElementPatternFiller() {
  return getRuleContext<GQLParser::InsertElementPatternFillerContext>(0);
}


size_t GQLParser::InsertEdgePointingLeftContext::getRuleIndex() const {
  return GQLParser::RuleInsertEdgePointingLeft;
}




//----------------- InsertEdgePointingRightContext ------------------------------------------------------------------

GQLParser::InsertEdgePointingRightContext::InsertEdgePointingRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::InsertEdgePointingRightContext::MINUS_LEFT_BRACKET() {
  return getToken(GQLParser::MINUS_LEFT_BRACKET, 0);
}

tree::TerminalNode* GQLParser::InsertEdgePointingRightContext::BRACKET_RIGHT_ARROW() {
  return getToken(GQLParser::BRACKET_RIGHT_ARROW, 0);
}

GQLParser::InsertElementPatternFillerContext* GQLParser::InsertEdgePointingRightContext::insertElementPatternFiller() {
  return getRuleContext<GQLParser::InsertElementPatternFillerContext>(0);
}


size_t GQLParser::InsertEdgePointingRightContext::getRuleIndex() const {
  return GQLParser::RuleInsertEdgePointingRight;
}




//----------------- InsertEdgeUndirectedContext ------------------------------------------------------------------

GQLParser::InsertEdgeUndirectedContext::InsertEdgeUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::InsertEdgeUndirectedContext::TILDE_LEFT_BRACKET() {
  return getToken(GQLParser::TILDE_LEFT_BRACKET, 0);
}

tree::TerminalNode* GQLParser::InsertEdgeUndirectedContext::RIGHT_BRACKET_TILDE() {
  return getToken(GQLParser::RIGHT_BRACKET_TILDE, 0);
}

GQLParser::InsertElementPatternFillerContext* GQLParser::InsertEdgeUndirectedContext::insertElementPatternFiller() {
  return getRuleContext<GQLParser::InsertElementPatternFillerContext>(0);
}


size_t GQLParser::InsertEdgeUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleInsertEdgeUndirected;
}




//----------------- InsertElementPatternFillerContext ------------------------------------------------------------------

GQLParser::InsertElementPatternFillerContext::InsertElementPatternFillerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementVariableDeclarationContext* GQLParser::InsertElementPatternFillerContext::elementVariableDeclaration() {
  return getRuleContext<GQLParser::ElementVariableDeclarationContext>(0);
}

GQLParser::LabelAndPropertySetSpecificationContext* GQLParser::InsertElementPatternFillerContext::labelAndPropertySetSpecification() {
  return getRuleContext<GQLParser::LabelAndPropertySetSpecificationContext>(0);
}


size_t GQLParser::InsertElementPatternFillerContext::getRuleIndex() const {
  return GQLParser::RuleInsertElementPatternFiller;
}




//----------------- LabelAndPropertySetSpecificationContext ------------------------------------------------------------------

GQLParser::LabelAndPropertySetSpecificationContext::LabelAndPropertySetSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IsOrColonContext* GQLParser::LabelAndPropertySetSpecificationContext::isOrColon() {
  return getRuleContext<GQLParser::IsOrColonContext>(0);
}

GQLParser::LabelSetSpecificationContext* GQLParser::LabelAndPropertySetSpecificationContext::labelSetSpecification() {
  return getRuleContext<GQLParser::LabelSetSpecificationContext>(0);
}

GQLParser::ElementPropertySpecificationContext* GQLParser::LabelAndPropertySetSpecificationContext::elementPropertySpecification() {
  return getRuleContext<GQLParser::ElementPropertySpecificationContext>(0);
}


size_t GQLParser::LabelAndPropertySetSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleLabelAndPropertySetSpecification;
}




//----------------- PathPatternPrefixContext ------------------------------------------------------------------

GQLParser::PathPatternPrefixContext::PathPatternPrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PathModePrefixContext* GQLParser::PathPatternPrefixContext::pathModePrefix() {
  return getRuleContext<GQLParser::PathModePrefixContext>(0);
}

GQLParser::PathSearchPrefixContext* GQLParser::PathPatternPrefixContext::pathSearchPrefix() {
  return getRuleContext<GQLParser::PathSearchPrefixContext>(0);
}


size_t GQLParser::PathPatternPrefixContext::getRuleIndex() const {
  return GQLParser::RulePathPatternPrefix;
}




//----------------- PathModePrefixContext ------------------------------------------------------------------

GQLParser::PathModePrefixContext::PathModePrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PathModeContext* GQLParser::PathModePrefixContext::pathMode() {
  return getRuleContext<GQLParser::PathModeContext>(0);
}

GQLParser::PathOrPathsContext* GQLParser::PathModePrefixContext::pathOrPaths() {
  return getRuleContext<GQLParser::PathOrPathsContext>(0);
}


size_t GQLParser::PathModePrefixContext::getRuleIndex() const {
  return GQLParser::RulePathModePrefix;
}




//----------------- PathModeContext ------------------------------------------------------------------

GQLParser::PathModeContext::PathModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PathModeContext::WALK() {
  return getToken(GQLParser::WALK, 0);
}

tree::TerminalNode* GQLParser::PathModeContext::TRAIL() {
  return getToken(GQLParser::TRAIL, 0);
}

tree::TerminalNode* GQLParser::PathModeContext::SIMPLE() {
  return getToken(GQLParser::SIMPLE, 0);
}

tree::TerminalNode* GQLParser::PathModeContext::ACYCLIC() {
  return getToken(GQLParser::ACYCLIC, 0);
}


size_t GQLParser::PathModeContext::getRuleIndex() const {
  return GQLParser::RulePathMode;
}




//----------------- PathSearchPrefixContext ------------------------------------------------------------------

GQLParser::PathSearchPrefixContext::PathSearchPrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AllPathSearchContext* GQLParser::PathSearchPrefixContext::allPathSearch() {
  return getRuleContext<GQLParser::AllPathSearchContext>(0);
}

GQLParser::AnyPathSearchContext* GQLParser::PathSearchPrefixContext::anyPathSearch() {
  return getRuleContext<GQLParser::AnyPathSearchContext>(0);
}

GQLParser::ShortestPathSearchContext* GQLParser::PathSearchPrefixContext::shortestPathSearch() {
  return getRuleContext<GQLParser::ShortestPathSearchContext>(0);
}


size_t GQLParser::PathSearchPrefixContext::getRuleIndex() const {
  return GQLParser::RulePathSearchPrefix;
}




//----------------- AllPathSearchContext ------------------------------------------------------------------

GQLParser::AllPathSearchContext::AllPathSearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AllPathSearchContext::ALL() {
  return getToken(GQLParser::ALL, 0);
}

GQLParser::PathModeContext* GQLParser::AllPathSearchContext::pathMode() {
  return getRuleContext<GQLParser::PathModeContext>(0);
}

GQLParser::PathOrPathsContext* GQLParser::AllPathSearchContext::pathOrPaths() {
  return getRuleContext<GQLParser::PathOrPathsContext>(0);
}


size_t GQLParser::AllPathSearchContext::getRuleIndex() const {
  return GQLParser::RuleAllPathSearch;
}




//----------------- PathOrPathsContext ------------------------------------------------------------------

GQLParser::PathOrPathsContext::PathOrPathsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PathOrPathsContext::PATH() {
  return getToken(GQLParser::PATH, 0);
}

tree::TerminalNode* GQLParser::PathOrPathsContext::PATHS() {
  return getToken(GQLParser::PATHS, 0);
}


size_t GQLParser::PathOrPathsContext::getRuleIndex() const {
  return GQLParser::RulePathOrPaths;
}




//----------------- AnyPathSearchContext ------------------------------------------------------------------

GQLParser::AnyPathSearchContext::AnyPathSearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AnyPathSearchContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

GQLParser::NumberOfPathsContext* GQLParser::AnyPathSearchContext::numberOfPaths() {
  return getRuleContext<GQLParser::NumberOfPathsContext>(0);
}

GQLParser::PathModeContext* GQLParser::AnyPathSearchContext::pathMode() {
  return getRuleContext<GQLParser::PathModeContext>(0);
}

GQLParser::PathOrPathsContext* GQLParser::AnyPathSearchContext::pathOrPaths() {
  return getRuleContext<GQLParser::PathOrPathsContext>(0);
}


size_t GQLParser::AnyPathSearchContext::getRuleIndex() const {
  return GQLParser::RuleAnyPathSearch;
}




//----------------- NumberOfPathsContext ------------------------------------------------------------------

GQLParser::NumberOfPathsContext::NumberOfPathsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NonNegativeIntegerSpecificationContext* GQLParser::NumberOfPathsContext::nonNegativeIntegerSpecification() {
  return getRuleContext<GQLParser::NonNegativeIntegerSpecificationContext>(0);
}


size_t GQLParser::NumberOfPathsContext::getRuleIndex() const {
  return GQLParser::RuleNumberOfPaths;
}




//----------------- ShortestPathSearchContext ------------------------------------------------------------------

GQLParser::ShortestPathSearchContext::ShortestPathSearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AllShortestPathSearchContext* GQLParser::ShortestPathSearchContext::allShortestPathSearch() {
  return getRuleContext<GQLParser::AllShortestPathSearchContext>(0);
}

GQLParser::AnyShortestPathSearchContext* GQLParser::ShortestPathSearchContext::anyShortestPathSearch() {
  return getRuleContext<GQLParser::AnyShortestPathSearchContext>(0);
}

GQLParser::CountedShortestPathSearchContext* GQLParser::ShortestPathSearchContext::countedShortestPathSearch() {
  return getRuleContext<GQLParser::CountedShortestPathSearchContext>(0);
}

GQLParser::CountedShortestGroupSearchContext* GQLParser::ShortestPathSearchContext::countedShortestGroupSearch() {
  return getRuleContext<GQLParser::CountedShortestGroupSearchContext>(0);
}


size_t GQLParser::ShortestPathSearchContext::getRuleIndex() const {
  return GQLParser::RuleShortestPathSearch;
}




//----------------- AllShortestPathSearchContext ------------------------------------------------------------------

GQLParser::AllShortestPathSearchContext::AllShortestPathSearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AllShortestPathSearchContext::ALL() {
  return getToken(GQLParser::ALL, 0);
}

tree::TerminalNode* GQLParser::AllShortestPathSearchContext::SHORTEST() {
  return getToken(GQLParser::SHORTEST, 0);
}

GQLParser::PathModeContext* GQLParser::AllShortestPathSearchContext::pathMode() {
  return getRuleContext<GQLParser::PathModeContext>(0);
}

GQLParser::PathOrPathsContext* GQLParser::AllShortestPathSearchContext::pathOrPaths() {
  return getRuleContext<GQLParser::PathOrPathsContext>(0);
}


size_t GQLParser::AllShortestPathSearchContext::getRuleIndex() const {
  return GQLParser::RuleAllShortestPathSearch;
}




//----------------- AnyShortestPathSearchContext ------------------------------------------------------------------

GQLParser::AnyShortestPathSearchContext::AnyShortestPathSearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AnyShortestPathSearchContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

tree::TerminalNode* GQLParser::AnyShortestPathSearchContext::SHORTEST() {
  return getToken(GQLParser::SHORTEST, 0);
}

GQLParser::PathModeContext* GQLParser::AnyShortestPathSearchContext::pathMode() {
  return getRuleContext<GQLParser::PathModeContext>(0);
}

GQLParser::PathOrPathsContext* GQLParser::AnyShortestPathSearchContext::pathOrPaths() {
  return getRuleContext<GQLParser::PathOrPathsContext>(0);
}


size_t GQLParser::AnyShortestPathSearchContext::getRuleIndex() const {
  return GQLParser::RuleAnyShortestPathSearch;
}




//----------------- CountedShortestPathSearchContext ------------------------------------------------------------------

GQLParser::CountedShortestPathSearchContext::CountedShortestPathSearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CountedShortestPathSearchContext::SHORTEST() {
  return getToken(GQLParser::SHORTEST, 0);
}

GQLParser::NumberOfPathsContext* GQLParser::CountedShortestPathSearchContext::numberOfPaths() {
  return getRuleContext<GQLParser::NumberOfPathsContext>(0);
}

GQLParser::PathModeContext* GQLParser::CountedShortestPathSearchContext::pathMode() {
  return getRuleContext<GQLParser::PathModeContext>(0);
}

GQLParser::PathOrPathsContext* GQLParser::CountedShortestPathSearchContext::pathOrPaths() {
  return getRuleContext<GQLParser::PathOrPathsContext>(0);
}


size_t GQLParser::CountedShortestPathSearchContext::getRuleIndex() const {
  return GQLParser::RuleCountedShortestPathSearch;
}




//----------------- CountedShortestGroupSearchContext ------------------------------------------------------------------

GQLParser::CountedShortestGroupSearchContext::CountedShortestGroupSearchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CountedShortestGroupSearchContext::SHORTEST() {
  return getToken(GQLParser::SHORTEST, 0);
}

tree::TerminalNode* GQLParser::CountedShortestGroupSearchContext::GROUP() {
  return getToken(GQLParser::GROUP, 0);
}

tree::TerminalNode* GQLParser::CountedShortestGroupSearchContext::GROUPS() {
  return getToken(GQLParser::GROUPS, 0);
}

GQLParser::NumberOfGroupsContext* GQLParser::CountedShortestGroupSearchContext::numberOfGroups() {
  return getRuleContext<GQLParser::NumberOfGroupsContext>(0);
}

GQLParser::PathModeContext* GQLParser::CountedShortestGroupSearchContext::pathMode() {
  return getRuleContext<GQLParser::PathModeContext>(0);
}

GQLParser::PathOrPathsContext* GQLParser::CountedShortestGroupSearchContext::pathOrPaths() {
  return getRuleContext<GQLParser::PathOrPathsContext>(0);
}


size_t GQLParser::CountedShortestGroupSearchContext::getRuleIndex() const {
  return GQLParser::RuleCountedShortestGroupSearch;
}




//----------------- NumberOfGroupsContext ------------------------------------------------------------------

GQLParser::NumberOfGroupsContext::NumberOfGroupsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NonNegativeIntegerSpecificationContext* GQLParser::NumberOfGroupsContext::nonNegativeIntegerSpecification() {
  return getRuleContext<GQLParser::NonNegativeIntegerSpecificationContext>(0);
}


size_t GQLParser::NumberOfGroupsContext::getRuleIndex() const {
  return GQLParser::RuleNumberOfGroups;
}




//----------------- PathPatternExpressionContext ------------------------------------------------------------------

GQLParser::PathPatternExpressionContext::PathPatternExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::PathPatternExpressionContext::getRuleIndex() const {
  return GQLParser::RulePathPatternExpression;
}

void GQLParser::PathPatternExpressionContext::copyFrom(PathPatternExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PpePatternUnionContext ------------------------------------------------------------------

std::vector<GQLParser::PathTermContext *> GQLParser::PpePatternUnionContext::pathTerm() {
  return getRuleContexts<GQLParser::PathTermContext>();
}

GQLParser::PathTermContext* GQLParser::PpePatternUnionContext::pathTerm(size_t i) {
  return getRuleContext<GQLParser::PathTermContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::PpePatternUnionContext::VERTICAL_BAR() {
  return getTokens(GQLParser::VERTICAL_BAR);
}

tree::TerminalNode* GQLParser::PpePatternUnionContext::VERTICAL_BAR(size_t i) {
  return getToken(GQLParser::VERTICAL_BAR, i);
}

GQLParser::PpePatternUnionContext::PpePatternUnionContext(PathPatternExpressionContext *ctx) { copyFrom(ctx); }


//----------------- PpePathTermContext ------------------------------------------------------------------

GQLParser::PathTermContext* GQLParser::PpePathTermContext::pathTerm() {
  return getRuleContext<GQLParser::PathTermContext>(0);
}

GQLParser::PpePathTermContext::PpePathTermContext(PathPatternExpressionContext *ctx) { copyFrom(ctx); }


//----------------- PpeMultisetAlternationContext ------------------------------------------------------------------

std::vector<GQLParser::PathTermContext *> GQLParser::PpeMultisetAlternationContext::pathTerm() {
  return getRuleContexts<GQLParser::PathTermContext>();
}

GQLParser::PathTermContext* GQLParser::PpeMultisetAlternationContext::pathTerm(size_t i) {
  return getRuleContext<GQLParser::PathTermContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::PpeMultisetAlternationContext::MULTISET_ALTERNATION_OPERATOR() {
  return getTokens(GQLParser::MULTISET_ALTERNATION_OPERATOR);
}

tree::TerminalNode* GQLParser::PpeMultisetAlternationContext::MULTISET_ALTERNATION_OPERATOR(size_t i) {
  return getToken(GQLParser::MULTISET_ALTERNATION_OPERATOR, i);
}

GQLParser::PpeMultisetAlternationContext::PpeMultisetAlternationContext(PathPatternExpressionContext *ctx) { copyFrom(ctx); }




//----------------- PathTermContext ------------------------------------------------------------------

GQLParser::PathTermContext::PathTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::PathFactorContext *> GQLParser::PathTermContext::pathFactor() {
  return getRuleContexts<GQLParser::PathFactorContext>();
}

GQLParser::PathFactorContext* GQLParser::PathTermContext::pathFactor(size_t i) {
  return getRuleContext<GQLParser::PathFactorContext>(i);
}


size_t GQLParser::PathTermContext::getRuleIndex() const {
  return GQLParser::RulePathTerm;
}




//----------------- PathFactorContext ------------------------------------------------------------------

GQLParser::PathFactorContext::PathFactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::PathFactorContext::getRuleIndex() const {
  return GQLParser::RulePathFactor;
}

void GQLParser::PathFactorContext::copyFrom(PathFactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PfQuantifiedPathPrimaryContext ------------------------------------------------------------------

GQLParser::PathPrimaryContext* GQLParser::PfQuantifiedPathPrimaryContext::pathPrimary() {
  return getRuleContext<GQLParser::PathPrimaryContext>(0);
}

GQLParser::GraphPatternQuantifierContext* GQLParser::PfQuantifiedPathPrimaryContext::graphPatternQuantifier() {
  return getRuleContext<GQLParser::GraphPatternQuantifierContext>(0);
}

GQLParser::PfQuantifiedPathPrimaryContext::PfQuantifiedPathPrimaryContext(PathFactorContext *ctx) { copyFrom(ctx); }


//----------------- PfQuestionedPathPrimaryContext ------------------------------------------------------------------

GQLParser::PathPrimaryContext* GQLParser::PfQuestionedPathPrimaryContext::pathPrimary() {
  return getRuleContext<GQLParser::PathPrimaryContext>(0);
}

tree::TerminalNode* GQLParser::PfQuestionedPathPrimaryContext::QUESTION_MARK() {
  return getToken(GQLParser::QUESTION_MARK, 0);
}

GQLParser::PfQuestionedPathPrimaryContext::PfQuestionedPathPrimaryContext(PathFactorContext *ctx) { copyFrom(ctx); }


//----------------- PfPathPrimaryContext ------------------------------------------------------------------

GQLParser::PathPrimaryContext* GQLParser::PfPathPrimaryContext::pathPrimary() {
  return getRuleContext<GQLParser::PathPrimaryContext>(0);
}

GQLParser::PfPathPrimaryContext::PfPathPrimaryContext(PathFactorContext *ctx) { copyFrom(ctx); }




//----------------- PathPrimaryContext ------------------------------------------------------------------

GQLParser::PathPrimaryContext::PathPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::PathPrimaryContext::getRuleIndex() const {
  return GQLParser::RulePathPrimary;
}

void GQLParser::PathPrimaryContext::copyFrom(PathPrimaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PpParenthesizedPathPatternExpressionContext ------------------------------------------------------------------

GQLParser::ParenthesizedPathPatternExpressionContext* GQLParser::PpParenthesizedPathPatternExpressionContext::parenthesizedPathPatternExpression() {
  return getRuleContext<GQLParser::ParenthesizedPathPatternExpressionContext>(0);
}

GQLParser::PpParenthesizedPathPatternExpressionContext::PpParenthesizedPathPatternExpressionContext(PathPrimaryContext *ctx) { copyFrom(ctx); }


//----------------- PpElementPatternContext ------------------------------------------------------------------

GQLParser::ElementPatternContext* GQLParser::PpElementPatternContext::elementPattern() {
  return getRuleContext<GQLParser::ElementPatternContext>(0);
}

GQLParser::PpElementPatternContext::PpElementPatternContext(PathPrimaryContext *ctx) { copyFrom(ctx); }


//----------------- PpSimplifiedPathPatternExpressionContext ------------------------------------------------------------------

GQLParser::SimplifiedPathPatternExpressionContext* GQLParser::PpSimplifiedPathPatternExpressionContext::simplifiedPathPatternExpression() {
  return getRuleContext<GQLParser::SimplifiedPathPatternExpressionContext>(0);
}

GQLParser::PpSimplifiedPathPatternExpressionContext::PpSimplifiedPathPatternExpressionContext(PathPrimaryContext *ctx) { copyFrom(ctx); }




//----------------- ElementPatternContext ------------------------------------------------------------------

GQLParser::ElementPatternContext::ElementPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodePatternContext* GQLParser::ElementPatternContext::nodePattern() {
  return getRuleContext<GQLParser::NodePatternContext>(0);
}

GQLParser::EdgePatternContext* GQLParser::ElementPatternContext::edgePattern() {
  return getRuleContext<GQLParser::EdgePatternContext>(0);
}


size_t GQLParser::ElementPatternContext::getRuleIndex() const {
  return GQLParser::RuleElementPattern;
}




//----------------- NodePatternContext ------------------------------------------------------------------

GQLParser::NodePatternContext::NodePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NodePatternContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::NodePatternContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::NodePatternContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::NodePatternContext::getRuleIndex() const {
  return GQLParser::RuleNodePattern;
}




//----------------- ElementPatternFillerContext ------------------------------------------------------------------

GQLParser::ElementPatternFillerContext::ElementPatternFillerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementVariableDeclarationContext* GQLParser::ElementPatternFillerContext::elementVariableDeclaration() {
  return getRuleContext<GQLParser::ElementVariableDeclarationContext>(0);
}

GQLParser::IsLabelExpressionContext* GQLParser::ElementPatternFillerContext::isLabelExpression() {
  return getRuleContext<GQLParser::IsLabelExpressionContext>(0);
}

GQLParser::ElementPatternPredicateContext* GQLParser::ElementPatternFillerContext::elementPatternPredicate() {
  return getRuleContext<GQLParser::ElementPatternPredicateContext>(0);
}


size_t GQLParser::ElementPatternFillerContext::getRuleIndex() const {
  return GQLParser::RuleElementPatternFiller;
}




//----------------- ElementVariableDeclarationContext ------------------------------------------------------------------

GQLParser::ElementVariableDeclarationContext::ElementVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementVariableContext* GQLParser::ElementVariableDeclarationContext::elementVariable() {
  return getRuleContext<GQLParser::ElementVariableContext>(0);
}

tree::TerminalNode* GQLParser::ElementVariableDeclarationContext::TEMP() {
  return getToken(GQLParser::TEMP, 0);
}


size_t GQLParser::ElementVariableDeclarationContext::getRuleIndex() const {
  return GQLParser::RuleElementVariableDeclaration;
}




//----------------- IsLabelExpressionContext ------------------------------------------------------------------

GQLParser::IsLabelExpressionContext::IsLabelExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IsOrColonContext* GQLParser::IsLabelExpressionContext::isOrColon() {
  return getRuleContext<GQLParser::IsOrColonContext>(0);
}

GQLParser::LabelExpressionContext* GQLParser::IsLabelExpressionContext::labelExpression() {
  return getRuleContext<GQLParser::LabelExpressionContext>(0);
}


size_t GQLParser::IsLabelExpressionContext::getRuleIndex() const {
  return GQLParser::RuleIsLabelExpression;
}




//----------------- IsOrColonContext ------------------------------------------------------------------

GQLParser::IsOrColonContext::IsOrColonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::IsOrColonContext::IS() {
  return getToken(GQLParser::IS, 0);
}

tree::TerminalNode* GQLParser::IsOrColonContext::COLON() {
  return getToken(GQLParser::COLON, 0);
}


size_t GQLParser::IsOrColonContext::getRuleIndex() const {
  return GQLParser::RuleIsOrColon;
}




//----------------- ElementPatternPredicateContext ------------------------------------------------------------------

GQLParser::ElementPatternPredicateContext::ElementPatternPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementPatternWhereClauseContext* GQLParser::ElementPatternPredicateContext::elementPatternWhereClause() {
  return getRuleContext<GQLParser::ElementPatternWhereClauseContext>(0);
}

GQLParser::ElementPropertySpecificationContext* GQLParser::ElementPatternPredicateContext::elementPropertySpecification() {
  return getRuleContext<GQLParser::ElementPropertySpecificationContext>(0);
}


size_t GQLParser::ElementPatternPredicateContext::getRuleIndex() const {
  return GQLParser::RuleElementPatternPredicate;
}




//----------------- ElementPatternWhereClauseContext ------------------------------------------------------------------

GQLParser::ElementPatternWhereClauseContext::ElementPatternWhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ElementPatternWhereClauseContext::WHERE() {
  return getToken(GQLParser::WHERE, 0);
}

GQLParser::SearchConditionContext* GQLParser::ElementPatternWhereClauseContext::searchCondition() {
  return getRuleContext<GQLParser::SearchConditionContext>(0);
}


size_t GQLParser::ElementPatternWhereClauseContext::getRuleIndex() const {
  return GQLParser::RuleElementPatternWhereClause;
}




//----------------- ElementPropertySpecificationContext ------------------------------------------------------------------

GQLParser::ElementPropertySpecificationContext::ElementPropertySpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ElementPropertySpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::PropertyKeyValuePairListContext* GQLParser::ElementPropertySpecificationContext::propertyKeyValuePairList() {
  return getRuleContext<GQLParser::PropertyKeyValuePairListContext>(0);
}

tree::TerminalNode* GQLParser::ElementPropertySpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}


size_t GQLParser::ElementPropertySpecificationContext::getRuleIndex() const {
  return GQLParser::RuleElementPropertySpecification;
}




//----------------- PropertyKeyValuePairListContext ------------------------------------------------------------------

GQLParser::PropertyKeyValuePairListContext::PropertyKeyValuePairListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::PropertyKeyValuePairContext *> GQLParser::PropertyKeyValuePairListContext::propertyKeyValuePair() {
  return getRuleContexts<GQLParser::PropertyKeyValuePairContext>();
}

GQLParser::PropertyKeyValuePairContext* GQLParser::PropertyKeyValuePairListContext::propertyKeyValuePair(size_t i) {
  return getRuleContext<GQLParser::PropertyKeyValuePairContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::PropertyKeyValuePairListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::PropertyKeyValuePairListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::PropertyKeyValuePairListContext::getRuleIndex() const {
  return GQLParser::RulePropertyKeyValuePairList;
}




//----------------- PropertyKeyValuePairContext ------------------------------------------------------------------

GQLParser::PropertyKeyValuePairContext::PropertyKeyValuePairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PropertyNameContext* GQLParser::PropertyKeyValuePairContext::propertyName() {
  return getRuleContext<GQLParser::PropertyNameContext>(0);
}

tree::TerminalNode* GQLParser::PropertyKeyValuePairContext::COLON() {
  return getToken(GQLParser::COLON, 0);
}

GQLParser::ValueExpressionContext* GQLParser::PropertyKeyValuePairContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::PropertyKeyValuePairContext::getRuleIndex() const {
  return GQLParser::RulePropertyKeyValuePair;
}




//----------------- EdgePatternContext ------------------------------------------------------------------

GQLParser::EdgePatternContext::EdgePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FullEdgePatternContext* GQLParser::EdgePatternContext::fullEdgePattern() {
  return getRuleContext<GQLParser::FullEdgePatternContext>(0);
}

GQLParser::AbbreviatedEdgePatternContext* GQLParser::EdgePatternContext::abbreviatedEdgePattern() {
  return getRuleContext<GQLParser::AbbreviatedEdgePatternContext>(0);
}


size_t GQLParser::EdgePatternContext::getRuleIndex() const {
  return GQLParser::RuleEdgePattern;
}




//----------------- FullEdgePatternContext ------------------------------------------------------------------

GQLParser::FullEdgePatternContext::FullEdgePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FullEdgePointingLeftContext* GQLParser::FullEdgePatternContext::fullEdgePointingLeft() {
  return getRuleContext<GQLParser::FullEdgePointingLeftContext>(0);
}

GQLParser::FullEdgeUndirectedContext* GQLParser::FullEdgePatternContext::fullEdgeUndirected() {
  return getRuleContext<GQLParser::FullEdgeUndirectedContext>(0);
}

GQLParser::FullEdgePointingRightContext* GQLParser::FullEdgePatternContext::fullEdgePointingRight() {
  return getRuleContext<GQLParser::FullEdgePointingRightContext>(0);
}

GQLParser::FullEdgeLeftOrUndirectedContext* GQLParser::FullEdgePatternContext::fullEdgeLeftOrUndirected() {
  return getRuleContext<GQLParser::FullEdgeLeftOrUndirectedContext>(0);
}

GQLParser::FullEdgeUndirectedOrRightContext* GQLParser::FullEdgePatternContext::fullEdgeUndirectedOrRight() {
  return getRuleContext<GQLParser::FullEdgeUndirectedOrRightContext>(0);
}

GQLParser::FullEdgeLeftOrRightContext* GQLParser::FullEdgePatternContext::fullEdgeLeftOrRight() {
  return getRuleContext<GQLParser::FullEdgeLeftOrRightContext>(0);
}

GQLParser::FullEdgeAnyDirectionContext* GQLParser::FullEdgePatternContext::fullEdgeAnyDirection() {
  return getRuleContext<GQLParser::FullEdgeAnyDirectionContext>(0);
}


size_t GQLParser::FullEdgePatternContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgePattern;
}




//----------------- FullEdgePointingLeftContext ------------------------------------------------------------------

GQLParser::FullEdgePointingLeftContext::FullEdgePointingLeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FullEdgePointingLeftContext::LEFT_ARROW_BRACKET() {
  return getToken(GQLParser::LEFT_ARROW_BRACKET, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::FullEdgePointingLeftContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::FullEdgePointingLeftContext::RIGHT_BRACKET_MINUS() {
  return getToken(GQLParser::RIGHT_BRACKET_MINUS, 0);
}


size_t GQLParser::FullEdgePointingLeftContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgePointingLeft;
}




//----------------- FullEdgeUndirectedContext ------------------------------------------------------------------

GQLParser::FullEdgeUndirectedContext::FullEdgeUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FullEdgeUndirectedContext::TILDE_LEFT_BRACKET() {
  return getToken(GQLParser::TILDE_LEFT_BRACKET, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::FullEdgeUndirectedContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::FullEdgeUndirectedContext::RIGHT_BRACKET_TILDE() {
  return getToken(GQLParser::RIGHT_BRACKET_TILDE, 0);
}


size_t GQLParser::FullEdgeUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgeUndirected;
}




//----------------- FullEdgePointingRightContext ------------------------------------------------------------------

GQLParser::FullEdgePointingRightContext::FullEdgePointingRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FullEdgePointingRightContext::MINUS_LEFT_BRACKET() {
  return getToken(GQLParser::MINUS_LEFT_BRACKET, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::FullEdgePointingRightContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::FullEdgePointingRightContext::BRACKET_RIGHT_ARROW() {
  return getToken(GQLParser::BRACKET_RIGHT_ARROW, 0);
}


size_t GQLParser::FullEdgePointingRightContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgePointingRight;
}




//----------------- FullEdgeLeftOrUndirectedContext ------------------------------------------------------------------

GQLParser::FullEdgeLeftOrUndirectedContext::FullEdgeLeftOrUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FullEdgeLeftOrUndirectedContext::LEFT_ARROW_TILDE_BRACKET() {
  return getToken(GQLParser::LEFT_ARROW_TILDE_BRACKET, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::FullEdgeLeftOrUndirectedContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::FullEdgeLeftOrUndirectedContext::RIGHT_BRACKET_TILDE() {
  return getToken(GQLParser::RIGHT_BRACKET_TILDE, 0);
}


size_t GQLParser::FullEdgeLeftOrUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgeLeftOrUndirected;
}




//----------------- FullEdgeUndirectedOrRightContext ------------------------------------------------------------------

GQLParser::FullEdgeUndirectedOrRightContext::FullEdgeUndirectedOrRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FullEdgeUndirectedOrRightContext::TILDE_LEFT_BRACKET() {
  return getToken(GQLParser::TILDE_LEFT_BRACKET, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::FullEdgeUndirectedOrRightContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::FullEdgeUndirectedOrRightContext::BRACKET_TILDE_RIGHT_ARROW() {
  return getToken(GQLParser::BRACKET_TILDE_RIGHT_ARROW, 0);
}


size_t GQLParser::FullEdgeUndirectedOrRightContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgeUndirectedOrRight;
}




//----------------- FullEdgeLeftOrRightContext ------------------------------------------------------------------

GQLParser::FullEdgeLeftOrRightContext::FullEdgeLeftOrRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FullEdgeLeftOrRightContext::LEFT_ARROW_BRACKET() {
  return getToken(GQLParser::LEFT_ARROW_BRACKET, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::FullEdgeLeftOrRightContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::FullEdgeLeftOrRightContext::BRACKET_RIGHT_ARROW() {
  return getToken(GQLParser::BRACKET_RIGHT_ARROW, 0);
}


size_t GQLParser::FullEdgeLeftOrRightContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgeLeftOrRight;
}




//----------------- FullEdgeAnyDirectionContext ------------------------------------------------------------------

GQLParser::FullEdgeAnyDirectionContext::FullEdgeAnyDirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FullEdgeAnyDirectionContext::MINUS_LEFT_BRACKET() {
  return getToken(GQLParser::MINUS_LEFT_BRACKET, 0);
}

GQLParser::ElementPatternFillerContext* GQLParser::FullEdgeAnyDirectionContext::elementPatternFiller() {
  return getRuleContext<GQLParser::ElementPatternFillerContext>(0);
}

tree::TerminalNode* GQLParser::FullEdgeAnyDirectionContext::RIGHT_BRACKET_MINUS() {
  return getToken(GQLParser::RIGHT_BRACKET_MINUS, 0);
}


size_t GQLParser::FullEdgeAnyDirectionContext::getRuleIndex() const {
  return GQLParser::RuleFullEdgeAnyDirection;
}




//----------------- AbbreviatedEdgePatternContext ------------------------------------------------------------------

GQLParser::AbbreviatedEdgePatternContext::AbbreviatedEdgePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AbbreviatedEdgePatternContext::LEFT_ARROW() {
  return getToken(GQLParser::LEFT_ARROW, 0);
}

tree::TerminalNode* GQLParser::AbbreviatedEdgePatternContext::TILDE() {
  return getToken(GQLParser::TILDE, 0);
}

tree::TerminalNode* GQLParser::AbbreviatedEdgePatternContext::RIGHT_ARROW() {
  return getToken(GQLParser::RIGHT_ARROW, 0);
}

tree::TerminalNode* GQLParser::AbbreviatedEdgePatternContext::LEFT_ARROW_TILDE() {
  return getToken(GQLParser::LEFT_ARROW_TILDE, 0);
}

tree::TerminalNode* GQLParser::AbbreviatedEdgePatternContext::TILDE_RIGHT_ARROW() {
  return getToken(GQLParser::TILDE_RIGHT_ARROW, 0);
}

tree::TerminalNode* GQLParser::AbbreviatedEdgePatternContext::LEFT_MINUS_RIGHT() {
  return getToken(GQLParser::LEFT_MINUS_RIGHT, 0);
}

tree::TerminalNode* GQLParser::AbbreviatedEdgePatternContext::MINUS_SIGN() {
  return getToken(GQLParser::MINUS_SIGN, 0);
}


size_t GQLParser::AbbreviatedEdgePatternContext::getRuleIndex() const {
  return GQLParser::RuleAbbreviatedEdgePattern;
}




//----------------- ParenthesizedPathPatternExpressionContext ------------------------------------------------------------------

GQLParser::ParenthesizedPathPatternExpressionContext::ParenthesizedPathPatternExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ParenthesizedPathPatternExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PathPatternExpressionContext* GQLParser::ParenthesizedPathPatternExpressionContext::pathPatternExpression() {
  return getRuleContext<GQLParser::PathPatternExpressionContext>(0);
}

tree::TerminalNode* GQLParser::ParenthesizedPathPatternExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::SubpathVariableDeclarationContext* GQLParser::ParenthesizedPathPatternExpressionContext::subpathVariableDeclaration() {
  return getRuleContext<GQLParser::SubpathVariableDeclarationContext>(0);
}

GQLParser::PathModePrefixContext* GQLParser::ParenthesizedPathPatternExpressionContext::pathModePrefix() {
  return getRuleContext<GQLParser::PathModePrefixContext>(0);
}

GQLParser::ParenthesizedPathPatternWhereClauseContext* GQLParser::ParenthesizedPathPatternExpressionContext::parenthesizedPathPatternWhereClause() {
  return getRuleContext<GQLParser::ParenthesizedPathPatternWhereClauseContext>(0);
}


size_t GQLParser::ParenthesizedPathPatternExpressionContext::getRuleIndex() const {
  return GQLParser::RuleParenthesizedPathPatternExpression;
}




//----------------- SubpathVariableDeclarationContext ------------------------------------------------------------------

GQLParser::SubpathVariableDeclarationContext::SubpathVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SubpathVariableContext* GQLParser::SubpathVariableDeclarationContext::subpathVariable() {
  return getRuleContext<GQLParser::SubpathVariableContext>(0);
}

tree::TerminalNode* GQLParser::SubpathVariableDeclarationContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}


size_t GQLParser::SubpathVariableDeclarationContext::getRuleIndex() const {
  return GQLParser::RuleSubpathVariableDeclaration;
}




//----------------- ParenthesizedPathPatternWhereClauseContext ------------------------------------------------------------------

GQLParser::ParenthesizedPathPatternWhereClauseContext::ParenthesizedPathPatternWhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ParenthesizedPathPatternWhereClauseContext::WHERE() {
  return getToken(GQLParser::WHERE, 0);
}

GQLParser::SearchConditionContext* GQLParser::ParenthesizedPathPatternWhereClauseContext::searchCondition() {
  return getRuleContext<GQLParser::SearchConditionContext>(0);
}


size_t GQLParser::ParenthesizedPathPatternWhereClauseContext::getRuleIndex() const {
  return GQLParser::RuleParenthesizedPathPatternWhereClause;
}




//----------------- LabelExpressionContext ------------------------------------------------------------------

GQLParser::LabelExpressionContext::LabelExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::LabelExpressionContext::getRuleIndex() const {
  return GQLParser::RuleLabelExpression;
}

void GQLParser::LabelExpressionContext::copyFrom(LabelExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LabelExpressionNegationContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::LabelExpressionNegationContext::EXCLAMATION_MARK() {
  return getToken(GQLParser::EXCLAMATION_MARK, 0);
}

GQLParser::LabelExpressionContext* GQLParser::LabelExpressionNegationContext::labelExpression() {
  return getRuleContext<GQLParser::LabelExpressionContext>(0);
}

GQLParser::LabelExpressionNegationContext::LabelExpressionNegationContext(LabelExpressionContext *ctx) { copyFrom(ctx); }


//----------------- LabelExpressionDisjunctionContext ------------------------------------------------------------------

std::vector<GQLParser::LabelExpressionContext *> GQLParser::LabelExpressionDisjunctionContext::labelExpression() {
  return getRuleContexts<GQLParser::LabelExpressionContext>();
}

GQLParser::LabelExpressionContext* GQLParser::LabelExpressionDisjunctionContext::labelExpression(size_t i) {
  return getRuleContext<GQLParser::LabelExpressionContext>(i);
}

tree::TerminalNode* GQLParser::LabelExpressionDisjunctionContext::VERTICAL_BAR() {
  return getToken(GQLParser::VERTICAL_BAR, 0);
}

GQLParser::LabelExpressionDisjunctionContext::LabelExpressionDisjunctionContext(LabelExpressionContext *ctx) { copyFrom(ctx); }


//----------------- LabelExpressionParenthesizedContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::LabelExpressionParenthesizedContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::LabelExpressionContext* GQLParser::LabelExpressionParenthesizedContext::labelExpression() {
  return getRuleContext<GQLParser::LabelExpressionContext>(0);
}

tree::TerminalNode* GQLParser::LabelExpressionParenthesizedContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::LabelExpressionParenthesizedContext::LabelExpressionParenthesizedContext(LabelExpressionContext *ctx) { copyFrom(ctx); }


//----------------- LabelExpressionWildcardContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::LabelExpressionWildcardContext::PERCENT() {
  return getToken(GQLParser::PERCENT, 0);
}

GQLParser::LabelExpressionWildcardContext::LabelExpressionWildcardContext(LabelExpressionContext *ctx) { copyFrom(ctx); }


//----------------- LabelExpressionConjunctionContext ------------------------------------------------------------------

std::vector<GQLParser::LabelExpressionContext *> GQLParser::LabelExpressionConjunctionContext::labelExpression() {
  return getRuleContexts<GQLParser::LabelExpressionContext>();
}

GQLParser::LabelExpressionContext* GQLParser::LabelExpressionConjunctionContext::labelExpression(size_t i) {
  return getRuleContext<GQLParser::LabelExpressionContext>(i);
}

tree::TerminalNode* GQLParser::LabelExpressionConjunctionContext::AMPERSAND() {
  return getToken(GQLParser::AMPERSAND, 0);
}

GQLParser::LabelExpressionConjunctionContext::LabelExpressionConjunctionContext(LabelExpressionContext *ctx) { copyFrom(ctx); }


//----------------- LabelExpressionNameContext ------------------------------------------------------------------

GQLParser::LabelNameContext* GQLParser::LabelExpressionNameContext::labelName() {
  return getRuleContext<GQLParser::LabelNameContext>(0);
}

GQLParser::LabelExpressionNameContext::LabelExpressionNameContext(LabelExpressionContext *ctx) { copyFrom(ctx); }




//----------------- PathVariableReferenceContext ------------------------------------------------------------------

GQLParser::PathVariableReferenceContext::PathVariableReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::PathVariableReferenceContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}


size_t GQLParser::PathVariableReferenceContext::getRuleIndex() const {
  return GQLParser::RulePathVariableReference;
}




//----------------- ElementVariableReferenceContext ------------------------------------------------------------------

GQLParser::ElementVariableReferenceContext::ElementVariableReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::ElementVariableReferenceContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}


size_t GQLParser::ElementVariableReferenceContext::getRuleIndex() const {
  return GQLParser::RuleElementVariableReference;
}




//----------------- GraphPatternQuantifierContext ------------------------------------------------------------------

GQLParser::GraphPatternQuantifierContext::GraphPatternQuantifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GraphPatternQuantifierContext::ASTERISK() {
  return getToken(GQLParser::ASTERISK, 0);
}

tree::TerminalNode* GQLParser::GraphPatternQuantifierContext::PLUS_SIGN() {
  return getToken(GQLParser::PLUS_SIGN, 0);
}

GQLParser::FixedQuantifierContext* GQLParser::GraphPatternQuantifierContext::fixedQuantifier() {
  return getRuleContext<GQLParser::FixedQuantifierContext>(0);
}

GQLParser::GeneralQuantifierContext* GQLParser::GraphPatternQuantifierContext::generalQuantifier() {
  return getRuleContext<GQLParser::GeneralQuantifierContext>(0);
}


size_t GQLParser::GraphPatternQuantifierContext::getRuleIndex() const {
  return GQLParser::RuleGraphPatternQuantifier;
}




//----------------- FixedQuantifierContext ------------------------------------------------------------------

GQLParser::FixedQuantifierContext::FixedQuantifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FixedQuantifierContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::UnsignedIntegerContext* GQLParser::FixedQuantifierContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}

tree::TerminalNode* GQLParser::FixedQuantifierContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}


size_t GQLParser::FixedQuantifierContext::getRuleIndex() const {
  return GQLParser::RuleFixedQuantifier;
}




//----------------- GeneralQuantifierContext ------------------------------------------------------------------

GQLParser::GeneralQuantifierContext::GeneralQuantifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GeneralQuantifierContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

tree::TerminalNode* GQLParser::GeneralQuantifierContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

tree::TerminalNode* GQLParser::GeneralQuantifierContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}

GQLParser::LowerBoundContext* GQLParser::GeneralQuantifierContext::lowerBound() {
  return getRuleContext<GQLParser::LowerBoundContext>(0);
}

GQLParser::UpperBoundContext* GQLParser::GeneralQuantifierContext::upperBound() {
  return getRuleContext<GQLParser::UpperBoundContext>(0);
}


size_t GQLParser::GeneralQuantifierContext::getRuleIndex() const {
  return GQLParser::RuleGeneralQuantifier;
}




//----------------- LowerBoundContext ------------------------------------------------------------------

GQLParser::LowerBoundContext::LowerBoundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedIntegerContext* GQLParser::LowerBoundContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}


size_t GQLParser::LowerBoundContext::getRuleIndex() const {
  return GQLParser::RuleLowerBound;
}




//----------------- UpperBoundContext ------------------------------------------------------------------

GQLParser::UpperBoundContext::UpperBoundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedIntegerContext* GQLParser::UpperBoundContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}


size_t GQLParser::UpperBoundContext::getRuleIndex() const {
  return GQLParser::RuleUpperBound;
}




//----------------- SimplifiedPathPatternExpressionContext ------------------------------------------------------------------

GQLParser::SimplifiedPathPatternExpressionContext::SimplifiedPathPatternExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedDefaultingLeftContext* GQLParser::SimplifiedPathPatternExpressionContext::simplifiedDefaultingLeft() {
  return getRuleContext<GQLParser::SimplifiedDefaultingLeftContext>(0);
}

GQLParser::SimplifiedDefaultingUndirectedContext* GQLParser::SimplifiedPathPatternExpressionContext::simplifiedDefaultingUndirected() {
  return getRuleContext<GQLParser::SimplifiedDefaultingUndirectedContext>(0);
}

GQLParser::SimplifiedDefaultingRightContext* GQLParser::SimplifiedPathPatternExpressionContext::simplifiedDefaultingRight() {
  return getRuleContext<GQLParser::SimplifiedDefaultingRightContext>(0);
}

GQLParser::SimplifiedDefaultingLeftOrUndirectedContext* GQLParser::SimplifiedPathPatternExpressionContext::simplifiedDefaultingLeftOrUndirected() {
  return getRuleContext<GQLParser::SimplifiedDefaultingLeftOrUndirectedContext>(0);
}

GQLParser::SimplifiedDefaultingUndirectedOrRightContext* GQLParser::SimplifiedPathPatternExpressionContext::simplifiedDefaultingUndirectedOrRight() {
  return getRuleContext<GQLParser::SimplifiedDefaultingUndirectedOrRightContext>(0);
}

GQLParser::SimplifiedDefaultingLeftOrRightContext* GQLParser::SimplifiedPathPatternExpressionContext::simplifiedDefaultingLeftOrRight() {
  return getRuleContext<GQLParser::SimplifiedDefaultingLeftOrRightContext>(0);
}

GQLParser::SimplifiedDefaultingAnyDirectionContext* GQLParser::SimplifiedPathPatternExpressionContext::simplifiedDefaultingAnyDirection() {
  return getRuleContext<GQLParser::SimplifiedDefaultingAnyDirectionContext>(0);
}


size_t GQLParser::SimplifiedPathPatternExpressionContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedPathPatternExpression;
}




//----------------- SimplifiedDefaultingLeftContext ------------------------------------------------------------------

GQLParser::SimplifiedDefaultingLeftContext::SimplifiedDefaultingLeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingLeftContext::LEFT_MINUS_SLASH() {
  return getToken(GQLParser::LEFT_MINUS_SLASH, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedDefaultingLeftContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingLeftContext::SLASH_MINUS() {
  return getToken(GQLParser::SLASH_MINUS, 0);
}


size_t GQLParser::SimplifiedDefaultingLeftContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDefaultingLeft;
}




//----------------- SimplifiedDefaultingUndirectedContext ------------------------------------------------------------------

GQLParser::SimplifiedDefaultingUndirectedContext::SimplifiedDefaultingUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingUndirectedContext::TILDE_SLASH() {
  return getToken(GQLParser::TILDE_SLASH, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedDefaultingUndirectedContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingUndirectedContext::SLASH_TILDE() {
  return getToken(GQLParser::SLASH_TILDE, 0);
}


size_t GQLParser::SimplifiedDefaultingUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDefaultingUndirected;
}




//----------------- SimplifiedDefaultingRightContext ------------------------------------------------------------------

GQLParser::SimplifiedDefaultingRightContext::SimplifiedDefaultingRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingRightContext::MINUS_SLASH() {
  return getToken(GQLParser::MINUS_SLASH, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedDefaultingRightContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingRightContext::SLASH_MINUS_RIGHT() {
  return getToken(GQLParser::SLASH_MINUS_RIGHT, 0);
}


size_t GQLParser::SimplifiedDefaultingRightContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDefaultingRight;
}




//----------------- SimplifiedDefaultingLeftOrUndirectedContext ------------------------------------------------------------------

GQLParser::SimplifiedDefaultingLeftOrUndirectedContext::SimplifiedDefaultingLeftOrUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingLeftOrUndirectedContext::LEFT_TILDE_SLASH() {
  return getToken(GQLParser::LEFT_TILDE_SLASH, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedDefaultingLeftOrUndirectedContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingLeftOrUndirectedContext::SLASH_TILDE() {
  return getToken(GQLParser::SLASH_TILDE, 0);
}


size_t GQLParser::SimplifiedDefaultingLeftOrUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDefaultingLeftOrUndirected;
}




//----------------- SimplifiedDefaultingUndirectedOrRightContext ------------------------------------------------------------------

GQLParser::SimplifiedDefaultingUndirectedOrRightContext::SimplifiedDefaultingUndirectedOrRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingUndirectedOrRightContext::TILDE_SLASH() {
  return getToken(GQLParser::TILDE_SLASH, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedDefaultingUndirectedOrRightContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingUndirectedOrRightContext::SLASH_TILDE_RIGHT() {
  return getToken(GQLParser::SLASH_TILDE_RIGHT, 0);
}


size_t GQLParser::SimplifiedDefaultingUndirectedOrRightContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDefaultingUndirectedOrRight;
}




//----------------- SimplifiedDefaultingLeftOrRightContext ------------------------------------------------------------------

GQLParser::SimplifiedDefaultingLeftOrRightContext::SimplifiedDefaultingLeftOrRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingLeftOrRightContext::LEFT_MINUS_SLASH() {
  return getToken(GQLParser::LEFT_MINUS_SLASH, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedDefaultingLeftOrRightContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingLeftOrRightContext::SLASH_MINUS_RIGHT() {
  return getToken(GQLParser::SLASH_MINUS_RIGHT, 0);
}


size_t GQLParser::SimplifiedDefaultingLeftOrRightContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDefaultingLeftOrRight;
}




//----------------- SimplifiedDefaultingAnyDirectionContext ------------------------------------------------------------------

GQLParser::SimplifiedDefaultingAnyDirectionContext::SimplifiedDefaultingAnyDirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingAnyDirectionContext::MINUS_SLASH() {
  return getToken(GQLParser::MINUS_SLASH, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedDefaultingAnyDirectionContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedDefaultingAnyDirectionContext::SLASH_MINUS() {
  return getToken(GQLParser::SLASH_MINUS, 0);
}


size_t GQLParser::SimplifiedDefaultingAnyDirectionContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDefaultingAnyDirection;
}




//----------------- SimplifiedContentsContext ------------------------------------------------------------------

GQLParser::SimplifiedContentsContext::SimplifiedContentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedTermContext* GQLParser::SimplifiedContentsContext::simplifiedTerm() {
  return getRuleContext<GQLParser::SimplifiedTermContext>(0);
}

GQLParser::SimplifiedPathUnionContext* GQLParser::SimplifiedContentsContext::simplifiedPathUnion() {
  return getRuleContext<GQLParser::SimplifiedPathUnionContext>(0);
}

GQLParser::SimplifiedMultisetAlternationContext* GQLParser::SimplifiedContentsContext::simplifiedMultisetAlternation() {
  return getRuleContext<GQLParser::SimplifiedMultisetAlternationContext>(0);
}


size_t GQLParser::SimplifiedContentsContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedContents;
}




//----------------- SimplifiedPathUnionContext ------------------------------------------------------------------

GQLParser::SimplifiedPathUnionContext::SimplifiedPathUnionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SimplifiedTermContext *> GQLParser::SimplifiedPathUnionContext::simplifiedTerm() {
  return getRuleContexts<GQLParser::SimplifiedTermContext>();
}

GQLParser::SimplifiedTermContext* GQLParser::SimplifiedPathUnionContext::simplifiedTerm(size_t i) {
  return getRuleContext<GQLParser::SimplifiedTermContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SimplifiedPathUnionContext::VERTICAL_BAR() {
  return getTokens(GQLParser::VERTICAL_BAR);
}

tree::TerminalNode* GQLParser::SimplifiedPathUnionContext::VERTICAL_BAR(size_t i) {
  return getToken(GQLParser::VERTICAL_BAR, i);
}


size_t GQLParser::SimplifiedPathUnionContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedPathUnion;
}




//----------------- SimplifiedMultisetAlternationContext ------------------------------------------------------------------

GQLParser::SimplifiedMultisetAlternationContext::SimplifiedMultisetAlternationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SimplifiedTermContext *> GQLParser::SimplifiedMultisetAlternationContext::simplifiedTerm() {
  return getRuleContexts<GQLParser::SimplifiedTermContext>();
}

GQLParser::SimplifiedTermContext* GQLParser::SimplifiedMultisetAlternationContext::simplifiedTerm(size_t i) {
  return getRuleContext<GQLParser::SimplifiedTermContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SimplifiedMultisetAlternationContext::MULTISET_ALTERNATION_OPERATOR() {
  return getTokens(GQLParser::MULTISET_ALTERNATION_OPERATOR);
}

tree::TerminalNode* GQLParser::SimplifiedMultisetAlternationContext::MULTISET_ALTERNATION_OPERATOR(size_t i) {
  return getToken(GQLParser::MULTISET_ALTERNATION_OPERATOR, i);
}


size_t GQLParser::SimplifiedMultisetAlternationContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedMultisetAlternation;
}




//----------------- SimplifiedTermContext ------------------------------------------------------------------

GQLParser::SimplifiedTermContext::SimplifiedTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::SimplifiedTermContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedTerm;
}

void GQLParser::SimplifiedTermContext::copyFrom(SimplifiedTermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimplifiedFactorLowLabelContext ------------------------------------------------------------------

GQLParser::SimplifiedFactorLowContext* GQLParser::SimplifiedFactorLowLabelContext::simplifiedFactorLow() {
  return getRuleContext<GQLParser::SimplifiedFactorLowContext>(0);
}

GQLParser::SimplifiedFactorLowLabelContext::SimplifiedFactorLowLabelContext(SimplifiedTermContext *ctx) { copyFrom(ctx); }


//----------------- SimplifiedConcatenationLabelContext ------------------------------------------------------------------

GQLParser::SimplifiedTermContext* GQLParser::SimplifiedConcatenationLabelContext::simplifiedTerm() {
  return getRuleContext<GQLParser::SimplifiedTermContext>(0);
}

GQLParser::SimplifiedFactorLowContext* GQLParser::SimplifiedConcatenationLabelContext::simplifiedFactorLow() {
  return getRuleContext<GQLParser::SimplifiedFactorLowContext>(0);
}

GQLParser::SimplifiedConcatenationLabelContext::SimplifiedConcatenationLabelContext(SimplifiedTermContext *ctx) { copyFrom(ctx); }




//----------------- SimplifiedFactorLowContext ------------------------------------------------------------------

GQLParser::SimplifiedFactorLowContext::SimplifiedFactorLowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::SimplifiedFactorLowContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedFactorLow;
}

void GQLParser::SimplifiedFactorLowContext::copyFrom(SimplifiedFactorLowContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimplifiedConjunctionLabelContext ------------------------------------------------------------------

GQLParser::SimplifiedFactorLowContext* GQLParser::SimplifiedConjunctionLabelContext::simplifiedFactorLow() {
  return getRuleContext<GQLParser::SimplifiedFactorLowContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedConjunctionLabelContext::AMPERSAND() {
  return getToken(GQLParser::AMPERSAND, 0);
}

GQLParser::SimplifiedFactorHighContext* GQLParser::SimplifiedConjunctionLabelContext::simplifiedFactorHigh() {
  return getRuleContext<GQLParser::SimplifiedFactorHighContext>(0);
}

GQLParser::SimplifiedConjunctionLabelContext::SimplifiedConjunctionLabelContext(SimplifiedFactorLowContext *ctx) { copyFrom(ctx); }


//----------------- SimplifiedFactorHighLabelContext ------------------------------------------------------------------

GQLParser::SimplifiedFactorHighContext* GQLParser::SimplifiedFactorHighLabelContext::simplifiedFactorHigh() {
  return getRuleContext<GQLParser::SimplifiedFactorHighContext>(0);
}

GQLParser::SimplifiedFactorHighLabelContext::SimplifiedFactorHighLabelContext(SimplifiedFactorLowContext *ctx) { copyFrom(ctx); }




//----------------- SimplifiedFactorHighContext ------------------------------------------------------------------

GQLParser::SimplifiedFactorHighContext::SimplifiedFactorHighContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedTertiaryContext* GQLParser::SimplifiedFactorHighContext::simplifiedTertiary() {
  return getRuleContext<GQLParser::SimplifiedTertiaryContext>(0);
}

GQLParser::SimplifiedQuantifiedContext* GQLParser::SimplifiedFactorHighContext::simplifiedQuantified() {
  return getRuleContext<GQLParser::SimplifiedQuantifiedContext>(0);
}

GQLParser::SimplifiedQuestionedContext* GQLParser::SimplifiedFactorHighContext::simplifiedQuestioned() {
  return getRuleContext<GQLParser::SimplifiedQuestionedContext>(0);
}


size_t GQLParser::SimplifiedFactorHighContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedFactorHigh;
}




//----------------- SimplifiedQuantifiedContext ------------------------------------------------------------------

GQLParser::SimplifiedQuantifiedContext::SimplifiedQuantifiedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedTertiaryContext* GQLParser::SimplifiedQuantifiedContext::simplifiedTertiary() {
  return getRuleContext<GQLParser::SimplifiedTertiaryContext>(0);
}

GQLParser::GraphPatternQuantifierContext* GQLParser::SimplifiedQuantifiedContext::graphPatternQuantifier() {
  return getRuleContext<GQLParser::GraphPatternQuantifierContext>(0);
}


size_t GQLParser::SimplifiedQuantifiedContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedQuantified;
}




//----------------- SimplifiedQuestionedContext ------------------------------------------------------------------

GQLParser::SimplifiedQuestionedContext::SimplifiedQuestionedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedTertiaryContext* GQLParser::SimplifiedQuestionedContext::simplifiedTertiary() {
  return getRuleContext<GQLParser::SimplifiedTertiaryContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedQuestionedContext::QUESTION_MARK() {
  return getToken(GQLParser::QUESTION_MARK, 0);
}


size_t GQLParser::SimplifiedQuestionedContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedQuestioned;
}




//----------------- SimplifiedTertiaryContext ------------------------------------------------------------------

GQLParser::SimplifiedTertiaryContext::SimplifiedTertiaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedDirectionOverrideContext* GQLParser::SimplifiedTertiaryContext::simplifiedDirectionOverride() {
  return getRuleContext<GQLParser::SimplifiedDirectionOverrideContext>(0);
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedTertiaryContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}


size_t GQLParser::SimplifiedTertiaryContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedTertiary;
}




//----------------- SimplifiedDirectionOverrideContext ------------------------------------------------------------------

GQLParser::SimplifiedDirectionOverrideContext::SimplifiedDirectionOverrideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedOverrideLeftContext* GQLParser::SimplifiedDirectionOverrideContext::simplifiedOverrideLeft() {
  return getRuleContext<GQLParser::SimplifiedOverrideLeftContext>(0);
}

GQLParser::SimplifiedOverrideUndirectedContext* GQLParser::SimplifiedDirectionOverrideContext::simplifiedOverrideUndirected() {
  return getRuleContext<GQLParser::SimplifiedOverrideUndirectedContext>(0);
}

GQLParser::SimplifiedOverrideRightContext* GQLParser::SimplifiedDirectionOverrideContext::simplifiedOverrideRight() {
  return getRuleContext<GQLParser::SimplifiedOverrideRightContext>(0);
}

GQLParser::SimplifiedOverrideLeftOrUndirectedContext* GQLParser::SimplifiedDirectionOverrideContext::simplifiedOverrideLeftOrUndirected() {
  return getRuleContext<GQLParser::SimplifiedOverrideLeftOrUndirectedContext>(0);
}

GQLParser::SimplifiedOverrideUndirectedOrRightContext* GQLParser::SimplifiedDirectionOverrideContext::simplifiedOverrideUndirectedOrRight() {
  return getRuleContext<GQLParser::SimplifiedOverrideUndirectedOrRightContext>(0);
}

GQLParser::SimplifiedOverrideLeftOrRightContext* GQLParser::SimplifiedDirectionOverrideContext::simplifiedOverrideLeftOrRight() {
  return getRuleContext<GQLParser::SimplifiedOverrideLeftOrRightContext>(0);
}

GQLParser::SimplifiedOverrideAnyDirectionContext* GQLParser::SimplifiedDirectionOverrideContext::simplifiedOverrideAnyDirection() {
  return getRuleContext<GQLParser::SimplifiedOverrideAnyDirectionContext>(0);
}


size_t GQLParser::SimplifiedDirectionOverrideContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedDirectionOverride;
}




//----------------- SimplifiedOverrideLeftContext ------------------------------------------------------------------

GQLParser::SimplifiedOverrideLeftContext::SimplifiedOverrideLeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedOverrideLeftContext::LEFT_ANGLE_BRACKET() {
  return getToken(GQLParser::LEFT_ANGLE_BRACKET, 0);
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedOverrideLeftContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}


size_t GQLParser::SimplifiedOverrideLeftContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedOverrideLeft;
}




//----------------- SimplifiedOverrideUndirectedContext ------------------------------------------------------------------

GQLParser::SimplifiedOverrideUndirectedContext::SimplifiedOverrideUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedOverrideUndirectedContext::TILDE() {
  return getToken(GQLParser::TILDE, 0);
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedOverrideUndirectedContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}


size_t GQLParser::SimplifiedOverrideUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedOverrideUndirected;
}




//----------------- SimplifiedOverrideRightContext ------------------------------------------------------------------

GQLParser::SimplifiedOverrideRightContext::SimplifiedOverrideRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedOverrideRightContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedOverrideRightContext::RIGHT_ANGLE_BRACKET() {
  return getToken(GQLParser::RIGHT_ANGLE_BRACKET, 0);
}


size_t GQLParser::SimplifiedOverrideRightContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedOverrideRight;
}




//----------------- SimplifiedOverrideLeftOrUndirectedContext ------------------------------------------------------------------

GQLParser::SimplifiedOverrideLeftOrUndirectedContext::SimplifiedOverrideLeftOrUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedOverrideLeftOrUndirectedContext::LEFT_ARROW_TILDE() {
  return getToken(GQLParser::LEFT_ARROW_TILDE, 0);
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedOverrideLeftOrUndirectedContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}


size_t GQLParser::SimplifiedOverrideLeftOrUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedOverrideLeftOrUndirected;
}




//----------------- SimplifiedOverrideUndirectedOrRightContext ------------------------------------------------------------------

GQLParser::SimplifiedOverrideUndirectedOrRightContext::SimplifiedOverrideUndirectedOrRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedOverrideUndirectedOrRightContext::TILDE() {
  return getToken(GQLParser::TILDE, 0);
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedOverrideUndirectedOrRightContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedOverrideUndirectedOrRightContext::RIGHT_ANGLE_BRACKET() {
  return getToken(GQLParser::RIGHT_ANGLE_BRACKET, 0);
}


size_t GQLParser::SimplifiedOverrideUndirectedOrRightContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedOverrideUndirectedOrRight;
}




//----------------- SimplifiedOverrideLeftOrRightContext ------------------------------------------------------------------

GQLParser::SimplifiedOverrideLeftOrRightContext::SimplifiedOverrideLeftOrRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedOverrideLeftOrRightContext::LEFT_ANGLE_BRACKET() {
  return getToken(GQLParser::LEFT_ANGLE_BRACKET, 0);
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedOverrideLeftOrRightContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedOverrideLeftOrRightContext::RIGHT_ANGLE_BRACKET() {
  return getToken(GQLParser::RIGHT_ANGLE_BRACKET, 0);
}


size_t GQLParser::SimplifiedOverrideLeftOrRightContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedOverrideLeftOrRight;
}




//----------------- SimplifiedOverrideAnyDirectionContext ------------------------------------------------------------------

GQLParser::SimplifiedOverrideAnyDirectionContext::SimplifiedOverrideAnyDirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedOverrideAnyDirectionContext::MINUS_SIGN() {
  return getToken(GQLParser::MINUS_SIGN, 0);
}

GQLParser::SimplifiedSecondaryContext* GQLParser::SimplifiedOverrideAnyDirectionContext::simplifiedSecondary() {
  return getRuleContext<GQLParser::SimplifiedSecondaryContext>(0);
}


size_t GQLParser::SimplifiedOverrideAnyDirectionContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedOverrideAnyDirection;
}




//----------------- SimplifiedSecondaryContext ------------------------------------------------------------------

GQLParser::SimplifiedSecondaryContext::SimplifiedSecondaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimplifiedPrimaryContext* GQLParser::SimplifiedSecondaryContext::simplifiedPrimary() {
  return getRuleContext<GQLParser::SimplifiedPrimaryContext>(0);
}

GQLParser::SimplifiedNegationContext* GQLParser::SimplifiedSecondaryContext::simplifiedNegation() {
  return getRuleContext<GQLParser::SimplifiedNegationContext>(0);
}


size_t GQLParser::SimplifiedSecondaryContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedSecondary;
}




//----------------- SimplifiedNegationContext ------------------------------------------------------------------

GQLParser::SimplifiedNegationContext::SimplifiedNegationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimplifiedNegationContext::EXCLAMATION_MARK() {
  return getToken(GQLParser::EXCLAMATION_MARK, 0);
}

GQLParser::SimplifiedPrimaryContext* GQLParser::SimplifiedNegationContext::simplifiedPrimary() {
  return getRuleContext<GQLParser::SimplifiedPrimaryContext>(0);
}


size_t GQLParser::SimplifiedNegationContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedNegation;
}




//----------------- SimplifiedPrimaryContext ------------------------------------------------------------------

GQLParser::SimplifiedPrimaryContext::SimplifiedPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::LabelNameContext* GQLParser::SimplifiedPrimaryContext::labelName() {
  return getRuleContext<GQLParser::LabelNameContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedPrimaryContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::SimplifiedContentsContext* GQLParser::SimplifiedPrimaryContext::simplifiedContents() {
  return getRuleContext<GQLParser::SimplifiedContentsContext>(0);
}

tree::TerminalNode* GQLParser::SimplifiedPrimaryContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::SimplifiedPrimaryContext::getRuleIndex() const {
  return GQLParser::RuleSimplifiedPrimary;
}




//----------------- WhereClauseContext ------------------------------------------------------------------

GQLParser::WhereClauseContext::WhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::WhereClauseContext::WHERE() {
  return getToken(GQLParser::WHERE, 0);
}

GQLParser::SearchConditionContext* GQLParser::WhereClauseContext::searchCondition() {
  return getRuleContext<GQLParser::SearchConditionContext>(0);
}


size_t GQLParser::WhereClauseContext::getRuleIndex() const {
  return GQLParser::RuleWhereClause;
}




//----------------- YieldClauseContext ------------------------------------------------------------------

GQLParser::YieldClauseContext::YieldClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::YieldClauseContext::YIELD() {
  return getToken(GQLParser::YIELD, 0);
}

GQLParser::YieldItemListContext* GQLParser::YieldClauseContext::yieldItemList() {
  return getRuleContext<GQLParser::YieldItemListContext>(0);
}


size_t GQLParser::YieldClauseContext::getRuleIndex() const {
  return GQLParser::RuleYieldClause;
}




//----------------- YieldItemListContext ------------------------------------------------------------------

GQLParser::YieldItemListContext::YieldItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::YieldItemContext *> GQLParser::YieldItemListContext::yieldItem() {
  return getRuleContexts<GQLParser::YieldItemContext>();
}

GQLParser::YieldItemContext* GQLParser::YieldItemListContext::yieldItem(size_t i) {
  return getRuleContext<GQLParser::YieldItemContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::YieldItemListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::YieldItemListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::YieldItemListContext::getRuleIndex() const {
  return GQLParser::RuleYieldItemList;
}




//----------------- YieldItemContext ------------------------------------------------------------------

GQLParser::YieldItemContext::YieldItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::YieldItemNameContext* GQLParser::YieldItemContext::yieldItemName() {
  return getRuleContext<GQLParser::YieldItemNameContext>(0);
}

GQLParser::YieldItemAliasContext* GQLParser::YieldItemContext::yieldItemAlias() {
  return getRuleContext<GQLParser::YieldItemAliasContext>(0);
}


size_t GQLParser::YieldItemContext::getRuleIndex() const {
  return GQLParser::RuleYieldItem;
}




//----------------- YieldItemNameContext ------------------------------------------------------------------

GQLParser::YieldItemNameContext::YieldItemNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FieldNameContext* GQLParser::YieldItemNameContext::fieldName() {
  return getRuleContext<GQLParser::FieldNameContext>(0);
}


size_t GQLParser::YieldItemNameContext::getRuleIndex() const {
  return GQLParser::RuleYieldItemName;
}




//----------------- YieldItemAliasContext ------------------------------------------------------------------

GQLParser::YieldItemAliasContext::YieldItemAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::YieldItemAliasContext::AS() {
  return getToken(GQLParser::AS, 0);
}

GQLParser::BindingVariableContext* GQLParser::YieldItemAliasContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}


size_t GQLParser::YieldItemAliasContext::getRuleIndex() const {
  return GQLParser::RuleYieldItemAlias;
}




//----------------- GroupByClauseContext ------------------------------------------------------------------

GQLParser::GroupByClauseContext::GroupByClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GroupByClauseContext::GROUP() {
  return getToken(GQLParser::GROUP, 0);
}

tree::TerminalNode* GQLParser::GroupByClauseContext::BY() {
  return getToken(GQLParser::BY, 0);
}

GQLParser::GroupingElementListContext* GQLParser::GroupByClauseContext::groupingElementList() {
  return getRuleContext<GQLParser::GroupingElementListContext>(0);
}


size_t GQLParser::GroupByClauseContext::getRuleIndex() const {
  return GQLParser::RuleGroupByClause;
}




//----------------- GroupingElementListContext ------------------------------------------------------------------

GQLParser::GroupingElementListContext::GroupingElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::GroupingElementContext *> GQLParser::GroupingElementListContext::groupingElement() {
  return getRuleContexts<GQLParser::GroupingElementContext>();
}

GQLParser::GroupingElementContext* GQLParser::GroupingElementListContext::groupingElement(size_t i) {
  return getRuleContext<GQLParser::GroupingElementContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::GroupingElementListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::GroupingElementListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}

GQLParser::EmptyGroupingSetContext* GQLParser::GroupingElementListContext::emptyGroupingSet() {
  return getRuleContext<GQLParser::EmptyGroupingSetContext>(0);
}


size_t GQLParser::GroupingElementListContext::getRuleIndex() const {
  return GQLParser::RuleGroupingElementList;
}




//----------------- GroupingElementContext ------------------------------------------------------------------

GQLParser::GroupingElementContext::GroupingElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableReferenceContext* GQLParser::GroupingElementContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}


size_t GQLParser::GroupingElementContext::getRuleIndex() const {
  return GQLParser::RuleGroupingElement;
}




//----------------- EmptyGroupingSetContext ------------------------------------------------------------------

GQLParser::EmptyGroupingSetContext::EmptyGroupingSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EmptyGroupingSetContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::EmptyGroupingSetContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::EmptyGroupingSetContext::getRuleIndex() const {
  return GQLParser::RuleEmptyGroupingSet;
}




//----------------- OrderByClauseContext ------------------------------------------------------------------

GQLParser::OrderByClauseContext::OrderByClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::OrderByClauseContext::ORDER() {
  return getToken(GQLParser::ORDER, 0);
}

tree::TerminalNode* GQLParser::OrderByClauseContext::BY() {
  return getToken(GQLParser::BY, 0);
}

GQLParser::SortSpecificationListContext* GQLParser::OrderByClauseContext::sortSpecificationList() {
  return getRuleContext<GQLParser::SortSpecificationListContext>(0);
}


size_t GQLParser::OrderByClauseContext::getRuleIndex() const {
  return GQLParser::RuleOrderByClause;
}




//----------------- SortSpecificationListContext ------------------------------------------------------------------

GQLParser::SortSpecificationListContext::SortSpecificationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::SortSpecificationContext *> GQLParser::SortSpecificationListContext::sortSpecification() {
  return getRuleContexts<GQLParser::SortSpecificationContext>();
}

GQLParser::SortSpecificationContext* GQLParser::SortSpecificationListContext::sortSpecification(size_t i) {
  return getRuleContext<GQLParser::SortSpecificationContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SortSpecificationListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::SortSpecificationListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::SortSpecificationListContext::getRuleIndex() const {
  return GQLParser::RuleSortSpecificationList;
}




//----------------- SortSpecificationContext ------------------------------------------------------------------

GQLParser::SortSpecificationContext::SortSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SortKeyContext* GQLParser::SortSpecificationContext::sortKey() {
  return getRuleContext<GQLParser::SortKeyContext>(0);
}

GQLParser::OrderingSpecificationContext* GQLParser::SortSpecificationContext::orderingSpecification() {
  return getRuleContext<GQLParser::OrderingSpecificationContext>(0);
}

GQLParser::NullOrderingContext* GQLParser::SortSpecificationContext::nullOrdering() {
  return getRuleContext<GQLParser::NullOrderingContext>(0);
}


size_t GQLParser::SortSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleSortSpecification;
}




//----------------- SortKeyContext ------------------------------------------------------------------

GQLParser::SortKeyContext::SortKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AggregatingValueExpressionContext* GQLParser::SortKeyContext::aggregatingValueExpression() {
  return getRuleContext<GQLParser::AggregatingValueExpressionContext>(0);
}


size_t GQLParser::SortKeyContext::getRuleIndex() const {
  return GQLParser::RuleSortKey;
}




//----------------- OrderingSpecificationContext ------------------------------------------------------------------

GQLParser::OrderingSpecificationContext::OrderingSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::OrderingSpecificationContext::ASC() {
  return getToken(GQLParser::ASC, 0);
}

tree::TerminalNode* GQLParser::OrderingSpecificationContext::ASCENDING() {
  return getToken(GQLParser::ASCENDING, 0);
}

tree::TerminalNode* GQLParser::OrderingSpecificationContext::DESC() {
  return getToken(GQLParser::DESC, 0);
}

tree::TerminalNode* GQLParser::OrderingSpecificationContext::DESCENDING() {
  return getToken(GQLParser::DESCENDING, 0);
}


size_t GQLParser::OrderingSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleOrderingSpecification;
}




//----------------- NullOrderingContext ------------------------------------------------------------------

GQLParser::NullOrderingContext::NullOrderingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NullOrderingContext::NULLS() {
  return getToken(GQLParser::NULLS, 0);
}

tree::TerminalNode* GQLParser::NullOrderingContext::FIRST() {
  return getToken(GQLParser::FIRST, 0);
}

tree::TerminalNode* GQLParser::NullOrderingContext::LAST() {
  return getToken(GQLParser::LAST, 0);
}


size_t GQLParser::NullOrderingContext::getRuleIndex() const {
  return GQLParser::RuleNullOrdering;
}




//----------------- LimitClauseContext ------------------------------------------------------------------

GQLParser::LimitClauseContext::LimitClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LimitClauseContext::LIMIT() {
  return getToken(GQLParser::LIMIT, 0);
}

GQLParser::NonNegativeIntegerSpecificationContext* GQLParser::LimitClauseContext::nonNegativeIntegerSpecification() {
  return getRuleContext<GQLParser::NonNegativeIntegerSpecificationContext>(0);
}


size_t GQLParser::LimitClauseContext::getRuleIndex() const {
  return GQLParser::RuleLimitClause;
}




//----------------- OffsetClauseContext ------------------------------------------------------------------

GQLParser::OffsetClauseContext::OffsetClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::OffsetSynonymContext* GQLParser::OffsetClauseContext::offsetSynonym() {
  return getRuleContext<GQLParser::OffsetSynonymContext>(0);
}

GQLParser::NonNegativeIntegerSpecificationContext* GQLParser::OffsetClauseContext::nonNegativeIntegerSpecification() {
  return getRuleContext<GQLParser::NonNegativeIntegerSpecificationContext>(0);
}


size_t GQLParser::OffsetClauseContext::getRuleIndex() const {
  return GQLParser::RuleOffsetClause;
}




//----------------- OffsetSynonymContext ------------------------------------------------------------------

GQLParser::OffsetSynonymContext::OffsetSynonymContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::OffsetSynonymContext::OFFSET() {
  return getToken(GQLParser::OFFSET, 0);
}

tree::TerminalNode* GQLParser::OffsetSynonymContext::SKIP_RESERVED_WORD() {
  return getToken(GQLParser::SKIP_RESERVED_WORD, 0);
}


size_t GQLParser::OffsetSynonymContext::getRuleIndex() const {
  return GQLParser::RuleOffsetSynonym;
}




//----------------- SchemaReferenceContext ------------------------------------------------------------------

GQLParser::SchemaReferenceContext::SchemaReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AbsoluteCatalogSchemaReferenceContext* GQLParser::SchemaReferenceContext::absoluteCatalogSchemaReference() {
  return getRuleContext<GQLParser::AbsoluteCatalogSchemaReferenceContext>(0);
}

GQLParser::RelativeCatalogSchemaReferenceContext* GQLParser::SchemaReferenceContext::relativeCatalogSchemaReference() {
  return getRuleContext<GQLParser::RelativeCatalogSchemaReferenceContext>(0);
}

GQLParser::ReferenceParameterSpecificationContext* GQLParser::SchemaReferenceContext::referenceParameterSpecification() {
  return getRuleContext<GQLParser::ReferenceParameterSpecificationContext>(0);
}


size_t GQLParser::SchemaReferenceContext::getRuleIndex() const {
  return GQLParser::RuleSchemaReference;
}




//----------------- AbsoluteCatalogSchemaReferenceContext ------------------------------------------------------------------

GQLParser::AbsoluteCatalogSchemaReferenceContext::AbsoluteCatalogSchemaReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AbsoluteCatalogSchemaReferenceContext::SOLIDUS() {
  return getToken(GQLParser::SOLIDUS, 0);
}

GQLParser::AbsoluteDirectoryPathContext* GQLParser::AbsoluteCatalogSchemaReferenceContext::absoluteDirectoryPath() {
  return getRuleContext<GQLParser::AbsoluteDirectoryPathContext>(0);
}

GQLParser::SchemaNameContext* GQLParser::AbsoluteCatalogSchemaReferenceContext::schemaName() {
  return getRuleContext<GQLParser::SchemaNameContext>(0);
}


size_t GQLParser::AbsoluteCatalogSchemaReferenceContext::getRuleIndex() const {
  return GQLParser::RuleAbsoluteCatalogSchemaReference;
}




//----------------- CatalogSchemaParentAndNameContext ------------------------------------------------------------------

GQLParser::CatalogSchemaParentAndNameContext::CatalogSchemaParentAndNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AbsoluteDirectoryPathContext* GQLParser::CatalogSchemaParentAndNameContext::absoluteDirectoryPath() {
  return getRuleContext<GQLParser::AbsoluteDirectoryPathContext>(0);
}

GQLParser::SchemaNameContext* GQLParser::CatalogSchemaParentAndNameContext::schemaName() {
  return getRuleContext<GQLParser::SchemaNameContext>(0);
}


size_t GQLParser::CatalogSchemaParentAndNameContext::getRuleIndex() const {
  return GQLParser::RuleCatalogSchemaParentAndName;
}




//----------------- RelativeCatalogSchemaReferenceContext ------------------------------------------------------------------

GQLParser::RelativeCatalogSchemaReferenceContext::RelativeCatalogSchemaReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PredefinedSchemaReferenceContext* GQLParser::RelativeCatalogSchemaReferenceContext::predefinedSchemaReference() {
  return getRuleContext<GQLParser::PredefinedSchemaReferenceContext>(0);
}

GQLParser::RelativeDirectoryPathContext* GQLParser::RelativeCatalogSchemaReferenceContext::relativeDirectoryPath() {
  return getRuleContext<GQLParser::RelativeDirectoryPathContext>(0);
}

GQLParser::SchemaNameContext* GQLParser::RelativeCatalogSchemaReferenceContext::schemaName() {
  return getRuleContext<GQLParser::SchemaNameContext>(0);
}


size_t GQLParser::RelativeCatalogSchemaReferenceContext::getRuleIndex() const {
  return GQLParser::RuleRelativeCatalogSchemaReference;
}




//----------------- PredefinedSchemaReferenceContext ------------------------------------------------------------------

GQLParser::PredefinedSchemaReferenceContext::PredefinedSchemaReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PredefinedSchemaReferenceContext::HOME_SCHEMA() {
  return getToken(GQLParser::HOME_SCHEMA, 0);
}

tree::TerminalNode* GQLParser::PredefinedSchemaReferenceContext::CURRENT_SCHEMA() {
  return getToken(GQLParser::CURRENT_SCHEMA, 0);
}

tree::TerminalNode* GQLParser::PredefinedSchemaReferenceContext::PERIOD() {
  return getToken(GQLParser::PERIOD, 0);
}


size_t GQLParser::PredefinedSchemaReferenceContext::getRuleIndex() const {
  return GQLParser::RulePredefinedSchemaReference;
}




//----------------- AbsoluteDirectoryPathContext ------------------------------------------------------------------

GQLParser::AbsoluteDirectoryPathContext::AbsoluteDirectoryPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AbsoluteDirectoryPathContext::SOLIDUS() {
  return getToken(GQLParser::SOLIDUS, 0);
}

GQLParser::SimpleDirectoryPathContext* GQLParser::AbsoluteDirectoryPathContext::simpleDirectoryPath() {
  return getRuleContext<GQLParser::SimpleDirectoryPathContext>(0);
}


size_t GQLParser::AbsoluteDirectoryPathContext::getRuleIndex() const {
  return GQLParser::RuleAbsoluteDirectoryPath;
}




//----------------- RelativeDirectoryPathContext ------------------------------------------------------------------

GQLParser::RelativeDirectoryPathContext::RelativeDirectoryPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GQLParser::RelativeDirectoryPathContext::DOUBLE_PERIOD() {
  return getTokens(GQLParser::DOUBLE_PERIOD);
}

tree::TerminalNode* GQLParser::RelativeDirectoryPathContext::DOUBLE_PERIOD(size_t i) {
  return getToken(GQLParser::DOUBLE_PERIOD, i);
}

std::vector<tree::TerminalNode *> GQLParser::RelativeDirectoryPathContext::SOLIDUS() {
  return getTokens(GQLParser::SOLIDUS);
}

tree::TerminalNode* GQLParser::RelativeDirectoryPathContext::SOLIDUS(size_t i) {
  return getToken(GQLParser::SOLIDUS, i);
}

GQLParser::SimpleDirectoryPathContext* GQLParser::RelativeDirectoryPathContext::simpleDirectoryPath() {
  return getRuleContext<GQLParser::SimpleDirectoryPathContext>(0);
}


size_t GQLParser::RelativeDirectoryPathContext::getRuleIndex() const {
  return GQLParser::RuleRelativeDirectoryPath;
}




//----------------- SimpleDirectoryPathContext ------------------------------------------------------------------

GQLParser::SimpleDirectoryPathContext::SimpleDirectoryPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::DirectoryNameContext *> GQLParser::SimpleDirectoryPathContext::directoryName() {
  return getRuleContexts<GQLParser::DirectoryNameContext>();
}

GQLParser::DirectoryNameContext* GQLParser::SimpleDirectoryPathContext::directoryName(size_t i) {
  return getRuleContext<GQLParser::DirectoryNameContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SimpleDirectoryPathContext::SOLIDUS() {
  return getTokens(GQLParser::SOLIDUS);
}

tree::TerminalNode* GQLParser::SimpleDirectoryPathContext::SOLIDUS(size_t i) {
  return getToken(GQLParser::SOLIDUS, i);
}


size_t GQLParser::SimpleDirectoryPathContext::getRuleIndex() const {
  return GQLParser::RuleSimpleDirectoryPath;
}




//----------------- GraphReferenceContext ------------------------------------------------------------------

GQLParser::GraphReferenceContext::GraphReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CatalogObjectParentReferenceContext* GQLParser::GraphReferenceContext::catalogObjectParentReference() {
  return getRuleContext<GQLParser::CatalogObjectParentReferenceContext>(0);
}

GQLParser::GraphNameContext* GQLParser::GraphReferenceContext::graphName() {
  return getRuleContext<GQLParser::GraphNameContext>(0);
}

GQLParser::DelimitedGraphNameContext* GQLParser::GraphReferenceContext::delimitedGraphName() {
  return getRuleContext<GQLParser::DelimitedGraphNameContext>(0);
}

GQLParser::HomeGraphContext* GQLParser::GraphReferenceContext::homeGraph() {
  return getRuleContext<GQLParser::HomeGraphContext>(0);
}

GQLParser::ReferenceParameterSpecificationContext* GQLParser::GraphReferenceContext::referenceParameterSpecification() {
  return getRuleContext<GQLParser::ReferenceParameterSpecificationContext>(0);
}


size_t GQLParser::GraphReferenceContext::getRuleIndex() const {
  return GQLParser::RuleGraphReference;
}




//----------------- CatalogGraphParentAndNameContext ------------------------------------------------------------------

GQLParser::CatalogGraphParentAndNameContext::CatalogGraphParentAndNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphNameContext* GQLParser::CatalogGraphParentAndNameContext::graphName() {
  return getRuleContext<GQLParser::GraphNameContext>(0);
}

GQLParser::CatalogObjectParentReferenceContext* GQLParser::CatalogGraphParentAndNameContext::catalogObjectParentReference() {
  return getRuleContext<GQLParser::CatalogObjectParentReferenceContext>(0);
}


size_t GQLParser::CatalogGraphParentAndNameContext::getRuleIndex() const {
  return GQLParser::RuleCatalogGraphParentAndName;
}




//----------------- HomeGraphContext ------------------------------------------------------------------

GQLParser::HomeGraphContext::HomeGraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::HomeGraphContext::HOME_PROPERTY_GRAPH() {
  return getToken(GQLParser::HOME_PROPERTY_GRAPH, 0);
}

tree::TerminalNode* GQLParser::HomeGraphContext::HOME_GRAPH() {
  return getToken(GQLParser::HOME_GRAPH, 0);
}


size_t GQLParser::HomeGraphContext::getRuleIndex() const {
  return GQLParser::RuleHomeGraph;
}




//----------------- GraphTypeReferenceContext ------------------------------------------------------------------

GQLParser::GraphTypeReferenceContext::GraphTypeReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CatalogGraphTypeParentAndNameContext* GQLParser::GraphTypeReferenceContext::catalogGraphTypeParentAndName() {
  return getRuleContext<GQLParser::CatalogGraphTypeParentAndNameContext>(0);
}

GQLParser::ReferenceParameterSpecificationContext* GQLParser::GraphTypeReferenceContext::referenceParameterSpecification() {
  return getRuleContext<GQLParser::ReferenceParameterSpecificationContext>(0);
}


size_t GQLParser::GraphTypeReferenceContext::getRuleIndex() const {
  return GQLParser::RuleGraphTypeReference;
}




//----------------- CatalogGraphTypeParentAndNameContext ------------------------------------------------------------------

GQLParser::CatalogGraphTypeParentAndNameContext::CatalogGraphTypeParentAndNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphTypeNameContext* GQLParser::CatalogGraphTypeParentAndNameContext::graphTypeName() {
  return getRuleContext<GQLParser::GraphTypeNameContext>(0);
}

GQLParser::CatalogObjectParentReferenceContext* GQLParser::CatalogGraphTypeParentAndNameContext::catalogObjectParentReference() {
  return getRuleContext<GQLParser::CatalogObjectParentReferenceContext>(0);
}


size_t GQLParser::CatalogGraphTypeParentAndNameContext::getRuleIndex() const {
  return GQLParser::RuleCatalogGraphTypeParentAndName;
}




//----------------- BindingTableReferenceContext ------------------------------------------------------------------

GQLParser::BindingTableReferenceContext::BindingTableReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CatalogObjectParentReferenceContext* GQLParser::BindingTableReferenceContext::catalogObjectParentReference() {
  return getRuleContext<GQLParser::CatalogObjectParentReferenceContext>(0);
}

GQLParser::BindingTableNameContext* GQLParser::BindingTableReferenceContext::bindingTableName() {
  return getRuleContext<GQLParser::BindingTableNameContext>(0);
}

GQLParser::DelimitedBindingTableNameContext* GQLParser::BindingTableReferenceContext::delimitedBindingTableName() {
  return getRuleContext<GQLParser::DelimitedBindingTableNameContext>(0);
}

GQLParser::ReferenceParameterSpecificationContext* GQLParser::BindingTableReferenceContext::referenceParameterSpecification() {
  return getRuleContext<GQLParser::ReferenceParameterSpecificationContext>(0);
}


size_t GQLParser::BindingTableReferenceContext::getRuleIndex() const {
  return GQLParser::RuleBindingTableReference;
}




//----------------- ProcedureReferenceContext ------------------------------------------------------------------

GQLParser::ProcedureReferenceContext::ProcedureReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CatalogProcedureParentAndNameContext* GQLParser::ProcedureReferenceContext::catalogProcedureParentAndName() {
  return getRuleContext<GQLParser::CatalogProcedureParentAndNameContext>(0);
}

GQLParser::ReferenceParameterSpecificationContext* GQLParser::ProcedureReferenceContext::referenceParameterSpecification() {
  return getRuleContext<GQLParser::ReferenceParameterSpecificationContext>(0);
}


size_t GQLParser::ProcedureReferenceContext::getRuleIndex() const {
  return GQLParser::RuleProcedureReference;
}




//----------------- CatalogProcedureParentAndNameContext ------------------------------------------------------------------

GQLParser::CatalogProcedureParentAndNameContext::CatalogProcedureParentAndNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ProcedureNameContext* GQLParser::CatalogProcedureParentAndNameContext::procedureName() {
  return getRuleContext<GQLParser::ProcedureNameContext>(0);
}

GQLParser::CatalogObjectParentReferenceContext* GQLParser::CatalogProcedureParentAndNameContext::catalogObjectParentReference() {
  return getRuleContext<GQLParser::CatalogObjectParentReferenceContext>(0);
}


size_t GQLParser::CatalogProcedureParentAndNameContext::getRuleIndex() const {
  return GQLParser::RuleCatalogProcedureParentAndName;
}




//----------------- CatalogObjectParentReferenceContext ------------------------------------------------------------------

GQLParser::CatalogObjectParentReferenceContext::CatalogObjectParentReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SchemaReferenceContext* GQLParser::CatalogObjectParentReferenceContext::schemaReference() {
  return getRuleContext<GQLParser::SchemaReferenceContext>(0);
}

tree::TerminalNode* GQLParser::CatalogObjectParentReferenceContext::SOLIDUS() {
  return getToken(GQLParser::SOLIDUS, 0);
}

std::vector<GQLParser::ObjectNameContext *> GQLParser::CatalogObjectParentReferenceContext::objectName() {
  return getRuleContexts<GQLParser::ObjectNameContext>();
}

GQLParser::ObjectNameContext* GQLParser::CatalogObjectParentReferenceContext::objectName(size_t i) {
  return getRuleContext<GQLParser::ObjectNameContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::CatalogObjectParentReferenceContext::PERIOD() {
  return getTokens(GQLParser::PERIOD);
}

tree::TerminalNode* GQLParser::CatalogObjectParentReferenceContext::PERIOD(size_t i) {
  return getToken(GQLParser::PERIOD, i);
}


size_t GQLParser::CatalogObjectParentReferenceContext::getRuleIndex() const {
  return GQLParser::RuleCatalogObjectParentReference;
}




//----------------- ReferenceParameterSpecificationContext ------------------------------------------------------------------

GQLParser::ReferenceParameterSpecificationContext::ReferenceParameterSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ReferenceParameterSpecificationContext::SUBSTITUTED_PARAMETER_REFERENCE() {
  return getToken(GQLParser::SUBSTITUTED_PARAMETER_REFERENCE, 0);
}


size_t GQLParser::ReferenceParameterSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleReferenceParameterSpecification;
}




//----------------- NestedGraphTypeSpecificationContext ------------------------------------------------------------------

GQLParser::NestedGraphTypeSpecificationContext::NestedGraphTypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NestedGraphTypeSpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::GraphTypeSpecificationBodyContext* GQLParser::NestedGraphTypeSpecificationContext::graphTypeSpecificationBody() {
  return getRuleContext<GQLParser::GraphTypeSpecificationBodyContext>(0);
}

tree::TerminalNode* GQLParser::NestedGraphTypeSpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}


size_t GQLParser::NestedGraphTypeSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleNestedGraphTypeSpecification;
}




//----------------- GraphTypeSpecificationBodyContext ------------------------------------------------------------------

GQLParser::GraphTypeSpecificationBodyContext::GraphTypeSpecificationBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementTypeListContext* GQLParser::GraphTypeSpecificationBodyContext::elementTypeList() {
  return getRuleContext<GQLParser::ElementTypeListContext>(0);
}


size_t GQLParser::GraphTypeSpecificationBodyContext::getRuleIndex() const {
  return GQLParser::RuleGraphTypeSpecificationBody;
}




//----------------- ElementTypeListContext ------------------------------------------------------------------

GQLParser::ElementTypeListContext::ElementTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::ElementTypeSpecificationContext *> GQLParser::ElementTypeListContext::elementTypeSpecification() {
  return getRuleContexts<GQLParser::ElementTypeSpecificationContext>();
}

GQLParser::ElementTypeSpecificationContext* GQLParser::ElementTypeListContext::elementTypeSpecification(size_t i) {
  return getRuleContext<GQLParser::ElementTypeSpecificationContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::ElementTypeListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::ElementTypeListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::ElementTypeListContext::getRuleIndex() const {
  return GQLParser::RuleElementTypeList;
}




//----------------- ElementTypeSpecificationContext ------------------------------------------------------------------

GQLParser::ElementTypeSpecificationContext::ElementTypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeTypeSpecificationContext* GQLParser::ElementTypeSpecificationContext::nodeTypeSpecification() {
  return getRuleContext<GQLParser::NodeTypeSpecificationContext>(0);
}

GQLParser::EdgeTypeSpecificationContext* GQLParser::ElementTypeSpecificationContext::edgeTypeSpecification() {
  return getRuleContext<GQLParser::EdgeTypeSpecificationContext>(0);
}


size_t GQLParser::ElementTypeSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleElementTypeSpecification;
}




//----------------- NodeTypeSpecificationContext ------------------------------------------------------------------

GQLParser::NodeTypeSpecificationContext::NodeTypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeTypePatternContext* GQLParser::NodeTypeSpecificationContext::nodeTypePattern() {
  return getRuleContext<GQLParser::NodeTypePatternContext>(0);
}

GQLParser::NodeTypePhraseContext* GQLParser::NodeTypeSpecificationContext::nodeTypePhrase() {
  return getRuleContext<GQLParser::NodeTypePhraseContext>(0);
}


size_t GQLParser::NodeTypeSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypeSpecification;
}




//----------------- NodeTypePatternContext ------------------------------------------------------------------

GQLParser::NodeTypePatternContext::NodeTypePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NodeTypePatternContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::NodeTypePatternContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::NodeSynonymContext* GQLParser::NodeTypePatternContext::nodeSynonym() {
  return getRuleContext<GQLParser::NodeSynonymContext>(0);
}

GQLParser::NodeTypeNameContext* GQLParser::NodeTypePatternContext::nodeTypeName() {
  return getRuleContext<GQLParser::NodeTypeNameContext>(0);
}

GQLParser::LocalNodeTypeAliasContext* GQLParser::NodeTypePatternContext::localNodeTypeAlias() {
  return getRuleContext<GQLParser::LocalNodeTypeAliasContext>(0);
}

GQLParser::NodeTypeFillerContext* GQLParser::NodeTypePatternContext::nodeTypeFiller() {
  return getRuleContext<GQLParser::NodeTypeFillerContext>(0);
}

tree::TerminalNode* GQLParser::NodeTypePatternContext::TYPE() {
  return getToken(GQLParser::TYPE, 0);
}


size_t GQLParser::NodeTypePatternContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypePattern;
}




//----------------- NodeTypePhraseContext ------------------------------------------------------------------

GQLParser::NodeTypePhraseContext::NodeTypePhraseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeSynonymContext* GQLParser::NodeTypePhraseContext::nodeSynonym() {
  return getRuleContext<GQLParser::NodeSynonymContext>(0);
}

GQLParser::NodeTypePhraseFillerContext* GQLParser::NodeTypePhraseContext::nodeTypePhraseFiller() {
  return getRuleContext<GQLParser::NodeTypePhraseFillerContext>(0);
}

tree::TerminalNode* GQLParser::NodeTypePhraseContext::TYPE() {
  return getToken(GQLParser::TYPE, 0);
}

tree::TerminalNode* GQLParser::NodeTypePhraseContext::AS() {
  return getToken(GQLParser::AS, 0);
}

GQLParser::LocalNodeTypeAliasContext* GQLParser::NodeTypePhraseContext::localNodeTypeAlias() {
  return getRuleContext<GQLParser::LocalNodeTypeAliasContext>(0);
}


size_t GQLParser::NodeTypePhraseContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypePhrase;
}




//----------------- NodeTypePhraseFillerContext ------------------------------------------------------------------

GQLParser::NodeTypePhraseFillerContext::NodeTypePhraseFillerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeTypeNameContext* GQLParser::NodeTypePhraseFillerContext::nodeTypeName() {
  return getRuleContext<GQLParser::NodeTypeNameContext>(0);
}

GQLParser::NodeTypeFillerContext* GQLParser::NodeTypePhraseFillerContext::nodeTypeFiller() {
  return getRuleContext<GQLParser::NodeTypeFillerContext>(0);
}


size_t GQLParser::NodeTypePhraseFillerContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypePhraseFiller;
}




//----------------- NodeTypeFillerContext ------------------------------------------------------------------

GQLParser::NodeTypeFillerContext::NodeTypeFillerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeTypeKeyLabelSetContext* GQLParser::NodeTypeFillerContext::nodeTypeKeyLabelSet() {
  return getRuleContext<GQLParser::NodeTypeKeyLabelSetContext>(0);
}

GQLParser::NodeTypeImpliedContentContext* GQLParser::NodeTypeFillerContext::nodeTypeImpliedContent() {
  return getRuleContext<GQLParser::NodeTypeImpliedContentContext>(0);
}


size_t GQLParser::NodeTypeFillerContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypeFiller;
}




//----------------- LocalNodeTypeAliasContext ------------------------------------------------------------------

GQLParser::LocalNodeTypeAliasContext::LocalNodeTypeAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::LocalNodeTypeAliasContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}


size_t GQLParser::LocalNodeTypeAliasContext::getRuleIndex() const {
  return GQLParser::RuleLocalNodeTypeAlias;
}




//----------------- NodeTypeImpliedContentContext ------------------------------------------------------------------

GQLParser::NodeTypeImpliedContentContext::NodeTypeImpliedContentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeTypeLabelSetContext* GQLParser::NodeTypeImpliedContentContext::nodeTypeLabelSet() {
  return getRuleContext<GQLParser::NodeTypeLabelSetContext>(0);
}

GQLParser::NodeTypePropertyTypesContext* GQLParser::NodeTypeImpliedContentContext::nodeTypePropertyTypes() {
  return getRuleContext<GQLParser::NodeTypePropertyTypesContext>(0);
}


size_t GQLParser::NodeTypeImpliedContentContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypeImpliedContent;
}




//----------------- NodeTypeKeyLabelSetContext ------------------------------------------------------------------

GQLParser::NodeTypeKeyLabelSetContext::NodeTypeKeyLabelSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NodeTypeKeyLabelSetContext::IMPLIES() {
  return getToken(GQLParser::IMPLIES, 0);
}

GQLParser::LabelSetPhraseContext* GQLParser::NodeTypeKeyLabelSetContext::labelSetPhrase() {
  return getRuleContext<GQLParser::LabelSetPhraseContext>(0);
}


size_t GQLParser::NodeTypeKeyLabelSetContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypeKeyLabelSet;
}




//----------------- NodeTypeLabelSetContext ------------------------------------------------------------------

GQLParser::NodeTypeLabelSetContext::NodeTypeLabelSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::LabelSetPhraseContext* GQLParser::NodeTypeLabelSetContext::labelSetPhrase() {
  return getRuleContext<GQLParser::LabelSetPhraseContext>(0);
}


size_t GQLParser::NodeTypeLabelSetContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypeLabelSet;
}




//----------------- NodeTypePropertyTypesContext ------------------------------------------------------------------

GQLParser::NodeTypePropertyTypesContext::NodeTypePropertyTypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PropertyTypesSpecificationContext* GQLParser::NodeTypePropertyTypesContext::propertyTypesSpecification() {
  return getRuleContext<GQLParser::PropertyTypesSpecificationContext>(0);
}


size_t GQLParser::NodeTypePropertyTypesContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypePropertyTypes;
}




//----------------- EdgeTypeSpecificationContext ------------------------------------------------------------------

GQLParser::EdgeTypeSpecificationContext::EdgeTypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeTypePatternContext* GQLParser::EdgeTypeSpecificationContext::edgeTypePattern() {
  return getRuleContext<GQLParser::EdgeTypePatternContext>(0);
}

GQLParser::EdgeTypePhraseContext* GQLParser::EdgeTypeSpecificationContext::edgeTypePhrase() {
  return getRuleContext<GQLParser::EdgeTypePhraseContext>(0);
}


size_t GQLParser::EdgeTypeSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypeSpecification;
}




//----------------- EdgeTypePatternContext ------------------------------------------------------------------

GQLParser::EdgeTypePatternContext::EdgeTypePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeTypePatternDirectedContext* GQLParser::EdgeTypePatternContext::edgeTypePatternDirected() {
  return getRuleContext<GQLParser::EdgeTypePatternDirectedContext>(0);
}

GQLParser::EdgeTypePatternUndirectedContext* GQLParser::EdgeTypePatternContext::edgeTypePatternUndirected() {
  return getRuleContext<GQLParser::EdgeTypePatternUndirectedContext>(0);
}

GQLParser::EdgeSynonymContext* GQLParser::EdgeTypePatternContext::edgeSynonym() {
  return getRuleContext<GQLParser::EdgeSynonymContext>(0);
}

GQLParser::EdgeTypeNameContext* GQLParser::EdgeTypePatternContext::edgeTypeName() {
  return getRuleContext<GQLParser::EdgeTypeNameContext>(0);
}

GQLParser::EdgeKindContext* GQLParser::EdgeTypePatternContext::edgeKind() {
  return getRuleContext<GQLParser::EdgeKindContext>(0);
}

tree::TerminalNode* GQLParser::EdgeTypePatternContext::TYPE() {
  return getToken(GQLParser::TYPE, 0);
}


size_t GQLParser::EdgeTypePatternContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePattern;
}




//----------------- EdgeTypePhraseContext ------------------------------------------------------------------

GQLParser::EdgeTypePhraseContext::EdgeTypePhraseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeKindContext* GQLParser::EdgeTypePhraseContext::edgeKind() {
  return getRuleContext<GQLParser::EdgeKindContext>(0);
}

GQLParser::EdgeSynonymContext* GQLParser::EdgeTypePhraseContext::edgeSynonym() {
  return getRuleContext<GQLParser::EdgeSynonymContext>(0);
}

GQLParser::EdgeTypePhraseFillerContext* GQLParser::EdgeTypePhraseContext::edgeTypePhraseFiller() {
  return getRuleContext<GQLParser::EdgeTypePhraseFillerContext>(0);
}

GQLParser::EndpointPairPhraseContext* GQLParser::EdgeTypePhraseContext::endpointPairPhrase() {
  return getRuleContext<GQLParser::EndpointPairPhraseContext>(0);
}

tree::TerminalNode* GQLParser::EdgeTypePhraseContext::TYPE() {
  return getToken(GQLParser::TYPE, 0);
}


size_t GQLParser::EdgeTypePhraseContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePhrase;
}




//----------------- EdgeTypePhraseFillerContext ------------------------------------------------------------------

GQLParser::EdgeTypePhraseFillerContext::EdgeTypePhraseFillerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeTypeNameContext* GQLParser::EdgeTypePhraseFillerContext::edgeTypeName() {
  return getRuleContext<GQLParser::EdgeTypeNameContext>(0);
}

GQLParser::EdgeTypeFillerContext* GQLParser::EdgeTypePhraseFillerContext::edgeTypeFiller() {
  return getRuleContext<GQLParser::EdgeTypeFillerContext>(0);
}


size_t GQLParser::EdgeTypePhraseFillerContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePhraseFiller;
}




//----------------- EdgeTypeFillerContext ------------------------------------------------------------------

GQLParser::EdgeTypeFillerContext::EdgeTypeFillerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeTypeKeyLabelSetContext* GQLParser::EdgeTypeFillerContext::edgeTypeKeyLabelSet() {
  return getRuleContext<GQLParser::EdgeTypeKeyLabelSetContext>(0);
}

GQLParser::EdgeTypeImpliedContentContext* GQLParser::EdgeTypeFillerContext::edgeTypeImpliedContent() {
  return getRuleContext<GQLParser::EdgeTypeImpliedContentContext>(0);
}


size_t GQLParser::EdgeTypeFillerContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypeFiller;
}




//----------------- EdgeTypeImpliedContentContext ------------------------------------------------------------------

GQLParser::EdgeTypeImpliedContentContext::EdgeTypeImpliedContentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeTypeLabelSetContext* GQLParser::EdgeTypeImpliedContentContext::edgeTypeLabelSet() {
  return getRuleContext<GQLParser::EdgeTypeLabelSetContext>(0);
}

GQLParser::EdgeTypePropertyTypesContext* GQLParser::EdgeTypeImpliedContentContext::edgeTypePropertyTypes() {
  return getRuleContext<GQLParser::EdgeTypePropertyTypesContext>(0);
}


size_t GQLParser::EdgeTypeImpliedContentContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypeImpliedContent;
}




//----------------- EdgeTypeKeyLabelSetContext ------------------------------------------------------------------

GQLParser::EdgeTypeKeyLabelSetContext::EdgeTypeKeyLabelSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EdgeTypeKeyLabelSetContext::IMPLIES() {
  return getToken(GQLParser::IMPLIES, 0);
}

GQLParser::LabelSetPhraseContext* GQLParser::EdgeTypeKeyLabelSetContext::labelSetPhrase() {
  return getRuleContext<GQLParser::LabelSetPhraseContext>(0);
}


size_t GQLParser::EdgeTypeKeyLabelSetContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypeKeyLabelSet;
}




//----------------- EdgeTypeLabelSetContext ------------------------------------------------------------------

GQLParser::EdgeTypeLabelSetContext::EdgeTypeLabelSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::LabelSetPhraseContext* GQLParser::EdgeTypeLabelSetContext::labelSetPhrase() {
  return getRuleContext<GQLParser::LabelSetPhraseContext>(0);
}


size_t GQLParser::EdgeTypeLabelSetContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypeLabelSet;
}




//----------------- EdgeTypePropertyTypesContext ------------------------------------------------------------------

GQLParser::EdgeTypePropertyTypesContext::EdgeTypePropertyTypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PropertyTypesSpecificationContext* GQLParser::EdgeTypePropertyTypesContext::propertyTypesSpecification() {
  return getRuleContext<GQLParser::PropertyTypesSpecificationContext>(0);
}


size_t GQLParser::EdgeTypePropertyTypesContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePropertyTypes;
}




//----------------- EdgeTypePatternDirectedContext ------------------------------------------------------------------

GQLParser::EdgeTypePatternDirectedContext::EdgeTypePatternDirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeTypePatternPointingRightContext* GQLParser::EdgeTypePatternDirectedContext::edgeTypePatternPointingRight() {
  return getRuleContext<GQLParser::EdgeTypePatternPointingRightContext>(0);
}

GQLParser::EdgeTypePatternPointingLeftContext* GQLParser::EdgeTypePatternDirectedContext::edgeTypePatternPointingLeft() {
  return getRuleContext<GQLParser::EdgeTypePatternPointingLeftContext>(0);
}


size_t GQLParser::EdgeTypePatternDirectedContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePatternDirected;
}




//----------------- EdgeTypePatternPointingRightContext ------------------------------------------------------------------

GQLParser::EdgeTypePatternPointingRightContext::EdgeTypePatternPointingRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SourceNodeTypeReferenceContext* GQLParser::EdgeTypePatternPointingRightContext::sourceNodeTypeReference() {
  return getRuleContext<GQLParser::SourceNodeTypeReferenceContext>(0);
}

GQLParser::ArcTypePointingRightContext* GQLParser::EdgeTypePatternPointingRightContext::arcTypePointingRight() {
  return getRuleContext<GQLParser::ArcTypePointingRightContext>(0);
}

GQLParser::DestinationNodeTypeReferenceContext* GQLParser::EdgeTypePatternPointingRightContext::destinationNodeTypeReference() {
  return getRuleContext<GQLParser::DestinationNodeTypeReferenceContext>(0);
}


size_t GQLParser::EdgeTypePatternPointingRightContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePatternPointingRight;
}




//----------------- EdgeTypePatternPointingLeftContext ------------------------------------------------------------------

GQLParser::EdgeTypePatternPointingLeftContext::EdgeTypePatternPointingLeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DestinationNodeTypeReferenceContext* GQLParser::EdgeTypePatternPointingLeftContext::destinationNodeTypeReference() {
  return getRuleContext<GQLParser::DestinationNodeTypeReferenceContext>(0);
}

GQLParser::ArcTypePointingLeftContext* GQLParser::EdgeTypePatternPointingLeftContext::arcTypePointingLeft() {
  return getRuleContext<GQLParser::ArcTypePointingLeftContext>(0);
}

GQLParser::SourceNodeTypeReferenceContext* GQLParser::EdgeTypePatternPointingLeftContext::sourceNodeTypeReference() {
  return getRuleContext<GQLParser::SourceNodeTypeReferenceContext>(0);
}


size_t GQLParser::EdgeTypePatternPointingLeftContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePatternPointingLeft;
}




//----------------- EdgeTypePatternUndirectedContext ------------------------------------------------------------------

GQLParser::EdgeTypePatternUndirectedContext::EdgeTypePatternUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SourceNodeTypeReferenceContext* GQLParser::EdgeTypePatternUndirectedContext::sourceNodeTypeReference() {
  return getRuleContext<GQLParser::SourceNodeTypeReferenceContext>(0);
}

GQLParser::ArcTypeUndirectedContext* GQLParser::EdgeTypePatternUndirectedContext::arcTypeUndirected() {
  return getRuleContext<GQLParser::ArcTypeUndirectedContext>(0);
}

GQLParser::DestinationNodeTypeReferenceContext* GQLParser::EdgeTypePatternUndirectedContext::destinationNodeTypeReference() {
  return getRuleContext<GQLParser::DestinationNodeTypeReferenceContext>(0);
}


size_t GQLParser::EdgeTypePatternUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypePatternUndirected;
}




//----------------- ArcTypePointingRightContext ------------------------------------------------------------------

GQLParser::ArcTypePointingRightContext::ArcTypePointingRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ArcTypePointingRightContext::MINUS_LEFT_BRACKET() {
  return getToken(GQLParser::MINUS_LEFT_BRACKET, 0);
}

GQLParser::EdgeTypeFillerContext* GQLParser::ArcTypePointingRightContext::edgeTypeFiller() {
  return getRuleContext<GQLParser::EdgeTypeFillerContext>(0);
}

tree::TerminalNode* GQLParser::ArcTypePointingRightContext::BRACKET_RIGHT_ARROW() {
  return getToken(GQLParser::BRACKET_RIGHT_ARROW, 0);
}


size_t GQLParser::ArcTypePointingRightContext::getRuleIndex() const {
  return GQLParser::RuleArcTypePointingRight;
}




//----------------- ArcTypePointingLeftContext ------------------------------------------------------------------

GQLParser::ArcTypePointingLeftContext::ArcTypePointingLeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ArcTypePointingLeftContext::LEFT_ARROW_BRACKET() {
  return getToken(GQLParser::LEFT_ARROW_BRACKET, 0);
}

GQLParser::EdgeTypeFillerContext* GQLParser::ArcTypePointingLeftContext::edgeTypeFiller() {
  return getRuleContext<GQLParser::EdgeTypeFillerContext>(0);
}

tree::TerminalNode* GQLParser::ArcTypePointingLeftContext::RIGHT_BRACKET_MINUS() {
  return getToken(GQLParser::RIGHT_BRACKET_MINUS, 0);
}


size_t GQLParser::ArcTypePointingLeftContext::getRuleIndex() const {
  return GQLParser::RuleArcTypePointingLeft;
}




//----------------- ArcTypeUndirectedContext ------------------------------------------------------------------

GQLParser::ArcTypeUndirectedContext::ArcTypeUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ArcTypeUndirectedContext::TILDE_LEFT_BRACKET() {
  return getToken(GQLParser::TILDE_LEFT_BRACKET, 0);
}

GQLParser::EdgeTypeFillerContext* GQLParser::ArcTypeUndirectedContext::edgeTypeFiller() {
  return getRuleContext<GQLParser::EdgeTypeFillerContext>(0);
}

tree::TerminalNode* GQLParser::ArcTypeUndirectedContext::RIGHT_BRACKET_TILDE() {
  return getToken(GQLParser::RIGHT_BRACKET_TILDE, 0);
}


size_t GQLParser::ArcTypeUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleArcTypeUndirected;
}




//----------------- SourceNodeTypeReferenceContext ------------------------------------------------------------------

GQLParser::SourceNodeTypeReferenceContext::SourceNodeTypeReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SourceNodeTypeReferenceContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::SourceNodeTypeAliasContext* GQLParser::SourceNodeTypeReferenceContext::sourceNodeTypeAlias() {
  return getRuleContext<GQLParser::SourceNodeTypeAliasContext>(0);
}

tree::TerminalNode* GQLParser::SourceNodeTypeReferenceContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::NodeTypeFillerContext* GQLParser::SourceNodeTypeReferenceContext::nodeTypeFiller() {
  return getRuleContext<GQLParser::NodeTypeFillerContext>(0);
}


size_t GQLParser::SourceNodeTypeReferenceContext::getRuleIndex() const {
  return GQLParser::RuleSourceNodeTypeReference;
}




//----------------- DestinationNodeTypeReferenceContext ------------------------------------------------------------------

GQLParser::DestinationNodeTypeReferenceContext::DestinationNodeTypeReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DestinationNodeTypeReferenceContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::DestinationNodeTypeAliasContext* GQLParser::DestinationNodeTypeReferenceContext::destinationNodeTypeAlias() {
  return getRuleContext<GQLParser::DestinationNodeTypeAliasContext>(0);
}

tree::TerminalNode* GQLParser::DestinationNodeTypeReferenceContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::NodeTypeFillerContext* GQLParser::DestinationNodeTypeReferenceContext::nodeTypeFiller() {
  return getRuleContext<GQLParser::NodeTypeFillerContext>(0);
}


size_t GQLParser::DestinationNodeTypeReferenceContext::getRuleIndex() const {
  return GQLParser::RuleDestinationNodeTypeReference;
}




//----------------- EdgeKindContext ------------------------------------------------------------------

GQLParser::EdgeKindContext::EdgeKindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EdgeKindContext::DIRECTED() {
  return getToken(GQLParser::DIRECTED, 0);
}

tree::TerminalNode* GQLParser::EdgeKindContext::UNDIRECTED() {
  return getToken(GQLParser::UNDIRECTED, 0);
}


size_t GQLParser::EdgeKindContext::getRuleIndex() const {
  return GQLParser::RuleEdgeKind;
}




//----------------- EndpointPairPhraseContext ------------------------------------------------------------------

GQLParser::EndpointPairPhraseContext::EndpointPairPhraseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EndpointPairPhraseContext::CONNECTING() {
  return getToken(GQLParser::CONNECTING, 0);
}

GQLParser::EndpointPairContext* GQLParser::EndpointPairPhraseContext::endpointPair() {
  return getRuleContext<GQLParser::EndpointPairContext>(0);
}


size_t GQLParser::EndpointPairPhraseContext::getRuleIndex() const {
  return GQLParser::RuleEndpointPairPhrase;
}




//----------------- EndpointPairContext ------------------------------------------------------------------

GQLParser::EndpointPairContext::EndpointPairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EndpointPairDirectedContext* GQLParser::EndpointPairContext::endpointPairDirected() {
  return getRuleContext<GQLParser::EndpointPairDirectedContext>(0);
}

GQLParser::EndpointPairUndirectedContext* GQLParser::EndpointPairContext::endpointPairUndirected() {
  return getRuleContext<GQLParser::EndpointPairUndirectedContext>(0);
}


size_t GQLParser::EndpointPairContext::getRuleIndex() const {
  return GQLParser::RuleEndpointPair;
}




//----------------- EndpointPairDirectedContext ------------------------------------------------------------------

GQLParser::EndpointPairDirectedContext::EndpointPairDirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EndpointPairPointingRightContext* GQLParser::EndpointPairDirectedContext::endpointPairPointingRight() {
  return getRuleContext<GQLParser::EndpointPairPointingRightContext>(0);
}

GQLParser::EndpointPairPointingLeftContext* GQLParser::EndpointPairDirectedContext::endpointPairPointingLeft() {
  return getRuleContext<GQLParser::EndpointPairPointingLeftContext>(0);
}


size_t GQLParser::EndpointPairDirectedContext::getRuleIndex() const {
  return GQLParser::RuleEndpointPairDirected;
}




//----------------- EndpointPairPointingRightContext ------------------------------------------------------------------

GQLParser::EndpointPairPointingRightContext::EndpointPairPointingRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EndpointPairPointingRightContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::SourceNodeTypeAliasContext* GQLParser::EndpointPairPointingRightContext::sourceNodeTypeAlias() {
  return getRuleContext<GQLParser::SourceNodeTypeAliasContext>(0);
}

GQLParser::ConnectorPointingRightContext* GQLParser::EndpointPairPointingRightContext::connectorPointingRight() {
  return getRuleContext<GQLParser::ConnectorPointingRightContext>(0);
}

GQLParser::DestinationNodeTypeAliasContext* GQLParser::EndpointPairPointingRightContext::destinationNodeTypeAlias() {
  return getRuleContext<GQLParser::DestinationNodeTypeAliasContext>(0);
}

tree::TerminalNode* GQLParser::EndpointPairPointingRightContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::EndpointPairPointingRightContext::getRuleIndex() const {
  return GQLParser::RuleEndpointPairPointingRight;
}




//----------------- EndpointPairPointingLeftContext ------------------------------------------------------------------

GQLParser::EndpointPairPointingLeftContext::EndpointPairPointingLeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EndpointPairPointingLeftContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::DestinationNodeTypeAliasContext* GQLParser::EndpointPairPointingLeftContext::destinationNodeTypeAlias() {
  return getRuleContext<GQLParser::DestinationNodeTypeAliasContext>(0);
}

tree::TerminalNode* GQLParser::EndpointPairPointingLeftContext::LEFT_ARROW() {
  return getToken(GQLParser::LEFT_ARROW, 0);
}

GQLParser::SourceNodeTypeAliasContext* GQLParser::EndpointPairPointingLeftContext::sourceNodeTypeAlias() {
  return getRuleContext<GQLParser::SourceNodeTypeAliasContext>(0);
}

tree::TerminalNode* GQLParser::EndpointPairPointingLeftContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::EndpointPairPointingLeftContext::getRuleIndex() const {
  return GQLParser::RuleEndpointPairPointingLeft;
}




//----------------- EndpointPairUndirectedContext ------------------------------------------------------------------

GQLParser::EndpointPairUndirectedContext::EndpointPairUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EndpointPairUndirectedContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::SourceNodeTypeAliasContext* GQLParser::EndpointPairUndirectedContext::sourceNodeTypeAlias() {
  return getRuleContext<GQLParser::SourceNodeTypeAliasContext>(0);
}

GQLParser::ConnectorUndirectedContext* GQLParser::EndpointPairUndirectedContext::connectorUndirected() {
  return getRuleContext<GQLParser::ConnectorUndirectedContext>(0);
}

GQLParser::DestinationNodeTypeAliasContext* GQLParser::EndpointPairUndirectedContext::destinationNodeTypeAlias() {
  return getRuleContext<GQLParser::DestinationNodeTypeAliasContext>(0);
}

tree::TerminalNode* GQLParser::EndpointPairUndirectedContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::EndpointPairUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleEndpointPairUndirected;
}




//----------------- ConnectorPointingRightContext ------------------------------------------------------------------

GQLParser::ConnectorPointingRightContext::ConnectorPointingRightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ConnectorPointingRightContext::TO() {
  return getToken(GQLParser::TO, 0);
}

tree::TerminalNode* GQLParser::ConnectorPointingRightContext::RIGHT_ARROW() {
  return getToken(GQLParser::RIGHT_ARROW, 0);
}


size_t GQLParser::ConnectorPointingRightContext::getRuleIndex() const {
  return GQLParser::RuleConnectorPointingRight;
}




//----------------- ConnectorUndirectedContext ------------------------------------------------------------------

GQLParser::ConnectorUndirectedContext::ConnectorUndirectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ConnectorUndirectedContext::TO() {
  return getToken(GQLParser::TO, 0);
}

tree::TerminalNode* GQLParser::ConnectorUndirectedContext::TILDE() {
  return getToken(GQLParser::TILDE, 0);
}


size_t GQLParser::ConnectorUndirectedContext::getRuleIndex() const {
  return GQLParser::RuleConnectorUndirected;
}




//----------------- SourceNodeTypeAliasContext ------------------------------------------------------------------

GQLParser::SourceNodeTypeAliasContext::SourceNodeTypeAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::SourceNodeTypeAliasContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}


size_t GQLParser::SourceNodeTypeAliasContext::getRuleIndex() const {
  return GQLParser::RuleSourceNodeTypeAlias;
}




//----------------- DestinationNodeTypeAliasContext ------------------------------------------------------------------

GQLParser::DestinationNodeTypeAliasContext::DestinationNodeTypeAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::DestinationNodeTypeAliasContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}


size_t GQLParser::DestinationNodeTypeAliasContext::getRuleIndex() const {
  return GQLParser::RuleDestinationNodeTypeAlias;
}




//----------------- LabelSetPhraseContext ------------------------------------------------------------------

GQLParser::LabelSetPhraseContext::LabelSetPhraseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LabelSetPhraseContext::LABEL() {
  return getToken(GQLParser::LABEL, 0);
}

GQLParser::LabelNameContext* GQLParser::LabelSetPhraseContext::labelName() {
  return getRuleContext<GQLParser::LabelNameContext>(0);
}

tree::TerminalNode* GQLParser::LabelSetPhraseContext::LABELS() {
  return getToken(GQLParser::LABELS, 0);
}

GQLParser::LabelSetSpecificationContext* GQLParser::LabelSetPhraseContext::labelSetSpecification() {
  return getRuleContext<GQLParser::LabelSetSpecificationContext>(0);
}

GQLParser::IsOrColonContext* GQLParser::LabelSetPhraseContext::isOrColon() {
  return getRuleContext<GQLParser::IsOrColonContext>(0);
}


size_t GQLParser::LabelSetPhraseContext::getRuleIndex() const {
  return GQLParser::RuleLabelSetPhrase;
}




//----------------- LabelSetSpecificationContext ------------------------------------------------------------------

GQLParser::LabelSetSpecificationContext::LabelSetSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::LabelNameContext *> GQLParser::LabelSetSpecificationContext::labelName() {
  return getRuleContexts<GQLParser::LabelNameContext>();
}

GQLParser::LabelNameContext* GQLParser::LabelSetSpecificationContext::labelName(size_t i) {
  return getRuleContext<GQLParser::LabelNameContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::LabelSetSpecificationContext::AMPERSAND() {
  return getTokens(GQLParser::AMPERSAND);
}

tree::TerminalNode* GQLParser::LabelSetSpecificationContext::AMPERSAND(size_t i) {
  return getToken(GQLParser::AMPERSAND, i);
}


size_t GQLParser::LabelSetSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleLabelSetSpecification;
}




//----------------- PropertyTypesSpecificationContext ------------------------------------------------------------------

GQLParser::PropertyTypesSpecificationContext::PropertyTypesSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PropertyTypesSpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

tree::TerminalNode* GQLParser::PropertyTypesSpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}

GQLParser::PropertyTypeListContext* GQLParser::PropertyTypesSpecificationContext::propertyTypeList() {
  return getRuleContext<GQLParser::PropertyTypeListContext>(0);
}


size_t GQLParser::PropertyTypesSpecificationContext::getRuleIndex() const {
  return GQLParser::RulePropertyTypesSpecification;
}




//----------------- PropertyTypeListContext ------------------------------------------------------------------

GQLParser::PropertyTypeListContext::PropertyTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::PropertyTypeContext *> GQLParser::PropertyTypeListContext::propertyType() {
  return getRuleContexts<GQLParser::PropertyTypeContext>();
}

GQLParser::PropertyTypeContext* GQLParser::PropertyTypeListContext::propertyType(size_t i) {
  return getRuleContext<GQLParser::PropertyTypeContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::PropertyTypeListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::PropertyTypeListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::PropertyTypeListContext::getRuleIndex() const {
  return GQLParser::RulePropertyTypeList;
}




//----------------- PropertyTypeContext ------------------------------------------------------------------

GQLParser::PropertyTypeContext::PropertyTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PropertyNameContext* GQLParser::PropertyTypeContext::propertyName() {
  return getRuleContext<GQLParser::PropertyNameContext>(0);
}

GQLParser::PropertyValueTypeContext* GQLParser::PropertyTypeContext::propertyValueType() {
  return getRuleContext<GQLParser::PropertyValueTypeContext>(0);
}

GQLParser::TypedContext* GQLParser::PropertyTypeContext::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}


size_t GQLParser::PropertyTypeContext::getRuleIndex() const {
  return GQLParser::RulePropertyType;
}




//----------------- PropertyValueTypeContext ------------------------------------------------------------------

GQLParser::PropertyValueTypeContext::PropertyValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueTypeContext* GQLParser::PropertyValueTypeContext::valueType() {
  return getRuleContext<GQLParser::ValueTypeContext>(0);
}


size_t GQLParser::PropertyValueTypeContext::getRuleIndex() const {
  return GQLParser::RulePropertyValueType;
}




//----------------- BindingTableTypeContext ------------------------------------------------------------------

GQLParser::BindingTableTypeContext::BindingTableTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::BindingTableTypeContext::TABLE() {
  return getToken(GQLParser::TABLE, 0);
}

GQLParser::FieldTypesSpecificationContext* GQLParser::BindingTableTypeContext::fieldTypesSpecification() {
  return getRuleContext<GQLParser::FieldTypesSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::BindingTableTypeContext::BINDING() {
  return getToken(GQLParser::BINDING, 0);
}


size_t GQLParser::BindingTableTypeContext::getRuleIndex() const {
  return GQLParser::RuleBindingTableType;
}




//----------------- ValueTypeContext ------------------------------------------------------------------

GQLParser::ValueTypeContext::ValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::ValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleValueType;
}

void GQLParser::ValueTypeContext::copyFrom(ValueTypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DynamicPropertyValueTypeLabelContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::DynamicPropertyValueTypeLabelContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

tree::TerminalNode* GQLParser::DynamicPropertyValueTypeLabelContext::VALUE() {
  return getToken(GQLParser::VALUE, 0);
}

tree::TerminalNode* GQLParser::DynamicPropertyValueTypeLabelContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

GQLParser::NotNullContext* GQLParser::DynamicPropertyValueTypeLabelContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::DynamicPropertyValueTypeLabelContext::DynamicPropertyValueTypeLabelContext(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- ClosedDynamicUnionTypeAtl1Context ------------------------------------------------------------------

tree::TerminalNode* GQLParser::ClosedDynamicUnionTypeAtl1Context::ANY() {
  return getToken(GQLParser::ANY, 0);
}

tree::TerminalNode* GQLParser::ClosedDynamicUnionTypeAtl1Context::LEFT_ANGLE_BRACKET() {
  return getToken(GQLParser::LEFT_ANGLE_BRACKET, 0);
}

std::vector<GQLParser::ValueTypeContext *> GQLParser::ClosedDynamicUnionTypeAtl1Context::valueType() {
  return getRuleContexts<GQLParser::ValueTypeContext>();
}

GQLParser::ValueTypeContext* GQLParser::ClosedDynamicUnionTypeAtl1Context::valueType(size_t i) {
  return getRuleContext<GQLParser::ValueTypeContext>(i);
}

tree::TerminalNode* GQLParser::ClosedDynamicUnionTypeAtl1Context::RIGHT_ANGLE_BRACKET() {
  return getToken(GQLParser::RIGHT_ANGLE_BRACKET, 0);
}

tree::TerminalNode* GQLParser::ClosedDynamicUnionTypeAtl1Context::VALUE() {
  return getToken(GQLParser::VALUE, 0);
}

std::vector<tree::TerminalNode *> GQLParser::ClosedDynamicUnionTypeAtl1Context::VERTICAL_BAR() {
  return getTokens(GQLParser::VERTICAL_BAR);
}

tree::TerminalNode* GQLParser::ClosedDynamicUnionTypeAtl1Context::VERTICAL_BAR(size_t i) {
  return getToken(GQLParser::VERTICAL_BAR, i);
}

GQLParser::ClosedDynamicUnionTypeAtl1Context::ClosedDynamicUnionTypeAtl1Context(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- ClosedDynamicUnionTypeAtl2Context ------------------------------------------------------------------

std::vector<GQLParser::ValueTypeContext *> GQLParser::ClosedDynamicUnionTypeAtl2Context::valueType() {
  return getRuleContexts<GQLParser::ValueTypeContext>();
}

GQLParser::ValueTypeContext* GQLParser::ClosedDynamicUnionTypeAtl2Context::valueType(size_t i) {
  return getRuleContext<GQLParser::ValueTypeContext>(i);
}

tree::TerminalNode* GQLParser::ClosedDynamicUnionTypeAtl2Context::VERTICAL_BAR() {
  return getToken(GQLParser::VERTICAL_BAR, 0);
}

GQLParser::ClosedDynamicUnionTypeAtl2Context::ClosedDynamicUnionTypeAtl2Context(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- PathValueTypeLabelContext ------------------------------------------------------------------

GQLParser::PathValueTypeContext* GQLParser::PathValueTypeLabelContext::pathValueType() {
  return getRuleContext<GQLParser::PathValueTypeContext>(0);
}

GQLParser::PathValueTypeLabelContext::PathValueTypeLabelContext(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- ListValueTypeAlt3Context ------------------------------------------------------------------

GQLParser::ListValueTypeNameContext* GQLParser::ListValueTypeAlt3Context::listValueTypeName() {
  return getRuleContext<GQLParser::ListValueTypeNameContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt3Context::LEFT_BRACKET() {
  return getToken(GQLParser::LEFT_BRACKET, 0);
}

GQLParser::MaxLengthContext* GQLParser::ListValueTypeAlt3Context::maxLength() {
  return getRuleContext<GQLParser::MaxLengthContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt3Context::RIGHT_BRACKET() {
  return getToken(GQLParser::RIGHT_BRACKET, 0);
}

GQLParser::NotNullContext* GQLParser::ListValueTypeAlt3Context::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::ListValueTypeAlt3Context::ListValueTypeAlt3Context(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- ListValueTypeAlt2Context ------------------------------------------------------------------

GQLParser::ValueTypeContext* GQLParser::ListValueTypeAlt2Context::valueType() {
  return getRuleContext<GQLParser::ValueTypeContext>(0);
}

GQLParser::ListValueTypeNameContext* GQLParser::ListValueTypeAlt2Context::listValueTypeName() {
  return getRuleContext<GQLParser::ListValueTypeNameContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt2Context::LEFT_BRACKET() {
  return getToken(GQLParser::LEFT_BRACKET, 0);
}

GQLParser::MaxLengthContext* GQLParser::ListValueTypeAlt2Context::maxLength() {
  return getRuleContext<GQLParser::MaxLengthContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt2Context::RIGHT_BRACKET() {
  return getToken(GQLParser::RIGHT_BRACKET, 0);
}

GQLParser::NotNullContext* GQLParser::ListValueTypeAlt2Context::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::ListValueTypeAlt2Context::ListValueTypeAlt2Context(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- ListValueTypeAlt1Context ------------------------------------------------------------------

GQLParser::ListValueTypeNameContext* GQLParser::ListValueTypeAlt1Context::listValueTypeName() {
  return getRuleContext<GQLParser::ListValueTypeNameContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt1Context::LEFT_ANGLE_BRACKET() {
  return getToken(GQLParser::LEFT_ANGLE_BRACKET, 0);
}

GQLParser::ValueTypeContext* GQLParser::ListValueTypeAlt1Context::valueType() {
  return getRuleContext<GQLParser::ValueTypeContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt1Context::RIGHT_ANGLE_BRACKET() {
  return getToken(GQLParser::RIGHT_ANGLE_BRACKET, 0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt1Context::LEFT_BRACKET() {
  return getToken(GQLParser::LEFT_BRACKET, 0);
}

GQLParser::MaxLengthContext* GQLParser::ListValueTypeAlt1Context::maxLength() {
  return getRuleContext<GQLParser::MaxLengthContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeAlt1Context::RIGHT_BRACKET() {
  return getToken(GQLParser::RIGHT_BRACKET, 0);
}

GQLParser::NotNullContext* GQLParser::ListValueTypeAlt1Context::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::ListValueTypeAlt1Context::ListValueTypeAlt1Context(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- PredefinedTypeLabelContext ------------------------------------------------------------------

GQLParser::PredefinedTypeContext* GQLParser::PredefinedTypeLabelContext::predefinedType() {
  return getRuleContext<GQLParser::PredefinedTypeContext>(0);
}

GQLParser::PredefinedTypeLabelContext::PredefinedTypeLabelContext(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- RecordTypeLabelContext ------------------------------------------------------------------

GQLParser::RecordTypeContext* GQLParser::RecordTypeLabelContext::recordType() {
  return getRuleContext<GQLParser::RecordTypeContext>(0);
}

GQLParser::RecordTypeLabelContext::RecordTypeLabelContext(ValueTypeContext *ctx) { copyFrom(ctx); }


//----------------- OpenDynamicUnionTypeLabelContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::OpenDynamicUnionTypeLabelContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

tree::TerminalNode* GQLParser::OpenDynamicUnionTypeLabelContext::VALUE() {
  return getToken(GQLParser::VALUE, 0);
}

GQLParser::NotNullContext* GQLParser::OpenDynamicUnionTypeLabelContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::OpenDynamicUnionTypeLabelContext::OpenDynamicUnionTypeLabelContext(ValueTypeContext *ctx) { copyFrom(ctx); }




//----------------- TypedContext ------------------------------------------------------------------

GQLParser::TypedContext::TypedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TypedContext::DOUBLE_COLON() {
  return getToken(GQLParser::DOUBLE_COLON, 0);
}

tree::TerminalNode* GQLParser::TypedContext::TYPED() {
  return getToken(GQLParser::TYPED, 0);
}


size_t GQLParser::TypedContext::getRuleIndex() const {
  return GQLParser::RuleTyped;
}




//----------------- PredefinedTypeContext ------------------------------------------------------------------

GQLParser::PredefinedTypeContext::PredefinedTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BooleanTypeContext* GQLParser::PredefinedTypeContext::booleanType() {
  return getRuleContext<GQLParser::BooleanTypeContext>(0);
}

GQLParser::CharacterStringTypeContext* GQLParser::PredefinedTypeContext::characterStringType() {
  return getRuleContext<GQLParser::CharacterStringTypeContext>(0);
}

GQLParser::ByteStringTypeContext* GQLParser::PredefinedTypeContext::byteStringType() {
  return getRuleContext<GQLParser::ByteStringTypeContext>(0);
}

GQLParser::NumericTypeContext* GQLParser::PredefinedTypeContext::numericType() {
  return getRuleContext<GQLParser::NumericTypeContext>(0);
}

GQLParser::TemporalTypeContext* GQLParser::PredefinedTypeContext::temporalType() {
  return getRuleContext<GQLParser::TemporalTypeContext>(0);
}

GQLParser::ReferenceValueTypeContext* GQLParser::PredefinedTypeContext::referenceValueType() {
  return getRuleContext<GQLParser::ReferenceValueTypeContext>(0);
}

GQLParser::ImmaterialValueTypeContext* GQLParser::PredefinedTypeContext::immaterialValueType() {
  return getRuleContext<GQLParser::ImmaterialValueTypeContext>(0);
}


size_t GQLParser::PredefinedTypeContext::getRuleIndex() const {
  return GQLParser::RulePredefinedType;
}




//----------------- BooleanTypeContext ------------------------------------------------------------------

GQLParser::BooleanTypeContext::BooleanTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::BooleanTypeContext::BOOL() {
  return getToken(GQLParser::BOOL, 0);
}

tree::TerminalNode* GQLParser::BooleanTypeContext::BOOLEAN() {
  return getToken(GQLParser::BOOLEAN, 0);
}

GQLParser::NotNullContext* GQLParser::BooleanTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::BooleanTypeContext::getRuleIndex() const {
  return GQLParser::RuleBooleanType;
}




//----------------- CharacterStringTypeContext ------------------------------------------------------------------

GQLParser::CharacterStringTypeContext::CharacterStringTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CharacterStringTypeContext::STRING() {
  return getToken(GQLParser::STRING, 0);
}

tree::TerminalNode* GQLParser::CharacterStringTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::MaxLengthContext* GQLParser::CharacterStringTypeContext::maxLength() {
  return getRuleContext<GQLParser::MaxLengthContext>(0);
}

tree::TerminalNode* GQLParser::CharacterStringTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::NotNullContext* GQLParser::CharacterStringTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::MinLengthContext* GQLParser::CharacterStringTypeContext::minLength() {
  return getRuleContext<GQLParser::MinLengthContext>(0);
}

tree::TerminalNode* GQLParser::CharacterStringTypeContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

tree::TerminalNode* GQLParser::CharacterStringTypeContext::CHAR() {
  return getToken(GQLParser::CHAR, 0);
}

GQLParser::FixedLengthContext* GQLParser::CharacterStringTypeContext::fixedLength() {
  return getRuleContext<GQLParser::FixedLengthContext>(0);
}

tree::TerminalNode* GQLParser::CharacterStringTypeContext::VARCHAR() {
  return getToken(GQLParser::VARCHAR, 0);
}


size_t GQLParser::CharacterStringTypeContext::getRuleIndex() const {
  return GQLParser::RuleCharacterStringType;
}




//----------------- ByteStringTypeContext ------------------------------------------------------------------

GQLParser::ByteStringTypeContext::ByteStringTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ByteStringTypeContext::BYTES() {
  return getToken(GQLParser::BYTES, 0);
}

tree::TerminalNode* GQLParser::ByteStringTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::MaxLengthContext* GQLParser::ByteStringTypeContext::maxLength() {
  return getRuleContext<GQLParser::MaxLengthContext>(0);
}

tree::TerminalNode* GQLParser::ByteStringTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::NotNullContext* GQLParser::ByteStringTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::MinLengthContext* GQLParser::ByteStringTypeContext::minLength() {
  return getRuleContext<GQLParser::MinLengthContext>(0);
}

tree::TerminalNode* GQLParser::ByteStringTypeContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

tree::TerminalNode* GQLParser::ByteStringTypeContext::BINARY() {
  return getToken(GQLParser::BINARY, 0);
}

GQLParser::FixedLengthContext* GQLParser::ByteStringTypeContext::fixedLength() {
  return getRuleContext<GQLParser::FixedLengthContext>(0);
}

tree::TerminalNode* GQLParser::ByteStringTypeContext::VARBINARY() {
  return getToken(GQLParser::VARBINARY, 0);
}


size_t GQLParser::ByteStringTypeContext::getRuleIndex() const {
  return GQLParser::RuleByteStringType;
}




//----------------- MinLengthContext ------------------------------------------------------------------

GQLParser::MinLengthContext::MinLengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedIntegerContext* GQLParser::MinLengthContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}


size_t GQLParser::MinLengthContext::getRuleIndex() const {
  return GQLParser::RuleMinLength;
}




//----------------- MaxLengthContext ------------------------------------------------------------------

GQLParser::MaxLengthContext::MaxLengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedIntegerContext* GQLParser::MaxLengthContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}


size_t GQLParser::MaxLengthContext::getRuleIndex() const {
  return GQLParser::RuleMaxLength;
}




//----------------- FixedLengthContext ------------------------------------------------------------------

GQLParser::FixedLengthContext::FixedLengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedIntegerContext* GQLParser::FixedLengthContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}


size_t GQLParser::FixedLengthContext::getRuleIndex() const {
  return GQLParser::RuleFixedLength;
}




//----------------- NumericTypeContext ------------------------------------------------------------------

GQLParser::NumericTypeContext::NumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ExactNumericTypeContext* GQLParser::NumericTypeContext::exactNumericType() {
  return getRuleContext<GQLParser::ExactNumericTypeContext>(0);
}

GQLParser::ApproximateNumericTypeContext* GQLParser::NumericTypeContext::approximateNumericType() {
  return getRuleContext<GQLParser::ApproximateNumericTypeContext>(0);
}


size_t GQLParser::NumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleNumericType;
}




//----------------- ExactNumericTypeContext ------------------------------------------------------------------

GQLParser::ExactNumericTypeContext::ExactNumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BinaryExactNumericTypeContext* GQLParser::ExactNumericTypeContext::binaryExactNumericType() {
  return getRuleContext<GQLParser::BinaryExactNumericTypeContext>(0);
}

GQLParser::DecimalExactNumericTypeContext* GQLParser::ExactNumericTypeContext::decimalExactNumericType() {
  return getRuleContext<GQLParser::DecimalExactNumericTypeContext>(0);
}


size_t GQLParser::ExactNumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleExactNumericType;
}




//----------------- BinaryExactNumericTypeContext ------------------------------------------------------------------

GQLParser::BinaryExactNumericTypeContext::BinaryExactNumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SignedBinaryExactNumericTypeContext* GQLParser::BinaryExactNumericTypeContext::signedBinaryExactNumericType() {
  return getRuleContext<GQLParser::SignedBinaryExactNumericTypeContext>(0);
}

GQLParser::UnsignedBinaryExactNumericTypeContext* GQLParser::BinaryExactNumericTypeContext::unsignedBinaryExactNumericType() {
  return getRuleContext<GQLParser::UnsignedBinaryExactNumericTypeContext>(0);
}


size_t GQLParser::BinaryExactNumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleBinaryExactNumericType;
}




//----------------- SignedBinaryExactNumericTypeContext ------------------------------------------------------------------

GQLParser::SignedBinaryExactNumericTypeContext::SignedBinaryExactNumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::INT8() {
  return getToken(GQLParser::INT8, 0);
}

GQLParser::NotNullContext* GQLParser::SignedBinaryExactNumericTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::INT16() {
  return getToken(GQLParser::INT16, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::INT32() {
  return getToken(GQLParser::INT32, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::INT64() {
  return getToken(GQLParser::INT64, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::INT128() {
  return getToken(GQLParser::INT128, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::INT256() {
  return getToken(GQLParser::INT256, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::SMALLINT() {
  return getToken(GQLParser::SMALLINT, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::INT() {
  return getToken(GQLParser::INT, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PrecisionContext* GQLParser::SignedBinaryExactNumericTypeContext::precision() {
  return getRuleContext<GQLParser::PrecisionContext>(0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::BIGINT() {
  return getToken(GQLParser::BIGINT, 0);
}

GQLParser::VerboseBinaryExactNumericTypeContext* GQLParser::SignedBinaryExactNumericTypeContext::verboseBinaryExactNumericType() {
  return getRuleContext<GQLParser::VerboseBinaryExactNumericTypeContext>(0);
}

tree::TerminalNode* GQLParser::SignedBinaryExactNumericTypeContext::SIGNED() {
  return getToken(GQLParser::SIGNED, 0);
}


size_t GQLParser::SignedBinaryExactNumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleSignedBinaryExactNumericType;
}




//----------------- UnsignedBinaryExactNumericTypeContext ------------------------------------------------------------------

GQLParser::UnsignedBinaryExactNumericTypeContext::UnsignedBinaryExactNumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UINT8() {
  return getToken(GQLParser::UINT8, 0);
}

GQLParser::NotNullContext* GQLParser::UnsignedBinaryExactNumericTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UINT16() {
  return getToken(GQLParser::UINT16, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UINT32() {
  return getToken(GQLParser::UINT32, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UINT64() {
  return getToken(GQLParser::UINT64, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UINT128() {
  return getToken(GQLParser::UINT128, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UINT256() {
  return getToken(GQLParser::UINT256, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::USMALLINT() {
  return getToken(GQLParser::USMALLINT, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UINT() {
  return getToken(GQLParser::UINT, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PrecisionContext* GQLParser::UnsignedBinaryExactNumericTypeContext::precision() {
  return getRuleContext<GQLParser::PrecisionContext>(0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UBIGINT() {
  return getToken(GQLParser::UBIGINT, 0);
}

tree::TerminalNode* GQLParser::UnsignedBinaryExactNumericTypeContext::UNSIGNED() {
  return getToken(GQLParser::UNSIGNED, 0);
}

GQLParser::VerboseBinaryExactNumericTypeContext* GQLParser::UnsignedBinaryExactNumericTypeContext::verboseBinaryExactNumericType() {
  return getRuleContext<GQLParser::VerboseBinaryExactNumericTypeContext>(0);
}


size_t GQLParser::UnsignedBinaryExactNumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleUnsignedBinaryExactNumericType;
}




//----------------- VerboseBinaryExactNumericTypeContext ------------------------------------------------------------------

GQLParser::VerboseBinaryExactNumericTypeContext::VerboseBinaryExactNumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::INTEGER8() {
  return getToken(GQLParser::INTEGER8, 0);
}

GQLParser::NotNullContext* GQLParser::VerboseBinaryExactNumericTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::INTEGER16() {
  return getToken(GQLParser::INTEGER16, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::INTEGER32() {
  return getToken(GQLParser::INTEGER32, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::INTEGER64() {
  return getToken(GQLParser::INTEGER64, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::INTEGER128() {
  return getToken(GQLParser::INTEGER128, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::INTEGER256() {
  return getToken(GQLParser::INTEGER256, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::SMALL() {
  return getToken(GQLParser::SMALL, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::INTEGER() {
  return getToken(GQLParser::INTEGER, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PrecisionContext* GQLParser::VerboseBinaryExactNumericTypeContext::precision() {
  return getRuleContext<GQLParser::PrecisionContext>(0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::VerboseBinaryExactNumericTypeContext::BIG() {
  return getToken(GQLParser::BIG, 0);
}


size_t GQLParser::VerboseBinaryExactNumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleVerboseBinaryExactNumericType;
}




//----------------- DecimalExactNumericTypeContext ------------------------------------------------------------------

GQLParser::DecimalExactNumericTypeContext::DecimalExactNumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DecimalExactNumericTypeContext::DECIMAL() {
  return getToken(GQLParser::DECIMAL, 0);
}

tree::TerminalNode* GQLParser::DecimalExactNumericTypeContext::DEC() {
  return getToken(GQLParser::DEC, 0);
}

tree::TerminalNode* GQLParser::DecimalExactNumericTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PrecisionContext* GQLParser::DecimalExactNumericTypeContext::precision() {
  return getRuleContext<GQLParser::PrecisionContext>(0);
}

tree::TerminalNode* GQLParser::DecimalExactNumericTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::DecimalExactNumericTypeContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::ScaleContext* GQLParser::DecimalExactNumericTypeContext::scale() {
  return getRuleContext<GQLParser::ScaleContext>(0);
}

GQLParser::NotNullContext* GQLParser::DecimalExactNumericTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::DecimalExactNumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleDecimalExactNumericType;
}




//----------------- PrecisionContext ------------------------------------------------------------------

GQLParser::PrecisionContext::PrecisionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedDecimalIntegerContext* GQLParser::PrecisionContext::unsignedDecimalInteger() {
  return getRuleContext<GQLParser::UnsignedDecimalIntegerContext>(0);
}


size_t GQLParser::PrecisionContext::getRuleIndex() const {
  return GQLParser::RulePrecision;
}




//----------------- ScaleContext ------------------------------------------------------------------

GQLParser::ScaleContext::ScaleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedDecimalIntegerContext* GQLParser::ScaleContext::unsignedDecimalInteger() {
  return getRuleContext<GQLParser::UnsignedDecimalIntegerContext>(0);
}


size_t GQLParser::ScaleContext::getRuleIndex() const {
  return GQLParser::RuleScale;
}




//----------------- ApproximateNumericTypeContext ------------------------------------------------------------------

GQLParser::ApproximateNumericTypeContext::ApproximateNumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::FLOAT16() {
  return getToken(GQLParser::FLOAT16, 0);
}

GQLParser::NotNullContext* GQLParser::ApproximateNumericTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::FLOAT32() {
  return getToken(GQLParser::FLOAT32, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::FLOAT64() {
  return getToken(GQLParser::FLOAT64, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::FLOAT128() {
  return getToken(GQLParser::FLOAT128, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::FLOAT256() {
  return getToken(GQLParser::FLOAT256, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::FLOAT() {
  return getToken(GQLParser::FLOAT, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PrecisionContext* GQLParser::ApproximateNumericTypeContext::precision() {
  return getRuleContext<GQLParser::PrecisionContext>(0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::ScaleContext* GQLParser::ApproximateNumericTypeContext::scale() {
  return getRuleContext<GQLParser::ScaleContext>(0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::REAL() {
  return getToken(GQLParser::REAL, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::DOUBLE() {
  return getToken(GQLParser::DOUBLE, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericTypeContext::PRECISION() {
  return getToken(GQLParser::PRECISION, 0);
}


size_t GQLParser::ApproximateNumericTypeContext::getRuleIndex() const {
  return GQLParser::RuleApproximateNumericType;
}




//----------------- TemporalTypeContext ------------------------------------------------------------------

GQLParser::TemporalTypeContext::TemporalTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::TemporalInstantTypeContext* GQLParser::TemporalTypeContext::temporalInstantType() {
  return getRuleContext<GQLParser::TemporalInstantTypeContext>(0);
}

GQLParser::TemporalDurationTypeContext* GQLParser::TemporalTypeContext::temporalDurationType() {
  return getRuleContext<GQLParser::TemporalDurationTypeContext>(0);
}


size_t GQLParser::TemporalTypeContext::getRuleIndex() const {
  return GQLParser::RuleTemporalType;
}




//----------------- TemporalInstantTypeContext ------------------------------------------------------------------

GQLParser::TemporalInstantTypeContext::TemporalInstantTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DatetimeTypeContext* GQLParser::TemporalInstantTypeContext::datetimeType() {
  return getRuleContext<GQLParser::DatetimeTypeContext>(0);
}

GQLParser::LocaldatetimeTypeContext* GQLParser::TemporalInstantTypeContext::localdatetimeType() {
  return getRuleContext<GQLParser::LocaldatetimeTypeContext>(0);
}

GQLParser::DateTypeContext* GQLParser::TemporalInstantTypeContext::dateType() {
  return getRuleContext<GQLParser::DateTypeContext>(0);
}

GQLParser::TimeTypeContext* GQLParser::TemporalInstantTypeContext::timeType() {
  return getRuleContext<GQLParser::TimeTypeContext>(0);
}

GQLParser::LocaltimeTypeContext* GQLParser::TemporalInstantTypeContext::localtimeType() {
  return getRuleContext<GQLParser::LocaltimeTypeContext>(0);
}


size_t GQLParser::TemporalInstantTypeContext::getRuleIndex() const {
  return GQLParser::RuleTemporalInstantType;
}




//----------------- DatetimeTypeContext ------------------------------------------------------------------

GQLParser::DatetimeTypeContext::DatetimeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DatetimeTypeContext::ZONED() {
  return getToken(GQLParser::ZONED, 0);
}

tree::TerminalNode* GQLParser::DatetimeTypeContext::DATETIME() {
  return getToken(GQLParser::DATETIME, 0);
}

GQLParser::NotNullContext* GQLParser::DatetimeTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::DatetimeTypeContext::TIMESTAMP() {
  return getToken(GQLParser::TIMESTAMP, 0);
}

tree::TerminalNode* GQLParser::DatetimeTypeContext::WITH() {
  return getToken(GQLParser::WITH, 0);
}

tree::TerminalNode* GQLParser::DatetimeTypeContext::TIME() {
  return getToken(GQLParser::TIME, 0);
}

tree::TerminalNode* GQLParser::DatetimeTypeContext::ZONE() {
  return getToken(GQLParser::ZONE, 0);
}


size_t GQLParser::DatetimeTypeContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeType;
}




//----------------- LocaldatetimeTypeContext ------------------------------------------------------------------

GQLParser::LocaldatetimeTypeContext::LocaldatetimeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LocaldatetimeTypeContext::LOCAL() {
  return getToken(GQLParser::LOCAL, 0);
}

tree::TerminalNode* GQLParser::LocaldatetimeTypeContext::DATETIME() {
  return getToken(GQLParser::DATETIME, 0);
}

GQLParser::NotNullContext* GQLParser::LocaldatetimeTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::LocaldatetimeTypeContext::TIMESTAMP() {
  return getToken(GQLParser::TIMESTAMP, 0);
}

tree::TerminalNode* GQLParser::LocaldatetimeTypeContext::WITHOUT() {
  return getToken(GQLParser::WITHOUT, 0);
}

tree::TerminalNode* GQLParser::LocaldatetimeTypeContext::TIME() {
  return getToken(GQLParser::TIME, 0);
}

tree::TerminalNode* GQLParser::LocaldatetimeTypeContext::ZONE() {
  return getToken(GQLParser::ZONE, 0);
}


size_t GQLParser::LocaldatetimeTypeContext::getRuleIndex() const {
  return GQLParser::RuleLocaldatetimeType;
}




//----------------- DateTypeContext ------------------------------------------------------------------

GQLParser::DateTypeContext::DateTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DateTypeContext::DATE() {
  return getToken(GQLParser::DATE, 0);
}

GQLParser::NotNullContext* GQLParser::DateTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::DateTypeContext::getRuleIndex() const {
  return GQLParser::RuleDateType;
}




//----------------- TimeTypeContext ------------------------------------------------------------------

GQLParser::TimeTypeContext::TimeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TimeTypeContext::ZONED() {
  return getToken(GQLParser::ZONED, 0);
}

std::vector<tree::TerminalNode *> GQLParser::TimeTypeContext::TIME() {
  return getTokens(GQLParser::TIME);
}

tree::TerminalNode* GQLParser::TimeTypeContext::TIME(size_t i) {
  return getToken(GQLParser::TIME, i);
}

GQLParser::NotNullContext* GQLParser::TimeTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::TimeTypeContext::WITH() {
  return getToken(GQLParser::WITH, 0);
}

tree::TerminalNode* GQLParser::TimeTypeContext::ZONE() {
  return getToken(GQLParser::ZONE, 0);
}


size_t GQLParser::TimeTypeContext::getRuleIndex() const {
  return GQLParser::RuleTimeType;
}




//----------------- LocaltimeTypeContext ------------------------------------------------------------------

GQLParser::LocaltimeTypeContext::LocaltimeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LocaltimeTypeContext::LOCAL() {
  return getToken(GQLParser::LOCAL, 0);
}

std::vector<tree::TerminalNode *> GQLParser::LocaltimeTypeContext::TIME() {
  return getTokens(GQLParser::TIME);
}

tree::TerminalNode* GQLParser::LocaltimeTypeContext::TIME(size_t i) {
  return getToken(GQLParser::TIME, i);
}

GQLParser::NotNullContext* GQLParser::LocaltimeTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::LocaltimeTypeContext::WITHOUT() {
  return getToken(GQLParser::WITHOUT, 0);
}

tree::TerminalNode* GQLParser::LocaltimeTypeContext::ZONE() {
  return getToken(GQLParser::ZONE, 0);
}


size_t GQLParser::LocaltimeTypeContext::getRuleIndex() const {
  return GQLParser::RuleLocaltimeType;
}




//----------------- TemporalDurationTypeContext ------------------------------------------------------------------

GQLParser::TemporalDurationTypeContext::TemporalDurationTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TemporalDurationTypeContext::DURATION() {
  return getToken(GQLParser::DURATION, 0);
}

tree::TerminalNode* GQLParser::TemporalDurationTypeContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::TemporalDurationQualifierContext* GQLParser::TemporalDurationTypeContext::temporalDurationQualifier() {
  return getRuleContext<GQLParser::TemporalDurationQualifierContext>(0);
}

tree::TerminalNode* GQLParser::TemporalDurationTypeContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::NotNullContext* GQLParser::TemporalDurationTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::TemporalDurationTypeContext::getRuleIndex() const {
  return GQLParser::RuleTemporalDurationType;
}




//----------------- TemporalDurationQualifierContext ------------------------------------------------------------------

GQLParser::TemporalDurationQualifierContext::TemporalDurationQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TemporalDurationQualifierContext::YEAR() {
  return getToken(GQLParser::YEAR, 0);
}

tree::TerminalNode* GQLParser::TemporalDurationQualifierContext::TO() {
  return getToken(GQLParser::TO, 0);
}

tree::TerminalNode* GQLParser::TemporalDurationQualifierContext::MONTH() {
  return getToken(GQLParser::MONTH, 0);
}

tree::TerminalNode* GQLParser::TemporalDurationQualifierContext::DAY() {
  return getToken(GQLParser::DAY, 0);
}

tree::TerminalNode* GQLParser::TemporalDurationQualifierContext::SECOND() {
  return getToken(GQLParser::SECOND, 0);
}


size_t GQLParser::TemporalDurationQualifierContext::getRuleIndex() const {
  return GQLParser::RuleTemporalDurationQualifier;
}




//----------------- ReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::ReferenceValueTypeContext::ReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GraphReferenceValueTypeContext* GQLParser::ReferenceValueTypeContext::graphReferenceValueType() {
  return getRuleContext<GQLParser::GraphReferenceValueTypeContext>(0);
}

GQLParser::BindingTableReferenceValueTypeContext* GQLParser::ReferenceValueTypeContext::bindingTableReferenceValueType() {
  return getRuleContext<GQLParser::BindingTableReferenceValueTypeContext>(0);
}

GQLParser::NodeReferenceValueTypeContext* GQLParser::ReferenceValueTypeContext::nodeReferenceValueType() {
  return getRuleContext<GQLParser::NodeReferenceValueTypeContext>(0);
}

GQLParser::EdgeReferenceValueTypeContext* GQLParser::ReferenceValueTypeContext::edgeReferenceValueType() {
  return getRuleContext<GQLParser::EdgeReferenceValueTypeContext>(0);
}


size_t GQLParser::ReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleReferenceValueType;
}




//----------------- ImmaterialValueTypeContext ------------------------------------------------------------------

GQLParser::ImmaterialValueTypeContext::ImmaterialValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NullTypeContext* GQLParser::ImmaterialValueTypeContext::nullType() {
  return getRuleContext<GQLParser::NullTypeContext>(0);
}

GQLParser::EmptyTypeContext* GQLParser::ImmaterialValueTypeContext::emptyType() {
  return getRuleContext<GQLParser::EmptyTypeContext>(0);
}


size_t GQLParser::ImmaterialValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleImmaterialValueType;
}




//----------------- NullTypeContext ------------------------------------------------------------------

GQLParser::NullTypeContext::NullTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NullTypeContext::NULL_KW() {
  return getToken(GQLParser::NULL_KW, 0);
}


size_t GQLParser::NullTypeContext::getRuleIndex() const {
  return GQLParser::RuleNullType;
}




//----------------- EmptyTypeContext ------------------------------------------------------------------

GQLParser::EmptyTypeContext::EmptyTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EmptyTypeContext::NULL_KW() {
  return getToken(GQLParser::NULL_KW, 0);
}

GQLParser::NotNullContext* GQLParser::EmptyTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

tree::TerminalNode* GQLParser::EmptyTypeContext::NOTHING() {
  return getToken(GQLParser::NOTHING, 0);
}


size_t GQLParser::EmptyTypeContext::getRuleIndex() const {
  return GQLParser::RuleEmptyType;
}




//----------------- GraphReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::GraphReferenceValueTypeContext::GraphReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::OpenGraphReferenceValueTypeContext* GQLParser::GraphReferenceValueTypeContext::openGraphReferenceValueType() {
  return getRuleContext<GQLParser::OpenGraphReferenceValueTypeContext>(0);
}

GQLParser::ClosedGraphReferenceValueTypeContext* GQLParser::GraphReferenceValueTypeContext::closedGraphReferenceValueType() {
  return getRuleContext<GQLParser::ClosedGraphReferenceValueTypeContext>(0);
}


size_t GQLParser::GraphReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleGraphReferenceValueType;
}




//----------------- ClosedGraphReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::ClosedGraphReferenceValueTypeContext::ClosedGraphReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ClosedGraphReferenceValueTypeContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

GQLParser::NestedGraphTypeSpecificationContext* GQLParser::ClosedGraphReferenceValueTypeContext::nestedGraphTypeSpecification() {
  return getRuleContext<GQLParser::NestedGraphTypeSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::ClosedGraphReferenceValueTypeContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

GQLParser::NotNullContext* GQLParser::ClosedGraphReferenceValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::ClosedGraphReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleClosedGraphReferenceValueType;
}




//----------------- OpenGraphReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::OpenGraphReferenceValueTypeContext::OpenGraphReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::OpenGraphReferenceValueTypeContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

tree::TerminalNode* GQLParser::OpenGraphReferenceValueTypeContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::OpenGraphReferenceValueTypeContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

GQLParser::NotNullContext* GQLParser::OpenGraphReferenceValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::OpenGraphReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleOpenGraphReferenceValueType;
}




//----------------- BindingTableReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::BindingTableReferenceValueTypeContext::BindingTableReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingTableTypeContext* GQLParser::BindingTableReferenceValueTypeContext::bindingTableType() {
  return getRuleContext<GQLParser::BindingTableTypeContext>(0);
}

GQLParser::NotNullContext* GQLParser::BindingTableReferenceValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::BindingTableReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleBindingTableReferenceValueType;
}




//----------------- NodeReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::NodeReferenceValueTypeContext::NodeReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::OpenNodeReferenceValueTypeContext* GQLParser::NodeReferenceValueTypeContext::openNodeReferenceValueType() {
  return getRuleContext<GQLParser::OpenNodeReferenceValueTypeContext>(0);
}

GQLParser::ClosedNodeReferenceValueTypeContext* GQLParser::NodeReferenceValueTypeContext::closedNodeReferenceValueType() {
  return getRuleContext<GQLParser::ClosedNodeReferenceValueTypeContext>(0);
}


size_t GQLParser::NodeReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleNodeReferenceValueType;
}




//----------------- ClosedNodeReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::ClosedNodeReferenceValueTypeContext::ClosedNodeReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeTypeSpecificationContext* GQLParser::ClosedNodeReferenceValueTypeContext::nodeTypeSpecification() {
  return getRuleContext<GQLParser::NodeTypeSpecificationContext>(0);
}

GQLParser::NotNullContext* GQLParser::ClosedNodeReferenceValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::ClosedNodeReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleClosedNodeReferenceValueType;
}




//----------------- OpenNodeReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::OpenNodeReferenceValueTypeContext::OpenNodeReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeSynonymContext* GQLParser::OpenNodeReferenceValueTypeContext::nodeSynonym() {
  return getRuleContext<GQLParser::NodeSynonymContext>(0);
}

tree::TerminalNode* GQLParser::OpenNodeReferenceValueTypeContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

GQLParser::NotNullContext* GQLParser::OpenNodeReferenceValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::OpenNodeReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleOpenNodeReferenceValueType;
}




//----------------- EdgeReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::EdgeReferenceValueTypeContext::EdgeReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::OpenEdgeReferenceValueTypeContext* GQLParser::EdgeReferenceValueTypeContext::openEdgeReferenceValueType() {
  return getRuleContext<GQLParser::OpenEdgeReferenceValueTypeContext>(0);
}

GQLParser::ClosedEdgeReferenceValueTypeContext* GQLParser::EdgeReferenceValueTypeContext::closedEdgeReferenceValueType() {
  return getRuleContext<GQLParser::ClosedEdgeReferenceValueTypeContext>(0);
}


size_t GQLParser::EdgeReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleEdgeReferenceValueType;
}




//----------------- ClosedEdgeReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::ClosedEdgeReferenceValueTypeContext::ClosedEdgeReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeTypeSpecificationContext* GQLParser::ClosedEdgeReferenceValueTypeContext::edgeTypeSpecification() {
  return getRuleContext<GQLParser::EdgeTypeSpecificationContext>(0);
}

GQLParser::NotNullContext* GQLParser::ClosedEdgeReferenceValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::ClosedEdgeReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleClosedEdgeReferenceValueType;
}




//----------------- OpenEdgeReferenceValueTypeContext ------------------------------------------------------------------

GQLParser::OpenEdgeReferenceValueTypeContext::OpenEdgeReferenceValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::EdgeSynonymContext* GQLParser::OpenEdgeReferenceValueTypeContext::edgeSynonym() {
  return getRuleContext<GQLParser::EdgeSynonymContext>(0);
}

tree::TerminalNode* GQLParser::OpenEdgeReferenceValueTypeContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

GQLParser::NotNullContext* GQLParser::OpenEdgeReferenceValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::OpenEdgeReferenceValueTypeContext::getRuleIndex() const {
  return GQLParser::RuleOpenEdgeReferenceValueType;
}




//----------------- PathValueTypeContext ------------------------------------------------------------------

GQLParser::PathValueTypeContext::PathValueTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PathValueTypeContext::PATH() {
  return getToken(GQLParser::PATH, 0);
}

GQLParser::NotNullContext* GQLParser::PathValueTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}


size_t GQLParser::PathValueTypeContext::getRuleIndex() const {
  return GQLParser::RulePathValueType;
}




//----------------- ListValueTypeNameContext ------------------------------------------------------------------

GQLParser::ListValueTypeNameContext::ListValueTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ListValueTypeNameSynonymContext* GQLParser::ListValueTypeNameContext::listValueTypeNameSynonym() {
  return getRuleContext<GQLParser::ListValueTypeNameSynonymContext>(0);
}

tree::TerminalNode* GQLParser::ListValueTypeNameContext::GROUP() {
  return getToken(GQLParser::GROUP, 0);
}


size_t GQLParser::ListValueTypeNameContext::getRuleIndex() const {
  return GQLParser::RuleListValueTypeName;
}




//----------------- ListValueTypeNameSynonymContext ------------------------------------------------------------------

GQLParser::ListValueTypeNameSynonymContext::ListValueTypeNameSynonymContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ListValueTypeNameSynonymContext::LIST() {
  return getToken(GQLParser::LIST, 0);
}

tree::TerminalNode* GQLParser::ListValueTypeNameSynonymContext::ARRAY() {
  return getToken(GQLParser::ARRAY, 0);
}


size_t GQLParser::ListValueTypeNameSynonymContext::getRuleIndex() const {
  return GQLParser::RuleListValueTypeNameSynonym;
}




//----------------- RecordTypeContext ------------------------------------------------------------------

GQLParser::RecordTypeContext::RecordTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::RecordTypeContext::RECORD() {
  return getToken(GQLParser::RECORD, 0);
}

tree::TerminalNode* GQLParser::RecordTypeContext::ANY() {
  return getToken(GQLParser::ANY, 0);
}

GQLParser::NotNullContext* GQLParser::RecordTypeContext::notNull() {
  return getRuleContext<GQLParser::NotNullContext>(0);
}

GQLParser::FieldTypesSpecificationContext* GQLParser::RecordTypeContext::fieldTypesSpecification() {
  return getRuleContext<GQLParser::FieldTypesSpecificationContext>(0);
}


size_t GQLParser::RecordTypeContext::getRuleIndex() const {
  return GQLParser::RuleRecordType;
}




//----------------- FieldTypesSpecificationContext ------------------------------------------------------------------

GQLParser::FieldTypesSpecificationContext::FieldTypesSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FieldTypesSpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

tree::TerminalNode* GQLParser::FieldTypesSpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}

GQLParser::FieldTypeListContext* GQLParser::FieldTypesSpecificationContext::fieldTypeList() {
  return getRuleContext<GQLParser::FieldTypeListContext>(0);
}


size_t GQLParser::FieldTypesSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleFieldTypesSpecification;
}




//----------------- FieldTypeListContext ------------------------------------------------------------------

GQLParser::FieldTypeListContext::FieldTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::FieldTypeContext *> GQLParser::FieldTypeListContext::fieldType() {
  return getRuleContexts<GQLParser::FieldTypeContext>();
}

GQLParser::FieldTypeContext* GQLParser::FieldTypeListContext::fieldType(size_t i) {
  return getRuleContext<GQLParser::FieldTypeContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::FieldTypeListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::FieldTypeListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::FieldTypeListContext::getRuleIndex() const {
  return GQLParser::RuleFieldTypeList;
}




//----------------- NotNullContext ------------------------------------------------------------------

GQLParser::NotNullContext::NotNullContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NotNullContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

tree::TerminalNode* GQLParser::NotNullContext::NULL_KW() {
  return getToken(GQLParser::NULL_KW, 0);
}


size_t GQLParser::NotNullContext::getRuleIndex() const {
  return GQLParser::RuleNotNull;
}




//----------------- FieldTypeContext ------------------------------------------------------------------

GQLParser::FieldTypeContext::FieldTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FieldNameContext* GQLParser::FieldTypeContext::fieldName() {
  return getRuleContext<GQLParser::FieldNameContext>(0);
}

GQLParser::ValueTypeContext* GQLParser::FieldTypeContext::valueType() {
  return getRuleContext<GQLParser::ValueTypeContext>(0);
}

GQLParser::TypedContext* GQLParser::FieldTypeContext::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}


size_t GQLParser::FieldTypeContext::getRuleIndex() const {
  return GQLParser::RuleFieldType;
}




//----------------- SearchConditionContext ------------------------------------------------------------------

GQLParser::SearchConditionContext::SearchConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BooleanValueExpressionContext* GQLParser::SearchConditionContext::booleanValueExpression() {
  return getRuleContext<GQLParser::BooleanValueExpressionContext>(0);
}


size_t GQLParser::SearchConditionContext::getRuleIndex() const {
  return GQLParser::RuleSearchCondition;
}




//----------------- PredicateContext ------------------------------------------------------------------

GQLParser::PredicateContext::PredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ExistsPredicateContext* GQLParser::PredicateContext::existsPredicate() {
  return getRuleContext<GQLParser::ExistsPredicateContext>(0);
}

GQLParser::NullPredicateContext* GQLParser::PredicateContext::nullPredicate() {
  return getRuleContext<GQLParser::NullPredicateContext>(0);
}

GQLParser::ValueTypePredicateContext* GQLParser::PredicateContext::valueTypePredicate() {
  return getRuleContext<GQLParser::ValueTypePredicateContext>(0);
}

GQLParser::DirectedPredicateContext* GQLParser::PredicateContext::directedPredicate() {
  return getRuleContext<GQLParser::DirectedPredicateContext>(0);
}

GQLParser::LabeledPredicateContext* GQLParser::PredicateContext::labeledPredicate() {
  return getRuleContext<GQLParser::LabeledPredicateContext>(0);
}

GQLParser::SourceDestinationPredicateContext* GQLParser::PredicateContext::sourceDestinationPredicate() {
  return getRuleContext<GQLParser::SourceDestinationPredicateContext>(0);
}

GQLParser::All_differentPredicateContext* GQLParser::PredicateContext::all_differentPredicate() {
  return getRuleContext<GQLParser::All_differentPredicateContext>(0);
}

GQLParser::SamePredicateContext* GQLParser::PredicateContext::samePredicate() {
  return getRuleContext<GQLParser::SamePredicateContext>(0);
}

GQLParser::Property_existsPredicateContext* GQLParser::PredicateContext::property_existsPredicate() {
  return getRuleContext<GQLParser::Property_existsPredicateContext>(0);
}


size_t GQLParser::PredicateContext::getRuleIndex() const {
  return GQLParser::RulePredicate;
}




//----------------- CompOpContext ------------------------------------------------------------------

GQLParser::CompOpContext::CompOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CompOpContext::EQUALS_OPERATOR() {
  return getToken(GQLParser::EQUALS_OPERATOR, 0);
}

tree::TerminalNode* GQLParser::CompOpContext::NOT_EQUALS_OPERATOR() {
  return getToken(GQLParser::NOT_EQUALS_OPERATOR, 0);
}

tree::TerminalNode* GQLParser::CompOpContext::LEFT_ANGLE_BRACKET() {
  return getToken(GQLParser::LEFT_ANGLE_BRACKET, 0);
}

tree::TerminalNode* GQLParser::CompOpContext::RIGHT_ANGLE_BRACKET() {
  return getToken(GQLParser::RIGHT_ANGLE_BRACKET, 0);
}

tree::TerminalNode* GQLParser::CompOpContext::LESS_THAN_OR_EQUALS_OPERATOR() {
  return getToken(GQLParser::LESS_THAN_OR_EQUALS_OPERATOR, 0);
}

tree::TerminalNode* GQLParser::CompOpContext::GREATER_THAN_OR_EQUALS_OPERATOR() {
  return getToken(GQLParser::GREATER_THAN_OR_EQUALS_OPERATOR, 0);
}


size_t GQLParser::CompOpContext::getRuleIndex() const {
  return GQLParser::RuleCompOp;
}




//----------------- ExistsPredicateContext ------------------------------------------------------------------

GQLParser::ExistsPredicateContext::ExistsPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ExistsPredicateContext::EXISTS() {
  return getToken(GQLParser::EXISTS, 0);
}

tree::TerminalNode* GQLParser::ExistsPredicateContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

GQLParser::GraphPatternContext* GQLParser::ExistsPredicateContext::graphPattern() {
  return getRuleContext<GQLParser::GraphPatternContext>(0);
}

tree::TerminalNode* GQLParser::ExistsPredicateContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}

tree::TerminalNode* GQLParser::ExistsPredicateContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::ExistsPredicateContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::MatchStatementBlockContext* GQLParser::ExistsPredicateContext::matchStatementBlock() {
  return getRuleContext<GQLParser::MatchStatementBlockContext>(0);
}

GQLParser::NestedQuerySpecificationContext* GQLParser::ExistsPredicateContext::nestedQuerySpecification() {
  return getRuleContext<GQLParser::NestedQuerySpecificationContext>(0);
}


size_t GQLParser::ExistsPredicateContext::getRuleIndex() const {
  return GQLParser::RuleExistsPredicate;
}




//----------------- NullPredicateContext ------------------------------------------------------------------

GQLParser::NullPredicateContext::NullPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionPrimaryContext* GQLParser::NullPredicateContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}

GQLParser::NullPredicatePart2Context* GQLParser::NullPredicateContext::nullPredicatePart2() {
  return getRuleContext<GQLParser::NullPredicatePart2Context>(0);
}


size_t GQLParser::NullPredicateContext::getRuleIndex() const {
  return GQLParser::RuleNullPredicate;
}




//----------------- NullPredicatePart2Context ------------------------------------------------------------------

GQLParser::NullPredicatePart2Context::NullPredicatePart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NullPredicatePart2Context::IS() {
  return getToken(GQLParser::IS, 0);
}

tree::TerminalNode* GQLParser::NullPredicatePart2Context::NULL_KW() {
  return getToken(GQLParser::NULL_KW, 0);
}

tree::TerminalNode* GQLParser::NullPredicatePart2Context::NOT() {
  return getToken(GQLParser::NOT, 0);
}


size_t GQLParser::NullPredicatePart2Context::getRuleIndex() const {
  return GQLParser::RuleNullPredicatePart2;
}




//----------------- ValueTypePredicateContext ------------------------------------------------------------------

GQLParser::ValueTypePredicateContext::ValueTypePredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionPrimaryContext* GQLParser::ValueTypePredicateContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}

GQLParser::ValueTypePredicatePart2Context* GQLParser::ValueTypePredicateContext::valueTypePredicatePart2() {
  return getRuleContext<GQLParser::ValueTypePredicatePart2Context>(0);
}


size_t GQLParser::ValueTypePredicateContext::getRuleIndex() const {
  return GQLParser::RuleValueTypePredicate;
}




//----------------- ValueTypePredicatePart2Context ------------------------------------------------------------------

GQLParser::ValueTypePredicatePart2Context::ValueTypePredicatePart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ValueTypePredicatePart2Context::IS() {
  return getToken(GQLParser::IS, 0);
}

GQLParser::TypedContext* GQLParser::ValueTypePredicatePart2Context::typed() {
  return getRuleContext<GQLParser::TypedContext>(0);
}

GQLParser::ValueTypeContext* GQLParser::ValueTypePredicatePart2Context::valueType() {
  return getRuleContext<GQLParser::ValueTypeContext>(0);
}

tree::TerminalNode* GQLParser::ValueTypePredicatePart2Context::NOT() {
  return getToken(GQLParser::NOT, 0);
}


size_t GQLParser::ValueTypePredicatePart2Context::getRuleIndex() const {
  return GQLParser::RuleValueTypePredicatePart2;
}




//----------------- NormalizedPredicatePart2Context ------------------------------------------------------------------

GQLParser::NormalizedPredicatePart2Context::NormalizedPredicatePart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NormalizedPredicatePart2Context::IS() {
  return getToken(GQLParser::IS, 0);
}

tree::TerminalNode* GQLParser::NormalizedPredicatePart2Context::NORMALIZED() {
  return getToken(GQLParser::NORMALIZED, 0);
}

tree::TerminalNode* GQLParser::NormalizedPredicatePart2Context::NOT() {
  return getToken(GQLParser::NOT, 0);
}

GQLParser::NormalFormContext* GQLParser::NormalizedPredicatePart2Context::normalForm() {
  return getRuleContext<GQLParser::NormalFormContext>(0);
}


size_t GQLParser::NormalizedPredicatePart2Context::getRuleIndex() const {
  return GQLParser::RuleNormalizedPredicatePart2;
}




//----------------- DirectedPredicateContext ------------------------------------------------------------------

GQLParser::DirectedPredicateContext::DirectedPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementVariableReferenceContext* GQLParser::DirectedPredicateContext::elementVariableReference() {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(0);
}

GQLParser::DirectedPredicatePart2Context* GQLParser::DirectedPredicateContext::directedPredicatePart2() {
  return getRuleContext<GQLParser::DirectedPredicatePart2Context>(0);
}


size_t GQLParser::DirectedPredicateContext::getRuleIndex() const {
  return GQLParser::RuleDirectedPredicate;
}




//----------------- DirectedPredicatePart2Context ------------------------------------------------------------------

GQLParser::DirectedPredicatePart2Context::DirectedPredicatePart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DirectedPredicatePart2Context::IS() {
  return getToken(GQLParser::IS, 0);
}

tree::TerminalNode* GQLParser::DirectedPredicatePart2Context::DIRECTED() {
  return getToken(GQLParser::DIRECTED, 0);
}

tree::TerminalNode* GQLParser::DirectedPredicatePart2Context::NOT() {
  return getToken(GQLParser::NOT, 0);
}


size_t GQLParser::DirectedPredicatePart2Context::getRuleIndex() const {
  return GQLParser::RuleDirectedPredicatePart2;
}




//----------------- LabeledPredicateContext ------------------------------------------------------------------

GQLParser::LabeledPredicateContext::LabeledPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementVariableReferenceContext* GQLParser::LabeledPredicateContext::elementVariableReference() {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(0);
}

GQLParser::LabeledPredicatePart2Context* GQLParser::LabeledPredicateContext::labeledPredicatePart2() {
  return getRuleContext<GQLParser::LabeledPredicatePart2Context>(0);
}


size_t GQLParser::LabeledPredicateContext::getRuleIndex() const {
  return GQLParser::RuleLabeledPredicate;
}




//----------------- LabeledPredicatePart2Context ------------------------------------------------------------------

GQLParser::LabeledPredicatePart2Context::LabeledPredicatePart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IsLabeledOrColonContext* GQLParser::LabeledPredicatePart2Context::isLabeledOrColon() {
  return getRuleContext<GQLParser::IsLabeledOrColonContext>(0);
}

GQLParser::LabelExpressionContext* GQLParser::LabeledPredicatePart2Context::labelExpression() {
  return getRuleContext<GQLParser::LabelExpressionContext>(0);
}


size_t GQLParser::LabeledPredicatePart2Context::getRuleIndex() const {
  return GQLParser::RuleLabeledPredicatePart2;
}




//----------------- IsLabeledOrColonContext ------------------------------------------------------------------

GQLParser::IsLabeledOrColonContext::IsLabeledOrColonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::IsLabeledOrColonContext::IS() {
  return getToken(GQLParser::IS, 0);
}

tree::TerminalNode* GQLParser::IsLabeledOrColonContext::LABELED() {
  return getToken(GQLParser::LABELED, 0);
}

tree::TerminalNode* GQLParser::IsLabeledOrColonContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

tree::TerminalNode* GQLParser::IsLabeledOrColonContext::COLON() {
  return getToken(GQLParser::COLON, 0);
}


size_t GQLParser::IsLabeledOrColonContext::getRuleIndex() const {
  return GQLParser::RuleIsLabeledOrColon;
}




//----------------- SourceDestinationPredicateContext ------------------------------------------------------------------

GQLParser::SourceDestinationPredicateContext::SourceDestinationPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeReferenceContext* GQLParser::SourceDestinationPredicateContext::nodeReference() {
  return getRuleContext<GQLParser::NodeReferenceContext>(0);
}

GQLParser::SourcePredicatePart2Context* GQLParser::SourceDestinationPredicateContext::sourcePredicatePart2() {
  return getRuleContext<GQLParser::SourcePredicatePart2Context>(0);
}

GQLParser::DestinationPredicatePart2Context* GQLParser::SourceDestinationPredicateContext::destinationPredicatePart2() {
  return getRuleContext<GQLParser::DestinationPredicatePart2Context>(0);
}


size_t GQLParser::SourceDestinationPredicateContext::getRuleIndex() const {
  return GQLParser::RuleSourceDestinationPredicate;
}




//----------------- NodeReferenceContext ------------------------------------------------------------------

GQLParser::NodeReferenceContext::NodeReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementVariableReferenceContext* GQLParser::NodeReferenceContext::elementVariableReference() {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(0);
}


size_t GQLParser::NodeReferenceContext::getRuleIndex() const {
  return GQLParser::RuleNodeReference;
}




//----------------- SourcePredicatePart2Context ------------------------------------------------------------------

GQLParser::SourcePredicatePart2Context::SourcePredicatePart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SourcePredicatePart2Context::IS() {
  return getToken(GQLParser::IS, 0);
}

tree::TerminalNode* GQLParser::SourcePredicatePart2Context::SOURCE() {
  return getToken(GQLParser::SOURCE, 0);
}

tree::TerminalNode* GQLParser::SourcePredicatePart2Context::OF() {
  return getToken(GQLParser::OF, 0);
}

GQLParser::EdgeReferenceContext* GQLParser::SourcePredicatePart2Context::edgeReference() {
  return getRuleContext<GQLParser::EdgeReferenceContext>(0);
}

tree::TerminalNode* GQLParser::SourcePredicatePart2Context::NOT() {
  return getToken(GQLParser::NOT, 0);
}


size_t GQLParser::SourcePredicatePart2Context::getRuleIndex() const {
  return GQLParser::RuleSourcePredicatePart2;
}




//----------------- DestinationPredicatePart2Context ------------------------------------------------------------------

GQLParser::DestinationPredicatePart2Context::DestinationPredicatePart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DestinationPredicatePart2Context::IS() {
  return getToken(GQLParser::IS, 0);
}

tree::TerminalNode* GQLParser::DestinationPredicatePart2Context::DESTINATION() {
  return getToken(GQLParser::DESTINATION, 0);
}

tree::TerminalNode* GQLParser::DestinationPredicatePart2Context::OF() {
  return getToken(GQLParser::OF, 0);
}

GQLParser::EdgeReferenceContext* GQLParser::DestinationPredicatePart2Context::edgeReference() {
  return getRuleContext<GQLParser::EdgeReferenceContext>(0);
}

tree::TerminalNode* GQLParser::DestinationPredicatePart2Context::NOT() {
  return getToken(GQLParser::NOT, 0);
}


size_t GQLParser::DestinationPredicatePart2Context::getRuleIndex() const {
  return GQLParser::RuleDestinationPredicatePart2;
}




//----------------- EdgeReferenceContext ------------------------------------------------------------------

GQLParser::EdgeReferenceContext::EdgeReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ElementVariableReferenceContext* GQLParser::EdgeReferenceContext::elementVariableReference() {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(0);
}


size_t GQLParser::EdgeReferenceContext::getRuleIndex() const {
  return GQLParser::RuleEdgeReference;
}




//----------------- All_differentPredicateContext ------------------------------------------------------------------

GQLParser::All_differentPredicateContext::All_differentPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::All_differentPredicateContext::ALL_DIFFERENT() {
  return getToken(GQLParser::ALL_DIFFERENT, 0);
}

tree::TerminalNode* GQLParser::All_differentPredicateContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

std::vector<GQLParser::ElementVariableReferenceContext *> GQLParser::All_differentPredicateContext::elementVariableReference() {
  return getRuleContexts<GQLParser::ElementVariableReferenceContext>();
}

GQLParser::ElementVariableReferenceContext* GQLParser::All_differentPredicateContext::elementVariableReference(size_t i) {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::All_differentPredicateContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::All_differentPredicateContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}

tree::TerminalNode* GQLParser::All_differentPredicateContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::All_differentPredicateContext::getRuleIndex() const {
  return GQLParser::RuleAll_differentPredicate;
}




//----------------- SamePredicateContext ------------------------------------------------------------------

GQLParser::SamePredicateContext::SamePredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SamePredicateContext::SAME() {
  return getToken(GQLParser::SAME, 0);
}

tree::TerminalNode* GQLParser::SamePredicateContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

std::vector<GQLParser::ElementVariableReferenceContext *> GQLParser::SamePredicateContext::elementVariableReference() {
  return getRuleContexts<GQLParser::ElementVariableReferenceContext>();
}

GQLParser::ElementVariableReferenceContext* GQLParser::SamePredicateContext::elementVariableReference(size_t i) {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::SamePredicateContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::SamePredicateContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}

tree::TerminalNode* GQLParser::SamePredicateContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::SamePredicateContext::getRuleIndex() const {
  return GQLParser::RuleSamePredicate;
}




//----------------- Property_existsPredicateContext ------------------------------------------------------------------

GQLParser::Property_existsPredicateContext::Property_existsPredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::Property_existsPredicateContext::PROPERTY_EXISTS() {
  return getToken(GQLParser::PROPERTY_EXISTS, 0);
}

tree::TerminalNode* GQLParser::Property_existsPredicateContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ElementVariableReferenceContext* GQLParser::Property_existsPredicateContext::elementVariableReference() {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(0);
}

tree::TerminalNode* GQLParser::Property_existsPredicateContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::PropertyNameContext* GQLParser::Property_existsPredicateContext::propertyName() {
  return getRuleContext<GQLParser::PropertyNameContext>(0);
}

tree::TerminalNode* GQLParser::Property_existsPredicateContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::Property_existsPredicateContext::getRuleIndex() const {
  return GQLParser::RuleProperty_existsPredicate;
}




//----------------- ValueExpressionContext ------------------------------------------------------------------

GQLParser::ValueExpressionContext::ValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::ValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleValueExpression;
}

void GQLParser::ValueExpressionContext::copyFrom(ValueExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConjunctiveExprAltContext ------------------------------------------------------------------

std::vector<GQLParser::ValueExpressionContext *> GQLParser::ConjunctiveExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::ConjunctiveExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::ConjunctiveExprAltContext::AND() {
  return getToken(GQLParser::AND, 0);
}

GQLParser::ConjunctiveExprAltContext::ConjunctiveExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- PropertyGraphExprAltContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::PropertyGraphExprAltContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

GQLParser::GraphExpressionContext* GQLParser::PropertyGraphExprAltContext::graphExpression() {
  return getRuleContext<GQLParser::GraphExpressionContext>(0);
}

tree::TerminalNode* GQLParser::PropertyGraphExprAltContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

GQLParser::PropertyGraphExprAltContext::PropertyGraphExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- MultDivExprAltContext ------------------------------------------------------------------

std::vector<GQLParser::ValueExpressionContext *> GQLParser::MultDivExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::MultDivExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::MultDivExprAltContext::ASTERISK() {
  return getToken(GQLParser::ASTERISK, 0);
}

tree::TerminalNode* GQLParser::MultDivExprAltContext::SOLIDUS() {
  return getToken(GQLParser::SOLIDUS, 0);
}

GQLParser::MultDivExprAltContext::MultDivExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- BindingTableExprAltContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::BindingTableExprAltContext::TABLE() {
  return getToken(GQLParser::TABLE, 0);
}

GQLParser::BindingTableExpressionContext* GQLParser::BindingTableExprAltContext::bindingTableExpression() {
  return getRuleContext<GQLParser::BindingTableExpressionContext>(0);
}

tree::TerminalNode* GQLParser::BindingTableExprAltContext::BINDING() {
  return getToken(GQLParser::BINDING, 0);
}

GQLParser::BindingTableExprAltContext::BindingTableExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- SignedExprAltContext ------------------------------------------------------------------

GQLParser::ValueExpressionContext* GQLParser::SignedExprAltContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::SignedExprAltContext::PLUS_SIGN() {
  return getToken(GQLParser::PLUS_SIGN, 0);
}

tree::TerminalNode* GQLParser::SignedExprAltContext::MINUS_SIGN() {
  return getToken(GQLParser::MINUS_SIGN, 0);
}

GQLParser::SignedExprAltContext::SignedExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- IsNotExprAltContext ------------------------------------------------------------------

GQLParser::ValueExpressionContext* GQLParser::IsNotExprAltContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::IsNotExprAltContext::IS() {
  return getToken(GQLParser::IS, 0);
}

GQLParser::TruthValueContext* GQLParser::IsNotExprAltContext::truthValue() {
  return getRuleContext<GQLParser::TruthValueContext>(0);
}

tree::TerminalNode* GQLParser::IsNotExprAltContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

GQLParser::IsNotExprAltContext::IsNotExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- NormalizedPredicateExprAltContext ------------------------------------------------------------------

GQLParser::ValueExpressionContext* GQLParser::NormalizedPredicateExprAltContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

GQLParser::NormalizedPredicatePart2Context* GQLParser::NormalizedPredicateExprAltContext::normalizedPredicatePart2() {
  return getRuleContext<GQLParser::NormalizedPredicatePart2Context>(0);
}

GQLParser::NormalizedPredicateExprAltContext::NormalizedPredicateExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- NotExprAltContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::NotExprAltContext::NOT() {
  return getToken(GQLParser::NOT, 0);
}

GQLParser::ValueExpressionContext* GQLParser::NotExprAltContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

GQLParser::NotExprAltContext::NotExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- ValueFunctionExprAltContext ------------------------------------------------------------------

GQLParser::ValueFunctionContext* GQLParser::ValueFunctionExprAltContext::valueFunction() {
  return getRuleContext<GQLParser::ValueFunctionContext>(0);
}

GQLParser::ValueFunctionExprAltContext::ValueFunctionExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- ConcatenationExprAltContext ------------------------------------------------------------------

std::vector<GQLParser::ValueExpressionContext *> GQLParser::ConcatenationExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::ConcatenationExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::ConcatenationExprAltContext::CONCATENATION_OPERATOR() {
  return getToken(GQLParser::CONCATENATION_OPERATOR, 0);
}

GQLParser::ConcatenationExprAltContext::ConcatenationExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- DisjunctiveExprAltContext ------------------------------------------------------------------

std::vector<GQLParser::ValueExpressionContext *> GQLParser::DisjunctiveExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::DisjunctiveExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::DisjunctiveExprAltContext::OR() {
  return getToken(GQLParser::OR, 0);
}

tree::TerminalNode* GQLParser::DisjunctiveExprAltContext::XOR() {
  return getToken(GQLParser::XOR, 0);
}

GQLParser::DisjunctiveExprAltContext::DisjunctiveExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- ComparisonExprAltContext ------------------------------------------------------------------

std::vector<GQLParser::ValueExpressionContext *> GQLParser::ComparisonExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::ComparisonExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

GQLParser::CompOpContext* GQLParser::ComparisonExprAltContext::compOp() {
  return getRuleContext<GQLParser::CompOpContext>(0);
}

GQLParser::ComparisonExprAltContext::ComparisonExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryExprAltContext ------------------------------------------------------------------

GQLParser::ValueExpressionPrimaryContext* GQLParser::PrimaryExprAltContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}

GQLParser::PrimaryExprAltContext::PrimaryExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- AddSubtractExprAltContext ------------------------------------------------------------------

std::vector<GQLParser::ValueExpressionContext *> GQLParser::AddSubtractExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::AddSubtractExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::AddSubtractExprAltContext::PLUS_SIGN() {
  return getToken(GQLParser::PLUS_SIGN, 0);
}

tree::TerminalNode* GQLParser::AddSubtractExprAltContext::MINUS_SIGN() {
  return getToken(GQLParser::MINUS_SIGN, 0);
}

GQLParser::AddSubtractExprAltContext::AddSubtractExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- PredicateExprAltContext ------------------------------------------------------------------

GQLParser::PredicateContext* GQLParser::PredicateExprAltContext::predicate() {
  return getRuleContext<GQLParser::PredicateContext>(0);
}

GQLParser::PredicateExprAltContext::PredicateExprAltContext(ValueExpressionContext *ctx) { copyFrom(ctx); }




//----------------- ValueFunctionContext ------------------------------------------------------------------

GQLParser::ValueFunctionContext::ValueFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueFunctionContext* GQLParser::ValueFunctionContext::numericValueFunction() {
  return getRuleContext<GQLParser::NumericValueFunctionContext>(0);
}

GQLParser::DatetimeSubtractionContext* GQLParser::ValueFunctionContext::datetimeSubtraction() {
  return getRuleContext<GQLParser::DatetimeSubtractionContext>(0);
}

GQLParser::DatetimeValueFunctionContext* GQLParser::ValueFunctionContext::datetimeValueFunction() {
  return getRuleContext<GQLParser::DatetimeValueFunctionContext>(0);
}

GQLParser::DurationValueFunctionContext* GQLParser::ValueFunctionContext::durationValueFunction() {
  return getRuleContext<GQLParser::DurationValueFunctionContext>(0);
}

GQLParser::CharacterOrByteStringFunctionContext* GQLParser::ValueFunctionContext::characterOrByteStringFunction() {
  return getRuleContext<GQLParser::CharacterOrByteStringFunctionContext>(0);
}

GQLParser::ListValueFunctionContext* GQLParser::ValueFunctionContext::listValueFunction() {
  return getRuleContext<GQLParser::ListValueFunctionContext>(0);
}


size_t GQLParser::ValueFunctionContext::getRuleIndex() const {
  return GQLParser::RuleValueFunction;
}




//----------------- BooleanValueExpressionContext ------------------------------------------------------------------

GQLParser::BooleanValueExpressionContext::BooleanValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::BooleanValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::BooleanValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleBooleanValueExpression;
}




//----------------- CharacterOrByteStringFunctionContext ------------------------------------------------------------------

GQLParser::CharacterOrByteStringFunctionContext::CharacterOrByteStringFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SubCharacterOrByteStringContext* GQLParser::CharacterOrByteStringFunctionContext::subCharacterOrByteString() {
  return getRuleContext<GQLParser::SubCharacterOrByteStringContext>(0);
}

GQLParser::TrimSingleCharacterOrByteStringContext* GQLParser::CharacterOrByteStringFunctionContext::trimSingleCharacterOrByteString() {
  return getRuleContext<GQLParser::TrimSingleCharacterOrByteStringContext>(0);
}

GQLParser::FoldCharacterStringContext* GQLParser::CharacterOrByteStringFunctionContext::foldCharacterString() {
  return getRuleContext<GQLParser::FoldCharacterStringContext>(0);
}

GQLParser::TrimMultiCharacterCharacterStringContext* GQLParser::CharacterOrByteStringFunctionContext::trimMultiCharacterCharacterString() {
  return getRuleContext<GQLParser::TrimMultiCharacterCharacterStringContext>(0);
}

GQLParser::NormalizeCharacterStringContext* GQLParser::CharacterOrByteStringFunctionContext::normalizeCharacterString() {
  return getRuleContext<GQLParser::NormalizeCharacterStringContext>(0);
}


size_t GQLParser::CharacterOrByteStringFunctionContext::getRuleIndex() const {
  return GQLParser::RuleCharacterOrByteStringFunction;
}




//----------------- SubCharacterOrByteStringContext ------------------------------------------------------------------

GQLParser::SubCharacterOrByteStringContext::SubCharacterOrByteStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SubCharacterOrByteStringContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ValueExpressionContext* GQLParser::SubCharacterOrByteStringContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::SubCharacterOrByteStringContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::StringLengthContext* GQLParser::SubCharacterOrByteStringContext::stringLength() {
  return getRuleContext<GQLParser::StringLengthContext>(0);
}

tree::TerminalNode* GQLParser::SubCharacterOrByteStringContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::SubCharacterOrByteStringContext::LEFT() {
  return getToken(GQLParser::LEFT, 0);
}

tree::TerminalNode* GQLParser::SubCharacterOrByteStringContext::RIGHT() {
  return getToken(GQLParser::RIGHT, 0);
}


size_t GQLParser::SubCharacterOrByteStringContext::getRuleIndex() const {
  return GQLParser::RuleSubCharacterOrByteString;
}




//----------------- TrimSingleCharacterOrByteStringContext ------------------------------------------------------------------

GQLParser::TrimSingleCharacterOrByteStringContext::TrimSingleCharacterOrByteStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TrimSingleCharacterOrByteStringContext::TRIM() {
  return getToken(GQLParser::TRIM, 0);
}

tree::TerminalNode* GQLParser::TrimSingleCharacterOrByteStringContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::TrimOperandsContext* GQLParser::TrimSingleCharacterOrByteStringContext::trimOperands() {
  return getRuleContext<GQLParser::TrimOperandsContext>(0);
}

tree::TerminalNode* GQLParser::TrimSingleCharacterOrByteStringContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::TrimSingleCharacterOrByteStringContext::getRuleIndex() const {
  return GQLParser::RuleTrimSingleCharacterOrByteString;
}




//----------------- FoldCharacterStringContext ------------------------------------------------------------------

GQLParser::FoldCharacterStringContext::FoldCharacterStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FoldCharacterStringContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ValueExpressionContext* GQLParser::FoldCharacterStringContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::FoldCharacterStringContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::FoldCharacterStringContext::UPPER() {
  return getToken(GQLParser::UPPER, 0);
}

tree::TerminalNode* GQLParser::FoldCharacterStringContext::LOWER() {
  return getToken(GQLParser::LOWER, 0);
}


size_t GQLParser::FoldCharacterStringContext::getRuleIndex() const {
  return GQLParser::RuleFoldCharacterString;
}




//----------------- TrimMultiCharacterCharacterStringContext ------------------------------------------------------------------

GQLParser::TrimMultiCharacterCharacterStringContext::TrimMultiCharacterCharacterStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TrimMultiCharacterCharacterStringContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

std::vector<GQLParser::ValueExpressionContext *> GQLParser::TrimMultiCharacterCharacterStringContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::TrimMultiCharacterCharacterStringContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::TrimMultiCharacterCharacterStringContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::TrimMultiCharacterCharacterStringContext::BTRIM() {
  return getToken(GQLParser::BTRIM, 0);
}

tree::TerminalNode* GQLParser::TrimMultiCharacterCharacterStringContext::LTRIM() {
  return getToken(GQLParser::LTRIM, 0);
}

tree::TerminalNode* GQLParser::TrimMultiCharacterCharacterStringContext::RTRIM() {
  return getToken(GQLParser::RTRIM, 0);
}

tree::TerminalNode* GQLParser::TrimMultiCharacterCharacterStringContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}


size_t GQLParser::TrimMultiCharacterCharacterStringContext::getRuleIndex() const {
  return GQLParser::RuleTrimMultiCharacterCharacterString;
}




//----------------- NormalizeCharacterStringContext ------------------------------------------------------------------

GQLParser::NormalizeCharacterStringContext::NormalizeCharacterStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NormalizeCharacterStringContext::NORMALIZE() {
  return getToken(GQLParser::NORMALIZE, 0);
}

tree::TerminalNode* GQLParser::NormalizeCharacterStringContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ValueExpressionContext* GQLParser::NormalizeCharacterStringContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::NormalizeCharacterStringContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::NormalizeCharacterStringContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::NormalFormContext* GQLParser::NormalizeCharacterStringContext::normalForm() {
  return getRuleContext<GQLParser::NormalFormContext>(0);
}


size_t GQLParser::NormalizeCharacterStringContext::getRuleIndex() const {
  return GQLParser::RuleNormalizeCharacterString;
}




//----------------- NodeReferenceValueExpressionContext ------------------------------------------------------------------

GQLParser::NodeReferenceValueExpressionContext::NodeReferenceValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionPrimaryContext* GQLParser::NodeReferenceValueExpressionContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}


size_t GQLParser::NodeReferenceValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleNodeReferenceValueExpression;
}




//----------------- EdgeReferenceValueExpressionContext ------------------------------------------------------------------

GQLParser::EdgeReferenceValueExpressionContext::EdgeReferenceValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionPrimaryContext* GQLParser::EdgeReferenceValueExpressionContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}


size_t GQLParser::EdgeReferenceValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleEdgeReferenceValueExpression;
}




//----------------- AggregatingValueExpressionContext ------------------------------------------------------------------

GQLParser::AggregatingValueExpressionContext::AggregatingValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::AggregatingValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::AggregatingValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleAggregatingValueExpression;
}




//----------------- ValueExpressionPrimaryContext ------------------------------------------------------------------

GQLParser::ValueExpressionPrimaryContext::ValueExpressionPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ParenthesizedValueExpressionContext* GQLParser::ValueExpressionPrimaryContext::parenthesizedValueExpression() {
  return getRuleContext<GQLParser::ParenthesizedValueExpressionContext>(0);
}

GQLParser::AggregateFunctionContext* GQLParser::ValueExpressionPrimaryContext::aggregateFunction() {
  return getRuleContext<GQLParser::AggregateFunctionContext>(0);
}

GQLParser::UnsignedValueSpecificationContext* GQLParser::ValueExpressionPrimaryContext::unsignedValueSpecification() {
  return getRuleContext<GQLParser::UnsignedValueSpecificationContext>(0);
}

GQLParser::PathValueConstructorContext* GQLParser::ValueExpressionPrimaryContext::pathValueConstructor() {
  return getRuleContext<GQLParser::PathValueConstructorContext>(0);
}

GQLParser::ValueQueryExpressionContext* GQLParser::ValueExpressionPrimaryContext::valueQueryExpression() {
  return getRuleContext<GQLParser::ValueQueryExpressionContext>(0);
}

GQLParser::CaseExpressionContext* GQLParser::ValueExpressionPrimaryContext::caseExpression() {
  return getRuleContext<GQLParser::CaseExpressionContext>(0);
}

GQLParser::CastSpecificationContext* GQLParser::ValueExpressionPrimaryContext::castSpecification() {
  return getRuleContext<GQLParser::CastSpecificationContext>(0);
}

GQLParser::Element_idFunctionContext* GQLParser::ValueExpressionPrimaryContext::element_idFunction() {
  return getRuleContext<GQLParser::Element_idFunctionContext>(0);
}

GQLParser::LetValueExpressionContext* GQLParser::ValueExpressionPrimaryContext::letValueExpression() {
  return getRuleContext<GQLParser::LetValueExpressionContext>(0);
}

GQLParser::BindingVariableReferenceContext* GQLParser::ValueExpressionPrimaryContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}

GQLParser::ValueExpressionPrimaryContext* GQLParser::ValueExpressionPrimaryContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}

tree::TerminalNode* GQLParser::ValueExpressionPrimaryContext::PERIOD() {
  return getToken(GQLParser::PERIOD, 0);
}

GQLParser::PropertyNameContext* GQLParser::ValueExpressionPrimaryContext::propertyName() {
  return getRuleContext<GQLParser::PropertyNameContext>(0);
}


size_t GQLParser::ValueExpressionPrimaryContext::getRuleIndex() const {
  return GQLParser::RuleValueExpressionPrimary;
}




//----------------- ParenthesizedValueExpressionContext ------------------------------------------------------------------

GQLParser::ParenthesizedValueExpressionContext::ParenthesizedValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ParenthesizedValueExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ValueExpressionContext* GQLParser::ParenthesizedValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::ParenthesizedValueExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::ParenthesizedValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleParenthesizedValueExpression;
}




//----------------- NonParenthesizedValueExpressionPrimaryContext ------------------------------------------------------------------

GQLParser::NonParenthesizedValueExpressionPrimaryContext::NonParenthesizedValueExpressionPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext* GQLParser::NonParenthesizedValueExpressionPrimaryContext::nonParenthesizedValueExpressionPrimarySpecialCase() {
  return getRuleContext<GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext>(0);
}

GQLParser::BindingVariableReferenceContext* GQLParser::NonParenthesizedValueExpressionPrimaryContext::bindingVariableReference() {
  return getRuleContext<GQLParser::BindingVariableReferenceContext>(0);
}


size_t GQLParser::NonParenthesizedValueExpressionPrimaryContext::getRuleIndex() const {
  return GQLParser::RuleNonParenthesizedValueExpressionPrimary;
}




//----------------- NonParenthesizedValueExpressionPrimarySpecialCaseContext ------------------------------------------------------------------

GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::NonParenthesizedValueExpressionPrimarySpecialCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::AggregateFunctionContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::aggregateFunction() {
  return getRuleContext<GQLParser::AggregateFunctionContext>(0);
}

GQLParser::UnsignedValueSpecificationContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::unsignedValueSpecification() {
  return getRuleContext<GQLParser::UnsignedValueSpecificationContext>(0);
}

GQLParser::PathValueConstructorContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::pathValueConstructor() {
  return getRuleContext<GQLParser::PathValueConstructorContext>(0);
}

GQLParser::ValueExpressionPrimaryContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}

tree::TerminalNode* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::PERIOD() {
  return getToken(GQLParser::PERIOD, 0);
}

GQLParser::PropertyNameContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::propertyName() {
  return getRuleContext<GQLParser::PropertyNameContext>(0);
}

GQLParser::ValueQueryExpressionContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::valueQueryExpression() {
  return getRuleContext<GQLParser::ValueQueryExpressionContext>(0);
}

GQLParser::CaseExpressionContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::caseExpression() {
  return getRuleContext<GQLParser::CaseExpressionContext>(0);
}

GQLParser::CastSpecificationContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::castSpecification() {
  return getRuleContext<GQLParser::CastSpecificationContext>(0);
}

GQLParser::Element_idFunctionContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::element_idFunction() {
  return getRuleContext<GQLParser::Element_idFunctionContext>(0);
}

GQLParser::LetValueExpressionContext* GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::letValueExpression() {
  return getRuleContext<GQLParser::LetValueExpressionContext>(0);
}


size_t GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext::getRuleIndex() const {
  return GQLParser::RuleNonParenthesizedValueExpressionPrimarySpecialCase;
}




//----------------- UnsignedValueSpecificationContext ------------------------------------------------------------------

GQLParser::UnsignedValueSpecificationContext::UnsignedValueSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedLiteralContext* GQLParser::UnsignedValueSpecificationContext::unsignedLiteral() {
  return getRuleContext<GQLParser::UnsignedLiteralContext>(0);
}

GQLParser::GeneralValueSpecificationContext* GQLParser::UnsignedValueSpecificationContext::generalValueSpecification() {
  return getRuleContext<GQLParser::GeneralValueSpecificationContext>(0);
}


size_t GQLParser::UnsignedValueSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleUnsignedValueSpecification;
}




//----------------- NonNegativeIntegerSpecificationContext ------------------------------------------------------------------

GQLParser::NonNegativeIntegerSpecificationContext::NonNegativeIntegerSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedIntegerContext* GQLParser::NonNegativeIntegerSpecificationContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}

GQLParser::DynamicParameterSpecificationContext* GQLParser::NonNegativeIntegerSpecificationContext::dynamicParameterSpecification() {
  return getRuleContext<GQLParser::DynamicParameterSpecificationContext>(0);
}


size_t GQLParser::NonNegativeIntegerSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleNonNegativeIntegerSpecification;
}




//----------------- GeneralValueSpecificationContext ------------------------------------------------------------------

GQLParser::GeneralValueSpecificationContext::GeneralValueSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DynamicParameterSpecificationContext* GQLParser::GeneralValueSpecificationContext::dynamicParameterSpecification() {
  return getRuleContext<GQLParser::DynamicParameterSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::GeneralValueSpecificationContext::SESSION_USER() {
  return getToken(GQLParser::SESSION_USER, 0);
}


size_t GQLParser::GeneralValueSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleGeneralValueSpecification;
}




//----------------- DynamicParameterSpecificationContext ------------------------------------------------------------------

GQLParser::DynamicParameterSpecificationContext::DynamicParameterSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DynamicParameterSpecificationContext::GENERAL_PARAMETER_REFERENCE() {
  return getToken(GQLParser::GENERAL_PARAMETER_REFERENCE, 0);
}


size_t GQLParser::DynamicParameterSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleDynamicParameterSpecification;
}




//----------------- LetValueExpressionContext ------------------------------------------------------------------

GQLParser::LetValueExpressionContext::LetValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LetValueExpressionContext::LET() {
  return getToken(GQLParser::LET, 0);
}

GQLParser::LetVariableDefinitionListContext* GQLParser::LetValueExpressionContext::letVariableDefinitionList() {
  return getRuleContext<GQLParser::LetVariableDefinitionListContext>(0);
}

tree::TerminalNode* GQLParser::LetValueExpressionContext::IN() {
  return getToken(GQLParser::IN, 0);
}

GQLParser::ValueExpressionContext* GQLParser::LetValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::LetValueExpressionContext::END() {
  return getToken(GQLParser::END, 0);
}


size_t GQLParser::LetValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleLetValueExpression;
}




//----------------- ValueQueryExpressionContext ------------------------------------------------------------------

GQLParser::ValueQueryExpressionContext::ValueQueryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ValueQueryExpressionContext::VALUE() {
  return getToken(GQLParser::VALUE, 0);
}

GQLParser::NestedQuerySpecificationContext* GQLParser::ValueQueryExpressionContext::nestedQuerySpecification() {
  return getRuleContext<GQLParser::NestedQuerySpecificationContext>(0);
}


size_t GQLParser::ValueQueryExpressionContext::getRuleIndex() const {
  return GQLParser::RuleValueQueryExpression;
}




//----------------- CaseExpressionContext ------------------------------------------------------------------

GQLParser::CaseExpressionContext::CaseExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CaseAbbreviationContext* GQLParser::CaseExpressionContext::caseAbbreviation() {
  return getRuleContext<GQLParser::CaseAbbreviationContext>(0);
}

GQLParser::CaseSpecificationContext* GQLParser::CaseExpressionContext::caseSpecification() {
  return getRuleContext<GQLParser::CaseSpecificationContext>(0);
}


size_t GQLParser::CaseExpressionContext::getRuleIndex() const {
  return GQLParser::RuleCaseExpression;
}




//----------------- CaseAbbreviationContext ------------------------------------------------------------------

GQLParser::CaseAbbreviationContext::CaseAbbreviationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::CaseAbbreviationContext::getRuleIndex() const {
  return GQLParser::RuleCaseAbbreviation;
}

void GQLParser::CaseAbbreviationContext::copyFrom(CaseAbbreviationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NullIfExprAltContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::NullIfExprAltContext::NULLIF() {
  return getToken(GQLParser::NULLIF, 0);
}

tree::TerminalNode* GQLParser::NullIfExprAltContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

std::vector<GQLParser::ValueExpressionContext *> GQLParser::NullIfExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::NullIfExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::NullIfExprAltContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

tree::TerminalNode* GQLParser::NullIfExprAltContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::NullIfExprAltContext::NullIfExprAltContext(CaseAbbreviationContext *ctx) { copyFrom(ctx); }


//----------------- CoalesceExprAltContext ------------------------------------------------------------------

tree::TerminalNode* GQLParser::CoalesceExprAltContext::COALESCE() {
  return getToken(GQLParser::COALESCE, 0);
}

tree::TerminalNode* GQLParser::CoalesceExprAltContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

std::vector<GQLParser::ValueExpressionContext *> GQLParser::CoalesceExprAltContext::valueExpression() {
  return getRuleContexts<GQLParser::ValueExpressionContext>();
}

GQLParser::ValueExpressionContext* GQLParser::CoalesceExprAltContext::valueExpression(size_t i) {
  return getRuleContext<GQLParser::ValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::CoalesceExprAltContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

std::vector<tree::TerminalNode *> GQLParser::CoalesceExprAltContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::CoalesceExprAltContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}

GQLParser::CoalesceExprAltContext::CoalesceExprAltContext(CaseAbbreviationContext *ctx) { copyFrom(ctx); }




//----------------- CaseSpecificationContext ------------------------------------------------------------------

GQLParser::CaseSpecificationContext::CaseSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::SimpleCaseContext* GQLParser::CaseSpecificationContext::simpleCase() {
  return getRuleContext<GQLParser::SimpleCaseContext>(0);
}

GQLParser::SearchedCaseContext* GQLParser::CaseSpecificationContext::searchedCase() {
  return getRuleContext<GQLParser::SearchedCaseContext>(0);
}


size_t GQLParser::CaseSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleCaseSpecification;
}




//----------------- SimpleCaseContext ------------------------------------------------------------------

GQLParser::SimpleCaseContext::SimpleCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimpleCaseContext::CASE() {
  return getToken(GQLParser::CASE, 0);
}

GQLParser::CaseOperandContext* GQLParser::SimpleCaseContext::caseOperand() {
  return getRuleContext<GQLParser::CaseOperandContext>(0);
}

tree::TerminalNode* GQLParser::SimpleCaseContext::END() {
  return getToken(GQLParser::END, 0);
}

std::vector<GQLParser::SimpleWhenClauseContext *> GQLParser::SimpleCaseContext::simpleWhenClause() {
  return getRuleContexts<GQLParser::SimpleWhenClauseContext>();
}

GQLParser::SimpleWhenClauseContext* GQLParser::SimpleCaseContext::simpleWhenClause(size_t i) {
  return getRuleContext<GQLParser::SimpleWhenClauseContext>(i);
}

GQLParser::ElseClauseContext* GQLParser::SimpleCaseContext::elseClause() {
  return getRuleContext<GQLParser::ElseClauseContext>(0);
}


size_t GQLParser::SimpleCaseContext::getRuleIndex() const {
  return GQLParser::RuleSimpleCase;
}




//----------------- SearchedCaseContext ------------------------------------------------------------------

GQLParser::SearchedCaseContext::SearchedCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SearchedCaseContext::CASE() {
  return getToken(GQLParser::CASE, 0);
}

tree::TerminalNode* GQLParser::SearchedCaseContext::END() {
  return getToken(GQLParser::END, 0);
}

std::vector<GQLParser::SearchedWhenClauseContext *> GQLParser::SearchedCaseContext::searchedWhenClause() {
  return getRuleContexts<GQLParser::SearchedWhenClauseContext>();
}

GQLParser::SearchedWhenClauseContext* GQLParser::SearchedCaseContext::searchedWhenClause(size_t i) {
  return getRuleContext<GQLParser::SearchedWhenClauseContext>(i);
}

GQLParser::ElseClauseContext* GQLParser::SearchedCaseContext::elseClause() {
  return getRuleContext<GQLParser::ElseClauseContext>(0);
}


size_t GQLParser::SearchedCaseContext::getRuleIndex() const {
  return GQLParser::RuleSearchedCase;
}




//----------------- SimpleWhenClauseContext ------------------------------------------------------------------

GQLParser::SimpleWhenClauseContext::SimpleWhenClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SimpleWhenClauseContext::WHEN() {
  return getToken(GQLParser::WHEN, 0);
}

GQLParser::WhenOperandListContext* GQLParser::SimpleWhenClauseContext::whenOperandList() {
  return getRuleContext<GQLParser::WhenOperandListContext>(0);
}

tree::TerminalNode* GQLParser::SimpleWhenClauseContext::THEN() {
  return getToken(GQLParser::THEN, 0);
}

GQLParser::ResultContext* GQLParser::SimpleWhenClauseContext::result() {
  return getRuleContext<GQLParser::ResultContext>(0);
}


size_t GQLParser::SimpleWhenClauseContext::getRuleIndex() const {
  return GQLParser::RuleSimpleWhenClause;
}




//----------------- SearchedWhenClauseContext ------------------------------------------------------------------

GQLParser::SearchedWhenClauseContext::SearchedWhenClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SearchedWhenClauseContext::WHEN() {
  return getToken(GQLParser::WHEN, 0);
}

GQLParser::SearchConditionContext* GQLParser::SearchedWhenClauseContext::searchCondition() {
  return getRuleContext<GQLParser::SearchConditionContext>(0);
}

tree::TerminalNode* GQLParser::SearchedWhenClauseContext::THEN() {
  return getToken(GQLParser::THEN, 0);
}

GQLParser::ResultContext* GQLParser::SearchedWhenClauseContext::result() {
  return getRuleContext<GQLParser::ResultContext>(0);
}


size_t GQLParser::SearchedWhenClauseContext::getRuleIndex() const {
  return GQLParser::RuleSearchedWhenClause;
}




//----------------- ElseClauseContext ------------------------------------------------------------------

GQLParser::ElseClauseContext::ElseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ElseClauseContext::ELSE() {
  return getToken(GQLParser::ELSE, 0);
}

GQLParser::ResultContext* GQLParser::ElseClauseContext::result() {
  return getRuleContext<GQLParser::ResultContext>(0);
}


size_t GQLParser::ElseClauseContext::getRuleIndex() const {
  return GQLParser::RuleElseClause;
}




//----------------- CaseOperandContext ------------------------------------------------------------------

GQLParser::CaseOperandContext::CaseOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NonParenthesizedValueExpressionPrimaryContext* GQLParser::CaseOperandContext::nonParenthesizedValueExpressionPrimary() {
  return getRuleContext<GQLParser::NonParenthesizedValueExpressionPrimaryContext>(0);
}

GQLParser::ElementVariableReferenceContext* GQLParser::CaseOperandContext::elementVariableReference() {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(0);
}


size_t GQLParser::CaseOperandContext::getRuleIndex() const {
  return GQLParser::RuleCaseOperand;
}




//----------------- WhenOperandListContext ------------------------------------------------------------------

GQLParser::WhenOperandListContext::WhenOperandListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::WhenOperandContext *> GQLParser::WhenOperandListContext::whenOperand() {
  return getRuleContexts<GQLParser::WhenOperandContext>();
}

GQLParser::WhenOperandContext* GQLParser::WhenOperandListContext::whenOperand(size_t i) {
  return getRuleContext<GQLParser::WhenOperandContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::WhenOperandListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::WhenOperandListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::WhenOperandListContext::getRuleIndex() const {
  return GQLParser::RuleWhenOperandList;
}




//----------------- WhenOperandContext ------------------------------------------------------------------

GQLParser::WhenOperandContext::WhenOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NonParenthesizedValueExpressionPrimaryContext* GQLParser::WhenOperandContext::nonParenthesizedValueExpressionPrimary() {
  return getRuleContext<GQLParser::NonParenthesizedValueExpressionPrimaryContext>(0);
}

GQLParser::CompOpContext* GQLParser::WhenOperandContext::compOp() {
  return getRuleContext<GQLParser::CompOpContext>(0);
}

GQLParser::ValueExpressionContext* GQLParser::WhenOperandContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

GQLParser::NullPredicatePart2Context* GQLParser::WhenOperandContext::nullPredicatePart2() {
  return getRuleContext<GQLParser::NullPredicatePart2Context>(0);
}

GQLParser::ValueTypePredicatePart2Context* GQLParser::WhenOperandContext::valueTypePredicatePart2() {
  return getRuleContext<GQLParser::ValueTypePredicatePart2Context>(0);
}

GQLParser::NormalizedPredicatePart2Context* GQLParser::WhenOperandContext::normalizedPredicatePart2() {
  return getRuleContext<GQLParser::NormalizedPredicatePart2Context>(0);
}

GQLParser::DirectedPredicatePart2Context* GQLParser::WhenOperandContext::directedPredicatePart2() {
  return getRuleContext<GQLParser::DirectedPredicatePart2Context>(0);
}

GQLParser::LabeledPredicatePart2Context* GQLParser::WhenOperandContext::labeledPredicatePart2() {
  return getRuleContext<GQLParser::LabeledPredicatePart2Context>(0);
}

GQLParser::SourcePredicatePart2Context* GQLParser::WhenOperandContext::sourcePredicatePart2() {
  return getRuleContext<GQLParser::SourcePredicatePart2Context>(0);
}

GQLParser::DestinationPredicatePart2Context* GQLParser::WhenOperandContext::destinationPredicatePart2() {
  return getRuleContext<GQLParser::DestinationPredicatePart2Context>(0);
}


size_t GQLParser::WhenOperandContext::getRuleIndex() const {
  return GQLParser::RuleWhenOperand;
}




//----------------- ResultContext ------------------------------------------------------------------

GQLParser::ResultContext::ResultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ResultExpressionContext* GQLParser::ResultContext::resultExpression() {
  return getRuleContext<GQLParser::ResultExpressionContext>(0);
}

GQLParser::NullLiteralContext* GQLParser::ResultContext::nullLiteral() {
  return getRuleContext<GQLParser::NullLiteralContext>(0);
}


size_t GQLParser::ResultContext::getRuleIndex() const {
  return GQLParser::RuleResult;
}




//----------------- ResultExpressionContext ------------------------------------------------------------------

GQLParser::ResultExpressionContext::ResultExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::ResultExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::ResultExpressionContext::getRuleIndex() const {
  return GQLParser::RuleResultExpression;
}




//----------------- CastSpecificationContext ------------------------------------------------------------------

GQLParser::CastSpecificationContext::CastSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CastSpecificationContext::CAST() {
  return getToken(GQLParser::CAST, 0);
}

tree::TerminalNode* GQLParser::CastSpecificationContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::CastOperandContext* GQLParser::CastSpecificationContext::castOperand() {
  return getRuleContext<GQLParser::CastOperandContext>(0);
}

tree::TerminalNode* GQLParser::CastSpecificationContext::AS() {
  return getToken(GQLParser::AS, 0);
}

GQLParser::CastTargetContext* GQLParser::CastSpecificationContext::castTarget() {
  return getRuleContext<GQLParser::CastTargetContext>(0);
}

tree::TerminalNode* GQLParser::CastSpecificationContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::CastSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleCastSpecification;
}




//----------------- CastOperandContext ------------------------------------------------------------------

GQLParser::CastOperandContext::CastOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::CastOperandContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

GQLParser::NullLiteralContext* GQLParser::CastOperandContext::nullLiteral() {
  return getRuleContext<GQLParser::NullLiteralContext>(0);
}


size_t GQLParser::CastOperandContext::getRuleIndex() const {
  return GQLParser::RuleCastOperand;
}




//----------------- CastTargetContext ------------------------------------------------------------------

GQLParser::CastTargetContext::CastTargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueTypeContext* GQLParser::CastTargetContext::valueType() {
  return getRuleContext<GQLParser::ValueTypeContext>(0);
}


size_t GQLParser::CastTargetContext::getRuleIndex() const {
  return GQLParser::RuleCastTarget;
}




//----------------- AggregateFunctionContext ------------------------------------------------------------------

GQLParser::AggregateFunctionContext::AggregateFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AggregateFunctionContext::COUNT() {
  return getToken(GQLParser::COUNT, 0);
}

tree::TerminalNode* GQLParser::AggregateFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::AggregateFunctionContext::ASTERISK() {
  return getToken(GQLParser::ASTERISK, 0);
}

tree::TerminalNode* GQLParser::AggregateFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::GeneralSetFunctionContext* GQLParser::AggregateFunctionContext::generalSetFunction() {
  return getRuleContext<GQLParser::GeneralSetFunctionContext>(0);
}

GQLParser::BinarySetFunctionContext* GQLParser::AggregateFunctionContext::binarySetFunction() {
  return getRuleContext<GQLParser::BinarySetFunctionContext>(0);
}


size_t GQLParser::AggregateFunctionContext::getRuleIndex() const {
  return GQLParser::RuleAggregateFunction;
}




//----------------- GeneralSetFunctionContext ------------------------------------------------------------------

GQLParser::GeneralSetFunctionContext::GeneralSetFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::GeneralSetFunctionTypeContext* GQLParser::GeneralSetFunctionContext::generalSetFunctionType() {
  return getRuleContext<GQLParser::GeneralSetFunctionTypeContext>(0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ValueExpressionContext* GQLParser::GeneralSetFunctionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::SetQuantifierContext* GQLParser::GeneralSetFunctionContext::setQuantifier() {
  return getRuleContext<GQLParser::SetQuantifierContext>(0);
}


size_t GQLParser::GeneralSetFunctionContext::getRuleIndex() const {
  return GQLParser::RuleGeneralSetFunction;
}




//----------------- BinarySetFunctionContext ------------------------------------------------------------------

GQLParser::BinarySetFunctionContext::BinarySetFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BinarySetFunctionTypeContext* GQLParser::BinarySetFunctionContext::binarySetFunctionType() {
  return getRuleContext<GQLParser::BinarySetFunctionTypeContext>(0);
}

tree::TerminalNode* GQLParser::BinarySetFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::DependentValueExpressionContext* GQLParser::BinarySetFunctionContext::dependentValueExpression() {
  return getRuleContext<GQLParser::DependentValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::BinarySetFunctionContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::IndependentValueExpressionContext* GQLParser::BinarySetFunctionContext::independentValueExpression() {
  return getRuleContext<GQLParser::IndependentValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::BinarySetFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::BinarySetFunctionContext::getRuleIndex() const {
  return GQLParser::RuleBinarySetFunction;
}




//----------------- GeneralSetFunctionTypeContext ------------------------------------------------------------------

GQLParser::GeneralSetFunctionTypeContext::GeneralSetFunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::AVG() {
  return getToken(GQLParser::AVG, 0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::COUNT() {
  return getToken(GQLParser::COUNT, 0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::MAX() {
  return getToken(GQLParser::MAX, 0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::MIN() {
  return getToken(GQLParser::MIN, 0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::SUM() {
  return getToken(GQLParser::SUM, 0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::COLLECT_LIST() {
  return getToken(GQLParser::COLLECT_LIST, 0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::STDDEV_SAMP() {
  return getToken(GQLParser::STDDEV_SAMP, 0);
}

tree::TerminalNode* GQLParser::GeneralSetFunctionTypeContext::STDDEV_POP() {
  return getToken(GQLParser::STDDEV_POP, 0);
}


size_t GQLParser::GeneralSetFunctionTypeContext::getRuleIndex() const {
  return GQLParser::RuleGeneralSetFunctionType;
}




//----------------- SetQuantifierContext ------------------------------------------------------------------

GQLParser::SetQuantifierContext::SetQuantifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SetQuantifierContext::DISTINCT() {
  return getToken(GQLParser::DISTINCT, 0);
}

tree::TerminalNode* GQLParser::SetQuantifierContext::ALL() {
  return getToken(GQLParser::ALL, 0);
}


size_t GQLParser::SetQuantifierContext::getRuleIndex() const {
  return GQLParser::RuleSetQuantifier;
}




//----------------- BinarySetFunctionTypeContext ------------------------------------------------------------------

GQLParser::BinarySetFunctionTypeContext::BinarySetFunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::BinarySetFunctionTypeContext::PERCENTILE_CONT() {
  return getToken(GQLParser::PERCENTILE_CONT, 0);
}

tree::TerminalNode* GQLParser::BinarySetFunctionTypeContext::PERCENTILE_DISC() {
  return getToken(GQLParser::PERCENTILE_DISC, 0);
}


size_t GQLParser::BinarySetFunctionTypeContext::getRuleIndex() const {
  return GQLParser::RuleBinarySetFunctionType;
}




//----------------- DependentValueExpressionContext ------------------------------------------------------------------

GQLParser::DependentValueExpressionContext::DependentValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::DependentValueExpressionContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

GQLParser::SetQuantifierContext* GQLParser::DependentValueExpressionContext::setQuantifier() {
  return getRuleContext<GQLParser::SetQuantifierContext>(0);
}


size_t GQLParser::DependentValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleDependentValueExpression;
}




//----------------- IndependentValueExpressionContext ------------------------------------------------------------------

GQLParser::IndependentValueExpressionContext::IndependentValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::IndependentValueExpressionContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::IndependentValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleIndependentValueExpression;
}




//----------------- Element_idFunctionContext ------------------------------------------------------------------

GQLParser::Element_idFunctionContext::Element_idFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::Element_idFunctionContext::ELEMENT_ID() {
  return getToken(GQLParser::ELEMENT_ID, 0);
}

tree::TerminalNode* GQLParser::Element_idFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ElementVariableReferenceContext* GQLParser::Element_idFunctionContext::elementVariableReference() {
  return getRuleContext<GQLParser::ElementVariableReferenceContext>(0);
}

tree::TerminalNode* GQLParser::Element_idFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::Element_idFunctionContext::getRuleIndex() const {
  return GQLParser::RuleElement_idFunction;
}




//----------------- BindingVariableReferenceContext ------------------------------------------------------------------

GQLParser::BindingVariableReferenceContext::BindingVariableReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableContext* GQLParser::BindingVariableReferenceContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}


size_t GQLParser::BindingVariableReferenceContext::getRuleIndex() const {
  return GQLParser::RuleBindingVariableReference;
}




//----------------- PathValueExpressionContext ------------------------------------------------------------------

GQLParser::PathValueExpressionContext::PathValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::PathValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::PathValueExpressionContext::getRuleIndex() const {
  return GQLParser::RulePathValueExpression;
}




//----------------- PathValueConstructorContext ------------------------------------------------------------------

GQLParser::PathValueConstructorContext::PathValueConstructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PathValueConstructorByEnumerationContext* GQLParser::PathValueConstructorContext::pathValueConstructorByEnumeration() {
  return getRuleContext<GQLParser::PathValueConstructorByEnumerationContext>(0);
}


size_t GQLParser::PathValueConstructorContext::getRuleIndex() const {
  return GQLParser::RulePathValueConstructor;
}




//----------------- PathValueConstructorByEnumerationContext ------------------------------------------------------------------

GQLParser::PathValueConstructorByEnumerationContext::PathValueConstructorByEnumerationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PathValueConstructorByEnumerationContext::PATH() {
  return getToken(GQLParser::PATH, 0);
}

tree::TerminalNode* GQLParser::PathValueConstructorByEnumerationContext::LEFT_BRACKET() {
  return getToken(GQLParser::LEFT_BRACKET, 0);
}

GQLParser::PathElementListContext* GQLParser::PathValueConstructorByEnumerationContext::pathElementList() {
  return getRuleContext<GQLParser::PathElementListContext>(0);
}

tree::TerminalNode* GQLParser::PathValueConstructorByEnumerationContext::RIGHT_BRACKET() {
  return getToken(GQLParser::RIGHT_BRACKET, 0);
}


size_t GQLParser::PathValueConstructorByEnumerationContext::getRuleIndex() const {
  return GQLParser::RulePathValueConstructorByEnumeration;
}




//----------------- PathElementListContext ------------------------------------------------------------------

GQLParser::PathElementListContext::PathElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::PathElementListStartContext* GQLParser::PathElementListContext::pathElementListStart() {
  return getRuleContext<GQLParser::PathElementListStartContext>(0);
}

std::vector<GQLParser::PathElementListStepContext *> GQLParser::PathElementListContext::pathElementListStep() {
  return getRuleContexts<GQLParser::PathElementListStepContext>();
}

GQLParser::PathElementListStepContext* GQLParser::PathElementListContext::pathElementListStep(size_t i) {
  return getRuleContext<GQLParser::PathElementListStepContext>(i);
}


size_t GQLParser::PathElementListContext::getRuleIndex() const {
  return GQLParser::RulePathElementList;
}




//----------------- PathElementListStartContext ------------------------------------------------------------------

GQLParser::PathElementListStartContext::PathElementListStartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NodeReferenceValueExpressionContext* GQLParser::PathElementListStartContext::nodeReferenceValueExpression() {
  return getRuleContext<GQLParser::NodeReferenceValueExpressionContext>(0);
}


size_t GQLParser::PathElementListStartContext::getRuleIndex() const {
  return GQLParser::RulePathElementListStart;
}




//----------------- PathElementListStepContext ------------------------------------------------------------------

GQLParser::PathElementListStepContext::PathElementListStepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GQLParser::PathElementListStepContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::PathElementListStepContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}

GQLParser::EdgeReferenceValueExpressionContext* GQLParser::PathElementListStepContext::edgeReferenceValueExpression() {
  return getRuleContext<GQLParser::EdgeReferenceValueExpressionContext>(0);
}

GQLParser::NodeReferenceValueExpressionContext* GQLParser::PathElementListStepContext::nodeReferenceValueExpression() {
  return getRuleContext<GQLParser::NodeReferenceValueExpressionContext>(0);
}


size_t GQLParser::PathElementListStepContext::getRuleIndex() const {
  return GQLParser::RulePathElementListStep;
}




//----------------- ListValueExpressionContext ------------------------------------------------------------------

GQLParser::ListValueExpressionContext::ListValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::ListValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::ListValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleListValueExpression;
}




//----------------- ListValueFunctionContext ------------------------------------------------------------------

GQLParser::ListValueFunctionContext::ListValueFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::TrimListFunctionContext* GQLParser::ListValueFunctionContext::trimListFunction() {
  return getRuleContext<GQLParser::TrimListFunctionContext>(0);
}

GQLParser::ElementsFunctionContext* GQLParser::ListValueFunctionContext::elementsFunction() {
  return getRuleContext<GQLParser::ElementsFunctionContext>(0);
}


size_t GQLParser::ListValueFunctionContext::getRuleIndex() const {
  return GQLParser::RuleListValueFunction;
}




//----------------- TrimListFunctionContext ------------------------------------------------------------------

GQLParser::TrimListFunctionContext::TrimListFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TrimListFunctionContext::TRIM() {
  return getToken(GQLParser::TRIM, 0);
}

tree::TerminalNode* GQLParser::TrimListFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ListValueExpressionContext* GQLParser::TrimListFunctionContext::listValueExpression() {
  return getRuleContext<GQLParser::ListValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::TrimListFunctionContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::TrimListFunctionContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::TrimListFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::TrimListFunctionContext::getRuleIndex() const {
  return GQLParser::RuleTrimListFunction;
}




//----------------- ElementsFunctionContext ------------------------------------------------------------------

GQLParser::ElementsFunctionContext::ElementsFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ElementsFunctionContext::ELEMENTS() {
  return getToken(GQLParser::ELEMENTS, 0);
}

tree::TerminalNode* GQLParser::ElementsFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PathValueExpressionContext* GQLParser::ElementsFunctionContext::pathValueExpression() {
  return getRuleContext<GQLParser::PathValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::ElementsFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::ElementsFunctionContext::getRuleIndex() const {
  return GQLParser::RuleElementsFunction;
}




//----------------- ListValueConstructorContext ------------------------------------------------------------------

GQLParser::ListValueConstructorContext::ListValueConstructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ListValueConstructorByEnumerationContext* GQLParser::ListValueConstructorContext::listValueConstructorByEnumeration() {
  return getRuleContext<GQLParser::ListValueConstructorByEnumerationContext>(0);
}


size_t GQLParser::ListValueConstructorContext::getRuleIndex() const {
  return GQLParser::RuleListValueConstructor;
}




//----------------- ListValueConstructorByEnumerationContext ------------------------------------------------------------------

GQLParser::ListValueConstructorByEnumerationContext::ListValueConstructorByEnumerationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ListValueConstructorByEnumerationContext::LEFT_BRACKET() {
  return getToken(GQLParser::LEFT_BRACKET, 0);
}

tree::TerminalNode* GQLParser::ListValueConstructorByEnumerationContext::RIGHT_BRACKET() {
  return getToken(GQLParser::RIGHT_BRACKET, 0);
}

GQLParser::ListValueTypeNameContext* GQLParser::ListValueConstructorByEnumerationContext::listValueTypeName() {
  return getRuleContext<GQLParser::ListValueTypeNameContext>(0);
}

GQLParser::ListElementListContext* GQLParser::ListValueConstructorByEnumerationContext::listElementList() {
  return getRuleContext<GQLParser::ListElementListContext>(0);
}


size_t GQLParser::ListValueConstructorByEnumerationContext::getRuleIndex() const {
  return GQLParser::RuleListValueConstructorByEnumeration;
}




//----------------- ListElementListContext ------------------------------------------------------------------

GQLParser::ListElementListContext::ListElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::ListElementContext *> GQLParser::ListElementListContext::listElement() {
  return getRuleContexts<GQLParser::ListElementContext>();
}

GQLParser::ListElementContext* GQLParser::ListElementListContext::listElement(size_t i) {
  return getRuleContext<GQLParser::ListElementContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::ListElementListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::ListElementListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::ListElementListContext::getRuleIndex() const {
  return GQLParser::RuleListElementList;
}




//----------------- ListElementContext ------------------------------------------------------------------

GQLParser::ListElementContext::ListElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::ListElementContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::ListElementContext::getRuleIndex() const {
  return GQLParser::RuleListElement;
}




//----------------- RecordConstructorContext ------------------------------------------------------------------

GQLParser::RecordConstructorContext::RecordConstructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FieldsSpecificationContext* GQLParser::RecordConstructorContext::fieldsSpecification() {
  return getRuleContext<GQLParser::FieldsSpecificationContext>(0);
}

tree::TerminalNode* GQLParser::RecordConstructorContext::RECORD() {
  return getToken(GQLParser::RECORD, 0);
}


size_t GQLParser::RecordConstructorContext::getRuleIndex() const {
  return GQLParser::RuleRecordConstructor;
}




//----------------- FieldsSpecificationContext ------------------------------------------------------------------

GQLParser::FieldsSpecificationContext::FieldsSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FieldsSpecificationContext::LEFT_BRACE() {
  return getToken(GQLParser::LEFT_BRACE, 0);
}

tree::TerminalNode* GQLParser::FieldsSpecificationContext::RIGHT_BRACE() {
  return getToken(GQLParser::RIGHT_BRACE, 0);
}

GQLParser::FieldListContext* GQLParser::FieldsSpecificationContext::fieldList() {
  return getRuleContext<GQLParser::FieldListContext>(0);
}


size_t GQLParser::FieldsSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleFieldsSpecification;
}




//----------------- FieldListContext ------------------------------------------------------------------

GQLParser::FieldListContext::FieldListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GQLParser::FieldContext *> GQLParser::FieldListContext::field() {
  return getRuleContexts<GQLParser::FieldContext>();
}

GQLParser::FieldContext* GQLParser::FieldListContext::field(size_t i) {
  return getRuleContext<GQLParser::FieldContext>(i);
}

std::vector<tree::TerminalNode *> GQLParser::FieldListContext::COMMA() {
  return getTokens(GQLParser::COMMA);
}

tree::TerminalNode* GQLParser::FieldListContext::COMMA(size_t i) {
  return getToken(GQLParser::COMMA, i);
}


size_t GQLParser::FieldListContext::getRuleIndex() const {
  return GQLParser::RuleFieldList;
}




//----------------- FieldContext ------------------------------------------------------------------

GQLParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::FieldNameContext* GQLParser::FieldContext::fieldName() {
  return getRuleContext<GQLParser::FieldNameContext>(0);
}

tree::TerminalNode* GQLParser::FieldContext::COLON() {
  return getToken(GQLParser::COLON, 0);
}

GQLParser::ValueExpressionContext* GQLParser::FieldContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::FieldContext::getRuleIndex() const {
  return GQLParser::RuleField;
}




//----------------- TruthValueContext ------------------------------------------------------------------

GQLParser::TruthValueContext::TruthValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TruthValueContext::BOOLEAN_LITERAL() {
  return getToken(GQLParser::BOOLEAN_LITERAL, 0);
}


size_t GQLParser::TruthValueContext::getRuleIndex() const {
  return GQLParser::RuleTruthValue;
}




//----------------- NumericValueExpressionContext ------------------------------------------------------------------

GQLParser::NumericValueExpressionContext::NumericValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GQLParser::NumericValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleNumericValueExpression;
}

void GQLParser::NumericValueExpressionContext::copyFrom(NumericValueExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultDivExprAlt2Context ------------------------------------------------------------------

std::vector<GQLParser::NumericValueExpressionContext *> GQLParser::MultDivExprAlt2Context::numericValueExpression() {
  return getRuleContexts<GQLParser::NumericValueExpressionContext>();
}

GQLParser::NumericValueExpressionContext* GQLParser::MultDivExprAlt2Context::numericValueExpression(size_t i) {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::MultDivExprAlt2Context::ASTERISK() {
  return getToken(GQLParser::ASTERISK, 0);
}

tree::TerminalNode* GQLParser::MultDivExprAlt2Context::SOLIDUS() {
  return getToken(GQLParser::SOLIDUS, 0);
}

GQLParser::MultDivExprAlt2Context::MultDivExprAlt2Context(NumericValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- NumericValueFunctionExprAltContext ------------------------------------------------------------------

GQLParser::NumericValueFunctionContext* GQLParser::NumericValueFunctionExprAltContext::numericValueFunction() {
  return getRuleContext<GQLParser::NumericValueFunctionContext>(0);
}

GQLParser::NumericValueFunctionExprAltContext::NumericValueFunctionExprAltContext(NumericValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- SignedExprAlt2Context ------------------------------------------------------------------

GQLParser::NumericValueExpressionContext* GQLParser::SignedExprAlt2Context::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::SignedExprAlt2Context::PLUS_SIGN() {
  return getToken(GQLParser::PLUS_SIGN, 0);
}

tree::TerminalNode* GQLParser::SignedExprAlt2Context::MINUS_SIGN() {
  return getToken(GQLParser::MINUS_SIGN, 0);
}

GQLParser::SignedExprAlt2Context::SignedExprAlt2Context(NumericValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryExprAlt2Context ------------------------------------------------------------------

GQLParser::ValueExpressionPrimaryContext* GQLParser::PrimaryExprAlt2Context::valueExpressionPrimary() {
  return getRuleContext<GQLParser::ValueExpressionPrimaryContext>(0);
}

GQLParser::PrimaryExprAlt2Context::PrimaryExprAlt2Context(NumericValueExpressionContext *ctx) { copyFrom(ctx); }


//----------------- AddSubtractExprAlt2Context ------------------------------------------------------------------

std::vector<GQLParser::NumericValueExpressionContext *> GQLParser::AddSubtractExprAlt2Context::numericValueExpression() {
  return getRuleContexts<GQLParser::NumericValueExpressionContext>();
}

GQLParser::NumericValueExpressionContext* GQLParser::AddSubtractExprAlt2Context::numericValueExpression(size_t i) {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(i);
}

tree::TerminalNode* GQLParser::AddSubtractExprAlt2Context::PLUS_SIGN() {
  return getToken(GQLParser::PLUS_SIGN, 0);
}

tree::TerminalNode* GQLParser::AddSubtractExprAlt2Context::MINUS_SIGN() {
  return getToken(GQLParser::MINUS_SIGN, 0);
}

GQLParser::AddSubtractExprAlt2Context::AddSubtractExprAlt2Context(NumericValueExpressionContext *ctx) { copyFrom(ctx); }




//----------------- NumericValueFunctionContext ------------------------------------------------------------------

GQLParser::NumericValueFunctionContext::NumericValueFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::LengthExpressionContext* GQLParser::NumericValueFunctionContext::lengthExpression() {
  return getRuleContext<GQLParser::LengthExpressionContext>(0);
}

GQLParser::CardinalityExpressionContext* GQLParser::NumericValueFunctionContext::cardinalityExpression() {
  return getRuleContext<GQLParser::CardinalityExpressionContext>(0);
}

GQLParser::AbsoluteValueExpressionContext* GQLParser::NumericValueFunctionContext::absoluteValueExpression() {
  return getRuleContext<GQLParser::AbsoluteValueExpressionContext>(0);
}

GQLParser::ModulusExpressionContext* GQLParser::NumericValueFunctionContext::modulusExpression() {
  return getRuleContext<GQLParser::ModulusExpressionContext>(0);
}

GQLParser::TrigonometricFunctionContext* GQLParser::NumericValueFunctionContext::trigonometricFunction() {
  return getRuleContext<GQLParser::TrigonometricFunctionContext>(0);
}

GQLParser::GeneralLogarithmFunctionContext* GQLParser::NumericValueFunctionContext::generalLogarithmFunction() {
  return getRuleContext<GQLParser::GeneralLogarithmFunctionContext>(0);
}

GQLParser::CommonLogarithmContext* GQLParser::NumericValueFunctionContext::commonLogarithm() {
  return getRuleContext<GQLParser::CommonLogarithmContext>(0);
}

GQLParser::NaturalLogarithmContext* GQLParser::NumericValueFunctionContext::naturalLogarithm() {
  return getRuleContext<GQLParser::NaturalLogarithmContext>(0);
}

GQLParser::ExponentialFunctionContext* GQLParser::NumericValueFunctionContext::exponentialFunction() {
  return getRuleContext<GQLParser::ExponentialFunctionContext>(0);
}

GQLParser::PowerFunctionContext* GQLParser::NumericValueFunctionContext::powerFunction() {
  return getRuleContext<GQLParser::PowerFunctionContext>(0);
}

GQLParser::SquareRootContext* GQLParser::NumericValueFunctionContext::squareRoot() {
  return getRuleContext<GQLParser::SquareRootContext>(0);
}

GQLParser::FloorFunctionContext* GQLParser::NumericValueFunctionContext::floorFunction() {
  return getRuleContext<GQLParser::FloorFunctionContext>(0);
}

GQLParser::CeilingFunctionContext* GQLParser::NumericValueFunctionContext::ceilingFunction() {
  return getRuleContext<GQLParser::CeilingFunctionContext>(0);
}


size_t GQLParser::NumericValueFunctionContext::getRuleIndex() const {
  return GQLParser::RuleNumericValueFunction;
}




//----------------- LengthExpressionContext ------------------------------------------------------------------

GQLParser::LengthExpressionContext::LengthExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CharLengthExpressionContext* GQLParser::LengthExpressionContext::charLengthExpression() {
  return getRuleContext<GQLParser::CharLengthExpressionContext>(0);
}

GQLParser::ByteLengthExpressionContext* GQLParser::LengthExpressionContext::byteLengthExpression() {
  return getRuleContext<GQLParser::ByteLengthExpressionContext>(0);
}

GQLParser::PathLengthExpressionContext* GQLParser::LengthExpressionContext::pathLengthExpression() {
  return getRuleContext<GQLParser::PathLengthExpressionContext>(0);
}


size_t GQLParser::LengthExpressionContext::getRuleIndex() const {
  return GQLParser::RuleLengthExpression;
}




//----------------- CardinalityExpressionContext ------------------------------------------------------------------

GQLParser::CardinalityExpressionContext::CardinalityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CardinalityExpressionContext::CARDINALITY() {
  return getToken(GQLParser::CARDINALITY, 0);
}

tree::TerminalNode* GQLParser::CardinalityExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::CardinalityExpressionArgumentContext* GQLParser::CardinalityExpressionContext::cardinalityExpressionArgument() {
  return getRuleContext<GQLParser::CardinalityExpressionArgumentContext>(0);
}

tree::TerminalNode* GQLParser::CardinalityExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::CardinalityExpressionContext::SIZE() {
  return getToken(GQLParser::SIZE, 0);
}

GQLParser::ListValueExpressionContext* GQLParser::CardinalityExpressionContext::listValueExpression() {
  return getRuleContext<GQLParser::ListValueExpressionContext>(0);
}


size_t GQLParser::CardinalityExpressionContext::getRuleIndex() const {
  return GQLParser::RuleCardinalityExpression;
}




//----------------- CardinalityExpressionArgumentContext ------------------------------------------------------------------

GQLParser::CardinalityExpressionArgumentContext::CardinalityExpressionArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::CardinalityExpressionArgumentContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::CardinalityExpressionArgumentContext::getRuleIndex() const {
  return GQLParser::RuleCardinalityExpressionArgument;
}




//----------------- CharLengthExpressionContext ------------------------------------------------------------------

GQLParser::CharLengthExpressionContext::CharLengthExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CharLengthExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::CharacterStringValueExpressionContext* GQLParser::CharLengthExpressionContext::characterStringValueExpression() {
  return getRuleContext<GQLParser::CharacterStringValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::CharLengthExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::CharLengthExpressionContext::CHAR_LENGTH() {
  return getToken(GQLParser::CHAR_LENGTH, 0);
}

tree::TerminalNode* GQLParser::CharLengthExpressionContext::CHARACTER_LENGTH() {
  return getToken(GQLParser::CHARACTER_LENGTH, 0);
}


size_t GQLParser::CharLengthExpressionContext::getRuleIndex() const {
  return GQLParser::RuleCharLengthExpression;
}




//----------------- ByteLengthExpressionContext ------------------------------------------------------------------

GQLParser::ByteLengthExpressionContext::ByteLengthExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ByteLengthExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ByteStringValueExpressionContext* GQLParser::ByteLengthExpressionContext::byteStringValueExpression() {
  return getRuleContext<GQLParser::ByteStringValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::ByteLengthExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::ByteLengthExpressionContext::BYTE_LENGTH() {
  return getToken(GQLParser::BYTE_LENGTH, 0);
}

tree::TerminalNode* GQLParser::ByteLengthExpressionContext::OCTET_LENGTH() {
  return getToken(GQLParser::OCTET_LENGTH, 0);
}


size_t GQLParser::ByteLengthExpressionContext::getRuleIndex() const {
  return GQLParser::RuleByteLengthExpression;
}




//----------------- PathLengthExpressionContext ------------------------------------------------------------------

GQLParser::PathLengthExpressionContext::PathLengthExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PathLengthExpressionContext::PATH_LENGTH() {
  return getToken(GQLParser::PATH_LENGTH, 0);
}

tree::TerminalNode* GQLParser::PathLengthExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::PathValueExpressionContext* GQLParser::PathLengthExpressionContext::pathValueExpression() {
  return getRuleContext<GQLParser::PathValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::PathLengthExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::PathLengthExpressionContext::getRuleIndex() const {
  return GQLParser::RulePathLengthExpression;
}




//----------------- AbsoluteValueExpressionContext ------------------------------------------------------------------

GQLParser::AbsoluteValueExpressionContext::AbsoluteValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::AbsoluteValueExpressionContext::ABS() {
  return getToken(GQLParser::ABS, 0);
}

tree::TerminalNode* GQLParser::AbsoluteValueExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::ValueExpressionContext* GQLParser::AbsoluteValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::AbsoluteValueExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::AbsoluteValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleAbsoluteValueExpression;
}




//----------------- ModulusExpressionContext ------------------------------------------------------------------

GQLParser::ModulusExpressionContext::ModulusExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ModulusExpressionContext::MOD() {
  return getToken(GQLParser::MOD, 0);
}

tree::TerminalNode* GQLParser::ModulusExpressionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionDividendContext* GQLParser::ModulusExpressionContext::numericValueExpressionDividend() {
  return getRuleContext<GQLParser::NumericValueExpressionDividendContext>(0);
}

tree::TerminalNode* GQLParser::ModulusExpressionContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::NumericValueExpressionDivisorContext* GQLParser::ModulusExpressionContext::numericValueExpressionDivisor() {
  return getRuleContext<GQLParser::NumericValueExpressionDivisorContext>(0);
}

tree::TerminalNode* GQLParser::ModulusExpressionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::ModulusExpressionContext::getRuleIndex() const {
  return GQLParser::RuleModulusExpression;
}




//----------------- NumericValueExpressionDividendContext ------------------------------------------------------------------

GQLParser::NumericValueExpressionDividendContext::NumericValueExpressionDividendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::NumericValueExpressionDividendContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::NumericValueExpressionDividendContext::getRuleIndex() const {
  return GQLParser::RuleNumericValueExpressionDividend;
}




//----------------- NumericValueExpressionDivisorContext ------------------------------------------------------------------

GQLParser::NumericValueExpressionDivisorContext::NumericValueExpressionDivisorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::NumericValueExpressionDivisorContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::NumericValueExpressionDivisorContext::getRuleIndex() const {
  return GQLParser::RuleNumericValueExpressionDivisor;
}




//----------------- TrigonometricFunctionContext ------------------------------------------------------------------

GQLParser::TrigonometricFunctionContext::TrigonometricFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::TrigonometricFunctionNameContext* GQLParser::TrigonometricFunctionContext::trigonometricFunctionName() {
  return getRuleContext<GQLParser::TrigonometricFunctionNameContext>(0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::TrigonometricFunctionContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::TrigonometricFunctionContext::getRuleIndex() const {
  return GQLParser::RuleTrigonometricFunction;
}




//----------------- TrigonometricFunctionNameContext ------------------------------------------------------------------

GQLParser::TrigonometricFunctionNameContext::TrigonometricFunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::SIN() {
  return getToken(GQLParser::SIN, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::COS() {
  return getToken(GQLParser::COS, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::TAN() {
  return getToken(GQLParser::TAN, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::COT() {
  return getToken(GQLParser::COT, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::SINH() {
  return getToken(GQLParser::SINH, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::COSH() {
  return getToken(GQLParser::COSH, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::TANH() {
  return getToken(GQLParser::TANH, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::ASIN() {
  return getToken(GQLParser::ASIN, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::ACOS() {
  return getToken(GQLParser::ACOS, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::ATAN() {
  return getToken(GQLParser::ATAN, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::DEGREES() {
  return getToken(GQLParser::DEGREES, 0);
}

tree::TerminalNode* GQLParser::TrigonometricFunctionNameContext::RADIANS() {
  return getToken(GQLParser::RADIANS, 0);
}


size_t GQLParser::TrigonometricFunctionNameContext::getRuleIndex() const {
  return GQLParser::RuleTrigonometricFunctionName;
}




//----------------- GeneralLogarithmFunctionContext ------------------------------------------------------------------

GQLParser::GeneralLogarithmFunctionContext::GeneralLogarithmFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GeneralLogarithmFunctionContext::LOG_KW() {
  return getToken(GQLParser::LOG_KW, 0);
}

tree::TerminalNode* GQLParser::GeneralLogarithmFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::GeneralLogarithmBaseContext* GQLParser::GeneralLogarithmFunctionContext::generalLogarithmBase() {
  return getRuleContext<GQLParser::GeneralLogarithmBaseContext>(0);
}

tree::TerminalNode* GQLParser::GeneralLogarithmFunctionContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::GeneralLogarithmArgumentContext* GQLParser::GeneralLogarithmFunctionContext::generalLogarithmArgument() {
  return getRuleContext<GQLParser::GeneralLogarithmArgumentContext>(0);
}

tree::TerminalNode* GQLParser::GeneralLogarithmFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::GeneralLogarithmFunctionContext::getRuleIndex() const {
  return GQLParser::RuleGeneralLogarithmFunction;
}




//----------------- GeneralLogarithmBaseContext ------------------------------------------------------------------

GQLParser::GeneralLogarithmBaseContext::GeneralLogarithmBaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::GeneralLogarithmBaseContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::GeneralLogarithmBaseContext::getRuleIndex() const {
  return GQLParser::RuleGeneralLogarithmBase;
}




//----------------- GeneralLogarithmArgumentContext ------------------------------------------------------------------

GQLParser::GeneralLogarithmArgumentContext::GeneralLogarithmArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::GeneralLogarithmArgumentContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::GeneralLogarithmArgumentContext::getRuleIndex() const {
  return GQLParser::RuleGeneralLogarithmArgument;
}




//----------------- CommonLogarithmContext ------------------------------------------------------------------

GQLParser::CommonLogarithmContext::CommonLogarithmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CommonLogarithmContext::LOG10() {
  return getToken(GQLParser::LOG10, 0);
}

tree::TerminalNode* GQLParser::CommonLogarithmContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::CommonLogarithmContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::CommonLogarithmContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::CommonLogarithmContext::getRuleIndex() const {
  return GQLParser::RuleCommonLogarithm;
}




//----------------- NaturalLogarithmContext ------------------------------------------------------------------

GQLParser::NaturalLogarithmContext::NaturalLogarithmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NaturalLogarithmContext::LN() {
  return getToken(GQLParser::LN, 0);
}

tree::TerminalNode* GQLParser::NaturalLogarithmContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::NaturalLogarithmContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::NaturalLogarithmContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::NaturalLogarithmContext::getRuleIndex() const {
  return GQLParser::RuleNaturalLogarithm;
}




//----------------- ExponentialFunctionContext ------------------------------------------------------------------

GQLParser::ExponentialFunctionContext::ExponentialFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ExponentialFunctionContext::EXP() {
  return getToken(GQLParser::EXP, 0);
}

tree::TerminalNode* GQLParser::ExponentialFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::ExponentialFunctionContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::ExponentialFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::ExponentialFunctionContext::getRuleIndex() const {
  return GQLParser::RuleExponentialFunction;
}




//----------------- PowerFunctionContext ------------------------------------------------------------------

GQLParser::PowerFunctionContext::PowerFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::PowerFunctionContext::POWER() {
  return getToken(GQLParser::POWER, 0);
}

tree::TerminalNode* GQLParser::PowerFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionBaseContext* GQLParser::PowerFunctionContext::numericValueExpressionBase() {
  return getRuleContext<GQLParser::NumericValueExpressionBaseContext>(0);
}

tree::TerminalNode* GQLParser::PowerFunctionContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::NumericValueExpressionExponentContext* GQLParser::PowerFunctionContext::numericValueExpressionExponent() {
  return getRuleContext<GQLParser::NumericValueExpressionExponentContext>(0);
}

tree::TerminalNode* GQLParser::PowerFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::PowerFunctionContext::getRuleIndex() const {
  return GQLParser::RulePowerFunction;
}




//----------------- NumericValueExpressionBaseContext ------------------------------------------------------------------

GQLParser::NumericValueExpressionBaseContext::NumericValueExpressionBaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::NumericValueExpressionBaseContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::NumericValueExpressionBaseContext::getRuleIndex() const {
  return GQLParser::RuleNumericValueExpressionBase;
}




//----------------- NumericValueExpressionExponentContext ------------------------------------------------------------------

GQLParser::NumericValueExpressionExponentContext::NumericValueExpressionExponentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::NumericValueExpressionExponentContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::NumericValueExpressionExponentContext::getRuleIndex() const {
  return GQLParser::RuleNumericValueExpressionExponent;
}




//----------------- SquareRootContext ------------------------------------------------------------------

GQLParser::SquareRootContext::SquareRootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::SquareRootContext::SQRT() {
  return getToken(GQLParser::SQRT, 0);
}

tree::TerminalNode* GQLParser::SquareRootContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::SquareRootContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::SquareRootContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::SquareRootContext::getRuleIndex() const {
  return GQLParser::RuleSquareRoot;
}




//----------------- FloorFunctionContext ------------------------------------------------------------------

GQLParser::FloorFunctionContext::FloorFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::FloorFunctionContext::FLOOR() {
  return getToken(GQLParser::FLOOR, 0);
}

tree::TerminalNode* GQLParser::FloorFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::FloorFunctionContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::FloorFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::FloorFunctionContext::getRuleIndex() const {
  return GQLParser::RuleFloorFunction;
}




//----------------- CeilingFunctionContext ------------------------------------------------------------------

GQLParser::CeilingFunctionContext::CeilingFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CeilingFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::NumericValueExpressionContext* GQLParser::CeilingFunctionContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}

tree::TerminalNode* GQLParser::CeilingFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* GQLParser::CeilingFunctionContext::CEIL() {
  return getToken(GQLParser::CEIL, 0);
}

tree::TerminalNode* GQLParser::CeilingFunctionContext::CEILING() {
  return getToken(GQLParser::CEILING, 0);
}


size_t GQLParser::CeilingFunctionContext::getRuleIndex() const {
  return GQLParser::RuleCeilingFunction;
}




//----------------- CharacterStringValueExpressionContext ------------------------------------------------------------------

GQLParser::CharacterStringValueExpressionContext::CharacterStringValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::CharacterStringValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::CharacterStringValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleCharacterStringValueExpression;
}




//----------------- ByteStringValueExpressionContext ------------------------------------------------------------------

GQLParser::ByteStringValueExpressionContext::ByteStringValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::ByteStringValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::ByteStringValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleByteStringValueExpression;
}




//----------------- TrimOperandsContext ------------------------------------------------------------------

GQLParser::TrimOperandsContext::TrimOperandsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::TrimCharacterOrByteStringSourceContext* GQLParser::TrimOperandsContext::trimCharacterOrByteStringSource() {
  return getRuleContext<GQLParser::TrimCharacterOrByteStringSourceContext>(0);
}

tree::TerminalNode* GQLParser::TrimOperandsContext::FROM() {
  return getToken(GQLParser::FROM, 0);
}

GQLParser::TrimSpecificationContext* GQLParser::TrimOperandsContext::trimSpecification() {
  return getRuleContext<GQLParser::TrimSpecificationContext>(0);
}

GQLParser::TrimCharacterOrByteStringContext* GQLParser::TrimOperandsContext::trimCharacterOrByteString() {
  return getRuleContext<GQLParser::TrimCharacterOrByteStringContext>(0);
}


size_t GQLParser::TrimOperandsContext::getRuleIndex() const {
  return GQLParser::RuleTrimOperands;
}




//----------------- TrimCharacterOrByteStringSourceContext ------------------------------------------------------------------

GQLParser::TrimCharacterOrByteStringSourceContext::TrimCharacterOrByteStringSourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::TrimCharacterOrByteStringSourceContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::TrimCharacterOrByteStringSourceContext::getRuleIndex() const {
  return GQLParser::RuleTrimCharacterOrByteStringSource;
}




//----------------- TrimSpecificationContext ------------------------------------------------------------------

GQLParser::TrimSpecificationContext::TrimSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TrimSpecificationContext::LEADING() {
  return getToken(GQLParser::LEADING, 0);
}

tree::TerminalNode* GQLParser::TrimSpecificationContext::TRAILING() {
  return getToken(GQLParser::TRAILING, 0);
}

tree::TerminalNode* GQLParser::TrimSpecificationContext::BOTH() {
  return getToken(GQLParser::BOTH, 0);
}


size_t GQLParser::TrimSpecificationContext::getRuleIndex() const {
  return GQLParser::RuleTrimSpecification;
}




//----------------- TrimCharacterOrByteStringContext ------------------------------------------------------------------

GQLParser::TrimCharacterOrByteStringContext::TrimCharacterOrByteStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::TrimCharacterOrByteStringContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::TrimCharacterOrByteStringContext::getRuleIndex() const {
  return GQLParser::RuleTrimCharacterOrByteString;
}




//----------------- NormalFormContext ------------------------------------------------------------------

GQLParser::NormalFormContext::NormalFormContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NormalFormContext::NFC() {
  return getToken(GQLParser::NFC, 0);
}

tree::TerminalNode* GQLParser::NormalFormContext::NFD() {
  return getToken(GQLParser::NFD, 0);
}

tree::TerminalNode* GQLParser::NormalFormContext::NFKC() {
  return getToken(GQLParser::NFKC, 0);
}

tree::TerminalNode* GQLParser::NormalFormContext::NFKD() {
  return getToken(GQLParser::NFKD, 0);
}


size_t GQLParser::NormalFormContext::getRuleIndex() const {
  return GQLParser::RuleNormalForm;
}




//----------------- StringLengthContext ------------------------------------------------------------------

GQLParser::StringLengthContext::StringLengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::NumericValueExpressionContext* GQLParser::StringLengthContext::numericValueExpression() {
  return getRuleContext<GQLParser::NumericValueExpressionContext>(0);
}


size_t GQLParser::StringLengthContext::getRuleIndex() const {
  return GQLParser::RuleStringLength;
}




//----------------- DatetimeValueExpressionContext ------------------------------------------------------------------

GQLParser::DatetimeValueExpressionContext::DatetimeValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::DatetimeValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::DatetimeValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeValueExpression;
}




//----------------- DatetimeValueFunctionContext ------------------------------------------------------------------

GQLParser::DatetimeValueFunctionContext::DatetimeValueFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DateFunctionContext* GQLParser::DatetimeValueFunctionContext::dateFunction() {
  return getRuleContext<GQLParser::DateFunctionContext>(0);
}

GQLParser::TimeFunctionContext* GQLParser::DatetimeValueFunctionContext::timeFunction() {
  return getRuleContext<GQLParser::TimeFunctionContext>(0);
}

GQLParser::DatetimeFunctionContext* GQLParser::DatetimeValueFunctionContext::datetimeFunction() {
  return getRuleContext<GQLParser::DatetimeFunctionContext>(0);
}

GQLParser::LocaltimeFunctionContext* GQLParser::DatetimeValueFunctionContext::localtimeFunction() {
  return getRuleContext<GQLParser::LocaltimeFunctionContext>(0);
}

GQLParser::LocaldatetimeFunctionContext* GQLParser::DatetimeValueFunctionContext::localdatetimeFunction() {
  return getRuleContext<GQLParser::LocaldatetimeFunctionContext>(0);
}


size_t GQLParser::DatetimeValueFunctionContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeValueFunction;
}




//----------------- DateFunctionContext ------------------------------------------------------------------

GQLParser::DateFunctionContext::DateFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DateFunctionContext::CURRENT_DATE() {
  return getToken(GQLParser::CURRENT_DATE, 0);
}

tree::TerminalNode* GQLParser::DateFunctionContext::DATE() {
  return getToken(GQLParser::DATE, 0);
}

tree::TerminalNode* GQLParser::DateFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::DateFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::DateFunctionParametersContext* GQLParser::DateFunctionContext::dateFunctionParameters() {
  return getRuleContext<GQLParser::DateFunctionParametersContext>(0);
}


size_t GQLParser::DateFunctionContext::getRuleIndex() const {
  return GQLParser::RuleDateFunction;
}




//----------------- TimeFunctionContext ------------------------------------------------------------------

GQLParser::TimeFunctionContext::TimeFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TimeFunctionContext::CURRENT_TIME() {
  return getToken(GQLParser::CURRENT_TIME, 0);
}

tree::TerminalNode* GQLParser::TimeFunctionContext::ZONED_TIME() {
  return getToken(GQLParser::ZONED_TIME, 0);
}

tree::TerminalNode* GQLParser::TimeFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::TimeFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::TimeFunctionParametersContext* GQLParser::TimeFunctionContext::timeFunctionParameters() {
  return getRuleContext<GQLParser::TimeFunctionParametersContext>(0);
}


size_t GQLParser::TimeFunctionContext::getRuleIndex() const {
  return GQLParser::RuleTimeFunction;
}




//----------------- LocaltimeFunctionContext ------------------------------------------------------------------

GQLParser::LocaltimeFunctionContext::LocaltimeFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LocaltimeFunctionContext::LOCAL_TIME() {
  return getToken(GQLParser::LOCAL_TIME, 0);
}

tree::TerminalNode* GQLParser::LocaltimeFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::LocaltimeFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::TimeFunctionParametersContext* GQLParser::LocaltimeFunctionContext::timeFunctionParameters() {
  return getRuleContext<GQLParser::TimeFunctionParametersContext>(0);
}


size_t GQLParser::LocaltimeFunctionContext::getRuleIndex() const {
  return GQLParser::RuleLocaltimeFunction;
}




//----------------- DatetimeFunctionContext ------------------------------------------------------------------

GQLParser::DatetimeFunctionContext::DatetimeFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DatetimeFunctionContext::CURRENT_TIMESTAMP() {
  return getToken(GQLParser::CURRENT_TIMESTAMP, 0);
}

tree::TerminalNode* GQLParser::DatetimeFunctionContext::ZONED_DATETIME() {
  return getToken(GQLParser::ZONED_DATETIME, 0);
}

tree::TerminalNode* GQLParser::DatetimeFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::DatetimeFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::DatetimeFunctionParametersContext* GQLParser::DatetimeFunctionContext::datetimeFunctionParameters() {
  return getRuleContext<GQLParser::DatetimeFunctionParametersContext>(0);
}


size_t GQLParser::DatetimeFunctionContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeFunction;
}




//----------------- LocaldatetimeFunctionContext ------------------------------------------------------------------

GQLParser::LocaldatetimeFunctionContext::LocaldatetimeFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::LocaldatetimeFunctionContext::LOCAL_TIMESTAMP() {
  return getToken(GQLParser::LOCAL_TIMESTAMP, 0);
}

tree::TerminalNode* GQLParser::LocaldatetimeFunctionContext::LOCAL_DATETIME() {
  return getToken(GQLParser::LOCAL_DATETIME, 0);
}

tree::TerminalNode* GQLParser::LocaldatetimeFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

tree::TerminalNode* GQLParser::LocaldatetimeFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::DatetimeFunctionParametersContext* GQLParser::LocaldatetimeFunctionContext::datetimeFunctionParameters() {
  return getRuleContext<GQLParser::DatetimeFunctionParametersContext>(0);
}


size_t GQLParser::LocaldatetimeFunctionContext::getRuleIndex() const {
  return GQLParser::RuleLocaldatetimeFunction;
}




//----------------- DateFunctionParametersContext ------------------------------------------------------------------

GQLParser::DateFunctionParametersContext::DateFunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DateStringContext* GQLParser::DateFunctionParametersContext::dateString() {
  return getRuleContext<GQLParser::DateStringContext>(0);
}

GQLParser::RecordConstructorContext* GQLParser::DateFunctionParametersContext::recordConstructor() {
  return getRuleContext<GQLParser::RecordConstructorContext>(0);
}


size_t GQLParser::DateFunctionParametersContext::getRuleIndex() const {
  return GQLParser::RuleDateFunctionParameters;
}




//----------------- TimeFunctionParametersContext ------------------------------------------------------------------

GQLParser::TimeFunctionParametersContext::TimeFunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::TimeStringContext* GQLParser::TimeFunctionParametersContext::timeString() {
  return getRuleContext<GQLParser::TimeStringContext>(0);
}

GQLParser::RecordConstructorContext* GQLParser::TimeFunctionParametersContext::recordConstructor() {
  return getRuleContext<GQLParser::RecordConstructorContext>(0);
}


size_t GQLParser::TimeFunctionParametersContext::getRuleIndex() const {
  return GQLParser::RuleTimeFunctionParameters;
}




//----------------- DatetimeFunctionParametersContext ------------------------------------------------------------------

GQLParser::DatetimeFunctionParametersContext::DatetimeFunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DatetimeStringContext* GQLParser::DatetimeFunctionParametersContext::datetimeString() {
  return getRuleContext<GQLParser::DatetimeStringContext>(0);
}

GQLParser::RecordConstructorContext* GQLParser::DatetimeFunctionParametersContext::recordConstructor() {
  return getRuleContext<GQLParser::RecordConstructorContext>(0);
}


size_t GQLParser::DatetimeFunctionParametersContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeFunctionParameters;
}




//----------------- DurationValueExpressionContext ------------------------------------------------------------------

GQLParser::DurationValueExpressionContext::DurationValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ValueExpressionContext* GQLParser::DurationValueExpressionContext::valueExpression() {
  return getRuleContext<GQLParser::ValueExpressionContext>(0);
}


size_t GQLParser::DurationValueExpressionContext::getRuleIndex() const {
  return GQLParser::RuleDurationValueExpression;
}




//----------------- DatetimeSubtractionContext ------------------------------------------------------------------

GQLParser::DatetimeSubtractionContext::DatetimeSubtractionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DatetimeSubtractionContext::DURATION_BETWEEN() {
  return getToken(GQLParser::DURATION_BETWEEN, 0);
}

tree::TerminalNode* GQLParser::DatetimeSubtractionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::DatetimeSubtractionParametersContext* GQLParser::DatetimeSubtractionContext::datetimeSubtractionParameters() {
  return getRuleContext<GQLParser::DatetimeSubtractionParametersContext>(0);
}

tree::TerminalNode* GQLParser::DatetimeSubtractionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}

GQLParser::TemporalDurationQualifierContext* GQLParser::DatetimeSubtractionContext::temporalDurationQualifier() {
  return getRuleContext<GQLParser::TemporalDurationQualifierContext>(0);
}


size_t GQLParser::DatetimeSubtractionContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeSubtraction;
}




//----------------- DatetimeSubtractionParametersContext ------------------------------------------------------------------

GQLParser::DatetimeSubtractionParametersContext::DatetimeSubtractionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DatetimeValueExpression1Context* GQLParser::DatetimeSubtractionParametersContext::datetimeValueExpression1() {
  return getRuleContext<GQLParser::DatetimeValueExpression1Context>(0);
}

tree::TerminalNode* GQLParser::DatetimeSubtractionParametersContext::COMMA() {
  return getToken(GQLParser::COMMA, 0);
}

GQLParser::DatetimeValueExpression2Context* GQLParser::DatetimeSubtractionParametersContext::datetimeValueExpression2() {
  return getRuleContext<GQLParser::DatetimeValueExpression2Context>(0);
}


size_t GQLParser::DatetimeSubtractionParametersContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeSubtractionParameters;
}




//----------------- DatetimeValueExpression1Context ------------------------------------------------------------------

GQLParser::DatetimeValueExpression1Context::DatetimeValueExpression1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DatetimeValueExpressionContext* GQLParser::DatetimeValueExpression1Context::datetimeValueExpression() {
  return getRuleContext<GQLParser::DatetimeValueExpressionContext>(0);
}


size_t GQLParser::DatetimeValueExpression1Context::getRuleIndex() const {
  return GQLParser::RuleDatetimeValueExpression1;
}




//----------------- DatetimeValueExpression2Context ------------------------------------------------------------------

GQLParser::DatetimeValueExpression2Context::DatetimeValueExpression2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DatetimeValueExpressionContext* GQLParser::DatetimeValueExpression2Context::datetimeValueExpression() {
  return getRuleContext<GQLParser::DatetimeValueExpressionContext>(0);
}


size_t GQLParser::DatetimeValueExpression2Context::getRuleIndex() const {
  return GQLParser::RuleDatetimeValueExpression2;
}




//----------------- DurationValueFunctionContext ------------------------------------------------------------------

GQLParser::DurationValueFunctionContext::DurationValueFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DurationFunctionContext* GQLParser::DurationValueFunctionContext::durationFunction() {
  return getRuleContext<GQLParser::DurationFunctionContext>(0);
}

GQLParser::AbsoluteValueExpressionContext* GQLParser::DurationValueFunctionContext::absoluteValueExpression() {
  return getRuleContext<GQLParser::AbsoluteValueExpressionContext>(0);
}


size_t GQLParser::DurationValueFunctionContext::getRuleIndex() const {
  return GQLParser::RuleDurationValueFunction;
}




//----------------- DurationFunctionContext ------------------------------------------------------------------

GQLParser::DurationFunctionContext::DurationFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DurationFunctionContext::DURATION() {
  return getToken(GQLParser::DURATION, 0);
}

tree::TerminalNode* GQLParser::DurationFunctionContext::LEFT_PAREN() {
  return getToken(GQLParser::LEFT_PAREN, 0);
}

GQLParser::DurationFunctionParametersContext* GQLParser::DurationFunctionContext::durationFunctionParameters() {
  return getRuleContext<GQLParser::DurationFunctionParametersContext>(0);
}

tree::TerminalNode* GQLParser::DurationFunctionContext::RIGHT_PAREN() {
  return getToken(GQLParser::RIGHT_PAREN, 0);
}


size_t GQLParser::DurationFunctionContext::getRuleIndex() const {
  return GQLParser::RuleDurationFunction;
}




//----------------- DurationFunctionParametersContext ------------------------------------------------------------------

GQLParser::DurationFunctionParametersContext::DurationFunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DurationStringContext* GQLParser::DurationFunctionParametersContext::durationString() {
  return getRuleContext<GQLParser::DurationStringContext>(0);
}

GQLParser::RecordConstructorContext* GQLParser::DurationFunctionParametersContext::recordConstructor() {
  return getRuleContext<GQLParser::RecordConstructorContext>(0);
}


size_t GQLParser::DurationFunctionParametersContext::getRuleIndex() const {
  return GQLParser::RuleDurationFunctionParameters;
}




//----------------- ObjectNameContext ------------------------------------------------------------------

GQLParser::ObjectNameContext::ObjectNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::ObjectNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::ObjectNameContext::getRuleIndex() const {
  return GQLParser::RuleObjectName;
}




//----------------- ObjectNameOrBindingVariableContext ------------------------------------------------------------------

GQLParser::ObjectNameOrBindingVariableContext::ObjectNameOrBindingVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::ObjectNameOrBindingVariableContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}


size_t GQLParser::ObjectNameOrBindingVariableContext::getRuleIndex() const {
  return GQLParser::RuleObjectNameOrBindingVariable;
}




//----------------- DirectoryNameContext ------------------------------------------------------------------

GQLParser::DirectoryNameContext::DirectoryNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::DirectoryNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::DirectoryNameContext::getRuleIndex() const {
  return GQLParser::RuleDirectoryName;
}




//----------------- SchemaNameContext ------------------------------------------------------------------

GQLParser::SchemaNameContext::SchemaNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::SchemaNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::SchemaNameContext::getRuleIndex() const {
  return GQLParser::RuleSchemaName;
}




//----------------- GraphNameContext ------------------------------------------------------------------

GQLParser::GraphNameContext::GraphNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::GraphNameContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}

GQLParser::DelimitedGraphNameContext* GQLParser::GraphNameContext::delimitedGraphName() {
  return getRuleContext<GQLParser::DelimitedGraphNameContext>(0);
}


size_t GQLParser::GraphNameContext::getRuleIndex() const {
  return GQLParser::RuleGraphName;
}




//----------------- DelimitedGraphNameContext ------------------------------------------------------------------

GQLParser::DelimitedGraphNameContext::DelimitedGraphNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DelimitedGraphNameContext::DOUBLE_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::DOUBLE_QUOTED_CHARACTER_SEQUENCE, 0);
}

tree::TerminalNode* GQLParser::DelimitedGraphNameContext::ACCENT_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::ACCENT_QUOTED_CHARACTER_SEQUENCE, 0);
}


size_t GQLParser::DelimitedGraphNameContext::getRuleIndex() const {
  return GQLParser::RuleDelimitedGraphName;
}




//----------------- GraphTypeNameContext ------------------------------------------------------------------

GQLParser::GraphTypeNameContext::GraphTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::GraphTypeNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::GraphTypeNameContext::getRuleIndex() const {
  return GQLParser::RuleGraphTypeName;
}




//----------------- NodeTypeNameContext ------------------------------------------------------------------

GQLParser::NodeTypeNameContext::NodeTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::NodeTypeNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::NodeTypeNameContext::getRuleIndex() const {
  return GQLParser::RuleNodeTypeName;
}




//----------------- EdgeTypeNameContext ------------------------------------------------------------------

GQLParser::EdgeTypeNameContext::EdgeTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::EdgeTypeNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::EdgeTypeNameContext::getRuleIndex() const {
  return GQLParser::RuleEdgeTypeName;
}




//----------------- BindingTableNameContext ------------------------------------------------------------------

GQLParser::BindingTableNameContext::BindingTableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::BindingTableNameContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}

GQLParser::DelimitedBindingTableNameContext* GQLParser::BindingTableNameContext::delimitedBindingTableName() {
  return getRuleContext<GQLParser::DelimitedBindingTableNameContext>(0);
}


size_t GQLParser::BindingTableNameContext::getRuleIndex() const {
  return GQLParser::RuleBindingTableName;
}




//----------------- DelimitedBindingTableNameContext ------------------------------------------------------------------

GQLParser::DelimitedBindingTableNameContext::DelimitedBindingTableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DelimitedBindingTableNameContext::DOUBLE_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::DOUBLE_QUOTED_CHARACTER_SEQUENCE, 0);
}

tree::TerminalNode* GQLParser::DelimitedBindingTableNameContext::ACCENT_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::ACCENT_QUOTED_CHARACTER_SEQUENCE, 0);
}


size_t GQLParser::DelimitedBindingTableNameContext::getRuleIndex() const {
  return GQLParser::RuleDelimitedBindingTableName;
}




//----------------- ProcedureNameContext ------------------------------------------------------------------

GQLParser::ProcedureNameContext::ProcedureNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::ProcedureNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::ProcedureNameContext::getRuleIndex() const {
  return GQLParser::RuleProcedureName;
}




//----------------- LabelNameContext ------------------------------------------------------------------

GQLParser::LabelNameContext::LabelNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::LabelNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::LabelNameContext::getRuleIndex() const {
  return GQLParser::RuleLabelName;
}




//----------------- PropertyNameContext ------------------------------------------------------------------

GQLParser::PropertyNameContext::PropertyNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::PropertyNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::PropertyNameContext::getRuleIndex() const {
  return GQLParser::RulePropertyName;
}




//----------------- FieldNameContext ------------------------------------------------------------------

GQLParser::FieldNameContext::FieldNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::IdentifierContext* GQLParser::FieldNameContext::identifier() {
  return getRuleContext<GQLParser::IdentifierContext>(0);
}


size_t GQLParser::FieldNameContext::getRuleIndex() const {
  return GQLParser::RuleFieldName;
}




//----------------- ElementVariableContext ------------------------------------------------------------------

GQLParser::ElementVariableContext::ElementVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableContext* GQLParser::ElementVariableContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}


size_t GQLParser::ElementVariableContext::getRuleIndex() const {
  return GQLParser::RuleElementVariable;
}




//----------------- PathVariableContext ------------------------------------------------------------------

GQLParser::PathVariableContext::PathVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::BindingVariableContext* GQLParser::PathVariableContext::bindingVariable() {
  return getRuleContext<GQLParser::BindingVariableContext>(0);
}


size_t GQLParser::PathVariableContext::getRuleIndex() const {
  return GQLParser::RulePathVariable;
}




//----------------- SubpathVariableContext ------------------------------------------------------------------

GQLParser::SubpathVariableContext::SubpathVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::SubpathVariableContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}


size_t GQLParser::SubpathVariableContext::getRuleIndex() const {
  return GQLParser::RuleSubpathVariable;
}




//----------------- BindingVariableContext ------------------------------------------------------------------

GQLParser::BindingVariableContext::BindingVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::BindingVariableContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}


size_t GQLParser::BindingVariableContext::getRuleIndex() const {
  return GQLParser::RuleBindingVariable;
}




//----------------- UnsignedLiteralContext ------------------------------------------------------------------

GQLParser::UnsignedLiteralContext::UnsignedLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::UnsignedNumericLiteralContext* GQLParser::UnsignedLiteralContext::unsignedNumericLiteral() {
  return getRuleContext<GQLParser::UnsignedNumericLiteralContext>(0);
}

GQLParser::GeneralLiteralContext* GQLParser::UnsignedLiteralContext::generalLiteral() {
  return getRuleContext<GQLParser::GeneralLiteralContext>(0);
}


size_t GQLParser::UnsignedLiteralContext::getRuleIndex() const {
  return GQLParser::RuleUnsignedLiteral;
}




//----------------- GeneralLiteralContext ------------------------------------------------------------------

GQLParser::GeneralLiteralContext::GeneralLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::GeneralLiteralContext::BOOLEAN_LITERAL() {
  return getToken(GQLParser::BOOLEAN_LITERAL, 0);
}

GQLParser::CharacterStringLiteralContext* GQLParser::GeneralLiteralContext::characterStringLiteral() {
  return getRuleContext<GQLParser::CharacterStringLiteralContext>(0);
}

tree::TerminalNode* GQLParser::GeneralLiteralContext::BYTE_STRING_LITERAL() {
  return getToken(GQLParser::BYTE_STRING_LITERAL, 0);
}

GQLParser::TemporalLiteralContext* GQLParser::GeneralLiteralContext::temporalLiteral() {
  return getRuleContext<GQLParser::TemporalLiteralContext>(0);
}

GQLParser::DurationLiteralContext* GQLParser::GeneralLiteralContext::durationLiteral() {
  return getRuleContext<GQLParser::DurationLiteralContext>(0);
}

GQLParser::NullLiteralContext* GQLParser::GeneralLiteralContext::nullLiteral() {
  return getRuleContext<GQLParser::NullLiteralContext>(0);
}

GQLParser::ListLiteralContext* GQLParser::GeneralLiteralContext::listLiteral() {
  return getRuleContext<GQLParser::ListLiteralContext>(0);
}

GQLParser::RecordLiteralContext* GQLParser::GeneralLiteralContext::recordLiteral() {
  return getRuleContext<GQLParser::RecordLiteralContext>(0);
}


size_t GQLParser::GeneralLiteralContext::getRuleIndex() const {
  return GQLParser::RuleGeneralLiteral;
}




//----------------- TemporalLiteralContext ------------------------------------------------------------------

GQLParser::TemporalLiteralContext::TemporalLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DateLiteralContext* GQLParser::TemporalLiteralContext::dateLiteral() {
  return getRuleContext<GQLParser::DateLiteralContext>(0);
}

GQLParser::TimeLiteralContext* GQLParser::TemporalLiteralContext::timeLiteral() {
  return getRuleContext<GQLParser::TimeLiteralContext>(0);
}

GQLParser::DatetimeLiteralContext* GQLParser::TemporalLiteralContext::datetimeLiteral() {
  return getRuleContext<GQLParser::DatetimeLiteralContext>(0);
}


size_t GQLParser::TemporalLiteralContext::getRuleIndex() const {
  return GQLParser::RuleTemporalLiteral;
}




//----------------- DateLiteralContext ------------------------------------------------------------------

GQLParser::DateLiteralContext::DateLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DateLiteralContext::DATE() {
  return getToken(GQLParser::DATE, 0);
}

GQLParser::DateStringContext* GQLParser::DateLiteralContext::dateString() {
  return getRuleContext<GQLParser::DateStringContext>(0);
}


size_t GQLParser::DateLiteralContext::getRuleIndex() const {
  return GQLParser::RuleDateLiteral;
}




//----------------- TimeLiteralContext ------------------------------------------------------------------

GQLParser::TimeLiteralContext::TimeLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::TimeLiteralContext::TIME() {
  return getToken(GQLParser::TIME, 0);
}

GQLParser::TimeStringContext* GQLParser::TimeLiteralContext::timeString() {
  return getRuleContext<GQLParser::TimeStringContext>(0);
}


size_t GQLParser::TimeLiteralContext::getRuleIndex() const {
  return GQLParser::RuleTimeLiteral;
}




//----------------- DatetimeLiteralContext ------------------------------------------------------------------

GQLParser::DatetimeLiteralContext::DatetimeLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::DatetimeStringContext* GQLParser::DatetimeLiteralContext::datetimeString() {
  return getRuleContext<GQLParser::DatetimeStringContext>(0);
}

tree::TerminalNode* GQLParser::DatetimeLiteralContext::DATETIME() {
  return getToken(GQLParser::DATETIME, 0);
}

tree::TerminalNode* GQLParser::DatetimeLiteralContext::TIMESTAMP() {
  return getToken(GQLParser::TIMESTAMP, 0);
}


size_t GQLParser::DatetimeLiteralContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeLiteral;
}




//----------------- ListLiteralContext ------------------------------------------------------------------

GQLParser::ListLiteralContext::ListLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ListValueConstructorByEnumerationContext* GQLParser::ListLiteralContext::listValueConstructorByEnumeration() {
  return getRuleContext<GQLParser::ListValueConstructorByEnumerationContext>(0);
}


size_t GQLParser::ListLiteralContext::getRuleIndex() const {
  return GQLParser::RuleListLiteral;
}




//----------------- RecordLiteralContext ------------------------------------------------------------------

GQLParser::RecordLiteralContext::RecordLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RecordConstructorContext* GQLParser::RecordLiteralContext::recordConstructor() {
  return getRuleContext<GQLParser::RecordConstructorContext>(0);
}


size_t GQLParser::RecordLiteralContext::getRuleIndex() const {
  return GQLParser::RuleRecordLiteral;
}




//----------------- IdentifierContext ------------------------------------------------------------------

GQLParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::RegularIdentifierContext* GQLParser::IdentifierContext::regularIdentifier() {
  return getRuleContext<GQLParser::RegularIdentifierContext>(0);
}

tree::TerminalNode* GQLParser::IdentifierContext::DOUBLE_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::DOUBLE_QUOTED_CHARACTER_SEQUENCE, 0);
}

tree::TerminalNode* GQLParser::IdentifierContext::ACCENT_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::ACCENT_QUOTED_CHARACTER_SEQUENCE, 0);
}


size_t GQLParser::IdentifierContext::getRuleIndex() const {
  return GQLParser::RuleIdentifier;
}




//----------------- RegularIdentifierContext ------------------------------------------------------------------

GQLParser::RegularIdentifierContext::RegularIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::RegularIdentifierContext::REGULAR_IDENTIFIER() {
  return getToken(GQLParser::REGULAR_IDENTIFIER, 0);
}

GQLParser::NonReservedWordsContext* GQLParser::RegularIdentifierContext::nonReservedWords() {
  return getRuleContext<GQLParser::NonReservedWordsContext>(0);
}


size_t GQLParser::RegularIdentifierContext::getRuleIndex() const {
  return GQLParser::RuleRegularIdentifier;
}




//----------------- TimeZoneStringContext ------------------------------------------------------------------

GQLParser::TimeZoneStringContext::TimeZoneStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CharacterStringLiteralContext* GQLParser::TimeZoneStringContext::characterStringLiteral() {
  return getRuleContext<GQLParser::CharacterStringLiteralContext>(0);
}


size_t GQLParser::TimeZoneStringContext::getRuleIndex() const {
  return GQLParser::RuleTimeZoneString;
}




//----------------- CharacterStringLiteralContext ------------------------------------------------------------------

GQLParser::CharacterStringLiteralContext::CharacterStringLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::CharacterStringLiteralContext::SINGLE_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::SINGLE_QUOTED_CHARACTER_SEQUENCE, 0);
}

tree::TerminalNode* GQLParser::CharacterStringLiteralContext::DOUBLE_QUOTED_CHARACTER_SEQUENCE() {
  return getToken(GQLParser::DOUBLE_QUOTED_CHARACTER_SEQUENCE, 0);
}


size_t GQLParser::CharacterStringLiteralContext::getRuleIndex() const {
  return GQLParser::RuleCharacterStringLiteral;
}




//----------------- UnsignedNumericLiteralContext ------------------------------------------------------------------

GQLParser::UnsignedNumericLiteralContext::UnsignedNumericLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::ExactNumericLiteralContext* GQLParser::UnsignedNumericLiteralContext::exactNumericLiteral() {
  return getRuleContext<GQLParser::ExactNumericLiteralContext>(0);
}

GQLParser::ApproximateNumericLiteralContext* GQLParser::UnsignedNumericLiteralContext::approximateNumericLiteral() {
  return getRuleContext<GQLParser::ApproximateNumericLiteralContext>(0);
}


size_t GQLParser::UnsignedNumericLiteralContext::getRuleIndex() const {
  return GQLParser::RuleUnsignedNumericLiteral;
}




//----------------- ExactNumericLiteralContext ------------------------------------------------------------------

GQLParser::ExactNumericLiteralContext::ExactNumericLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ExactNumericLiteralContext::UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX, 0);
}

tree::TerminalNode* GQLParser::ExactNumericLiteralContext::UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX, 0);
}

tree::TerminalNode* GQLParser::ExactNumericLiteralContext::UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX, 0);
}

tree::TerminalNode* GQLParser::ExactNumericLiteralContext::UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX, 0);
}

GQLParser::UnsignedIntegerContext* GQLParser::ExactNumericLiteralContext::unsignedInteger() {
  return getRuleContext<GQLParser::UnsignedIntegerContext>(0);
}


size_t GQLParser::ExactNumericLiteralContext::getRuleIndex() const {
  return GQLParser::RuleExactNumericLiteral;
}




//----------------- ApproximateNumericLiteralContext ------------------------------------------------------------------

GQLParser::ApproximateNumericLiteralContext::ApproximateNumericLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::ApproximateNumericLiteralContext::UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericLiteralContext::UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericLiteralContext::UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX, 0);
}

tree::TerminalNode* GQLParser::ApproximateNumericLiteralContext::UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX, 0);
}


size_t GQLParser::ApproximateNumericLiteralContext::getRuleIndex() const {
  return GQLParser::RuleApproximateNumericLiteral;
}




//----------------- UnsignedIntegerContext ------------------------------------------------------------------

GQLParser::UnsignedIntegerContext::UnsignedIntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::UnsignedIntegerContext::UNSIGNED_DECIMAL_INTEGER() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_INTEGER, 0);
}

tree::TerminalNode* GQLParser::UnsignedIntegerContext::UNSIGNED_HEXADECIMAL_INTEGER() {
  return getToken(GQLParser::UNSIGNED_HEXADECIMAL_INTEGER, 0);
}

tree::TerminalNode* GQLParser::UnsignedIntegerContext::UNSIGNED_OCTAL_INTEGER() {
  return getToken(GQLParser::UNSIGNED_OCTAL_INTEGER, 0);
}

tree::TerminalNode* GQLParser::UnsignedIntegerContext::UNSIGNED_BINARY_INTEGER() {
  return getToken(GQLParser::UNSIGNED_BINARY_INTEGER, 0);
}


size_t GQLParser::UnsignedIntegerContext::getRuleIndex() const {
  return GQLParser::RuleUnsignedInteger;
}




//----------------- UnsignedDecimalIntegerContext ------------------------------------------------------------------

GQLParser::UnsignedDecimalIntegerContext::UnsignedDecimalIntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::UnsignedDecimalIntegerContext::UNSIGNED_DECIMAL_INTEGER() {
  return getToken(GQLParser::UNSIGNED_DECIMAL_INTEGER, 0);
}


size_t GQLParser::UnsignedDecimalIntegerContext::getRuleIndex() const {
  return GQLParser::RuleUnsignedDecimalInteger;
}




//----------------- NullLiteralContext ------------------------------------------------------------------

GQLParser::NullLiteralContext::NullLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NullLiteralContext::NULL_KW() {
  return getToken(GQLParser::NULL_KW, 0);
}


size_t GQLParser::NullLiteralContext::getRuleIndex() const {
  return GQLParser::RuleNullLiteral;
}




//----------------- DateStringContext ------------------------------------------------------------------

GQLParser::DateStringContext::DateStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CharacterStringLiteralContext* GQLParser::DateStringContext::characterStringLiteral() {
  return getRuleContext<GQLParser::CharacterStringLiteralContext>(0);
}


size_t GQLParser::DateStringContext::getRuleIndex() const {
  return GQLParser::RuleDateString;
}




//----------------- TimeStringContext ------------------------------------------------------------------

GQLParser::TimeStringContext::TimeStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CharacterStringLiteralContext* GQLParser::TimeStringContext::characterStringLiteral() {
  return getRuleContext<GQLParser::CharacterStringLiteralContext>(0);
}


size_t GQLParser::TimeStringContext::getRuleIndex() const {
  return GQLParser::RuleTimeString;
}




//----------------- DatetimeStringContext ------------------------------------------------------------------

GQLParser::DatetimeStringContext::DatetimeStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CharacterStringLiteralContext* GQLParser::DatetimeStringContext::characterStringLiteral() {
  return getRuleContext<GQLParser::CharacterStringLiteralContext>(0);
}


size_t GQLParser::DatetimeStringContext::getRuleIndex() const {
  return GQLParser::RuleDatetimeString;
}




//----------------- DurationLiteralContext ------------------------------------------------------------------

GQLParser::DurationLiteralContext::DurationLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::DurationLiteralContext::DURATION() {
  return getToken(GQLParser::DURATION, 0);
}

GQLParser::DurationStringContext* GQLParser::DurationLiteralContext::durationString() {
  return getRuleContext<GQLParser::DurationStringContext>(0);
}


size_t GQLParser::DurationLiteralContext::getRuleIndex() const {
  return GQLParser::RuleDurationLiteral;
}




//----------------- DurationStringContext ------------------------------------------------------------------

GQLParser::DurationStringContext::DurationStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GQLParser::CharacterStringLiteralContext* GQLParser::DurationStringContext::characterStringLiteral() {
  return getRuleContext<GQLParser::CharacterStringLiteralContext>(0);
}


size_t GQLParser::DurationStringContext::getRuleIndex() const {
  return GQLParser::RuleDurationString;
}




//----------------- NodeSynonymContext ------------------------------------------------------------------

GQLParser::NodeSynonymContext::NodeSynonymContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NodeSynonymContext::NODE() {
  return getToken(GQLParser::NODE, 0);
}

tree::TerminalNode* GQLParser::NodeSynonymContext::VERTEX() {
  return getToken(GQLParser::VERTEX, 0);
}


size_t GQLParser::NodeSynonymContext::getRuleIndex() const {
  return GQLParser::RuleNodeSynonym;
}




//----------------- EdgesSynonymContext ------------------------------------------------------------------

GQLParser::EdgesSynonymContext::EdgesSynonymContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EdgesSynonymContext::EDGES() {
  return getToken(GQLParser::EDGES, 0);
}

tree::TerminalNode* GQLParser::EdgesSynonymContext::RELATIONSHIPS() {
  return getToken(GQLParser::RELATIONSHIPS, 0);
}


size_t GQLParser::EdgesSynonymContext::getRuleIndex() const {
  return GQLParser::RuleEdgesSynonym;
}




//----------------- EdgeSynonymContext ------------------------------------------------------------------

GQLParser::EdgeSynonymContext::EdgeSynonymContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::EdgeSynonymContext::EDGE() {
  return getToken(GQLParser::EDGE, 0);
}

tree::TerminalNode* GQLParser::EdgeSynonymContext::RELATIONSHIP() {
  return getToken(GQLParser::RELATIONSHIP, 0);
}


size_t GQLParser::EdgeSynonymContext::getRuleIndex() const {
  return GQLParser::RuleEdgeSynonym;
}




//----------------- NonReservedWordsContext ------------------------------------------------------------------

GQLParser::NonReservedWordsContext::NonReservedWordsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::ACYCLIC() {
  return getToken(GQLParser::ACYCLIC, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::BINDING() {
  return getToken(GQLParser::BINDING, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::BINDINGS() {
  return getToken(GQLParser::BINDINGS, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::CONNECTING() {
  return getToken(GQLParser::CONNECTING, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::DESTINATION() {
  return getToken(GQLParser::DESTINATION, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::DIFFERENT() {
  return getToken(GQLParser::DIFFERENT, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::DIRECTED() {
  return getToken(GQLParser::DIRECTED, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::EDGE() {
  return getToken(GQLParser::EDGE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::EDGES() {
  return getToken(GQLParser::EDGES, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::ELEMENT() {
  return getToken(GQLParser::ELEMENT, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::ELEMENTS() {
  return getToken(GQLParser::ELEMENTS, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::FIRST() {
  return getToken(GQLParser::FIRST, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::GRAPH() {
  return getToken(GQLParser::GRAPH, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::GROUPS() {
  return getToken(GQLParser::GROUPS, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::KEEP() {
  return getToken(GQLParser::KEEP, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::LABEL() {
  return getToken(GQLParser::LABEL, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::LABELED() {
  return getToken(GQLParser::LABELED, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::LABELS() {
  return getToken(GQLParser::LABELS, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::LAST() {
  return getToken(GQLParser::LAST, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::NFC() {
  return getToken(GQLParser::NFC, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::NFD() {
  return getToken(GQLParser::NFD, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::NFKC() {
  return getToken(GQLParser::NFKC, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::NFKD() {
  return getToken(GQLParser::NFKD, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::NO() {
  return getToken(GQLParser::NO, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::NODE() {
  return getToken(GQLParser::NODE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::NORMALIZED() {
  return getToken(GQLParser::NORMALIZED, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::ONLY() {
  return getToken(GQLParser::ONLY, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::ORDINALITY() {
  return getToken(GQLParser::ORDINALITY, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::PROPERTY() {
  return getToken(GQLParser::PROPERTY, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::READ() {
  return getToken(GQLParser::READ, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::RELATIONSHIP() {
  return getToken(GQLParser::RELATIONSHIP, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::RELATIONSHIPS() {
  return getToken(GQLParser::RELATIONSHIPS, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::REPEATABLE() {
  return getToken(GQLParser::REPEATABLE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::SHORTEST() {
  return getToken(GQLParser::SHORTEST, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::SIMPLE() {
  return getToken(GQLParser::SIMPLE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::SOURCE() {
  return getToken(GQLParser::SOURCE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::TABLE() {
  return getToken(GQLParser::TABLE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::TEMP() {
  return getToken(GQLParser::TEMP, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::TO() {
  return getToken(GQLParser::TO, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::TRAIL() {
  return getToken(GQLParser::TRAIL, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::TRANSACTION() {
  return getToken(GQLParser::TRANSACTION, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::TYPE() {
  return getToken(GQLParser::TYPE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::UNDIRECTED() {
  return getToken(GQLParser::UNDIRECTED, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::VERTEX() {
  return getToken(GQLParser::VERTEX, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::WALK() {
  return getToken(GQLParser::WALK, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::WITHOUT() {
  return getToken(GQLParser::WITHOUT, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::WRITE() {
  return getToken(GQLParser::WRITE, 0);
}

tree::TerminalNode* GQLParser::NonReservedWordsContext::ZONE() {
  return getToken(GQLParser::ZONE, 0);
}


size_t GQLParser::NonReservedWordsContext::getRuleIndex() const {
  return GQLParser::RuleNonReservedWords;
}




bool GQLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 92: return compositeQueryExpressionSempred(antlrcpp::downCast<CompositeQueryExpressionContext *>(context), predicateIndex);

    case 214: return labelExpressionSempred(antlrcpp::downCast<LabelExpressionContext *>(context), predicateIndex);

    case 233: return simplifiedTermSempred(antlrcpp::downCast<SimplifiedTermContext *>(context), predicateIndex);

    case 234: return simplifiedFactorLowSempred(antlrcpp::downCast<SimplifiedFactorLowContext *>(context), predicateIndex);

    case 337: return valueTypeSempred(antlrcpp::downCast<ValueTypeContext *>(context), predicateIndex);

    case 409: return valueExpressionSempred(antlrcpp::downCast<ValueExpressionContext *>(context), predicateIndex);

    case 421: return valueExpressionPrimarySempred(antlrcpp::downCast<ValueExpressionPrimaryContext *>(context), predicateIndex);

    case 476: return numericValueExpressionSempred(antlrcpp::downCast<NumericValueExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GQLParser::compositeQueryExpressionSempred(CompositeQueryExpressionContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool GQLParser::labelExpressionSempred(LabelExpressionContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool GQLParser::simplifiedTermSempred(SimplifiedTermContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool GQLParser::simplifiedFactorLowSempred(SimplifiedFactorLowContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool GQLParser::valueTypeSempred(ValueTypeContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);
    case 6: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

bool GQLParser::valueExpressionSempred(ValueExpressionContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 14);
    case 8: return precpred(_ctx, 13);
    case 9: return precpred(_ctx, 12);
    case 10: return precpred(_ctx, 11);
    case 11: return precpred(_ctx, 6);
    case 12: return precpred(_ctx, 5);
    case 13: return precpred(_ctx, 9);
    case 14: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

bool GQLParser::valueExpressionPrimarySempred(ValueExpressionPrimaryContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 15: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

bool GQLParser::numericValueExpressionSempred(NumericValueExpressionContext *_localctx, size_t predicateIndex) {
  (void)_localctx;
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 4);
    case 17: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void GQLParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  gqlParserInitialize();
#else
  ::antlr4::internal::call_once(gqlParserOnceFlag, gqlParserInitialize);
#endif
}
