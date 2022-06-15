cmake_minimum_required(VERSION 3.0.0)#cmake 最低版本
project(hello VERSION 0.1.0)#项目名称

set(CMAKE_CXX_STANDARD 20)#C++版本

set(CMAKE_CXX_CLANG_TIDY
        clang-tidy-10;#这个要求clang-tidy-10版本
        -format-style='file';
        -checks=cppcoreguidelines*#clang-tidy-10的argument选项
        -header-filter=${CMAKE_CURRENT_SOURCE_DIR};
)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")

include_directories(${PROJECT_SOURCE_DIR})#包含目录设置为当前项目文件夹下
#add_executable(writer main.cpp Client.cpp FileWriter.cpp MemoryWriter.cpp TestWriter.cpp) 
add_executable(writer main.cpp) 


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
