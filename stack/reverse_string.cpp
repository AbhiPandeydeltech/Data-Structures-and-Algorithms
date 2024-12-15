#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    stack<char>st;
    for(int i=0;i<s.length();i++)
    st.push(s[i]);
    
    string ans="";

    while(!st.empty()){
       ans+=st.top();
       st.pop();
    }

    cout<<"Reverse string is : "<<ans<<endl;
    
    return 0;
}