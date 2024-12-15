#include <iostream>
#include <algorithm>
using namespace std;

// in this approach we wont be taking new arrays and copying right and left part into them
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void merge(int *arr, int s, int e, int mid, int maxi)
{
    int i = s;
    int j = mid + 1;
    int mainArrayindex = s;
    while (i <= mid && j <= e)
    {

        if (arr[i] % maxi < arr[j] % maxi)
        {
            arr[mainArrayindex] = arr[mainArrayindex] + (arr[i] % maxi) * maxi;
            mainArrayindex++;
            i++;
        }
        else
        {
            arr[mainArrayindex] = arr[mainArrayindex] + (arr[j] % maxi) * maxi;
            mainArrayindex++;
            j++;
        }
    }
    
    while (i <= mid)
    {
        arr[mainArrayindex] = arr[mainArrayindex] + (arr[i] % maxi) * maxi;
        mainArrayindex++;
        i++;
    }
    while (j <= e)
    {
        arr[mainArrayindex] = arr[mainArrayindex] + (arr[j] % maxi) * maxi;
        mainArrayindex++;
        j++;
    }
    // obtaining actual values now :
    for (int i = s; i <= e; i++)
        arr[i] = arr[i] / maxi;
}
void mergesort(int *arr, int s, int e, int maxi)
{
    if (s >= e)
        return; // jaise hi s=e hojae then 1 element bchega which is already sorted

    int mid = s + (e - s) / 2;
    // sort left part
    mergesort(arr, s, mid, maxi);

    // sort right part
    mergesort(arr, mid + 1, e, maxi);

    // merge both sorted left and right parts
    merge(arr, s, e, mid, maxi);
}

int main()
{
    int arr[10] = {9, 8, 7, 100, 0, 100, 2, 3, 4, 1};

    int maxi = *max_element(arr, arr + 10) + 1;

    cout << "before : " << endl;
    print(arr, 10);
    cout << endl;
    mergesort(arr, 0, 9, maxi);
    cout << "after : " << endl;
    print(arr, 10);

    return 0;
}