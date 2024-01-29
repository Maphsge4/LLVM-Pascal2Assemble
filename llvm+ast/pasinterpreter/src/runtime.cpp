
#include <iostream>
#include "runtime.h"
#include "runtime/io.h"

#include <llvm/IR/Type.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/IRBuilder.h>

using namespace std;
using namespace llvm;

runtime_info::runtime_info(Module *module)
{
    inputivar = new GlobalVariable(*module,
                                   Type::getInt32Ty(module->getContext()),
                                   false,
                                   GlobalValue::ExternalLinkage,
                                   ConstantInt::get(Type::getInt32Ty(module->getContext()), 0),
                                   "inputivar");
    inputfvar = new GlobalVariable(*module,
                                   Type::getDoubleTy(module->getContext()),
                                   false,
                                   GlobalValue::ExternalLinkage,
                                   ConstantFP::get(Type::getDoubleTy(module->getContext()), 0),
                                   "inputfvar");
    outputivar = new GlobalVariable(*module,
                                    Type::getInt32Ty(module->getContext()),
                                    false,
                                    GlobalValue::ExternalLinkage,
                                    ConstantInt::get(Type::getInt32Ty(module->getContext()), 0),
                                    "outputivar");
    outputfvar = new GlobalVariable(*module,
                                    Type::getDoubleTy(module->getContext()),
                                    false,
                                    GlobalValue::ExternalLinkage,
                                    ConstantFP::get(Type::getDoubleTy(module->getContext()), 0),
                                    "outputfvar");
    auto inputIntimpl = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()),
                                                         {Type::getInt32PtrTy(module->getContext())},
                                                         false),
                                       GlobalValue::LinkageTypes::ExternalLinkage,
                                       "inputIntimpl",
                                       module);
    auto inputFloatimpl = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()),
                                                         {Type::getDoublePtrTy(module->getContext())},
                                                         false),
                                       GlobalValue::LinkageTypes::ExternalLinkage,
                                       "inputFloatimpl",
                                       module);
    auto outputIntimpl = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()),
                                                          {Type::getInt32PtrTy(module->getContext())},
                                                          false),
                                        GlobalValue::LinkageTypes::ExternalLinkage,
                                        "outputIntimpl",
                                        module);
    auto outputFloatimpl = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()),
                                                          {Type::getDoublePtrTy(module->getContext())},
                                                          false),
                                        GlobalValue::LinkageTypes::ExternalLinkage,
                                        "outputFloatimpl",
                                        module);

    IRBuilder<> builder(module->getContext());

    inputIntfunc = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()), {}, false),
                                  GlobalValue::LinkageTypes::ExternalLinkage,
                                  "inputInt",
                                  module);
    builder.SetInsertPoint(BasicBlock::Create(module->getContext(), "entry", inputIntfunc));
    builder.CreateCall(inputIntimpl, {inputivar});
    builder.CreateRetVoid();

    inputFloatfunc = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()), {}, false),
                                  GlobalValue::LinkageTypes::ExternalLinkage,
                                  "inputFloat",
                                  module);
    builder.SetInsertPoint(BasicBlock::Create(module->getContext(), "entry", inputFloatfunc));
    builder.CreateCall(inputFloatimpl, {inputfvar});
    builder.CreateRetVoid();

    outputIntfunc = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()), {}, false),
                                   GlobalValue::LinkageTypes::ExternalLinkage,
                                   "outputInt",
                                   module);
    builder.SetInsertPoint(BasicBlock::Create(module->getContext(), "entry", outputIntfunc));
    builder.CreateCall(outputIntimpl, {outputivar});
    builder.CreateRetVoid();

    outputFloatfunc = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()), {}, false),
                                   GlobalValue::LinkageTypes::ExternalLinkage,
                                   "outputFloat",
                                   module);
    builder.SetInsertPoint(BasicBlock::Create(module->getContext(), "entry", outputFloatfunc));
    builder.CreateCall(outputFloatimpl, {outputfvar});
    builder.CreateRetVoid();
}

using namespace string_literals;

vector<tuple<string, llvm::GlobalValue *, bool, bool, int,int>> runtime_info::get_language_symbols()
{
    return {
        make_tuple("inputivar"s, inputivar, false, false, 0,0),
        make_tuple("inputfvar"s, inputfvar, false, false, 1,0),
        make_tuple("outputivar"s, outputivar, false, false, 0,0),
        make_tuple("outputfvar"s, outputfvar, false, false, 1,0),
        make_tuple("inputInt"s, inputIntfunc, true, false, 0,0),
        make_tuple("inputFloat"s, inputFloatfunc, true, false,1,0),
        make_tuple("outputInt"s, outputIntfunc, true, false, 0,0),
        make_tuple("outputFloat"s, outputFloatfunc, true, false,1,0)};
}

vector<tuple<string, void *>> runtime_info::get_runtime_symbols()
{
    return {
        make_tuple("inputIntimpl"s, (void *)&::inputInt),
        make_tuple("inputFloatimpl"s, (void *)&::inputFloat),
        make_tuple("outputIntimpl"s, (void *)&::outputInt),
        make_tuple("outputFloatimpl"s, (void *)&::outputFloat) };
}
