#include <iostream>
using namespace std;

// 1         1
// 1 2     2 1
// 1 2 3 3 2 1
int main(){
    int n ;
    cin>>n;

    int i = 1;
    while(i<=n){
         int j = 1;
        while(j<=i){
            cout<<j<<" ";
            j++;
        }

        int spaces = 2*(n-i);
        while(spaces){
            cout<<"  ";
            spaces--;
        }
        j=i;
        while(j){
            cout<<j<<" ";
            j--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}