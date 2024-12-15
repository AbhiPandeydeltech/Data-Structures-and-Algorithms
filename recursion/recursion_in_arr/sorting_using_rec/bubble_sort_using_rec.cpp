#include <iostream>
using namespace std;

void print(int * arr, int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

void bubble_sort(int *arr,int n){
    if(n==0 || n==1)
    return ;
    
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);  // 1 case solved 
    }

    bubble_sort(arr,n-1);

}
int main(){
    int arr[10]={3,2,5,1,6,10,0,-1,11,11};

    cout<<"Before sorting , arr : "<<endl;
    print(arr,10);
    
    bubble_sort(arr,10);
    cout<<endl;
    cout<<"After printing , arr : "<<endl;
    print(arr,10);
    return 0;
}