#include <iostream>
using namespace std;

int merge(int *arr, int *extra, int s, int e, int mid)
{
    int inv_count = 0;
    int i = s;
    int j = mid + 1;
    int k = s;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
            extra[k++] = arr[i++];
        else
        {
            extra[k++] = arr[j++];
            inv_count += (mid - i+1);
        }
    }
    while (i <= mid)
        extra[k++] = arr[i++];
    while (j <= e)
        extra[k++] = arr[j++];

    // copy back the merged elements into original array
    for (int i = s; i <= e; i++)
        arr[i] = extra[i];

    return inv_count;
}
int mergesort(int *arr, int *extra, int s, int e)
{
    int inv_count = 0;

    if (s == e)           // --> isko bhi use krke krskta tha but something new
        return inv_count; // jaise hi s=e hojae then 1 element bchega which is already sorted

    int mid = s + (e - s) / 2;
    // sort left part and count inversions int left part after creation of this leftpart by merging 2 array in the previous step
    inv_count +=mergesort(arr, extra, s, mid);
    // cout<<"left inv_count "<<inv_count<<endl;

    // sort right part and count inversions int right part after creation of this leftpart by merging 2 array in the previous step

    inv_count+= mergesort(arr, extra, mid + 1, e);
    // cout<<"right inv_count "<<inv_count<<endl;

    // merge both sorted left and right parts and count the no of inversions from merging left and right part
    inv_count+= merge(arr, extra, s, e, mid);
    // cout<<"merged inv_count "<<inv_count<<endl;

    return inv_count;
}

int main()
{
    int arr[5] = {5, 3, 2, 4, 1};
    int extra[5];
    cout << "Inversion count of the given array is : " << mergesort(arr, extra, 0, 4) << endl;

    

    return 0;
}