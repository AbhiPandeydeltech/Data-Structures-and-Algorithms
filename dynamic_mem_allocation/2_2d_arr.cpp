#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    //make 2d array using dynamic memory or heap memory with n*n dimension 
    
    int **arr=new int*[n]; //arr is a pointer to an array in heap having its element as pointer (int *) type

    //each block of the above array will point an array 

    for(int i=0;i<n;i++)
    arr[i]= new int[n]; //arr[i]= *(arr+i) = which will be a pointer and then apply the 1D allocation here 

    //taking input 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    
    //for output 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    //releasing memory 
    for(int i=0;i<n;i++)
    delete []arr[i];  //first releasing all the 1D array 

    delete []arr; //then delete the pointers storing array initialised at line 11 
    return 0;
}