#include <iostream>
using namespace std;

int main()
{

    int arr[] = {1, 7, 9, 2, 3, 0, 10};
    for (int i = 0; i < 6; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < 7; j++)
        {
            if (arr[j] > arr[max_index])
                max_index = j;
        }
        swap(arr[max_index], arr[i]);
    }

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}