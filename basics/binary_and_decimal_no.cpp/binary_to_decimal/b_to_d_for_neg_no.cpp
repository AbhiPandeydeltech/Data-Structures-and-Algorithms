#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the binary number : ";
    cin >> n;

    // here n is the binary representaion of negative no , that means first digit will be 1 always and it will show that n is the
    // binary representation of the negative numbers

    int i = 0;
    int answer = 0;
    cout << "The negative decimal number for the given binary no " << n << " is : ";
    while (n != 0)
    {
        int digit = n % 10;
        /*method 1 :
        int bit=0;
        if (digit)
        {
            bit = 0;
        }
        else
        {
            bit = 1;
        }
        if (bit)
        {
            float e = pow(2, i);
            answer = (bit * e) + answer;
        }
        */
       
       //method 2 : 
        if (!digit)
        {
            float e = pow(2, i);
            answer = (!digit* e) + answer;
        }   //--> upto here,method 2
        n /= 10;
        i++;
    }

    answer = answer + 1;
    answer = -answer;
    cout << answer;

    return 0;
}