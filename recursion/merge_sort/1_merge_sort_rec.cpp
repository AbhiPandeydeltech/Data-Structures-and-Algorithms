#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;

    // approach 1 : 2 arrays being created and values to be copied into them
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];  // creating those 2 arrays dynamically
    int *second = new int[len2]; // make sure to release the heap memory manually using delete

    int mainArrayindex = s; // arr ka index hai jisse values copy hongi
    for (int i = 0; i < len1; i++)
        first[i] = arr[mainArrayindex++]; // copying elements into first array

    for (int i = 0; i < len2; i++)
        second[i] = arr[mainArrayindex++]; // copying elements into second array

    // copy done now merge 2 sorted arrays :

    int i = 0;
    int j = 0;
    mainArrayindex = s;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
            arr[mainArrayindex++] = first[i++];
        else
            arr[mainArrayindex++] = second[j++];

        /*
        else{   //without this block also it will work fine
            arr[mainArrayindex++]=first[i++];
            arr[mainArrayindex++]=second[j++];
        */
    }

    while (i < len1)
        arr[mainArrayindex++] = first[i++];

    while (j < len2)
        arr[mainArrayindex++] = second[j++];

    delete[] first;
    delete[] second;
}
void mergesort(int *arr, int s, int e)
{
    if (s >= e)
        return; // jaise hi s=e hojae then 1 element bchega which is already sorted

    int mid = s + (e - s) / 2;
    // sort left part
    mergesort(arr, s, mid);

    // sort right part
    mergesort(arr, mid + 1, e);

    // merge both sorted left and right parts
    merge(arr, s, e);
}

int main()
{
    int arr[10] = {9, 8, 7, 100, -1, 100, 2, 3, 4, -9};

    cout << "before : " << endl;
    print(arr, 10);
    cout << endl;
    mergesort(arr, 0, 9);
    cout << "after : " << endl;
    print(arr, 10);

    return 0;
}