#include <iostream>
using namespace std;

int main(){

//pattern :
// A A A A
// B B B B
// C C C C
// D D D D
    //method 1(a);
    int n;
    cin>>n;
    int i=0;
    while(i<n){
        int j=0;
        char ch= i+'A';     //i--> an integer ,'A'-> corresponding ASCII integer taken , added with i and then that integer
        //is typecasted to character from integer datatype
        while(j<n){
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    //method 1(b);
    cout<<endl;
    int k=1;
    while(k<=n){
        int l=1;
        char c='A'+k-1;
        while(l<=n){
            cout<<c<<" ";
            l++;
        }
        cout<<endl;
        k++;
    }

    //method 2:
    cout<<endl;
    int m=1;
    while(m<=n){
        int o=1;
        while(o<=n){
            cout<<char('A'+m-1)<<" ";   //here, char(int) --> as a typecasting used ,directy 
            o++;
        }
        cout<<endl;
        m++;
    }
    return 0;
}