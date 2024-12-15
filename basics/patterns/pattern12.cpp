#include <iostream>
using namespace std;

//pattern : 
// 1 2 3 4
//   2 3 4
//     3 4
//       4

int main(){
    int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int spaces=i-1;
        while(spaces){
            cout<<"  ";
            spaces--;
        }
        int j=i;
        while(j<=n){
            cout<<j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}