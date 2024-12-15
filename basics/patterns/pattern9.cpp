#include <iostream>
using namespace std;

// pattern :
//        *
//      * *
//    * * *
//  * * * *

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {

        // print spaces :

        int spaces = n - i;
        while (spaces)
        {
            cout << "  ";
            spaces--;
        }

        // print columns :

        int j = 1;
        while (j <= i)
        {
            cout << "* ";
            j++;
        }
        cout << endl;

        i++;
    }
    return 0;
}