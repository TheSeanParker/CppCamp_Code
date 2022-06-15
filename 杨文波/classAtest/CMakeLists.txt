#CMake 支持大写、小写和大小写混合命令
cmake_minimum_required(VERSION 3.0.0)#cmake 最低版本
project(hello VERSION 0.1.0)## set the project name and version

set(CMAKE_CXX_STANDARD 17)#C++版本

set(CMAKE_CXX_CLANG_TIDY
        clang-tidy-10;#这个要求clang-tidy-10版本
        -format-style='file';
        -checks=cppcoreguidelines*#clang-tidy-10的argument选项
        -header-filter=${CMAKE_CURRENT_SOURCE_DIR};#当前Cmakelist所在的目录By default Clang-Tidy will not check your header files for problems. 
        #But you might be interested in running Clang-Tidy on your headers as well. This is done with the argument -header-filter=.. For example:
)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")# Debug模式下的编译参数
#有{CMAKE_CXX_FLAGS_DEBUG} 是追加模式，没有则是覆盖模式
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")

include_directories(${PROJECT_SOURCE_DIR}/include)#包含目录设置为当前项目文件夹下
#add_executable(writer main.cpp Client.cpp FileWriter.cpp MemoryWriter.cpp TestWriter.cpp) 
add_executable(abc classWithPointer.cpp) #编译


set(CPACK_PROJECT_NAME ${PROJECT_NAME})#代表hello
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})#set的本质是定义常量
include(CPack)
