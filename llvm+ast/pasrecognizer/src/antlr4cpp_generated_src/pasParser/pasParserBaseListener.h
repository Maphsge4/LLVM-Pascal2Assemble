
// Generated from /home/lhd/Desktop/antlr4-pas/grammar/pasParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "pasParserListener.h"


/**
 * This class provides an empty implementation of pasParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  pasParserBaseListener : public pasParserListener {
public:

  virtual void enterProgram(pasParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(pasParser::ProgramContext * /*ctx*/) override { }

  virtual void enterProgram_head(pasParser::Program_headContext * /*ctx*/) override { }
  virtual void exitProgram_head(pasParser::Program_headContext * /*ctx*/) override { }

  virtual void enterProgram_body(pasParser::Program_bodyContext * /*ctx*/) override { }
  virtual void exitProgram_body(pasParser::Program_bodyContext * /*ctx*/) override { }

  virtual void enterSubprogram_declaration(pasParser::Subprogram_declarationContext * /*ctx*/) override { }
  virtual void exitSubprogram_declaration(pasParser::Subprogram_declarationContext * /*ctx*/) override { }

  virtual void enterPara_de(pasParser::Para_deContext * /*ctx*/) override { }
  virtual void exitPara_de(pasParser::Para_deContext * /*ctx*/) override { }

  virtual void enterType_de(pasParser::Type_deContext * /*ctx*/) override { }
  virtual void exitType_de(pasParser::Type_deContext * /*ctx*/) override { }

  virtual void enterConst_de(pasParser::Const_deContext * /*ctx*/) override { }
  virtual void exitConst_de(pasParser::Const_deContext * /*ctx*/) override { }

  virtual void enterVar_de(pasParser::Var_deContext * /*ctx*/) override { }
  virtual void exitVar_de(pasParser::Var_deContext * /*ctx*/) override { }

  virtual void enterIdentifier(pasParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(pasParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterType(pasParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(pasParser::TypeContext * /*ctx*/) override { }

  virtual void enterStandrad_type(pasParser::Standrad_typeContext * /*ctx*/) override { }
  virtual void exitStandrad_type(pasParser::Standrad_typeContext * /*ctx*/) override { }

  virtual void enterRecord_body(pasParser::Record_bodyContext * /*ctx*/) override { }
  virtual void exitRecord_body(pasParser::Record_bodyContext * /*ctx*/) override { }

  virtual void enterPeriod(pasParser::PeriodContext * /*ctx*/) override { }
  virtual void exitPeriod(pasParser::PeriodContext * /*ctx*/) override { }

  virtual void enterConst_variable(pasParser::Const_variableContext * /*ctx*/) override { }
  virtual void exitConst_variable(pasParser::Const_variableContext * /*ctx*/) override { }

  virtual void enterCompound_statement(pasParser::Compound_statementContext * /*ctx*/) override { }
  virtual void exitCompound_statement(pasParser::Compound_statementContext * /*ctx*/) override { }

  virtual void enterStatement_list(pasParser::Statement_listContext * /*ctx*/) override { }
  virtual void exitStatement_list(pasParser::Statement_listContext * /*ctx*/) override { }

  virtual void enterStatement1(pasParser::Statement1Context * /*ctx*/) override { }
  virtual void exitStatement1(pasParser::Statement1Context * /*ctx*/) override { }

  virtual void enterCom(pasParser::ComContext * /*ctx*/) override { }
  virtual void exitCom(pasParser::ComContext * /*ctx*/) override { }

  virtual void enterCall_pro_statement(pasParser::Call_pro_statementContext * /*ctx*/) override { }
  virtual void exitCall_pro_statement(pasParser::Call_pro_statementContext * /*ctx*/) override { }

  virtual void enterIf_else(pasParser::If_elseContext * /*ctx*/) override { }
  virtual void exitIf_else(pasParser::If_elseContext * /*ctx*/) override { }

  virtual void enterWhile(pasParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(pasParser::WhileContext * /*ctx*/) override { }

  virtual void enterRepeat(pasParser::RepeatContext * /*ctx*/) override { }
  virtual void exitRepeat(pasParser::RepeatContext * /*ctx*/) override { }

  virtual void enterStatement2(pasParser::Statement2Context * /*ctx*/) override { }
  virtual void exitStatement2(pasParser::Statement2Context * /*ctx*/) override { }

  virtual void enterCall_procedure_statement(pasParser::Call_procedure_statementContext * /*ctx*/) override { }
  virtual void exitCall_procedure_statement(pasParser::Call_procedure_statementContext * /*ctx*/) override { }

  virtual void enterVariable(pasParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(pasParser::VariableContext * /*ctx*/) override { }

  virtual void enterId_varpart(pasParser::Id_varpartContext * /*ctx*/) override { }
  virtual void exitId_varpart(pasParser::Id_varpartContext * /*ctx*/) override { }

  virtual void enterExpression_list(pasParser::Expression_listContext * /*ctx*/) override { }
  virtual void exitExpression_list(pasParser::Expression_listContext * /*ctx*/) override { }

  virtual void enterExpression(pasParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(pasParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterSimple_expression(pasParser::Simple_expressionContext * /*ctx*/) override { }
  virtual void exitSimple_expression(pasParser::Simple_expressionContext * /*ctx*/) override { }

  virtual void enterTerm(pasParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(pasParser::TermContext * /*ctx*/) override { }

  virtual void enterFactor(pasParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(pasParser::FactorContext * /*ctx*/) override { }

  virtual void enterUnsign_const_variable(pasParser::Unsign_const_variableContext * /*ctx*/) override { }
  virtual void exitUnsign_const_variable(pasParser::Unsign_const_variableContext * /*ctx*/) override { }

  virtual void enterNum(pasParser::NumContext * /*ctx*/) override { }
  virtual void exitNum(pasParser::NumContext * /*ctx*/) override { }

  virtual void enterEmpty(pasParser::EmptyContext * /*ctx*/) override { }
  virtual void exitEmpty(pasParser::EmptyContext * /*ctx*/) override { }

  virtual void enterDigits(pasParser::DigitsContext * /*ctx*/) override { }
  virtual void exitDigits(pasParser::DigitsContext * /*ctx*/) override { }

  virtual void enterMulop(pasParser::MulopContext * /*ctx*/) override { }
  virtual void exitMulop(pasParser::MulopContext * /*ctx*/) override { }

  virtual void enterAddop(pasParser::AddopContext * /*ctx*/) override { }
  virtual void exitAddop(pasParser::AddopContext * /*ctx*/) override { }

  virtual void enterRelop(pasParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(pasParser::RelopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

