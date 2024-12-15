#include <iostream>
using namespace std;

int main(){

    //pattern 4
// 1
// 1 2
// 2 3 4
// 4 5 6 7
    int n;
    cin>>n;
    int i,count;
    i=count=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<count<<" ";
            count++;
            j++;
        }
        count--;
        cout<<endl;
        i++;
    }
    
    cout<<endl;

    
    return 0;
}