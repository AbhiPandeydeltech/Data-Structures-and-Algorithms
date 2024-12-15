#include <iostream>
using namespace std;

//pattern 6:
// 1
// 2 1
// 3 2 1
// 4 3 2 1

int main(){
    //method 1 : 
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<i-j+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    //method 1(b) :
    cout<<endl; 
    int k=0;
    while(k<n){
        int l=0;
        while(l<=k){
            cout<<k-l+1<<" ";
            l++;
        }
        cout<<endl;
        k++;
    }

    //method 2 : 
    cout<<endl;
    int p=1;
    while(p<=n){
        int q=1;
        int count=p;
        while(q<=p){
           cout<<count<<" ";
           count--;
           q++;
        }
        cout<<endl;
        p++;
    }
    return 0;
}