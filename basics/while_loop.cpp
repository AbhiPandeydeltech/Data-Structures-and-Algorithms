#include <iostream>
using namespace std;

//there is some problem in the logic, refer the notes

int main()
{
    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};
    int i = 0;
    int j = 7;
    while (i < j)
    {
        while (arr[i] == 0)  //to make it working add &&(i<j) to both while blocks 
        {
            cout << "1st block" << endl;
            
            i++;
            cout << i << " & " << j << endl;
        }
        while (arr[j] == 1)
        {
            cout << "2nd block" << endl;
            // cout << i << " & " << j << endl;
            j--;
            cout << i << " & " << j << endl;
        }

        if (arr[i] == 1 && arr[j] == 0)
        {
            cout << "3rd block" << endl;
            // cout << i << " & " << j << endl;
            swap(arr[i], arr[j]);
            i++;
            j--;
            cout << i << " & " << j << endl;
        }
    }

    cout<<endl;
    for(int i=0;i<8;i++)
    cout<<arr[i]<<" ";  //--> output ->0 0 0 0 1 0 1 1 

    return 0;
}