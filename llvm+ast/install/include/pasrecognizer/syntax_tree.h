#ifndef _PAS_SYNTAX_TREE_H_
#define _PAS_SYNTAX_TREE_H_
#include <vector>
#include <memory>
#include <string>

namespace pas_recognizer
{
namespace syntax_tree
{
// Use unique postd::stringtype to reference stored objects
template <typename T>
using ptr = std::shared_ptr<T>;

// List of reference of type
template <typename T>
using ptr_list = std::vector<ptr<T>>;

// Enumerations
enum class relop
{
    equal = 0,
    non_equal,
    less,
    less_equal,
    greater,
    greater_equal
};

enum class binop
{
    plus = 0,
    minus,
    multiply,
    divide,
    modulo,
    or_,
    div,
    and_
};

enum class unaryop
{
    plus = 0,
    minus,
    not_
};


// Forward declaration
struct syntax_tree_node;
struct assembly;
struct global_def_syntax;
struct func_def_syntax;
//
struct para_de_syntax;
//
struct cond_syntax;

struct expr_syntax;
struct binop_expr_syntax;
struct unaryop_expr_syntax;
struct lval_syntax;
struct id_varpart_syntax;
struct literal_syntax;

struct stmt_syntax;
struct var_def_stmt_syntax;
//
struct type_def_syntax;
struct record_syntax;
struct array_type_def_syntax;
struct period_syntax;
struct const_var_syntax;
//
struct assign_stmt_syntax;
struct func_call_stmt_syntax;
struct block_syntax;
struct if_stmt_syntax;
struct while_stmt_syntax;

struct syntax_tree_visitor;

// Virtual base of all kinds of syntax tree nodes.
struct syntax_tree_node
{
    int line;
    int pos;
    // Used in syntax_tree_visitor. Irrelevant to syntax tree generation.
    virtual void accept(syntax_tree_visitor &visitor) = 0;
};

// Root node of an ordinary syntax tree.
struct assembly : syntax_tree_node
{
    ptr_list<global_def_syntax> global_defs;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// Virtual base of lobal definitions, function or variable one.
struct global_def_syntax : virtual syntax_tree_node
{
    virtual void accept(syntax_tree_visitor &visitor) override = 0;
};

// Function definition.
struct func_def_syntax : global_def_syntax
{
    std::string name;
    ptr_list<para_de_syntax> para_de;

    std::string ret_type;//boolean char integer real
    ptr_list<var_def_stmt_syntax> local_var_de;
    ptr<stmt_syntax> body;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};
struct para_de_syntax : syntax_tree_node
{
    bool is_varg;
    std::string name;
    std::string type;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};




// Virtual base of expressions.
struct expr_syntax : virtual syntax_tree_node
{
    virtual void accept(syntax_tree_visitor &visitor) = 0;
};
//xiu gai wei zhi/// Condition expression. (Not actually treated as expression, enough for C1)
struct cond_syntax : expr_syntax//syntax_tree_node,
{
    relop op;
    ptr<expr_syntax> lhs, rhs;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};


// Expression like `lhs op rhs`.
struct binop_expr_syntax : expr_syntax
{
    binop op;
    ptr<expr_syntax> lhs, rhs;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// Expression like `op rhs`.
struct unaryop_expr_syntax : expr_syntax
{
    unaryop op;
    ptr<expr_syntax> rhs;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// Expression like `ident` or `ident[exp]`.   or 'id(a,b,c)'
struct lval_syntax : expr_syntax
{
    std::string name;
    
    ptr_list<id_varpart_syntax>id_varpart;
    
    ptr<expr_syntax> array_index; // nullptr if not indexed as array
    ptr_list<expr_syntax> expression_list; // nullptr if not exist func()
    
    virtual void accept(syntax_tree_visitor &visitor) override final;
};
/////
struct id_varpart_syntax : expr_syntax
{
    std::string spot_id;                      //.
    ptr_list<expr_syntax> expression_list;    //[]
    virtual void accept(syntax_tree_visitor &visitor) override final;
};



// Expression constructed by a literal number.
struct literal_syntax : expr_syntax
{
    bool is_int;
    int intConst;
    double floatConst;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// Virtual base for statements.
struct stmt_syntax : virtual syntax_tree_node
{
    virtual void accept(syntax_tree_visitor &visitor) = 0;
};

// Variable definition. Multiple of this would be both a statement and a global definition; however, itself only
// represents a single variable definition.
struct var_def_stmt_syntax : stmt_syntax, global_def_syntax
{
    bool is_constant;
    bool is_int;
    std::string name;
    ptr<const_var_syntax> const_value;
    ptr<type_def_syntax> var_type;// standard、array、record
    
    
    ptr<expr_syntax> array_length; // nullptr for non-array variables
    ptr_list<expr_syntax> initializers;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};
//type_def_syntax
struct type_def_syntax : stmt_syntax
{
    std::string var_type;//bool.. array .. record
    ptr<array_type_def_syntax> array;
    ptr<record_syntax> record;
    
    virtual void accept(syntax_tree_visitor &visitor) override final;
};
struct record_syntax : syntax_tree_node
{
    ptr_list<var_def_stmt_syntax> var_de;

    virtual void accept(syntax_tree_visitor &visitor) override final;
};
//array_type_def_syntax
struct array_type_def_syntax : stmt_syntax
{
    ptr<type_def_syntax> array_type;
    ptr_list<period_syntax> period;

    virtual void accept(syntax_tree_visitor &visitor) override final;
};
struct period_syntax : stmt_syntax
{
    ptr<const_var_syntax>start;
    ptr<const_var_syntax>end;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};
struct const_var_syntax : expr_syntax,stmt_syntax
{
    std::string flag;
    // bool is_id;
    // bool is_num;
    // bool is_letter;
    
    std::string id;
    ptr<expr_syntax> num;
    std::string letter;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};








// Assignment statement.
struct assign_stmt_syntax : stmt_syntax
{
    ptr<expr_syntax> target;//ident
    ptr<expr_syntax> value;//
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// Function call statement.
struct func_call_stmt_syntax : stmt_syntax,expr_syntax
{
    std::string name;
    ptr_list<expr_syntax> expression_list;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// Block statement.
struct block_syntax : stmt_syntax
{
    ptr_list<stmt_syntax> body;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// If statement.
struct if_stmt_syntax : stmt_syntax
{
    ptr<expr_syntax> pred;
    ptr<stmt_syntax> then_body;
    ptr<stmt_syntax> else_body;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// While statement.
struct while_stmt_syntax : stmt_syntax
{
    ptr<expr_syntax> pred;
    ptr<stmt_syntax> body;
    virtual void accept(syntax_tree_visitor &visitor) override final;
};

// Empty statement (aka a single ';').
struct empty_stmt_syntax : stmt_syntax
{
    virtual void accept(syntax_tree_visitor &visitor) override final;
};


class syntax_tree_visitor
{
  public:
    virtual void visit(assembly &node) = 0;
    virtual void visit(func_def_syntax &node) = 0;//函数申明
    //
    virtual void visit(para_de_syntax &node) = 0;
    //
    virtual void visit(cond_syntax &node) = 0;
    virtual void visit(binop_expr_syntax &node) = 0;//二元表示运算符
    virtual void visit(unaryop_expr_syntax &node) = 0;
    virtual void visit(lval_syntax &node) = 0;
    virtual void visit(id_varpart_syntax &node) = 0;
    
    virtual void visit(literal_syntax &node) = 0;
    virtual void visit(var_def_stmt_syntax &node) = 0;//变量语句申明
    
    //
    virtual void visit(type_def_syntax &node) = 0;
    virtual void visit(record_syntax  &node) = 0;
    virtual void visit(array_type_def_syntax  &node) = 0;
    virtual void visit(period_syntax  &node) = 0;
    virtual void visit(const_var_syntax   &node) = 0;
    //
    virtual void visit(assign_stmt_syntax &node) = 0;//赋值语句
    virtual void visit(func_call_stmt_syntax &node) = 0;//函数调用语句
    virtual void visit(block_syntax &node) = 0;
    virtual void visit(if_stmt_syntax &node) = 0;//if语句
    virtual void visit(while_stmt_syntax &node) = 0;//循环语句
    virtual void visit(empty_stmt_syntax &node) = 0;//空
};






}
}


#endif






