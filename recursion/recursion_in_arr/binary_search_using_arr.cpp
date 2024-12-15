#include <iostream>
using namespace std;

// binary search using recursion:

int binary_search(int *arr, int start, int end, int key)
{

    if (start > end)
        return -1; // base case  -> agr start end se bda hogaya to exist hi nhi krta key
    //-1 represents that not found

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return mid; // one more base case

    else if (arr[mid] < key)
        return binary_search(arr, mid + 1, end, key);

    return binary_search(arr, start, mid - 1, key);
}

// below code is only to check whether the key is present or not
bool binary_Search(int *arr, int start, int end, int key)
{
    if (start > end)
        return false; // base case  -> agr start end se bda hogaya to exist hi nhi krta key
    //-1 represents that not found

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return true; // one more base case

    else if (arr[mid] < key)
        return binary_search(arr, mid + 1, end, key);

    return binary_search(arr, start, mid - 1, key);
}

int main()
{
    int arr[6] = {2, 4, 6, 10, 14, 16};

    int key;
    cout << "Enter the key you want to search : ";
    cin >> key;
    
    cout<<key<<" is present or not : "<<binary_Search(arr,0,5,key)<<endl;
    if(binary_Search(arr,0,5,key))
    cout << "The index of " << key << " in the given array is : " << binary_search(arr, 0, 5, key) << endl;
    

    return 0;
}