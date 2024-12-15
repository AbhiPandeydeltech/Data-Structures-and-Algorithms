#include <iostream>
using namespace std;

int main(){

    for(int a=0,b=1;a<=0 && b>=1;a--,b--)   //---> multiple variables can be used as well in for loop
    cout<<a<<" "<<b<<endl;

    for(int i=0;i<=15;i+=2){
        cout<<i<<endl;

        if(i&1)
        continue;

        i++;
    }
    return 0;
}