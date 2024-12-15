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

    int count = 0; // storing the count of elements lesser than pivot
    for (int i = s + 1; i <= e; i++)
        if (arr[i] < pivot)
            count++;

    // putting pivot element into its position
    int pivot_index = s + count;
    swap(arr[s], arr[pivot_index]);

    // correcting the positions of all the elements in the left side of pivot and right side of pivot
    int i = s;
    int j = e;
    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] < pivot && (i < pivot_index && j > pivot_index) )   //-> y this condition also 
            i++;  //--> see the case of 70,30,50,40 and suppose 50 is the pivot element u will get it and similarly for neeche vala too

        while (arr[j] > pivot && (i < pivot_index && j > pivot_index) )
            j--;

        // agr upr vale dono blocks valid nhi to swap hi hoga bs
        if (i < pivot_index && j > pivot_index)
            swap(arr[i], arr[j]);
    }

    return pivot_index;
}

void quicksort(int *arr, int s, int e)
{
    if (s >= e)
        return; // base case

    // partition :
    int p = partition(arr, s, e);

    // quicksort in left part of arr
    quicksort(arr, s, p - 1);

    // quicksort in right part of arr
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[10] = {-9, 8, 7, 100, 0, 100, 2, 3, 4, -1};

    cout << "Before : " << endl;
    print(arr, 10);

    cout << "After : " << endl;
    quicksort(arr, 0, 9);
    print(arr, 10);

    return 0;
}