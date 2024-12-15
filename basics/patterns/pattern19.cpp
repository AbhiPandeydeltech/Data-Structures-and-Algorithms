#include <iostream>
using namespace std;

//     *
//    * *
//   * * *
//  * * * *
// * * * * *
// * * * * *
//  * * * *
//   * * *
//    * *
//     *


//    *
//   * *
//  * * *
// * * * *
// * * * *
//  * * *
//   * *
//    * 
int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int spaces = n - i;
        while (spaces)
        {
            cout << " ";
            spaces--;
        }
        int star = 1;
        while (star <= i)
        {
            if (star % 2 != 0)
                cout << "*";
            else
                cout << " ";
            star++;
        }
        int j = 1;
        while (j <= (i - 1))
        {
            if ((i + j) % 2 != 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            j++;
        }
        cout << endl;
        i++;
    }
    i = 1;
    while (i <= n)
    {
        int spaces = i - 1;
        while (spaces)
        {
            cout << " ";
            spaces--;
        }
        int star = 1;
        while (star <= (n - i + 1))
        {
            if (star % 2 != 0)
                cout << "*";
            else
                cout << " ";

            star++;
        }
        int star2 = 1;
        while (star2 <= (n - i))
        {
            if (n % 2)
            {
                if ((i + star2) % 2 != 0)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                if ((i + star2) % 2 != 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
            }
            star2++;
        }

        cout << endl;
        i++;
    }
    return 0;
}