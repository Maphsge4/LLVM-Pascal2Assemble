
#ifndef _PAS_SYNTAX_TREE_BUILDER_H_
#define _PAS_SYNTAX_TREE_BUILDER_H_

#include "pasrecognizer/syntax_tree.h"
#include "pasParserBaseVisitor.h"
#include <pasrecognizer/error_reporter.h>

namespace pas_recognizer
{
  namespace syntax_tree
  {
    class syntax_tree_builder : public pasParserBaseVisitor
    {
    public:
      syntax_tree_builder(error_reporter &_err);

      virtual antlrcpp::Any visitProgram(pasParser::ProgramContext *ctx) override;
      virtual antlrcpp::Any visitProgram_head(pasParser::Program_headContext *ctx) override;
      virtual antlrcpp::Any visitProgram_body(pasParser::Program_bodyContext *ctx) override;

      virtual antlrcpp::Any visitSubprogram_declaration(pasParser::Subprogram_declarationContext *ctx) override;

      virtual antlrcpp::Any visitPara_de(pasParser::Para_deContext *ctx) override;

      // Const_de
      virtual antlrcpp::Any visitConst_de(pasParser::Const_deContext *ctx) override;
      virtual antlrcpp::Any visitType_de(pasParser::Type_deContext *ctx) override;

      //

      virtual antlrcpp::Any visitVar_de(pasParser::Var_deContext *ctx) override;
      virtual antlrcpp::Any visitType(pasParser::TypeContext *ctx) override;
      virtual antlrcpp::Any visitIdentifier(pasParser::IdentifierContext *ctx) override;
      virtual antlrcpp::Any visitStandrad_type(pasParser::Standrad_typeContext *ctx) override;
      virtual antlrcpp::Any visitRecord_body(pasParser::Record_bodyContext *ctx) override;
      virtual antlrcpp::Any visitPeriod(pasParser::PeriodContext *ctx) override;
      virtual antlrcpp::Any visitConst_variable(pasParser::Const_variableContext *ctx) override;

      //  virtual antlrcpp::Any visitId_not_one(pasParser::Id_not_oneContext *ctx) override;
      //  virtual antlrcpp::Any visitId_one(pasParser::Id_oneContext *ctx) override;
      virtual antlrcpp::Any visitCompound_statement(pasParser::Compound_statementContext *ctx) override;
      virtual antlrcpp::Any visitStatement_list(pasParser::Statement_listContext *ctx) override;
      virtual antlrcpp::Any visitStatement1(pasParser::Statement1Context *ctx) override;
      virtual antlrcpp::Any visitCom(pasParser::ComContext *ctx) override;
      virtual antlrcpp::Any visitRepeat(pasParser::RepeatContext *ctx) override;

      // Call_pro_statement Call_procedure_statement
      virtual antlrcpp::Any visitCall_pro_statement(pasParser::Call_pro_statementContext *ctx) override;
      virtual antlrcpp::Any visitCall_procedure_statement(pasParser::Call_procedure_statementContext *ctx) override;
      // If_else
      virtual antlrcpp::Any visitIf_else(pasParser::If_elseContext *ctx) override;
      virtual antlrcpp::Any visitWhile(pasParser::WhileContext *ctx) override;

      virtual antlrcpp::Any visitStatement2(pasParser::Statement2Context *ctx) override;
      virtual antlrcpp::Any visitVariable(pasParser::VariableContext *ctx) override;     // Id_varpart
      virtual antlrcpp::Any visitId_varpart(pasParser::Id_varpartContext *ctx) override; // Id_varpart

      //
      virtual antlrcpp::Any visitUnsign_const_variable(pasParser::Unsign_const_variableContext *ctx) override;
      virtual antlrcpp::Any visitMulop(pasParser::MulopContext *ctx) override;
      virtual antlrcpp::Any visitAddop(pasParser::AddopContext *ctx) override;
      virtual antlrcpp::Any visitRelop(pasParser::RelopContext *ctx) override;
      virtual antlrcpp::Any visitFactor(pasParser::FactorContext *ctx) override;

      virtual antlrcpp::Any visitTerm(pasParser::TermContext *ctx) override;

      virtual antlrcpp::Any visitSimple_expression(pasParser::Simple_expressionContext *ctx) override;
      virtual antlrcpp::Any visitExpression(pasParser::ExpressionContext *ctx) override;
      virtual antlrcpp::Any visitExpression_list(pasParser::Expression_listContext *ctx) override;

      //
      virtual antlrcpp::Any visitNum(pasParser::NumContext *ctx) override;
      virtual antlrcpp::Any visitEmpty(pasParser::EmptyContext *ctx) override;
      virtual antlrcpp::Any visitDigits(pasParser::DigitsContext *ctx) override;
      //
      //

      //
      ptr<syntax_tree_node> operator()(antlr4::tree::ParseTree *ctx);

    private:
      error_reporter &err;
    };
  }
}

#endif
