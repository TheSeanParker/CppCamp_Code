#include <iostream>
using namespace std;



void process(int&& data);
void process(int& data);

void process(int&& data)
{
    cout<<"right value ref"<<endl;
    process(data); //right, or left? 
}

void process(int& data)
{
    cout<<"left value ref"<<endl;

}



int main()
{

    
    const int x=100;
    int y=200;

    //process(x);
    //process(100);

     //process(++x);
     //process(x++);

     //process(x=300);
     process(x+y);
    

     process(100);
     //"hello"
     //"hello"s


    
    // cout<<sizeof("hello")<<endl;
}