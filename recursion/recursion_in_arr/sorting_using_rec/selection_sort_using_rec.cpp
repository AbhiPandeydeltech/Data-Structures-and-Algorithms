#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void selection_sort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return; // already sorted and base case
    int min_index = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[min_index] > arr[j])
            min_index = j; //----> 1 case solve , i.e find the smallest element and place it in its right place and then baki recursion
                           // smbhal lega
    }
    swap(arr[0], arr[min_index]);

    selection_sort(arr+1,n-1);
}

int main()
{
    int arr[10]={3,2,5,1,6,10,0,-1,11,11};

    cout << "Before sorting , arr : " << endl;
    print(arr, 10);

    selection_sort(arr, 10);
    cout << endl;
    cout << "After printing , arr : " << endl;
    print(arr, 10);
    return 0;
}