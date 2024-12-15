#include <iostream>
using namespace std;

//checking if array is sorted or not using recursion(sorted in ascending order)
bool isSorted(int *arr,int n){

    //base case 
    if(n==0 || n==1)
    return true ;  //1 element hoga ya 1 bhi na ho to vo sorted hi mana jaega na

    //case 1 solve krlo;
    if(arr[0]>arr[1])
    return false; 
/*  
    arr++;
    n--;   --> either do like this or do one statement only like in line 19
    return isSorted(arr,n);
*/
    return isSorted(arr+1,n-1);
}

int sum_of_elements(int* arr,int n){
    int sum=arr[0];
    if(n==1)
    return sum;
    return sum+sum_of_elements(arr+1,n-1);
}
int main(){

    // int arr[5]={2,4,6,8,9}; --> op= sorted and sum=29 --> showing correctly 
    int arr[5]={3,2,5,1,6};
    
    if(isSorted(arr,5))
    cout<<"Sorted"<<endl;
    else
    cout<<"Not Sorted"<<endl;

    cout<<"Sum of all elements in the Array is : "<<sum_of_elements(arr,5)<<endl;
    
    return 0;
}