#include <iostream>
#include<cmath>
using namespace std;

int main(){
    
    int n;
    cout << "Enter the decimal number : ";
    cin >> n;
    // int c =( ~(-n) + 1);   -->this is equal to n only 
    int c= (~n);
    int answer=0;
    int i=0;
    while(c!=0){
        int bit;
        if(c&1)
        bit=0;
        else
        bit=1;
        float e=pow(10,i);
        answer=(bit*e)+answer;
        i++;
        c=c>>1;
    }
    float d= pow(10,i);
    answer=(1*d) + answer;
    cout<<answer;
    

    
    return 0;
}