#include <iostream>
#include <memory>
using namespace std;

class Base 
{ 
public:
    int a; 
    virtual void process()  { 
        std::cout << "Base.process()"<<endl;
    }
    ~Base(){

        cout<<"~Base"<<endl;
    }
};
 
class Sub : public Base
{
public:
    void process()  override{ 
        std::cout << "Sub.process()"<<endl; 
    }

    void invoke(){
        std::cout << "Sub.invoke()"<<endl;
    }
    ~Sub(){

        cout<<"~Sub"<<endl;
    }
};
 
int main(){

    {
        Base* b1=new Base();
        Sub* s1=new Sub();

        Base* b2=s1;
        b2->process();

        Sub* s3=dynamic_cast<Sub*> (b2);
        s3->process();

        delete b1;
        delete b2; //非虚析构，非多态删除

    }
    cout<<"block 1--------"<<endl;

    {
        Base* b1=new Base();
        Sub* s1=new Sub();

        shared_ptr<Base> sp1{b1};
        shared_ptr<Base> sp2{s1};

        shared_ptr<Base> sp3{sp1};
        
        sp3->process();
        sp3.reset();
    }
    
 
    // auto s1 = std::make_shared<Sub>();
    // s1->process();

    // //shared_ptr<Base> b2{b1};
    // shared_ptr<Base> s4{s1};
    // s4->process();
    // //shared_ptr<Sub> s3{s2};

 
    //  shared_ptr<Base> b2 = std::static_pointer_cast<Base>(s1);

    //  s1.reset();
    //  b2->process();
 
    // //shared_ptr<Sub> s3=shared_ptr<Sub>( dynamic_cast<Sub*>(b2.get()) );

    //  shared_ptr<Sub>  s2 = std::dynamic_pointer_cast<Sub>(b2);    //共享所有权，但指向b2.get()

    // // //shared_ptr<Sub>  s2 {  dynamic_cast<Sub*> (b2.get())}; 

    // // if(s2!=nullptr)
    // // { 
    // //     s2->invoke();
    // // }
 
    //  //std::cout <<  s2.use_count() <<endl; 
    
}