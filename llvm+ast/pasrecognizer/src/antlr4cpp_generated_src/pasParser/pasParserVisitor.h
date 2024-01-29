
// Generated from /home/lhd/Desktop/antlr4-pas/grammar/pasParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "pasParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by pasParser.
 */
class  pasParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by pasParser.
   */
    virtual antlrcpp::Any visitProgram(pasParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgram_head(pasParser::Program_headContext *context) = 0;

    virtual antlrcpp::Any visitProgram_body(pasParser::Program_bodyContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_declaration(pasParser::Subprogram_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPara_de(pasParser::Para_deContext *context) = 0;

    virtual antlrcpp::Any visitType_de(pasParser::Type_deContext *context) = 0;

    virtual antlrcpp::Any visitConst_de(pasParser::Const_deContext *context) = 0;

    virtual antlrcpp::Any visitVar_de(pasParser::Var_deContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(pasParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitType(pasParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitStandrad_type(pasParser::Standrad_typeContext *context) = 0;

    virtual antlrcpp::Any visitRecord_body(pasParser::Record_bodyContext *context) = 0;

    virtual antlrcpp::Any visitPeriod(pasParser::PeriodContext *context) = 0;

    virtual antlrcpp::Any visitConst_variable(pasParser::Const_variableContext *context) = 0;

    virtual antlrcpp::Any visitCompound_statement(pasParser::Compound_statementContext *context) = 0;

    virtual antlrcpp::Any visitStatement_list(pasParser::Statement_listContext *context) = 0;

    virtual antlrcpp::Any visitStatement1(pasParser::Statement1Context *context) = 0;

    virtual antlrcpp::Any visitCom(pasParser::ComContext *context) = 0;

    virtual antlrcpp::Any visitCall_pro_statement(pasParser::Call_pro_statementContext *context) = 0;

    virtual antlrcpp::Any visitIf_else(pasParser::If_elseContext *context) = 0;

    virtual antlrcpp::Any visitWhile(pasParser::WhileContext *context) = 0;

    virtual antlrcpp::Any visitRepeat(pasParser::RepeatContext *context) = 0;

    virtual antlrcpp::Any visitStatement2(pasParser::Statement2Context *context) = 0;

    virtual antlrcpp::Any visitCall_procedure_statement(pasParser::Call_procedure_statementContext *context) = 0;

    virtual antlrcpp::Any visitVariable(pasParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitId_varpart(pasParser::Id_varpartContext *context) = 0;

    virtual antlrcpp::Any visitExpression_list(pasParser::Expression_listContext *context) = 0;

    virtual antlrcpp::Any visitExpression(pasParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimple_expression(pasParser::Simple_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(pasParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitFactor(pasParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitUnsign_const_variable(pasParser::Unsign_const_variableContext *context) = 0;

    virtual antlrcpp::Any visitNum(pasParser::NumContext *context) = 0;

    virtual antlrcpp::Any visitEmpty(pasParser::EmptyContext *context) = 0;

    virtual antlrcpp::Any visitDigits(pasParser::DigitsContext *context) = 0;

    virtual antlrcpp::Any visitMulop(pasParser::MulopContext *context) = 0;

    virtual antlrcpp::Any visitAddop(pasParser::AddopContext *context) = 0;

    virtual antlrcpp::Any visitRelop(pasParser::RelopContext *context) = 0;


};

