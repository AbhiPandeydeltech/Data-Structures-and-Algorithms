#include <iostream>
using namespace std;

//linear search in the array using recursion 
bool isFound(int* arr,int n,int key){
    
    if(n==0)
    return false;  //base case 

    if(arr[0]==key)
    return true ;   //base case 

    return isFound(arr+1,n-1,key);
    
}

int main(){
    // int arr[5]={3,2,5,1,6};
    int arr[5]={2,4,6,8,9};
    
    int key;
    cout<<"check whether the key is present or not ";
    cin>>key;

    if(isFound(arr,5,key))
    cout<<key<<" is present in the given array "<<endl;
    else
    cout<<key<<" is not present in the given array "<<endl;
    return 0;
}