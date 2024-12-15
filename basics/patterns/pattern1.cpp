#include <iostream>
using namespace std;

int main(){

    //Pattern 1;
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16


    //int i=int count=1; ---> this is wrong way to do so
    int n,i,count;
    cin>>n;
    i=count=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
    
    return 0;
}