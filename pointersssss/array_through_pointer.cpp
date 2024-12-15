#include <iostream>
using namespace std;

int get_sum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*arr;
        ++arr;
    }
    return sum;
}


int get_Sum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    return sum;
}

//both above functions are same 

int main(){
    
    int arr[5]={1,2,3,4,5};
    cout<<"Sum of all elements through the first function are  : "<<get_sum(arr,5)<<endl;
    cout<<"Sum of all elements through the second function are : "<<get_Sum(arr,5)<<endl;

    char c[3]="ab";
    // char *ch=&c;  --> this is wrong due to change in behaviour 



    return 0;
}