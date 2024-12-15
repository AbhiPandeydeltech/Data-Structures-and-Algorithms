#include <iostream>
using namespace std;

// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444
int main(){
    int n;
    cin>>n;
    int i = 1;
    int count = n;
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<(n-j+1);
            j++;
        }
        int num = 2*(n-i);
        while(num){
            cout<<count;
            num--;
        }
        count--;

        j=i-1;
        while(j){
            cout<<(n-j+1);
            j--;
        }
        cout<<endl;
        i++;
    }
    i = 1;
    count = i+1;
    while(i<=(n-1)){
        int j = 1;
        while(j<=(n-i)){
            cout<<(n-j+1);
            j++;
        }
        int num = 2*i;
        while(num){
          cout<<count;
          num--;
        }
        count++;
        j=n-i-1;
        while(j){
            cout<<(n-j+1);
            j--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}