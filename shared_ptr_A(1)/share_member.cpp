#include <iostream>
#include <memory>
 
using namespace std;

struct Widget{
    int data;

    ~Widget(){
        cout<<"~Widget()"<<endl;
    }
};

struct SelfCircle{
    shared_ptr<SelfCircle> self;

    SelfCircle(){
        cout<<"SelfCircle()"<<endl;
    }
    ~SelfCircle(){
        cout<<"~SelfCircle()"<<endl;
    }
};

int main()
{
   
    {
         shared_ptr<Widget> spw(new Widget());

         shared_ptr<int> spd(spw, &spw->data);

         cout<<spd.use_count()<<endl;
         cout<<spw.use_count()<<endl;
         spw.reset();
         cout<<"after reset..."<<endl;
         cout<<spd.use_count()<<endl;
         cout<<spw.use_count()<<endl;


    }

    {
        shared_ptr<SelfCircle> spCircle{new SelfCircle()};
        spCircle->self=spCircle;
        cout<<spCircle.use_count()<<endl;
    }
}