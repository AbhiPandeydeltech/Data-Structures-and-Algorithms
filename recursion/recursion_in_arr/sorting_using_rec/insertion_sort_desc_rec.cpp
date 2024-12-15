#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// void insertion_sort(int *arr,int i=1,int n){this will be an error because default argument declaration must start from the rightmost
void insertion_sort(int *arr, int n, int i = 1)
{
    if(n==0 || n==1)
    return ;
    
    if(i>=n)
    return ;

    int temp=arr[i];
    int j=i-1;
    for( ;j>=0;j--){
        if(arr[j]<temp)
        arr[j+1]=arr[j];
        else
        break;
    }
    arr[j+1]=temp;  //1 case solved 

    insertion_sort(arr,n,i+1);
}

int main()
{
    int arr[10]={3,2,5,1,6,10,0,-1,11,11};

    cout << "Before sorting , arr : " << endl;
    print(arr, 10);

    insertion_sort(arr, 10);
    cout << endl;
    cout << "After printing , arr : " << endl;
    print(arr, 10);
    return 0;
}