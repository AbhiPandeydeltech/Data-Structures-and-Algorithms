#include <iostream>
using namespace std;

int power(int a,int b){
    if(b==0)
    return 1;
    
    return (a*power(a,b-1));
}

//optimised code 
int power2(int a,int b){
    if(b==0)
    return 1;

    if(b==1)
    return a;
    
   // recursive call 
    int ans=power(a,b/2);
    if(b&1)
    return a*ans*ans;

    return ans*ans;
}

int main(){
    int a,b;
    cin>>a>>b;

    // cout<<a<<" to the power "<<b<<" is : "<<power(a,b)<<endl; --> working fine
    cout<<a<<" to the power "<<b<<" is : "<<power2(a,b)<<endl;
    return 0;
}