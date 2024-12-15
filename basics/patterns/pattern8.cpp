#include <iostream>
using namespace std;
//pattern : 
// A B C D
// B C D E
// C D E F
// D E F G
int main(){
    //method 1(A): 
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<char('A'+i+j-2)<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    //method 1(B) : 
    cout<<endl;
    int k=0;
    while(k<n){
        int l=0;
        while(l<n){
            cout<<char('A'+k+l)<<" ";
            l++;
        }
        cout<<endl;
        k++;
    }

    //method 2:
    /*
    i=1;
    while(i<=n){
        j=1;
        count=i;
        while(j<=n){
            cout<<char('A'+count-1)<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
    */
   
    return 0;
}