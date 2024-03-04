CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

add_definitions(-DFULL_IMPL)

SET (CMAKE_CXX_STANDARD 14)

# 2.26新加的
# add_definitions(-std=c++14)

# 会在llvm+ast/install/cmake目录下寻找pasrecognizer-config.cmake文件
# 找到了，就对了；找不到，就报错
# 然后你在cmake命令里面-Dpasrecognizer_DIR这个参数要和这个package名对应！
find_package(pasrecognizer)
include_directories(${PASRECOGNIZER_INCLUDE_DIRS})
link_directories(${PASRECOGNIZER_LIBRARY_DIRS})

# Import LLVM
# 是不是说以config的模式寻找package？没查过
# 既然又用了find_package，所以在cmake命令里面有了-DLLVM_DIR这个参数
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
llvm_map_components_to_libnames(llvm_libs core mcjit native)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

include_directories(dependency/pasrecognizer/include)
add_executable(pasi
  src/main.cpp
  src/assembly_builder.cpp
  src/runtime.cpp
  src/runtime/io.c
  src/assembly_builder.h
  src/runtime.h
  src/runtime/io.h)
target_link_libraries(pasi ${PASRECOGNIZER_LIBS} ${llvm_libs})
