#include <iostream>
#include <string>
#include "include/func.h"
//拷贝构造和普通构造函数的本质区别在参数是类类型，而不是其他类型
int main(int argc, char const *argv[])
{
    /* code */
    int x=2;
    
    std::cout<<"Output func(x)="<<func(x)<<std::endl;
    return 0;
}
