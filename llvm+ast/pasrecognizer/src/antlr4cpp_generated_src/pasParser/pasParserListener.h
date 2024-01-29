
// Generated from /home/lhd/Desktop/antlr4-pas/grammar/pasParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "pasParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by pasParser.
 */
class  pasParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(pasParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(pasParser::ProgramContext *ctx) = 0;

  virtual void enterProgram_head(pasParser::Program_headContext *ctx) = 0;
  virtual void exitProgram_head(pasParser::Program_headContext *ctx) = 0;

  virtual void enterProgram_body(pasParser::Program_bodyContext *ctx) = 0;
  virtual void exitProgram_body(pasParser::Program_bodyContext *ctx) = 0;

  virtual void enterSubprogram_declaration(pasParser::Subprogram_declarationContext *ctx) = 0;
  virtual void exitSubprogram_declaration(pasParser::Subprogram_declarationContext *ctx) = 0;

  virtual void enterPara_de(pasParser::Para_deContext *ctx) = 0;
  virtual void exitPara_de(pasParser::Para_deContext *ctx) = 0;

  virtual void enterType_de(pasParser::Type_deContext *ctx) = 0;
  virtual void exitType_de(pasParser::Type_deContext *ctx) = 0;

  virtual void enterConst_de(pasParser::Const_deContext *ctx) = 0;
  virtual void exitConst_de(pasParser::Const_deContext *ctx) = 0;

  virtual void enterVar_de(pasParser::Var_deContext *ctx) = 0;
  virtual void exitVar_de(pasParser::Var_deContext *ctx) = 0;

  virtual void enterIdentifier(pasParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(pasParser::IdentifierContext *ctx) = 0;

  virtual void enterType(pasParser::TypeContext *ctx) = 0;
  virtual void exitType(pasParser::TypeContext *ctx) = 0;

  virtual void enterStandrad_type(pasParser::Standrad_typeContext *ctx) = 0;
  virtual void exitStandrad_type(pasParser::Standrad_typeContext *ctx) = 0;

  virtual void enterRecord_body(pasParser::Record_bodyContext *ctx) = 0;
  virtual void exitRecord_body(pasParser::Record_bodyContext *ctx) = 0;

  virtual void enterPeriod(pasParser::PeriodContext *ctx) = 0;
  virtual void exitPeriod(pasParser::PeriodContext *ctx) = 0;

  virtual void enterConst_variable(pasParser::Const_variableContext *ctx) = 0;
  virtual void exitConst_variable(pasParser::Const_variableContext *ctx) = 0;

  virtual void enterCompound_statement(pasParser::Compound_statementContext *ctx) = 0;
  virtual void exitCompound_statement(pasParser::Compound_statementContext *ctx) = 0;

  virtual void enterStatement_list(pasParser::Statement_listContext *ctx) = 0;
  virtual void exitStatement_list(pasParser::Statement_listContext *ctx) = 0;

  virtual void enterStatement1(pasParser::Statement1Context *ctx) = 0;
  virtual void exitStatement1(pasParser::Statement1Context *ctx) = 0;

  virtual void enterCom(pasParser::ComContext *ctx) = 0;
  virtual void exitCom(pasParser::ComContext *ctx) = 0;

  virtual void enterCall_pro_statement(pasParser::Call_pro_statementContext *ctx) = 0;
  virtual void exitCall_pro_statement(pasParser::Call_pro_statementContext *ctx) = 0;

  virtual void enterIf_else(pasParser::If_elseContext *ctx) = 0;
  virtual void exitIf_else(pasParser::If_elseContext *ctx) = 0;

  virtual void enterWhile(pasParser::WhileContext *ctx) = 0;
  virtual void exitWhile(pasParser::WhileContext *ctx) = 0;

  virtual void enterRepeat(pasParser::RepeatContext *ctx) = 0;
  virtual void exitRepeat(pasParser::RepeatContext *ctx) = 0;

  virtual void enterStatement2(pasParser::Statement2Context *ctx) = 0;
  virtual void exitStatement2(pasParser::Statement2Context *ctx) = 0;

  virtual void enterCall_procedure_statement(pasParser::Call_procedure_statementContext *ctx) = 0;
  virtual void exitCall_procedure_statement(pasParser::Call_procedure_statementContext *ctx) = 0;

  virtual void enterVariable(pasParser::VariableContext *ctx) = 0;
  virtual void exitVariable(pasParser::VariableContext *ctx) = 0;

  virtual void enterId_varpart(pasParser::Id_varpartContext *ctx) = 0;
  virtual void exitId_varpart(pasParser::Id_varpartContext *ctx) = 0;

  virtual void enterExpression_list(pasParser::Expression_listContext *ctx) = 0;
  virtual void exitExpression_list(pasParser::Expression_listContext *ctx) = 0;

  virtual void enterExpression(pasParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(pasParser::ExpressionContext *ctx) = 0;

  virtual void enterSimple_expression(pasParser::Simple_expressionContext *ctx) = 0;
  virtual void exitSimple_expression(pasParser::Simple_expressionContext *ctx) = 0;

  virtual void enterTerm(pasParser::TermContext *ctx) = 0;
  virtual void exitTerm(pasParser::TermContext *ctx) = 0;

  virtual void enterFactor(pasParser::FactorContext *ctx) = 0;
  virtual void exitFactor(pasParser::FactorContext *ctx) = 0;

  virtual void enterUnsign_const_variable(pasParser::Unsign_const_variableContext *ctx) = 0;
  virtual void exitUnsign_const_variable(pasParser::Unsign_const_variableContext *ctx) = 0;

  virtual void enterNum(pasParser::NumContext *ctx) = 0;
  virtual void exitNum(pasParser::NumContext *ctx) = 0;

  virtual void enterEmpty(pasParser::EmptyContext *ctx) = 0;
  virtual void exitEmpty(pasParser::EmptyContext *ctx) = 0;

  virtual void enterDigits(pasParser::DigitsContext *ctx) = 0;
  virtual void exitDigits(pasParser::DigitsContext *ctx) = 0;

  virtual void enterMulop(pasParser::MulopContext *ctx) = 0;
  virtual void exitMulop(pasParser::MulopContext *ctx) = 0;

  virtual void enterAddop(pasParser::AddopContext *ctx) = 0;
  virtual void exitAddop(pasParser::AddopContext *ctx) = 0;

  virtual void enterRelop(pasParser::RelopContext *ctx) = 0;
  virtual void exitRelop(pasParser::RelopContext *ctx) = 0;


};

