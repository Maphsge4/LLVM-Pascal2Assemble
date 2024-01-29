// 在整个 cpp 文件中，数十次这样调用 antlr，声明为嵌套类并利用遍历的方式来遍历输入的抽象语法树，来生成 ast，并同时生成ast 的数据结构。
#include <pasrecognizer/syntax_tree_builder.h>
#include <memory>
#include <iostream>
#include <cmath>
using namespace pas_recognizer;
using namespace pas_recognizer::syntax_tree;
using namespace std;//watch out
syntax_tree_builder::syntax_tree_builder(error_reporter &_err) : err(_err) {}

    //program_head program_body SPOT
    antlrcpp::Any syntax_tree_builder::visitProgram(pasParser::ProgramContext *ctx) 
    {
        return(visit(ctx->program_body()));
        // auto program_body=ctx->program_body();
        // return static_cast<assembly *>(visit(program_body));
        //static_cast<expr_syntax *>(result);
    }
    //PROGRAM ID LEFTPAREN identifier_list RIGHTPAREN SEMICOLON
    antlrcpp::Any syntax_tree_builder::visitProgram_head(pasParser::Program_headContext *ctx)
    {
    }
    /*


program_body
    :(CONST const_de (SEMICOLON const_de)* SEMICOLON|) (TYPE type_de (SEMICOLON type_de)* SEMICOLON|) (VAR var_de (SEMICOLON var_de)* SEMICOLON|)  ((subprogram_declaration)+ SEMICOLON|) compound_statement
    ;
subprogram_declaration
    :FUNCTION ID (LEFTPAREN (VAR)? para_de (SEMICOLON (VAR)? para_de)* RIGHTPAREN|) COLON standrad_type SEMICOLON program_body
    |PROCEDURE ID (LEFTPAREN (VAR)? para_de (SEMICOLON (VAR)? para_de)* RIGHTPAREN|) SEMICOLON program_body
    ;
para_de
    :ID (COMMA ID)* COLON standrad_type
    ;
    */
    antlrcpp::Any syntax_tree_builder::visitProgram_body(pasParser::Program_bodyContext *ctx)
    {
        auto result = new assembly;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
         for (auto def : ctx->children)//对子节点遍历
        {
          if (auto con1 =dynamic_cast<pasParser::Const_deContext *>(def))
          {
            //auto defs = visit(con1).as<ptr_list<var_def_stmt_syntax>>();
            result->global_defs.push_back(ptr<global_def_syntax>(visit(con1).as<var_def_stmt_syntax *>()));
            
            /////////////////////////////////////   
          }  
          else if (auto var1 = dynamic_cast<pasParser::Var_deContext *>(def))
          {
            auto defs = visit(var1).as<ptr_list<var_def_stmt_syntax>>();
            for (auto def : defs)
                result->global_defs.push_back(std::dynamic_pointer_cast<global_def_syntax>(def));
          }  

          else if (auto compound_statement = dynamic_cast<pasParser::Compound_statementContext *>(def))//
           result->global_defs.push_back(ptr<global_def_syntax>(visit(compound_statement).as<func_def_syntax *>()));
          else if(auto type1 =dynamic_cast<pasParser::Type_deContext *>(def))
          {
              result->global_defs.push_back(ptr<global_def_syntax>(visit(type1).as<var_def_stmt_syntax *>()));
          }else if(auto subprogram_declaration = dynamic_cast<pasParser::Subprogram_declarationContext *>(def))
          {
              result->global_defs.push_back(ptr<global_def_syntax>(visit(subprogram_declaration).as<func_def_syntax *>()));
          }

 
        }
           
        return result;
    }
// subprogram_declaration
//     :FUNCTION ID (LEFTPAREN (VAR)? para_de (SEMICOLON (VAR)? para_de)* RIGHTPAREN|) COLON standrad_type SEMICOLON BEGIN statement_list END
//     |PROCEDURE ID (LEFTPAREN (VAR)? para_de (SEMICOLON (VAR)? para_de)* RIGHTPAREN|) SEMICOLON BEGIN statement_list END
//     ;
/*
subprogram_declaration
    :FUNCTION ID (LEFTPAREN para_de (SEMICOLON para_de)* RIGHTPAREN|) COLON standrad_type SEMICOLON (VAR var_de (SEMICOLON var_de)* SEMICOLON|) BEGIN statement_list END
    |PROCEDURE ID (LEFTPAREN para_de (SEMICOLON  para_de)* RIGHTPAREN|) SEMICOLON (VAR var_de (SEMICOLON var_de)* SEMICOLON|) BEGIN statement_list END
    ;

    ptr_list<var_def_stmt_syntax>
*/
    antlrcpp::Any syntax_tree_builder::visitSubprogram_declaration(pasParser::Subprogram_declarationContext *ctx)
    {
        auto result = new func_def_syntax;
        result->name = ctx->ID()->getText();
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        // result->is_varg=false;
        // if(ctx->)
        for (auto t:ctx->para_de()){
     
            auto t2 = visit(t).as<ptr_list<para_de_syntax>>();
            for (auto t3 :t2)
                result->para_de.push_back(ptr<para_de_syntax>(t3));
     
        }
        if(ctx->standrad_type())result->ret_type=ctx->standrad_type()->getText();

        if(ctx->var_de().size()>0){
            
            for(auto t:ctx->var_de()){
                auto t2 = visit(t).as<ptr_list<var_def_stmt_syntax>>();
                for (auto t3 :t2)
                    result->local_var_de.push_back(ptr<var_def_stmt_syntax>(t3));
            }
        }
        result->body.reset(visit(ctx->statement_list()).as<stmt_syntax *>());
        return result;
    }
/*
            auto vars=visit(var_de).as<ptr_list<var_def_stmt_syntax>>();

            for (auto v : vars)
                result->var_de.push_back(ptr<var_def_stmt_syntax>(v));
*/
    
// para_de
//     :(VAR)? ID (COMMA ID)* COLON standrad_type
//     ;    
    antlrcpp::Any syntax_tree_builder::visitPara_de(pasParser::Para_deContext *ctx)
    {
        ptr_list<para_de_syntax> result;
        
        for (auto t:ctx->ID())
        {
            auto r = new para_de_syntax;
            r->line = ctx->getStart()->getLine();
            r->pos = ctx->getStart()->getCharPositionInLine();
            r->name=t->getText();
            r->type=ctx->standrad_type()->getText();
            if(ctx->VAR())r->is_varg=true;
            else{
                r->is_varg=false;
            }
            result.push_back(ptr<para_de_syntax>(r));
        }
    
        return result;
    }
    

/*
type_de
    :ID EQUAL type
    ;
*/
    antlrcpp::Any syntax_tree_builder::visitType_de(pasParser::Type_deContext *ctx)
    {
        auto result= new var_def_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        
        result->name=ctx->ID()->getText();
        result->is_constant=true;//note
        result->var_type.reset(visit(ctx->type()).as<type_def_syntax *>());

        return result;
    }
    
    
    //const_de:ID EQUAL const_variable
    antlrcpp::Any syntax_tree_builder::visitConst_de(pasParser::Const_deContext *ctx)
    {
        auto result = new var_def_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->is_constant=true;
        result->name=ctx->ID()->getText();
//    ptr<const_var_syntax> const_value; visit(exps[0]).as<expr_syntax *>()
        result->const_value.reset(visit(ctx->const_variable()).as<const_var_syntax *>());
        return result;
    }

    //identifier (COMMA identifier)* COLON type
    antlrcpp::Any syntax_tree_builder::visitVar_de(pasParser::Var_deContext *ctx)
    {
        ptr_list<var_def_stmt_syntax> result;
        int i = 0;
        auto type=ctx->type();
        for (auto ID : ctx->identifier()){
            auto result2 = new var_def_stmt_syntax;
            result2->is_constant = false;            
            result2->name = ID->getText();
            result2->line = ID->getStart()->getLine();
            result2->pos = ID->getStart()->getCharPositionInLine();
            result2->var_type.reset(visit(type).as<type_def_syntax *>());
 
            result.push_back(ptr<var_def_stmt_syntax>(result2));
        }
        return result;
    }
    antlrcpp::Any syntax_tree_builder::visitIdentifier(pasParser::IdentifierContext *ctx)
    {
        auto result = new var_def_stmt_syntax;
        result->is_constant = false;
        
        result->name = ctx->ID()->getSymbol()->getText();
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();

        return result;
    }
    //
    /*
    :standrad_type
    |RECORD record_body END
    |ARRAY LBRACK period (COMMA period)* RBRACK OF type

    */
    antlrcpp::Any syntax_tree_builder::visitType(pasParser::TypeContext *ctx)
    {
        auto result =new type_def_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        if(ctx->standrad_type())
        {
            result->var_type=ctx->standrad_type()->getText();
        }
        if(ctx->record_body())
        {
            result->var_type="record";
            result->record.reset(visit(ctx->record_body()).as<record_syntax *>());

        }
        if(ctx->type())
        {
                result->var_type="array";
                auto r= new array_type_def_syntax;
                r->line = ctx->getStart()->getLine();
                r->pos = ctx->getStart()->getCharPositionInLine();
                for (auto p : ctx->period())    
                    r->period.push_back(ptr<period_syntax>(visit(p).as<period_syntax *>()));
                r->array_type.reset(visit(ctx->type()).as<type_def_syntax *>());
                result->array.reset(r);
        }
        
 
        return result;
    }
    
    antlrcpp::Any syntax_tree_builder::visitStandrad_type(pasParser::Standrad_typeContext *ctx)
    {
    }
    /*
    :var_de (SEMICOLON var_de)*
    |empty
    */
    antlrcpp::Any syntax_tree_builder::visitRecord_body(pasParser::Record_bodyContext *ctx)
    {
        auto result =new record_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();

        for (auto var_de : ctx->var_de())//对子节点遍历
        {
            auto vars=visit(var_de).as<ptr_list<var_def_stmt_syntax>>();

            for (auto v : vars)
                result->var_de.push_back(ptr<var_def_stmt_syntax>(v));
        }
        return result;
    }
    //const_variable SPOT SPOT const_variable
    antlrcpp::Any syntax_tree_builder::visitPeriod(pasParser::PeriodContext *ctx)
    {
        auto result =new period_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        int i=0;
        for (auto c :ctx->const_variable())
        {
            if(i==0)
            {
        
                result->start.reset(visit(c).as<const_var_syntax *>());
        
            }
            if(i==1)
            {
                result->end.reset(visit(c).as<const_var_syntax *>());
            }
            
            i++;
        }

        
        return result;
    }
    /*
    :PLUS ID
    |MINUS ID
    |ID
    |PLUS num
    |MINUS num
    |num
    |LETTER    
    */
    antlrcpp::Any syntax_tree_builder::visitConst_variable(pasParser::Const_variableContext *ctx)
    {
        auto result =new const_var_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        if(ctx->PLUS()){
            result->flag="+";
        }
        if(ctx->MINUS()){
            result->flag="-";
        }
        if(ctx->ID()){
            result->id=ctx->ID()->getText();
        }
        if(ctx->num()){
            result->num.reset(visit(ctx->num()).as<expr_syntax *>());
        }
        if(ctx->LETTER()){
            result->letter=ctx->LETTER()->getText();
        }
        
        return result;
    }












    antlrcpp::Any syntax_tree_builder::visitCompound_statement(pasParser::Compound_statementContext *ctx)
    {
        auto result = new func_def_syntax;
        result->name = "main";
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->body.reset(visit(ctx->statement_list()).as<stmt_syntax *>());
        return result;
    }
    
    //statement (SEMICOLON statement)*
    antlrcpp::Any syntax_tree_builder::visitStatement_list(pasParser::Statement_listContext *ctx)
    {
        auto result = new block_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();

        for (auto subtree : ctx->children)
        {
        if (auto statement = dynamic_cast<pasParser::Statement1Context *>(subtree))
            result->body.push_back(ptr<stmt_syntax>(visit(statement).as<stmt_syntax *>()));
        if (auto statement = dynamic_cast<pasParser::Call_pro_statementContext *>(subtree))
            result->body.push_back(ptr<stmt_syntax>(visit(statement).as<stmt_syntax *>()));
        
        if (auto statement = dynamic_cast<pasParser::If_elseContext *>(subtree))
            result->body.push_back(ptr<stmt_syntax>(visit(statement).as<stmt_syntax *>()));
        
        if (auto statement = dynamic_cast<pasParser::WhileContext *>(subtree))
            result->body.push_back(ptr<stmt_syntax>(visit(statement).as<stmt_syntax *>()));
        
        if (auto statement = dynamic_cast<pasParser::ComContext *>(subtree))
            result->body.push_back(ptr<stmt_syntax>(visit(statement).as<stmt_syntax *>()));
        if (auto statement = dynamic_cast<pasParser::RepeatContext *>(subtree))
            result->body.push_back(ptr<stmt_syntax>(visit(statement).as<stmt_syntax *>()));
        
        
        }
        
        ///add
        // return result;
        return static_cast<stmt_syntax *>(result);
    }
    
    //variable ASSIGNOP expression 
    //    |BEGIN statement_list END                        #com  
    //|REPEAT statement_list UNTIL expression #repeat
    
    antlrcpp::Any syntax_tree_builder::visitRepeat(pasParser::RepeatContext *ctx)
    {
        auto result = new while_stmt_syntax;
        result->line= ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(visit(ctx->expression()).as<expr_syntax *>());
        result->body.reset(visit(ctx->statement_list()).as<stmt_syntax *>());
        return static_cast<stmt_syntax *>(result);
        //return static_cast<stmt_syntax *>(visit(ctx->statement_list()));
    }
    
    antlrcpp::Any syntax_tree_builder::visitCom(pasParser::ComContext *ctx)
    {
        return visit(ctx->statement_list());
        //return static_cast<stmt_syntax *>(visit(ctx->statement_list()).as<block_syntax *>());
        //ptr<global_def_syntax>(visit(subprogram_declaration).as<func_def_syntax *>())
    }
    
    antlrcpp::Any syntax_tree_builder::visitStatement1(pasParser::Statement1Context *ctx)
    {
        auto result = new assign_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->target.reset(visit(ctx->variable()).as<expr_syntax *>());
        result->value.reset(visit(ctx->expression()).as<expr_syntax *>());
                   
        return static_cast<stmt_syntax *>(result);
    }
    /*
statement
    :variable ASSIGNOP expression             #statement1
    |call_procedure_statement            #call_pro_statement
    |empty                             #statement2
    ;
call_procedure_statement
    :ID
    |ID LEFTPAREN expression_list RIGHTPAREN
    ;
    */
    antlrcpp::Any syntax_tree_builder::visitCall_pro_statement(pasParser::Call_pro_statementContext *ctx)
    {
        return visit(ctx->call_procedure_statement());
    }
    antlrcpp::Any syntax_tree_builder::visitCall_procedure_statement(pasParser::Call_procedure_statementContext *ctx) 
    {
        auto result = new func_call_stmt_syntax;
        result->line= ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->name= ctx->ID()->getText();
        if(ctx->LEFTPAREN()){
            auto exp=visit(ctx->expression_list()).as<ptr_list<expr_syntax>>();
            for (auto e:exp)
            {
                result->expression_list.push_back(ptr<expr_syntax>(e));
            }
        }
        return static_cast<stmt_syntax *>(result);
    }
    //    |IF expression THEN statement (ELSE statement|)  # if_else
    antlrcpp::Any syntax_tree_builder::visitIf_else(pasParser::If_elseContext *ctx)
    {
        auto result = new if_stmt_syntax;
        result->line= ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();

        result->pred.reset(visit(ctx->expression()).as<expr_syntax *>());
        int i=0;
        for(auto s: ctx->statement()){
            if(i==0)result->then_body.reset(visit(s).as<stmt_syntax *>());
        
            if(i==1)result->else_body.reset(visit(s).as<stmt_syntax *>());
            i++;
        }
        
//  result->value.reset(visit(ctx->expression()).as<expr_syntax *>());
      

        return static_cast<stmt_syntax *>(result);
    }
//WHILE expression DO statement                   #while
//    ptr<cond_syntax> pred;
    // ptr<stmt_syntax> body;
    antlrcpp::Any syntax_tree_builder::visitWhile(pasParser::WhileContext *ctx)
    {
        auto result = new while_stmt_syntax;
        result->line= ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(visit(ctx->expression()).as<expr_syntax *>());
        result->body.reset(visit(ctx->statement()).as<stmt_syntax *>());


        return static_cast<stmt_syntax *>(result);

    }



    antlrcpp::Any syntax_tree_builder::visitStatement2(pasParser::Statement2Context *ctx)
    {

    }
    //ID
    /*
variable
    :ID (id_varpart)*
    ;
id_varpart
    :LBRACK expression_list RBRACK
    |SPOT ID
    ;

        if (auto e = ctx->exp())
        result->array_index.reset(visit(e).as<expr_syntax *>());
    */   
    antlrcpp::Any syntax_tree_builder::visitVariable(pasParser::VariableContext *ctx)
    {
        auto result = new lval_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->name = ctx->ID()->getSymbol()->getText();
        
        for(auto part: ctx->id_varpart())
        {
            result->id_varpart.push_back(ptr<id_varpart_syntax>(visit(part).as<id_varpart_syntax *>()));
        }
        // if (auto e = ctx->exp())
        //     result->array_index.reset(visit(e).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    antlrcpp::Any syntax_tree_builder::visitId_varpart(pasParser::Id_varpartContext *ctx)
    {
        auto result = new id_varpart_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        
        if(ctx->SPOT())
        {
            result->spot_id=ctx->ID()->getText();
            
        }else{
            //.as<ptr_list<expr_syntax>>();
            auto exp=visit(ctx->expression_list()).as<ptr_list<expr_syntax>>();
            for (auto e:exp)
            {
                result->expression_list.push_back(ptr<expr_syntax>(e));
            }
        }

        return result;
    }






    //expression (COMMA expression)*
    antlrcpp::Any syntax_tree_builder::visitExpression_list(pasParser::Expression_listContext *ctx)
    {
        ptr_list<expr_syntax> result;    
        for (auto exp : ctx->expression()){
            //auto result2 = visit(exp);
            ptr_list<expr_syntax> result2 ;
            result2.push_back(ptr<expr_syntax>(visit(exp).as<expr_syntax *>()));
            
            
            for (auto r: result2)
                result.push_back(ptr<expr_syntax>(r));
            //result->global_defs.push_back(std::dynamic_pointer_cast<global_def_syntax>(def));
            //ptr<period_syntax>(visit(p).as<period_syntax *>())
        }
        return result;
    }
//           auto defs = visit(decl).as<ptr_list<var_def_stmt_syntax>>();
    
    /*expression
    :simple_expression relop simple_expression
    |simple_expression
    ;
    */
    antlrcpp::Any syntax_tree_builder::visitExpression(pasParser::ExpressionContext *ctx)
    {
        
        if(ctx->relop())
        {
            auto result=new cond_syntax;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            result->lhs.reset(visit(ctx->simple_expression(0)).as<expr_syntax *>());

            std::string op=ctx->relop()->getText();
            if(op=="=")
                result->op=relop::equal;
            if(op=="<")
                result->op=relop::less;
            if(op==">")
                result->op=relop::greater;
            if(op=="<>")
                result->op=relop::non_equal;
            if(op=="<=")
                result->op=relop::less_equal;
            if(op==">=")
                result->op=relop::greater_equal;
            
            result->rhs.reset(visit(ctx->simple_expression(1)).as<expr_syntax *>());
            return static_cast<expr_syntax *>(result);
            //static_cast<expr_syntax *>

        }else{
            return visit(ctx->simple_expression(0));
        }

        //return result;
    }    
/*
simple_expression
    :term
    |PLUS term
    |MINUS term
    |simple_expression addop term
    ;
*/
    antlrcpp::Any syntax_tree_builder::visitSimple_expression(pasParser::Simple_expressionContext *ctx)
    {
        if(ctx->PLUS()){
            auto result =new unaryop_expr_syntax;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            result->op=unaryop::plus;
            result->rhs.reset(visit(ctx->term()).as<expr_syntax *>());
            return static_cast<expr_syntax *>(result);
        }else if(ctx->MINUS()){
            auto result =new unaryop_expr_syntax;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            result->op=unaryop::minus;
            result->rhs.reset(visit(ctx->term()).as<expr_syntax *>());
            return static_cast<expr_syntax *>(result);
        }else if(ctx->addop()){
            auto result = new binop_expr_syntax;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();

            result->lhs.reset(visit(ctx->simple_expression()).as<expr_syntax *>());

            std:string add_op=ctx->addop()->getText();
            if(add_op=="+")
                result->op=binop::plus;
            if(add_op=="-")
                result->op=binop::minus;
            if(add_op=="or"||add_op=="Or"||add_op=="oR"||add_op=="OR")
                result->op=binop::or_;
            
            result->rhs.reset(visit(ctx->term()).as<expr_syntax *>());

            return static_cast<expr_syntax *>(result);
        }else{
            return visit(ctx->term());
        }

    }
/*
term
    :term mulop factor
    |factor
    ;
mulop
    :'*'
    |'/'
    |DIV
    |MOD
    |AND
    ;
*/
    antlrcpp::Any syntax_tree_builder::visitTerm(pasParser::TermContext *ctx)
    {
        if(ctx->mulop())
        {
            auto result = new binop_expr_syntax;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            result->lhs.reset(visit(ctx->term()).as<expr_syntax *>());
            
            std:string mul_op=ctx->mulop()->getText();
            if(mul_op=="*")
                result->op=binop::multiply;
            if(mul_op=="/")
                result->op=binop::divide;
            if(mul_op=="DIV"||mul_op=="dIV"||mul_op=="DiV"||mul_op=="DIv"||mul_op=="diV"||mul_op=="dIv"||mul_op=="Div"||mul_op=="div")
                result->op=binop::div;
            if(mul_op=="MOD"||mul_op=="mOD"||mul_op=="MoD"||mul_op=="MOd"||mul_op=="moD"||mul_op=="mOd"||mul_op=="Mod"||mul_op=="mod")
                result->op=binop::modulo;
            if(mul_op=="AND"||mul_op=="aND"||mul_op=="AnD"||mul_op=="ANd"||mul_op=="anD"||mul_op=="aNd"||mul_op=="And"||mul_op=="and")
                result->op=binop::and_;
                
            result->rhs.reset(visit(ctx->factor()).as<expr_syntax *>());

            return static_cast<expr_syntax *>(result);
        }else{
            return (visit(ctx->factor()));
        }
    }
    
/*
factor
    :unsign_const_variable
    |variable
    |ID LEFTPAREN expression_list RIGHTPAREN
    |LEFTPAREN expression RIGHTPAREN
    |NOT factor
    ;
            auto vars=visit(var_de).as<ptr_list<var_def_stmt_syntax>>();

            for (auto v : vars)
                result->var_de.push_back(ptr<var_def_stmt_syntax>(v));
*/
    antlrcpp::Any syntax_tree_builder::visitFactor(pasParser::FactorContext *ctx)
    {
        if(ctx->unsign_const_variable()){
            return visit(ctx->unsign_const_variable());
        }else if(ctx->variable()){
            
            return visit(ctx->variable());

        }else if(ctx->NOT()){
        
            auto result =new unaryop_expr_syntax;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            result->op=unaryop::not_;
            result->rhs.reset(visit(ctx->factor()).as<expr_syntax *>());
            return static_cast<expr_syntax *>(result);        
        
        }else if(ctx->ID()){
            auto result = new func_call_stmt_syntax;
            result->line= ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            result->name= ctx->ID()->getText();
            if(ctx->LEFTPAREN()){
                auto exp=visit(ctx->expression_list()).as<ptr_list<expr_syntax>>();
                for (auto e:exp)
                {
                    result->expression_list.push_back(ptr<expr_syntax>(e));
                }
            }
            return static_cast<expr_syntax *>(result);
            // auto result =new lval_syntax;
            // result->line = ctx->getStart()->getLine();
            // result->pos = ctx->getStart()->getCharPositionInLine();
            
            // result->name=ctx->ID()->getText();

            // auto result2=visit(ctx->expression_list()).as<ptr_list<expr_syntax>>();

            // for (auto r : result2)
            //     result->expression_list.push_back(ptr<expr_syntax>(r));

            // return static_cast<expr_syntax *>(result);
        }else{
            return visit(ctx->expression());
        }
    }
/*
unsign_const_variable
    :ID
    |num
    |LETTER
    ;
*/
    antlrcpp::Any syntax_tree_builder::visitUnsign_const_variable(pasParser::Unsign_const_variableContext *ctx)
    {
        auto result =new const_var_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
       
        if(ctx->ID()){
            result->id=ctx->ID()->getText();
        }
        if(ctx->num()){
            result->num.reset(visit(ctx->num()).as<expr_syntax *>());
        }
        if(ctx->LETTER()){
            result->letter=ctx->LETTER()->getText();
        }
        
        return static_cast<expr_syntax *>(result);
    }
    antlrcpp::Any syntax_tree_builder::visitMulop(pasParser::MulopContext *ctx)
    {

    }
    antlrcpp::Any syntax_tree_builder::visitAddop(pasParser::AddopContext *ctx)
    {

    }
    antlrcpp::Any syntax_tree_builder::visitRelop(pasParser::RelopContext *ctx)
    {

    }
    













    //digits (SPOT digits|) (EXPONENT|)
    antlrcpp::Any syntax_tree_builder::visitNum(pasParser::NumContext *ctx)
    {
        
        auto result = new literal_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();

         std::string s;
            for(auto num : ctx->children)
            {
                s.append(num->getText());
            }
            double number = std::stod(s);

        if(fabs(number-(int)number)<1e-8){
            result->is_int=true;
            result->intConst=(int)number;
        }else{
            result->is_int=false;
            result->floatConst=number;
        }
        return static_cast<expr_syntax *>(result);
    }


    antlrcpp::Any syntax_tree_builder::visitEmpty(pasParser::EmptyContext *ctx)
    {

    }


    //DIGIT+
    antlrcpp::Any syntax_tree_builder::visitDigits(pasParser::DigitsContext *ctx)
    {

    }





    ptr<syntax_tree_node> syntax_tree_builder::operator()(antlr4::tree::ParseTree *ctx)
{
    auto result = visit(ctx);
    if (result.is<syntax_tree_node *>())
        return ptr<syntax_tree_node>(result.as<syntax_tree_node *>());
    if (result.is<assembly *>())
        return ptr<syntax_tree_node>(result.as<assembly *>());
    if (result.is<global_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<global_def_syntax *>());
    if (result.is<func_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_def_syntax *>());//&node) = 0;   para_de_syntax
    
    if (result.is<para_de_syntax *>())
        return ptr<syntax_tree_node>(result.as<para_de_syntax *>());
    
    if (result.is<cond_syntax *>())
        return ptr<syntax_tree_node>(result.as<cond_syntax *>());
    if (result.is<expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<expr_syntax *>());
    if (result.is<binop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<binop_expr_syntax *>());
    if (result.is<unaryop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<unaryop_expr_syntax *>());
    if (result.is<lval_syntax *>())
        return ptr<syntax_tree_node>(result.as<lval_syntax *>());
if (result.is<id_varpart_syntax *>())
        return ptr<syntax_tree_node>(result.as<id_varpart_syntax *>());
        
    if (result.is<literal_syntax *>())
        return ptr<syntax_tree_node>(result.as<literal_syntax *>());
    if (result.is<stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<stmt_syntax *>());
    if (result.is<var_def_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<var_def_stmt_syntax *>());
if (result.is<type_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<type_def_syntax *>());
if (result.is<record_syntax *>())
        return ptr<syntax_tree_node>(result.as<record_syntax *>());
if (result.is<array_type_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<array_type_def_syntax *>());
if (result.is<period_syntax *>())
        return ptr<syntax_tree_node>(result.as<period_syntax *>());
if (result.is<const_var_syntax *>())
        return ptr<syntax_tree_node>(result.as<const_var_syntax *>());



    if (result.is<assign_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<assign_stmt_syntax *>());
    if (result.is<func_call_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_call_stmt_syntax *>());
    if (result.is<block_syntax *>())
        return ptr<syntax_tree_node>(result.as<block_syntax *>());
    if (result.is<if_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<if_stmt_syntax *>());
    if (result.is<while_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<while_stmt_syntax *>());
    return nullptr;
}
