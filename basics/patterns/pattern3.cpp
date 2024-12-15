#include <iostream>
using namespace std;

int main(){

//Pattern 3 : 
// 1
// 2 3
// 4 5 6
// 7 8 9 10
    int n;
    cin>>n;
    int i,count;
    i=count=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}