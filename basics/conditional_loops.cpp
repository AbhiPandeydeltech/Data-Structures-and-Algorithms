#include <iostream>
using namespace std;

int main(){
    int a=9;
    if(a==9)
    cout<<"Niney ";
    if(a>0)
    cout<<"Positive ";
    else
    cout<<"Negative ";

    cout<<endl;

    int b=2;
    int c=b+1;

    if((b=3)==c)  //b is changed here 
    cout<<b;

    else
    cout<<b+1;

    cout<<endl;

    int d=24;

    if(d>20)
    cout<<"Love ";
    else if (d==24)
    cout<<"Lovely ";

    else
    cout<<"Babbar ";

    char ch;
    // cin>>ch;
    ch=cin.get();   //we can take characters as input like this also

    if(ch>='A' && ch<='Z')
    cout<<"Uppercase ";
    else if(ch>='a' && ch<='z')
    cout<<"Lowercase";
    else if(ch>='0' && ch<='9')
    cout<<"Digits";

    return 0;
}