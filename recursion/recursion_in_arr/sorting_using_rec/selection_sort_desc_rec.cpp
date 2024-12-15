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
        return;

    // in selection_sort desc, largest elements ko shi posi pe lao using selection sort algo
    int max_index = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] > arr[max_index])
            max_index = j;
    }
    swap(arr[0],arr[max_index]);   //--> 1 case solved 

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