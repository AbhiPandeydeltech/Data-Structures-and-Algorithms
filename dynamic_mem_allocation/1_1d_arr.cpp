#include <iostream>
using namespace std;


//function calling : 

int sum(int *arr,int n){
    int s=0;
    for(int i=0;i<n;i++)
    s+=i[arr];
    return s;
}
int main(){

 /*   
    int n;
    cin>>n;  --> bad practice, read from notes 
    int arr[n];
 */

   //instead use the below to create variable size array using heap memory or dynamic memory 
   int n;
   cin>>n;

   int *arr=new int[5];

   for(int i=0;i<n;i++)
   cin>>arr[i];
  
   cout<<"Sum of all elements in the array is : "<<sum(arr,n)<<endl;

   delete []arr; //--> heap memory are deleted manuallyy by this 

   cout<<"Successfully done";


    return 0;
}