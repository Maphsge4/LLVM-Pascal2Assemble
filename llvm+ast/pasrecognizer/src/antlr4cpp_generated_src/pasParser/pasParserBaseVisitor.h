
// Generated from /home/lhd/Desktop/antlr4-pas/grammar/pasParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "pasParserVisitor.h"


/**
 * This class provides an empty implementation of pasParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  pasParserBaseVisitor : public pasParserVisitor {
public:

  virtual antlrcpp::Any visitProgram(pasParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_head(pasParser::Program_headContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_body(pasParser::Program_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubprogram_declaration(pasParser::Subprogram_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPara_de(pasParser::Para_deContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_de(pasParser::Type_deContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_de(pasParser::Const_deContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_de(pasParser::Var_deContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(pasParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(pasParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStandrad_type(pasParser::Standrad_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecord_body(pasParser::Record_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPeriod(pasParser::PeriodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_variable(pasParser::Const_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_statement(pasParser::Compound_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_list(pasParser::Statement_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement1(pasParser::Statement1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCom(pasParser::ComContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall_pro_statement(pasParser::Call_pro_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_else(pasParser::If_elseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile(pasParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeat(pasParser::RepeatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement2(pasParser::Statement2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall_procedure_statement(pasParser::Call_procedure_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(pasParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId_varpart(pasParser::Id_varpartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_list(pasParser::Expression_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(pasParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_expression(pasParser::Simple_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(pasParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(pasParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsign_const_variable(pasParser::Unsign_const_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNum(pasParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmpty(pasParser::EmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDigits(pasParser::DigitsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulop(pasParser::MulopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddop(pasParser::AddopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelop(pasParser::RelopContext *ctx) override {
    return visitChildren(ctx);
  }


};

