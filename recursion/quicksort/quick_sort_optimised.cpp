#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int i=s;
    int j=e;
    while(i<=j){
        while(arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<=j)
        swap(arr[i],arr[j]); 
    }
     //j will be the pivot index
    swap(arr[s],arr[j]);

    return j;
}


void quicksort(int *arr, int s, int e)
{
    if (s >= e)
        return; // base case

    // partition :
    int p = partition(arr, s, e);
    cout<<"partition index : "<<p<<endl;

    // quicksort in left part of arr
    quicksort(arr, s, p - 1);

    // quicksort in right part of arr
    quicksort(arr, p + 1, e);
}

int main()
{
    // int arr[9] = {-9, 8, 7, 100, 0, 100, 2, 3, -1};

    int arr[5]={3,1,4,5,2};

    cout << "Before : " << endl;
    print(arr, 5);

    cout << "After : " << endl;
    quicksort(arr, 0, 4);
    print(arr, 5);

    return 0;
}