#include <iostream>
using namespace std;

class example1{
   char a;
   short int b;
   int c;
   char d;
};

//if the above class properties is written as decreasing order of their size then 
class example2{
    int c;
    short int b;
    char a;
    char d;
};

class Example {
    char c;
    double d;
    int i;
    short s;
};

//if the above class properties is written as decreasing order of their size then
class Example2{
    double d;
    int i;
    short s;
    char c;
};

int main(){

    cout<<"Size of class example1 is : "<<sizeof(example1)<<endl; //12 bytes --> concept of padding used here 
    cout<<"Sise of class example2 is : "<<sizeof(example2)<<endl;  //8 bytes ---> concept of greedy alignment used here
    cout<<"Sixe of class Example is : "<<sizeof(Example)<<endl; //24 bytes --> concept of padding used here 

    cout<<"Size of class Example2 is : "<<sizeof(Example2)<<endl; //16  bytes   ---> concept of greedy alignment used here

    
    return 0;
}