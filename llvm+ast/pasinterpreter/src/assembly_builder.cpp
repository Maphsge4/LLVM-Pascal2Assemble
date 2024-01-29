// 通过遍历 ast 的每一个分支，将其翻译成 ir。
#include "assembly_builder.h"

#include <vector>

using namespace llvm;
using namespace pas_recognizer::syntax_tree;

void assembly_builder::visit(assembly &node)
{
    in_global = true;
    bb_count = 0;
    value_result = ConstantInt::get(Type::getInt32Ty(context), 0);
    flag_array=false;
    int_const_result=0;
    float_const_result=0;
    bool_const_result=false;
    char_const_result=false;
    flag_funcret=true;
    //is_result_int=true;//note
    // const_result = 0;
    is_record=false;    

    error_flag = false;
    for(auto def : node.global_defs)
    {
        def->accept(*this);
    }
}

void assembly_builder::visit(func_def_syntax &node)
{
    auto func_name = node.name;

    for(auto t : functions)
    {
        if(t.first == func_name)
        {
            error_flag = true;
            err.error(node.line, node.pos, "function: " + func_name + " has already been declared.");
            return;
        }
    }
    if(func_name=="main"){
        auto func = Function::Create(FunctionType::get(Type::getVoidTy(context), std::vector<Type *>(), false),
                                    GlobalValue::LinkageTypes::ExternalLinkage,
                                    func_name, module.get());
        current_function = func;
        current_function_name =node.name;
        auto func_entry = BasicBlock::Create(context, "entry", func);
        builder.SetInsertPoint(func_entry);
        functions[func_name] = func;
        in_global = true;
        node.body->accept(*this);
        builder.CreateRetVoid();
        in_global = true;

    }else{

        // node.body->accept(*this);
        int k=0;
        Type* pt1;
        
        for(auto p :node.para_de)//name type
        {
            p->accept(*this);//ptn ptt
            p_name[k++]=ptn;
            if(ptt=="integer")pt1=Type::getInt32Ty(context);
            if(ptt=="real")pt1=Type::getDoubleTy(context);
            if(ptt=="boolean")pt1=Type::getInt1Ty(context);
            if(ptt=="char")pt1=Type::getInt8Ty(context);
            cs.push_back(pt1);
            
        }
        Type* ret_type;
        int ttt=0;
        // AllocaInst* ret_value;
        if(node.ret_type=="integer"){ret_type=Type::getInt32Ty(context);func_result=ConstantInt::get(Type::getInt32Ty(context), 0);ttt=0;}
        if(node.ret_type=="real"){ret_type=Type::getDoubleTy(context);func_result=ConstantFP::get(context, APFloat((double)0));ttt=1;}
        if(node.ret_type=="boolean"){ret_type=Type::getInt1Ty(context);func_result=ConstantInt::get(Type::getInt1Ty(context), 0);ttt=2;}
        if(node.ret_type=="char"){ret_type=Type::getInt8Ty(context);func_result=ConstantInt::get(Type::getInt8Ty(context), 0);ttt=3;}
        if(node.ret_type==""){ret_type=Type::getVoidTy(context);}
        
        //{pt1,pt2,pt3}

        auto func = Function::Create(FunctionType::get(ret_type, cs, is_varg),
                                    GlobalValue::LinkageTypes::ExternalLinkage,
                                    func_name, module.get());


        if(node.ret_type=="integer")func_result = new GlobalVariable(*module,
                                            Type::getInt32Ty(module->getContext()),
                                            false,
                                            GlobalValue::ExternalLinkage,
                                            ConstantInt::get(Type::getInt32Ty(module->getContext()),0),
                                            func_name);
        if(node.ret_type=="real")func_result = new GlobalVariable(*module,
                                            Type::getDoubleTy(module->getContext()),
                                            false,
                                            GlobalValue::ExternalLinkage,
                                            ConstantFP::get(context, APFloat((double)0)),
                                            func_name); 
        if(node.ret_type=="boolean")func_result = new GlobalVariable(*module,
                                            Type::getInt1Ty(module->getContext()),
                                            false,
                                            GlobalValue::ExternalLinkage,
                                            ConstantInt::get(Type::getInt1Ty(module->getContext()),0),
                                            func_name);
        if(node.ret_type=="char")func_result = new GlobalVariable(*module,
                                            Type::getInt8Ty(module->getContext()),
                                            false,
                                            GlobalValue::ExternalLinkage,
                                            ConstantInt::get(Type::getInt8Ty(module->getContext()),0),
                                            func_name);       
        // if(!declare_variable(func_name,var_ptr,node.is_constant,result_is,array_type)){
        //             err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
        //             error_flag=true;
        //             return;
        // }

        //set name
        k=0;
        for (auto &Arg:func->args()){
            Arg.setName(p_name[k]);
            NV[p_name[k++]]=&Arg;
        }

        // for (auto &Arg:func->ret()){
        //     //Arg.setName(p_name[k]);
        //     func_result=&Arg;
        // }

        current_function = func;
        current_function_name =node.name;
        auto func_entry = BasicBlock::Create(context, "entry", func);
        builder.SetInsertPoint(func_entry);
        functions[func_name] = func;
        //
        for(int j=k-1;j>=0;j--)
        {
            auto tt=cs.back();
            cs.pop_back();
            auto var_ptr=builder.CreateAlloca(tt,nullptr,p_name[j]);
            builder.CreateStore(NV[p_name[j]],var_ptr);
            NV[p_name[j]]=var_ptr;
        }
        //reference back()
        in_global = false;
        for(auto n:node.local_var_de)n->accept(*this);
        //
        Value * var_ptr;

        if(node.ret_type!="")
        {
            flag_funcret=true;
            var_ptr=builder.CreateAlloca(ret_type,nullptr,current_function_name);
                    if(!declare_variable(current_function_name,var_ptr,false,ttt,array_type)){
                        err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                        error_flag=true;
                        return;
                    }
        }
        else{
            flag_funcret=false;
        }


        node.body->accept(*this);
        // func_result
        // builder.CreateLoad(var_ptr);
        if(node.ret_type!="")builder.CreateRet(builder.CreateLoad(var_ptr));
        else builder.CreateRetVoid();
        in_global = true;

        cs.clear();
    }
}
//para_de_syntax
void assembly_builder::visit(para_de_syntax &node)
{
    is_varg=node.is_varg;
    ptn=node.name;
    ptt=node.type;
    
}
void assembly_builder::visit(cond_syntax &node)
{
    constexpr_expected = false;
    node.lhs->accept(*this);
    auto _lhs = value_result;
    node.rhs->accept(*this);
    auto _rhs = value_result;
    if(node.op == relop::equal)
        value_result = builder.CreateICmpEQ(_lhs, _rhs);
    else if(node.op == relop::non_equal)
        value_result = builder.CreateICmpNE(_lhs, _rhs);
    else if(node.op == relop::less)
        value_result = builder.CreateICmpSLT(_lhs, _rhs);
    else if(node.op == relop::less_equal)
        value_result = builder.CreateICmpSLE(_lhs, _rhs);
    else if(node.op == relop::greater)
        value_result = builder.CreateICmpSGT(_lhs, _rhs);
    else if(node.op == relop::greater_equal)
        value_result = builder.CreateICmpSGE(_lhs, _rhs);
}

void assembly_builder::visit(binop_expr_syntax &node)
{
    if(constexpr_expected == false)
    {
        node.lhs->accept(*this);
        auto _lhs = value_result;

        node.rhs->accept(*this);
        auto _rhs = value_result;
        if(node.op == binop::plus)
            value_result = builder.CreateNSWAdd(_lhs, _rhs);
        else if(node.op == binop::minus)
            value_result = builder.CreateNSWSub(_lhs, _rhs);
        else if(node.op == binop::multiply)
            value_result = builder.CreateNSWMul(_lhs, _rhs);
        else if(node.op == binop::divide)
            value_result = builder.CreateSDiv(_lhs, _rhs);
        else if(node.op == binop::modulo)
            value_result = builder.CreateSRem(_lhs, _rhs);
        else if(node.op==binop::and_)
            value_result = builder.CreateAnd(_lhs, _rhs);
        else if(node.op==binop::or_)
            value_result = builder.CreateOr(_lhs, _rhs);
  
    }
    else
    {
        if(is_result==0)
        {    
            node.lhs->accept(*this);
            int _lhs = int_const_result;
            node.rhs->accept(*this);
            int _rhs = int_const_result;
            if(node.op == binop::plus)
                int_const_result = _lhs + _rhs;
            else if(node.op == binop::minus)
                int_const_result = _lhs - _rhs;
            else if(node.op == binop::multiply)
                int_const_result = _lhs * _rhs;
            else if(node.op == binop::divide)
                int_const_result = _lhs / _rhs;
            else if(node.op == binop::modulo)
                int_const_result = _lhs % _rhs;
            else if(node.op == binop::or_)
                int_const_result = _lhs | _rhs;
            else if(node.op == binop::div)
                int_const_result = _lhs / _rhs;
            else if(node.op == binop::and_)
                int_const_result = _lhs & _rhs;
        }
        if(is_result==1)//real
        {    
            node.lhs->accept(*this);
            double _lhs = float_const_result;
            node.rhs->accept(*this);
            double _rhs = float_const_result;
            if(node.op == binop::plus)
                float_const_result = _lhs + _rhs;
            else if(node.op == binop::minus)
                float_const_result = _lhs - _rhs;
            else if(node.op == binop::multiply)
                float_const_result = _lhs * _rhs;
            else if(node.op == binop::divide)
                float_const_result = _lhs / _rhs;
            else if(node.op == binop::modulo)
                // float_const_result = _lhs % _rhs;
                    {
                        error_flag = true;
                        err.error(node.line, node.pos, "invalid operands of types double and double to binary operator %");
                        return;
                    }
            else if(node.op == binop::or_)
                // float_const_result = _lhs | _rhs;
                    {
                        error_flag = true;
                        err.error(node.line, node.pos, "invalid operands of types double and double to binary operator |");
                        return;
                    }
            else if(node.op == binop::div)
                float_const_result = (int)(_lhs / _rhs);
            else if(node.op == binop::and_)
                // float_const_result = _lhs & _rhs;
                    {
                        error_flag = true;
                        err.error(node.line, node.pos, "invalid operands of types double and double to binary operator &");
                        return;
                    }
        }
    }
}

void assembly_builder::visit(unaryop_expr_syntax &node)
{
    // only need to deal with minus
    node.rhs->accept(*this);
    if(node.op == unaryop::minus)
    {
        // printf("work or not ???\n");
        if(constexpr_expected){
            // std::cout<<is_result<<std::endl;
            if(is_result==0)
                int_const_result = -int_const_result;
            else if(is_result==1)
                float_const_result = -float_const_result;
            else if(is_result==2)
                bool_const_result =! bool_const_result;
        }
        else{
            // printf("work or not ??\n");
            if(is_result==0)
            {
                Value* int_const_int32_0 = ConstantInt::get(Type::getInt32Ty(context), 0);
                value_result = builder.CreateNSWSub(int_const_int32_0, value_result);
            }else if(is_result==1)
            {
                Value* float_const_int32_0 =ConstantFP::get(context, APFloat((double)0));
                value_result = builder.CreateNSWSub(float_const_int32_0, value_result);
            }else if(is_result==2)
            {
                Value* int_const_int32_0 = ConstantInt::get(Type::getInt1Ty(context), 1);
                value_result = builder.CreateNSWSub(int_const_int32_0, value_result);    
            }

        }
    }else if(node.op==unaryop::not_){
        if(constexpr_expected){
            if(is_result==2)
                bool_const_result =! bool_const_result;
        }else{
            if(is_result==2)
            {
                Value* int_const_int32_0 = ConstantInt::get(Type::getInt1Ty(context), 1);
                value_result = builder.CreateNSWSub(int_const_int32_0, value_result);    
            }
        }
    }
}

void assembly_builder::visit(lval_syntax &node)
{
    // printf("lval_syntax\n");
    // if(in_global==false&&node.name==current_function_name){
    //     value_result=func_result;//func_result
    //     return;
    // }
    for(int i=0;i<=10;i++)
    {
        if(in_global==false&&node.name==p_name[i]){

            
            if(lval_as_rval == false)value_result=NV[node.name];
            else value_result=builder.CreateLoad(NV[node.name]);//builder.CreateStore(NV[node.name],value_result);
            return;
        }
    
    }
    
    if(constexpr_expected == true)
    {
        err.error(node.line, node.pos, "constant value expected.");
        error_flag = true;
        return;
    }
    auto t = lookup_variable(node.name);
    if(!std::get<0>(t))
    {
        err.error(node.line, node.pos, "use of undeclared variable : " + node.name);
        error_flag = true;
        return;
    }
    auto lval =  std::get<0>(t); // data
    // std::cout<<"cessss"<<std::endl;
    bool is_const = std::get<1>(t);
    int is_res = std::get<2>(t);//0int 1real 2 bool 3 char 4array 5 record
    int arr_t = std::get<3>(t);
    is_result  = is_res;
    result_is = is_res;
    if(is_res != 4 &&is_res != 5)//not array
    {
        // if(node.array_index)
        // {
        //     err.error(node.line, node.pos, "type mismatch: expecting a non-array.");
        //     error_flag = true;
        //     return;
        // }
        if(lval_as_rval == false)
        {
            if(is_const == true)
            {
                err.error(node.line, node.pos, "const value cannot be a lval.");
                error_flag = true;
                return;
            }
            value_result = lval;//ptr
        }
        else
        {
            value_result = builder.CreateLoad(lval);//value
        }
    }else if(is_res == 4){//array
        for (auto t:node.id_varpart)//one
            t->accept(*this);//array_index
            if(flag_array==true){

                std::vector<Value *> index;
                int temp_lval = lval_as_rval;
                lval_as_rval = true;
                lval_as_rval = temp_lval;
                Value * const_int_index;
                //value_result = ConstantInt::get(Type::getInt32Ty(context), array_index);
                const_int_index = value_result;//array_index
                index.push_back((Value *)ConstantInt::get(Type::getInt32Ty(context), 0));
                index.push_back(const_int_index);
                Value * element = builder.CreateGEP(lval, index);
            
                if(lval_as_rval == false)
                {
                    value_result = element;
                }
                else
                {
                    value_result = builder.CreateLoad(element);
                }
                ///
                is_result  = arr_t;//array_type

            }else{
                    ///
                std::vector<Value *> index;
                int temp_lval = lval_as_rval;
                lval_as_rval = true;
                
                lval_as_rval = temp_lval;
                Value * const_int_index;
                value_result = ConstantInt::get(Type::getInt32Ty(context), array_index);
                const_int_index = value_result;//array_index
                index.push_back((Value *)ConstantInt::get(Type::getInt32Ty(context), 0));
                index.push_back(const_int_index);
                Value * element = builder.CreateGEP(lval, index);
            
                if(lval_as_rval == false)
                {
                    value_result = element;
                }
                else
                {
                    value_result = builder.CreateLoad(element);
                }
                ///
                is_result  = arr_t;//array_type
            
            }
            flag_array=false;
            // **************************
    }else{
        for (auto t2:node.id_varpart)//one
            t2->accept(*this);//spot
        auto t3 = lookup_variable(node.name+"_"+spot);
        auto lval3 =  std::get<0>(t3); // data
        // std::cout<<"cessss"<<std::endl;
        bool is_const3 = std::get<1>(t3);
        int is_res3 = std::get<2>(t3);//0int 1real 2 bool 3 char 4array 5 record
        int arr_t3 = std::get<3>(t3);
        is_result  = is_res3;

            //
                if(is_res3 != 4 &&is_res3 != 5)//not array
                {
                    // if(node.array_index)
                    // {
                    //     err.error(node.line, node.pos, "type mismatch: expecting a non-array.");
                    //     error_flag = true;
                    //     return;
                    // }
                    if(lval_as_rval == false)
                    {
                        if(is_const3 == true)
                        {
                            err.error(node.line, node.pos, "const value cannot be a lval.");
                            error_flag = true;
                            return;
                        }
                        value_result = lval3;//ptr
                    }
                    else
                    {
                        value_result = builder.CreateLoad(lval3);//value
                    }
                }else if(is_res3 == 4){//array
                    for (auto t:node.id_varpart)//one
                        t->accept(*this);//array_index

                        ///
                        std::vector<Value *> index;
                        int temp_lval = lval_as_rval;
                        lval_as_rval = true;
                        
                        lval_as_rval = temp_lval;
                        Value * const_int_index;
                        value_result = ConstantInt::get(Type::getInt32Ty(context), array_index);
                        const_int_index = value_result;//array_index
                        index.push_back((Value *)ConstantInt::get(Type::getInt32Ty(context), 0));
                        index.push_back(const_int_index);
                        Value * element = builder.CreateGEP(lval3, index);
                        if(lval_as_rval == false)
                        {
                            // if(is_const == true)
                            // {
                            //     err.error(node.line, node.pos, "const value cannot be a lval.");
                            //     error_flag = true;
                            //     return;
                            // }
                            value_result = element;
                        }
                        else
                        {
                            value_result = builder.CreateLoad(element);
                        }
                        ///
                        is_result  = arr_t;//array_type
                        // **************************
                }


            //

        
    }
    //record?
}
void assembly_builder::visit(id_varpart_syntax &node)
{
    if(node.spot_id==""){
    
            for (auto t:node.expression_list)//one
            {        
                    bool tempb=constexpr_expected;
                    is_result=6;
                    constexpr_expected=true;
                    t->accept(*this);
                    constexpr_expected=tempb;
            }
            if(result_is==0)array_index=(int)int_const_result;
            else if(result_is==3)array_index=(int)char_const_result;
            else {
                        err.error(node.line, node.pos, "array index error type.");
                        error_flag = true;
                        return;
            }

    
    }
    else{
        spot=node.spot_id;//auto t = lookup_variable(+node.spot_id);
    }


}

void assembly_builder::visit(literal_syntax &node)
{
    if(is_result==0){    
        if(constexpr_expected == true)
        {
            if(node.is_int)int_const_result = node.intConst;
            else{
                err.error(node.line, node.pos, "type mismatch: expecting a integer.");
                error_flag = true;
                return;
            }
            // if(!node.is_int)float_const_result = node.floatConst;        
        }
        else
        {
            if(node.is_int)value_result = ConstantInt::get(Type::getInt32Ty(context), node.intConst);
            else{
                err.error(node.line, node.pos, "type mismatch: expecting a integer.");
                error_flag = true;
                return;
            }
            //if(!node.is_int)value_result = ConstantFP::get(Type::getDoubleTy(context), node.floatConst);
        }
    }
    else if(is_result==1){    
        if(constexpr_expected == true)
        {
            if(!node.is_int)float_const_result = node.floatConst;
            else{
                float_const_result = node.intConst;
            }
            // if(!node.is_int)float_const_result = node.floatConst;        
        }
        else
        {
            if(!node.is_int)value_result = ConstantFP::get(context, APFloat((double)node.floatConst));
            else{
                // value_result = ConstantFP::get(Type::getDoubleTy(context), (double)(node.intConst));//change
                value_result = ConstantFP::get(context, APFloat((double)(node.intConst)));
            }
            //if(!node.is_int)value_result = ConstantFP::get(Type::getDoubleTy(context), node.floatConst);
        }
    }
    else if(is_result==2){    //bool
        if(constexpr_expected == true)
        {
            if(node.is_int&&(node.intConst==0||node.intConst==1))bool_const_result = node.intConst;
            else{
                err.error(node.line, node.pos, "type mismatch: expecting a boolean.");
                error_flag = true;
                return;
            }
            // if(!node.is_int)float_const_result = node.floatConst;        
        }
        else
        {
            if(node.is_int&&(node.intConst==0||node.intConst==1))value_result = ConstantInt::get(Type::getInt1Ty(context), node.intConst);
            else{
                err.error(node.line, node.pos, "type mismatch: expecting a boolean.");
                error_flag = true;
                return;
            }
            //if(!node.is_int)value_result = ConstantFP::get(Type::getDoubleTy(context), node.floatConst);
        }
    }else if(is_result==6)//wu zhi ding
    {


        if(node.is_int){
            int_const_result=node.intConst;
            is_result=0;

            
        }else{
            float_const_result=node.floatConst;
            is_result=1;
        }
    }
    
    else{
            err.error(node.line, node.pos, "type mismatch: expecting not a number.");
            error_flag = true;
            return;
    }



}

void assembly_builder::visit(var_def_stmt_syntax &node)
{
    //printf("visiting var_def.\n");
    auto var_name = node.name;
    if(is_record==false){
        record_name=var_name;

    }
    if(node.var_type){
    
        node.var_type->accept(*this);
        
        if(is_record==true){
            // if(result_is==0){
            //     rec.push_back(Type::getInt32Ty(module->getContext()));
            //     rec_res.push_back(ConstantInt::get(Type::getInt32Ty(module->getContext()),0));
            // }else if(result_is==1){
            //     rec.push_back(Type::getDoubleTy(module->getContext()));
            //     rec_res.push_back(ConstantFP::get(Type::getDoubleTy(module->getContext()),0));
            // }
            var_name=record_name+"_"+var_name;
         
        }
        
        if(result_is==0){           //integer
            Value * var_ptr;
            if(in_global)
            {
                //constexpr_expected = true;

                var_ptr = new GlobalVariable(*module,
                                            Type::getInt32Ty(module->getContext()),
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage,
                                            ConstantInt::get(Type::getInt32Ty(module->getContext()),0),
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                var_ptr=builder.CreateAlloca(Type::getInt32Ty(context),nullptr,var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }
        }else if(result_is==1){//real
            Value * var_ptr;
            if(in_global)
            {
                //constexpr_expected = true;

                var_ptr = new GlobalVariable(*module,
                                            Type::getDoubleTy(module->getContext()),
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage,
                                            ConstantFP::get(context, APFloat((double)0)),
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                var_ptr=builder.CreateAlloca(Type::getDoubleTy(context),nullptr,var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }
        }else if(result_is==2){//boolean
            Value * var_ptr;
            if(in_global)
            {
                //constexpr_expected = true;
                var_ptr = new GlobalVariable(*module,
                                            Type::getInt1Ty(module->getContext()),//bool-> bit 1 int
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage,
                                            ConstantInt::get(Type::getInt1Ty(module->getContext()),0),
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                var_ptr=builder.CreateAlloca(Type::getInt1Ty(context),nullptr,var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }
        }else if(result_is==3){//char
            Value * var_ptr;
            if(in_global)
            {
                //constexpr_expected = true;
                var_ptr = new GlobalVariable(*module,
                                            Type::getInt8Ty(module->getContext()),
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage,
                                            ConstantInt::get(Type::getInt8Ty(module->getContext()),0),
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                var_ptr=builder.CreateAlloca(Type::getInt8Ty(context),nullptr,var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }
        }else if(result_is==4&&array_type==0){//array //length //a_type
            Value * var_ptr;
            if(in_global)
            {

                std::vector<Constant *> init_array;
                Constant * const_int_0 = ConstantInt::get(Type::getInt32Ty(context), 0);
                int array_len = array_length;
                int temp_array_len = array_length;
                if(temp_array_len < 0)
                {
                    err.error(node.line, node.pos, "size of an array must be greater than 0.");
                    error_flag = true;
                    return;
                }
                if(temp_array_len == 0)
                {
                    err.warn(node.line, node.pos, "declaring a 0-sized array.");
                }
                for(int i = 0; i < temp_array_len; i++)
                {
                    
                    init_array.push_back(const_int_0);
                    
                }
                var_ptr = new GlobalVariable(*module,
                                            ArrayType::get(Type::getInt32Ty(context), temp_array_len), 
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage, 
                                            ConstantArray::get(ArrayType::get(Type::getInt32Ty(context), temp_array_len), init_array), 
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                            int temp_array_len = array_length;
                            if(temp_array_len < 0)
                            {
                                err.error(node.line, node.pos, "size of an array must be greater than 0.");
                                error_flag = true;
                                return;
                            }
                            if(temp_array_len == 0)
                            {
                                err.warn(node.line, node.pos, "declaring a 0-sized array.");
                            }
                            var_ptr = builder.CreateAlloca(ArrayType::get(Type::getInt32Ty(context), temp_array_len), nullptr, var_name);
                            
                            Value * element;
                            std::vector<Value *> index;
                            index.push_back((Value *)ConstantInt::get(Type::getInt32Ty(context), 0));
                            for(int len = 0; len < temp_array_len; len++)
                            {
                                index.push_back((Value *)ConstantInt::get(Type::getInt32Ty(context), len));
                                element = builder.CreateGEP(var_ptr, index);
                                index.pop_back();
                                
                                Value * init = ConstantInt::get(Type::getInt32Ty(context), 0);
                                builder.CreateStore(init, element);
                                
                            }
                            if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                                err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                                error_flag=true;
                                return;
                            }
                }

        }else if(result_is==4&&array_type==1){//array //length //a_type
            Value * var_ptr;
            if(in_global)
            {

                std::vector<Constant *> init_array;
                Constant * const_float_0 = ConstantFP::get(context, APFloat((double)0));
                int array_len = array_length;
                int temp_array_len = array_length;
                if(temp_array_len < 0)
                {
                    err.error(node.line, node.pos, "size of an array must be greater than 0.");
                    error_flag = true;
                    return;
                }
                if(temp_array_len == 0)
                {
                    err.warn(node.line, node.pos, "declaring a 0-sized array.");
                }
                for(int i = 0; i < temp_array_len; i++)
                {
                    
                    init_array.push_back(const_float_0);
                    
                }
                var_ptr = new GlobalVariable(*module,
                                            ArrayType::get(Type::getDoubleTy(context), temp_array_len), 
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage, 
                                            ConstantArray::get(ArrayType::get(Type::getDoubleTy(context), temp_array_len), init_array), 
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                            int temp_array_len = array_length;
                            if(temp_array_len < 0)
                            {
                                err.error(node.line, node.pos, "size of an array must be greater than 0.");
                                error_flag = true;
                                return;
                            }
                            if(temp_array_len == 0)
                            {
                                err.warn(node.line, node.pos, "declaring a 0-sized array.");
                            }
                            var_ptr = builder.CreateAlloca(ArrayType::get(Type::getDoubleTy(context), temp_array_len), nullptr, var_name);
                            
                            Value * element;
                            std::vector<Value *> index;
                            index.push_back((Value *)ConstantFP::get(context, APFloat((double)0)));
                            for(int len = 0; len < temp_array_len; len++)
                            {
                                index.push_back((Value *)ConstantFP::get(context, APFloat((double)len)));
                                element = builder.CreateGEP(var_ptr, index);
                                index.pop_back();
                                
                                Value * init = ConstantFP::get(context, APFloat((double)0));
                                builder.CreateStore(init, element);
                                
                            }
                            if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                                err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                                error_flag=true;
                                return;
                            }
                }        
        }else if(result_is==4&&array_type==2){//array //length //a_type

            Value * var_ptr;
            if(in_global)
            {

                std::vector<Constant *> init_array;
                Constant * const_int_0 = ConstantInt::get(Type::getInt1Ty(context), 0);
                int array_len = array_length;
                int temp_array_len = array_length;
                if(temp_array_len < 0)
                {
                    err.error(node.line, node.pos, "size of an array must be greater than 0.");
                    error_flag = true;
                    return;
                }
                if(temp_array_len == 0)
                {
                    err.warn(node.line, node.pos, "declaring a 0-sized array.");
                }
                for(int i = 0; i < temp_array_len; i++)
                {
                    
                    init_array.push_back(const_int_0);
                    
                }
                var_ptr = new GlobalVariable(*module,
                                            ArrayType::get(Type::getInt1Ty(context), temp_array_len), 
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage, 
                                            ConstantArray::get(ArrayType::get(Type::getInt1Ty(context), temp_array_len), init_array), 
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                            int temp_array_len = array_length;
                            if(temp_array_len < 0)
                            {
                                err.error(node.line, node.pos, "size of an array must be greater than 0.");
                                error_flag = true;
                                return;
                            }
                            if(temp_array_len == 0)
                            {
                                err.warn(node.line, node.pos, "declaring a 0-sized array.");
                            }
                            var_ptr = builder.CreateAlloca(ArrayType::get(Type::getInt1Ty(context), temp_array_len), nullptr, var_name);
                            
                            Value * element;
                            std::vector<Value *> index;
                            index.push_back((Value *)ConstantInt::get(Type::getInt1Ty(context), 0));
                            for(int len = 0; len < temp_array_len; len++)
                            {
                                index.push_back((Value *)ConstantInt::get(Type::getInt1Ty(context), len));
                                element = builder.CreateGEP(var_ptr, index);
                                index.pop_back();
                                
                                Value * init = ConstantInt::get(Type::getInt1Ty(context), 0);
                                builder.CreateStore(init, element);
                                
                            }
                            if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                                err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                                error_flag=true;
                                return;
                            }
                }


        }
        else if(result_is==4&&array_type==3){//array //length //a_type
            Value * var_ptr;
            if(in_global)
            {

                std::vector<Constant *> init_array;
                Constant * const_int_0 = ConstantInt::get(Type::getInt8Ty(context), 0);
                int array_len = array_length;
                int temp_array_len = array_length;
                if(temp_array_len < 0)
                {
                    err.error(node.line, node.pos, "size of an array must be greater than 0.");
                    error_flag = true;
                    return;
                }
                if(temp_array_len == 0)
                {
                    err.warn(node.line, node.pos, "declaring a 0-sized array.");
                }
                for(int i = 0; i < temp_array_len; i++)
                {
                    
                    init_array.push_back(const_int_0);
                    
                }
                var_ptr = new GlobalVariable(*module,
                                            ArrayType::get(Type::getInt8Ty(context), temp_array_len), 
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage, 
                                            ConstantArray::get(ArrayType::get(Type::getInt8Ty(context), temp_array_len), init_array), 
                                            var_name);
                if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }
            }else{//add after 
                            int temp_array_len = array_length;
                            if(temp_array_len < 0)
                            {
                                err.error(node.line, node.pos, "size of an array must be greater than 0.");
                                error_flag = true;
                                return;
                            }
                            if(temp_array_len == 0)
                            {
                                err.warn(node.line, node.pos, "declaring a 0-sized array.");
                            }
                            var_ptr = builder.CreateAlloca(ArrayType::get(Type::getInt8Ty(context), temp_array_len), nullptr, var_name);
                            
                            Value * element;
                            std::vector<Value *> index;
                            index.push_back((Value *)ConstantInt::get(Type::getInt8Ty(context), 0));
                            for(int len = 0; len < temp_array_len; len++)
                            {
                                index.push_back((Value *)ConstantInt::get(Type::getInt8Ty(context), len));
                                element = builder.CreateGEP(var_ptr, index);
                                index.pop_back();
                                
                                Value * init = ConstantInt::get(Type::getInt8Ty(context), 0);
                                builder.CreateStore(init, element);
                                
                            }
                            if(!declare_variable(var_name,var_ptr,node.is_constant,result_is,array_type)){
                                err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                                error_flag=true;
                                return;
                            }
                }



        }
        else if(result_is==5){//record  //get rec\rec_res
            //record_name=node.name;
            Value * var_ptr;
            if(in_global)
            {
                //constexpr_expected = true;
                var_ptr = new GlobalVariable(*module,
                                            StructType::get(module->getContext()),//Type::getInt1Ty(module->getContext()),//bool-> bit 1 int
                                            node.is_constant,
                                            GlobalValue::ExternalLinkage,
                                            ConstantStruct::get(StructType::get(module->getContext()),{}),//struct_type 、 {constant}
                                            node.name);
                        
                //////
                // LLVM::StructType *Foo=LLVM::StructType::create(module->getContext(),var_name);
                // Foo->setBody(llvm::ArrayRef< T >::ArrayRef(rec));
                // struct Foo foo_struct;
                // var_ptr = new GlobalVariable(*module,);//Foo foo_struct
                
                //////

                if(!declare_variable(node.name,var_ptr,node.is_constant,result_is,array_type)){
                    err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                    error_flag=true;
                    return;
                }

                // rec.clear();
                // rec_res.clear();
            }else{//add after 


            }



        }

    }else if(node.const_value)
    {//const
            is_result=6;
            constexpr_expected = true;
            node.const_value->accept(*this);
            Value * var_ptr;
            if(result_is==0){
                if(in_global)
                {

                    var_ptr = new GlobalVariable(*module,
                                                Type::getInt32Ty(module->getContext()),
                                                node.is_constant,
                                                GlobalValue::ExternalLinkage,
                                                ConstantInt::get(Type::getInt32Ty(module->getContext()),int_const_result),
                                                var_name);
                    if(!declare_variable(var_name,var_ptr,node.is_constant,is_result,array_type)){
                        err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                        error_flag=true;
                        return;
                    }
                }else{//add after 

                }
            }else if(result_is==1){
                if(in_global)
                {
                    constexpr_expected = true;
                    var_ptr = new GlobalVariable(*module,
                                                Type::getDoubleTy(module->getContext()),
                                                node.is_constant,
                                                GlobalValue::ExternalLinkage,
                                                ConstantFP::get(context, APFloat((double)float_const_result)),
                                                var_name);
                    if(!declare_variable(var_name,var_ptr,node.is_constant,is_result,array_type)){
                        err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                        error_flag=true;
                        return;
                    }
                }else{//add after 

                }
            }else if(result_is==3){
                if(in_global)
                {
                    constexpr_expected = true;
                    var_ptr = new GlobalVariable(*module,
                                                Type::getInt8Ty(module->getContext()),
                                                node.is_constant,
                                                GlobalValue::ExternalLinkage,
                                                ConstantInt::get(Type::getInt8Ty(module->getContext()),char_const_result),
                                                var_name);
                    if(!declare_variable(var_name,var_ptr,node.is_constant,is_result,array_type)){
                        err.error(node.line,node.pos,"variable: " +node.name + "has already been declared.");
                        error_flag=true;
                        return;
                    }
                }else{//add after 

                }
            }else{
                err.error(node.line,node.pos,"error1");
                        error_flag=true;
                        return;
            }

    }else{
                        err.error(node.line,node.pos,"error2");
                        error_flag=true;
                        return;


    }
}

void assembly_builder::visit(type_def_syntax &node)
{
    std::string type=node.var_type;
    if(type=="integer"){
        result_is=0;
    }else if(type=="real"){
        result_is=1;
    }else if(type=="boolean"){
        result_is=2;
    }else if(type=="char"){
        result_is=3;
    }else if(type=="array"){
        result_is=4;
        node.array->accept(*this);//get a_type、a_l

        result_is=4;
    }else if(type=="record"){//record  var_de,var_de,var_de... end
        result_is=5;
        node.record->accept(*this);//rec \res
        result_is=5;
    }

}
void assembly_builder::visit(record_syntax &node)
{
    is_record=true;
    for(auto t:node.var_de)//list:var_de
        t->accept(*this);
    is_record=false;

}
void assembly_builder::visit(array_type_def_syntax &node)
{
    node.array_type->accept(*this);
    array_type=result_is;

    start=9999;
    end=-9999;
    for (auto t: node.period){//get start/end
        constexpr_expected=true;
        is_result=6;
        t->accept(*this);   
    }
    if(start>end){
        err.error(node.line,node.pos,"index of array is not legal.");
        error_flag=true;
        return;
    }
    array_length=end+1;

}
void assembly_builder::visit(period_syntax &node)
{
    node.start->accept(*this);
    if(result_is!=0&&result_is!=3){
        err.error(node.line,node.pos,"index of array is not legal.");
        error_flag=true;
        return;
    }
    if(result_is==0)temp_start=int_const_result;
    else temp_start=(int)(char_const_result);
    if(temp_start<start){
        start=temp_start;
    }

    node.end->accept(*this);
    if(result_is!=0&&result_is!=3){
        err.error(node.line,node.pos,"index of array is not legal.");
        error_flag=true;
        return;
    }
    if(result_is==0)temp_end=int_const_result;
    else temp_end=(int)(char_const_result);
    if(temp_end>end){
        end=temp_end;
    }
}
void assembly_builder::visit(const_var_syntax &node)
{
    if(node.num){

        node.num->accept(*this);
        if(node.flag=="-"){//sign
            int_const_result=-int_const_result;
            float_const_result=-float_const_result;
            bool_const_result=!bool_const_result;
            // //-char not exist
            value_result =builder.CreateNSWSub(ConstantInt::get(Type::getInt32Ty(context),0),value_result);
        }
        result_is=is_result;

    }else if(node.id!=""){//
        flag_array=true;
//////////////////////////
        // if(in_global==false&&node.id==current_function_name){
        //     value_result=func_result;//func_result
        //     return;
        // }
        for(int i=0;i<=10;i++)
        {
            // std::cout<<node.id<<std::endl;
            if(in_global==false&&node.id==p_name[i]){

                if(lval_as_rval == false)value_result=NV[node.id];
                else {
                    //builder.CreateStore(NV[node.id],value_result);
                    value_result=builder.CreateLoad(NV[node.id]);
                    }
                return;
            }
        
        }


    ///////////////////////////
            // node.num->accept(*this);
            auto t = lookup_variable(node.id);
            if(!std::get<0>(t))
            {
                err.error(node.line, node.pos, "use of undeclared const variable : " + node.id);
                error_flag = true;
                return;
            }
            auto lval =  std::get<0>(t); // data
            bool is_const = std::get<1>(t);
            // if(is_const==false){
            //     err.error(node.line, node.pos, "use of not const variable : " + node.id);
            //     error_flag = true;
            //     return;
            // }
            int is_res = std::get<2>(t);//0int 1real 2 bool 3 char 4array 5 record
            
            if(is_result!=is_res&&is_result!=6&&!(is_result==1&&is_res==0)){
                err.error(node.line, node.pos, "use of error type variable : " + node.id);
                error_flag = true;
                return;
            }
            // int arr_t = std::get<3>(t); pas-s里 右值只有id 没有 variable
            is_result  = is_res;
            result_is = is_res;
            
            value_result = builder.CreateLoad(lval);//value
            if(node.flag=="-"){//sign
               value_result =builder.CreateNSWSub(ConstantInt::get(Type::getInt32Ty(context),0),value_result);
            }
    }else if(node.letter!=""){
        if(is_result!=3&&is_result!=6){
            err.error(node.line, node.pos, "dont want a char type : " + node.id);
            error_flag = true;
            return;
        }
        if(constexpr_expected)
        {

            auto temp = node.letter.c_str();
            char_const_result=(int8_t)(temp[1]);
            // std::cout<<char_const_result<<std::endl;
            result_is=3;
            is_result=3;
            if(node.flag=="-"){//sign
                err.error(node.line, node.pos, "don't exist signed letter : " + node.letter);
                error_flag = true;
                return;       
            }
        }
        else{
            //std::cout<<node.letter<<std::endl;
            //std::cout<<(int32_t)node.letter[0]<<std::endl;
            auto temp = node.letter.c_str();
            //std::cout<<(int8_t)(temp[1])<<std::endl;
            
            value_result = ConstantInt::get(Type::getInt8Ty(context),(int8_t)(temp[1]));
            is_result=3;
            result_is=3;
            if(node.flag=="-"){//sign
                err.error(node.line, node.pos, "don't exist signed letter : " + node.letter);
                error_flag = true;
                return;       
            }
        }
    }
}



void assembly_builder::visit(assign_stmt_syntax &node)
{
    constexpr_expected = false;
    lval_as_rval = false;
    node.target->accept(*this);
    auto _target = value_result;

    constexpr_expected = false;
    lval_as_rval = true;
    node.value->accept(*this);
    auto _value = value_result;

    builder.CreateStore(_value, _target);

}

void assembly_builder::visit(func_call_stmt_syntax &node)
{
    auto func_name = node.name;

    // check if the functions is declared
    int found = 0;
    for(auto t : functions)
    {
        if(t.first == func_name)
        {
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        err.error(node.line, node.pos, "use of undeclared function : " + node.name);
        error_flag = true;
        return;
    }
    auto func = functions[func_name];


    if(node.expression_list.size()>0){        
            std::vector<Value *> args;
            auto t1=constexpr_expected;
            auto t2=is_result;
            for(auto t:node.expression_list)
            {
                constexpr_expected = false;
                is_result=6;
                t->accept(*this);
                args.push_back(value_result);
                constexpr_expected = t1;
                is_result=t2;
            }
            
            if(flag_funcret==true)value_result=builder.CreateCall(func,args);
            else  builder.CreateCall(func,args);
    }else{
        if(flag_funcret==true)value_result=builder.CreateCall(func,{});
        else builder.CreateCall(func,{});
    }
}

void assembly_builder::visit(block_syntax &node)
{
    enter_scope();
    for(auto t : node.body)
    {
        t->accept(*this);
    }
    exit_scope();
}

void assembly_builder::visit(if_stmt_syntax &node)
{
    node.pred->accept(*this);
    auto if_cond = value_result;
    auto if_then = BasicBlock::Create(context, "", current_function);
    auto if_else = BasicBlock::Create(context, "", current_function);
    if(node.else_body)
    {
        auto if_next = BasicBlock::Create(context, "", current_function);
        builder.CreateCondBr(if_cond, if_then, if_else);
        builder.SetInsertPoint(if_then);
        node.then_body->accept(*this);
        builder.CreateBr(if_next);
        builder.SetInsertPoint(if_else);
        node.else_body->accept(*this);
        builder.CreateBr(if_next);
        builder.SetInsertPoint(if_next);
    }
    else
    {
        builder.CreateCondBr(if_cond, if_then, if_else);
        builder.SetInsertPoint(if_then);
        node.then_body->accept(*this);
        builder.CreateBr(if_else);
        builder.SetInsertPoint(if_else);
    }
}

void assembly_builder::visit(while_stmt_syntax &node)
{
    auto while_loop = BasicBlock::Create(context, "", current_function);
    auto while_true = BasicBlock::Create(context, "", current_function);
    auto while_next = BasicBlock::Create(context, "", current_function);
    builder.CreateBr(while_loop);
    builder.SetInsertPoint(while_loop);
    node.pred->accept(*this);
    auto while_cond = value_result;
    builder.CreateCondBr(while_cond, while_true, while_next);
    builder.SetInsertPoint(while_true);
    node.body->accept(*this);
    builder.CreateBr(while_loop);
    builder.SetInsertPoint(while_next);
}

void assembly_builder::visit(empty_stmt_syntax &node)
{
}
