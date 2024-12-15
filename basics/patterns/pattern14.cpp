#include <iostream>
using namespace std;

//pattern :
//         1
//       1 2 1
//     1 2 3 2 1
//   1 2 3 4 3 2 1
// 1 2 3 4 5 4 3 2 1

int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        int spaces=n-i;
        while(spaces){
            cout<<"  ";
            spaces--;
        }
        int j=1;
        while(j<=i){
            cout<<j<<" ";
            j++;
        }
        int k=i-1;
        while(k){
            cout<<k<<" ";
            k--;
        }
        cout<<endl;
        i++;
    }

    return 0;
}