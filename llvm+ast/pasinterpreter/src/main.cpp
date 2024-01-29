#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/TargetSelect.h>

#include <pasrecognizer/recognizer.h>

#include "assembly_builder.h"

using namespace llvm;
using namespace std;
using namespace pas_recognizer;
using namespace syntax_tree;
using namespace std::literals::string_literals;

int main(int argc, char **argv)
{
    char *in_file = nullptr;
    bool emit_llvm = false;
    for (int i = 1; i < argc; ++i)
        if ("-emit-llvm"s == argv[i])  // 这个参数的作用是生成llvm ir，没有这个参数的话就是直接执行程序
            emit_llvm = true;
        else if ("-h"s == argv[i] || "--help"s == argv[i])
        {
            // 命令行有help参数时候的输出
            cout << "Usage: pasi [-emit-llvm] <input-pas-source>." << endl;
            return 0;
        }
        else if (argv[i][0] == '-')
        {
            cerr << "Unknown option '" << argv[i] << "'." << endl;
            return 1;
        }
        else
        {
            if (!in_file)
                in_file = argv[i];
            else
            {
                cerr << "Multiple input file specified. Compiling multiple sources is not supported in pas." << endl;
                return 1;
            }
        }

    if (!in_file)
    {
        cerr << "Input file expected." << endl;
        return 1;
    }


    ifstream in_stream(in_file);
    
    // 这两个都是在pasrecognizer的namespace里面定义的
    recognizer pasr(in_stream);
    error_reporter err(cerr);

    // 执行一个parse的过程
    bool temp=pasr.execute(err);
    if (!temp)
    {
        cerr << "Parsing failed. Exiting." << endl;
        return 2;
    }
    auto ast = pasr.get_syntax_tree();
    string name = in_file;
    name = name.substr(name.find_last_of("/\\") + 1);

    LLVMContext llvm_ctx;  // LLVM库里的
    assembly_builder builder(llvm_ctx, err);  // assembly_builder.h定义的
    
    builder.build(name, ast);  // 遍历AST并构建IR
    auto module = builder.get_module();
    auto runtime = builder.get_runtime_info();

    if (!module)
    {
        cerr << "Semantic failed. Exiting." << endl;  // semantic：语义的
        return 3;
    }

    if (emit_llvm)  // 如果命令行输入了这个参数，就只打印llvm ir
        module->print(outs(), nullptr);
    else
    {
        auto entry_func = module->getFunction("main");
        if (!entry_func)
        {
            cerr << "No 'main' function presented. Exiting." << endl;
            return 4;
        }
        
        // JIT（just-in-time）即时编译技术是在运行时（runtime）将调用的函数或程序段编译成机器码载入内存，以加快程序的执行。
        // 所以，JIT是一种提高程序时间和空间有效性的方法。
        InitializeNativeTarget();  // 主程序应该调用此函数来初始化与主机对应的本机目标。这对于JIT应用程序非常有用，以确保目标被正确地链接。客户端对这个函数进行多次调用是合法的。
        InitializeNativeTargetAsmPrinter();  // 主程序应该调用此函数来初始化本机目标asm打印机(asm是LLVM的汇编代码IR的意思吗？)
        InitializeNativeTargetAsmParser();  // 主程序应该调用这个函数来初始化本机目标asm解析器
        
        for (auto t : runtime->get_runtime_symbols())
            sys::DynamicLibrary::AddSymbol(get<0>(t), get<1>(t));

        string error_info;
        // unique_ptr持有对对象的独有权，即两个 unique_ptr 不能指向一个对象，不能进行复制操作只能进行移动操作。
        // unique_ptr 之所以叫这个名字，是因为它只能指向一个对象，即当它指向其他对象时，之前所指向的对象会被摧毁。
        // 其次，当 unique_ptr 超出作用域时，指向的对象也会被自动摧毁，帮助程序员实现了自动释放的功能
        unique_ptr<ExecutionEngine> engine(EngineBuilder(move(module))
                                               .setEngineKind(EngineKind::JIT)
                                               .setErrorStr(&error_info)
                                               .create());
        if (!engine)
        {
            cerr << "EngineBuilder failed: " << error_info << endl;
            return 4;
        }
        engine->runFunction(entry_func, {});
    }

    return 0;
}
