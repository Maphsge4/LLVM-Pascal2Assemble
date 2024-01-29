// 其中包含一些之后用于 ir 文件翻译的变量的声明。
#ifndef _PAS_ASSEMBLY_BUILDER_H_
#define _PAS_ASSEMBLY_BUILDER_H_

#include <deque>
#include <unordered_map>
#include <string>
#include <tuple>
#include <vector>

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include <pasrecognizer/error_reporter.h>
#include <pasrecognizer/syntax_tree.h>

#include "runtime.h"

class assembly_builder : public pas_recognizer::syntax_tree::syntax_tree_visitor
{
    virtual void visit(pas_recognizer::syntax_tree::assembly &node) override;
    virtual void visit(pas_recognizer::syntax_tree::func_def_syntax &node) override;
    //para_de_syntax
    virtual void visit(pas_recognizer::syntax_tree::para_de_syntax &node) override;
    
    virtual void visit(pas_recognizer::syntax_tree::cond_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::binop_expr_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::unaryop_expr_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::lval_syntax &node) override;
    
    virtual void visit(pas_recognizer::syntax_tree::id_varpart_syntax &node) override;
    
    
    
    virtual void visit(pas_recognizer::syntax_tree::literal_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::var_def_stmt_syntax &node) override;
    
    virtual void visit(pas_recognizer::syntax_tree::type_def_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::record_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::array_type_def_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::period_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::const_var_syntax &node) override;
    

    
    virtual void visit(pas_recognizer::syntax_tree::assign_stmt_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::func_call_stmt_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::block_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::if_stmt_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::while_stmt_syntax &node) override;
    virtual void visit(pas_recognizer::syntax_tree::empty_stmt_syntax &node) override;

    llvm::LLVMContext &context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<runtime_info> runtime;

    llvm::Value *value_result;
    llvm::Value *func_result;
    std::map<std::string,llvm::Value*> NV;

    //int const_result;////
    
    int int_const_result;//
    double float_const_result;//
    bool bool_const_result;
    char char_const_result;
    bool is_varg;
    int is_result;//0 -int 1-real 2-boolean 3-char 4-array 5-record
    //bool is_result_int;//
    int result_is;
    int array_index;
    int array_type;
    int array_length; 
    ////
    bool flag_array;
    bool flag_funcret;
    ////
    int start;
    int end;
    int temp_start;
    int temp_end;
    //
    std::string record_name; 
    bool is_record;
    
    std::string spot;


    std::string ptn,ptn1,ptn2,ptn3;
    std::string ptt,ptt1,ptt2,ptt3;
    
    std::vector<llvm::Type *>cs;
    std::string p_name[50];
    //static Type *
    // vector<llvm::Type *>rec;
    // vector<llvm::Constant *>rec_res;
    
    // int record_index;
    // std::string record_id_num[10];//id a b
    // int record_type_num[10];//type int float
    //
    llvm::Function *current_function;
    std::string current_function_name;
    int bb_count;

    bool lval_as_rval;
    bool in_global;
    bool constexpr_expected;

    pas_recognizer::error_reporter &err;
    bool error_flag;

  public:
    assembly_builder(llvm::LLVMContext &ctx, pas_recognizer::error_reporter &error_stream)
        : context(ctx), builder(ctx), err(error_stream) {}

    void build(std::string name, std::shared_ptr<pas_recognizer::syntax_tree::syntax_tree_node> tree)
    {
        // Initialize environment.
        module = std::make_unique<llvm::Module>(name, context);
        runtime = std::make_unique<runtime_info>(module.get());

        enter_scope();
        for (auto t : runtime->get_language_symbols())
        {
            llvm::GlobalValue *val;
            std::string name;
            bool is_function;
            bool is_const;
            int is_res;
            int array_ty;
            // bool is_array;
            // bool is_int;
            //std::tie(name, val, is_function, is_const, is_array, is_int) = t;
            std::tie(name, val, is_function, is_const, is_res,array_ty) = t;
            
            if (is_function)
                functions[name] = static_cast<llvm::Function *>(val);
            else
                declare_variable(name, val, is_const, is_res,array_ty);
        }

        lval_as_rval = true;
        in_global = true;
        constexpr_expected = false;
        error_flag = false;
        // Start building by starting iterate over the syntax tree.
        tree->accept(*this);
        // Finish by clear IRBuilder's insertion point and moving away built module.
        builder.ClearInsertionPoint();
        exit_scope();
        if (error_flag)
        {
            module.release();
            runtime.release();
        }
    }

    std::unique_ptr<llvm::Module> get_module() { return std::move(module); }
    std::unique_ptr<runtime_info> get_runtime_info() { return std::move(runtime); }

  private:
    void enter_scope() { variables.emplace_front(); }

    void exit_scope() { variables.pop_front(); }

    std::tuple<llvm::Value *, bool, int , int> lookup_variable(std::string name)
    {
        for (auto m : variables)
            if (m.count(name))
                return m[name];
        return std::make_tuple((llvm::Value *)nullptr, false, 0,0);
    }

    bool declare_variable(std::string name, llvm::Value *var_ptr, bool is_const,int is_res,int array_type)//is_res->is_int
    {
        if (variables.front().count(name))
            return false;
        variables.front()[name] = std::make_tuple(var_ptr, is_const,is_res,array_type);
        return true;
    }

    std::deque<std::unordered_map<std::string, std::tuple<llvm::Value *, bool, int ,int>>> variables;//add array_type

    std::unordered_map<std::string, llvm::Function *> functions;
};

#endif


