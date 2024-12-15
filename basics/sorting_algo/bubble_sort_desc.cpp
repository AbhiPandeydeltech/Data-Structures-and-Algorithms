#include <iostream>
using namespace std;

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        { // j<n-i-1
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void bubble_sort_optimal_sol(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool is_true = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                is_true = 1;
            }
        }
        if (is_true == 0)
            break;
    }
}

int main()
{

    int arr[] = {1, 7, 9, 2, 3, 0, 10};

    bubble_sort_optimal_sol(arr, 7);
    // bubble_sort(arr,7);

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}