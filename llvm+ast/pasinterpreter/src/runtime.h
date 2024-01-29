
#ifndef _PAS_RUNTIME_H_
#define _PAS_RUNTIME_H_

#include <vector>
#include <tuple>

#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>

class runtime_info
{
    llvm::GlobalVariable *inputivar;
    llvm::GlobalVariable *inputfvar;
    llvm::GlobalVariable *outputivar;
    llvm::GlobalVariable *outputfvar;
    llvm::Function *inputIntfunc;
    llvm::Function *inputFloatfunc;
    llvm::Function *outputIntfunc;
    llvm::Function *outputFloatfunc;

  public:
    runtime_info(llvm::Module *module);

    std::vector<std::tuple<std::string, llvm::GlobalValue *, bool, bool, int,int>> get_language_symbols();

    std::vector<std::tuple<std::string, void *>> get_runtime_symbols();
};

#endif

