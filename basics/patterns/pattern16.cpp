#include <iostream>
using namespace std;

// 1
// 01
// 101  whether (i+j) is even or not , if even then print 1 or print 0
// 0101
int main(){
    int n ;
    cin>>n;

    int i = 0 ;
    while(i<n){
        int j = 0;
        while(j<=i){
           if((i+j)%2 == 0){
               cout<<1;
           }
           else
           cout<<0;

           j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}