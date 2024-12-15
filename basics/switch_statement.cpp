#include <iostream>
using namespace std;

int main()
{
    /*
    int a=2;
    while(true){
        switch(a){
            case 1: cout<<"One"<<endl;
            // break;
            exit(1);  //--> works fine here as well
            case 2: cout<<"Two"<<endl;
            // break;
            exit(1);
        }
        // exit(1);  --> works fine here
    }
    */

/*
    int num = 2;
    switch (num)
    {
    case 1:
        cout << num << endl;
        // continue;
        break;
    case 2:
    { //hm chahein to block ka bhi use krskte hai nhi to direct bhi likh skte hai it will work fine
        cout << (num + 1) << endl; // output : error: continue statement not within a loop
        cout << "Hi" << endl;
    }

    break;
    }

*/

   int n;
   cout<<"Enter the amount : "<<endl;
   cin>>n;
   int m=n; //for printing the amount below in switch statement as n will keep on changing
   while(n!=0){
    int num;
    cin>>num;
    switch(num){
        case 100:cout<<"The number of 100 ruppee notes in "<<m<<" is "<<(n/100)<<endl;
        break;
        case 20: cout<<"The number of 20 ruppee notes in "<<m<<" is "<<(n/20)<<endl;
        break;
        case 10:cout<<"The number of 10 ruppee notes in "<<m<<" is "<<(n/10)<<endl;
        break;
        case 5:cout<<"The number of 5 ruppee notes in "<<m<<" is "<<(n/5)<<endl;
        break;
        case 1:cout<<"The number of 1 ruppee notes in "<<m<<" is "<<(n)<<endl;
        break;
    }
    n=(n%num);
   }
    return 0;
}