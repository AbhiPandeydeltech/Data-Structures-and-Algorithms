#include <iostream>
using namespace std;

// pattern :
//  + + + +
//    + + +
//      + +
//        +

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int spaces = i - 1;
        while (spaces)
        {
            cout << "  ";
            spaces--;
        }
        int j = 1;
        while (j <= (n - i + 1))
        {
            cout << "+ ";
            j++;
        }
        cout << endl;
        i++;
    }

    // pattern :
    //     1 1 1 1
    //       2 2 2
    //         3 3
    //           4

    cout << endl;
    int p = 1;
    while (p <= n)
    {
        int spaces = p - 1;
        while (spaces)
        {
            cout << "  ";
            spaces--;
        }
        int j = 1;
        while (j <= (n - p + 1))
        {
            cout << p << " ";
            j++;
        }
        cout << endl;
        p++;
    }
    return 0;
}