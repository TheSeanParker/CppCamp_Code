#include <iostream>
using namespace std;


class Base{
public:
    void process()
    {

    }
 
};

class Sub1{
    Base b; //组合 1
    double data; //8

public:
    void func(){
        b.process();
    }
};

// 私有继承 == 组合
class Sub2: private Base{ //空基类优化 惯用法
    double data; //8

public:
    void func(){
        Base::process();
    }
};



int main()
{
    cout<<sizeof(Base)<<endl;// 1
    cout<<sizeof(Sub1)<<endl;// 
    cout<<sizeof(Sub2)<<endl;//  

    
}