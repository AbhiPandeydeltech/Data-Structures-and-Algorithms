#include <iostream>
using namespace std;

//swap a string using recursion :

void swap_str(string& s,int start,int end){
    if(start>end)
    return ;   //base case 
    
    swap(s[start],s[end]); //1 case solve krlo
    swap_str(s,start+1,end-1);
}

//swap string using recursion and 1 pointer 
void swap_str2(string& s,int start){
    if(start>(s.length()-start-1))
    return ;   //base case 
    
    swap(s[start],s[s.length()-start-1]); //1 case solve krlo
    swap_str2(s,start+1);
}

int main(){
    string s;
    cout<<"Enter the string you want to reverse ";
    getline(cin,s);
    // int n=s.length(); 
    // swap_str(s,0,n-1); --> working fine

    swap_str2(s,0);

    cout<<"Reversed string is : "<<s<<endl;
    return 0;
}