#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // we will here print binary by initialising it as int , but deep down we know ki inside system a decimal or int number is stored
    // in its bit form but to show here the transformation we doing this :

    int n;
    cout << "Enter the decimal number : ";
    cin >> n;
    int answer = 0;
    int i = 0;
    cout << "Binary representation of the number is : " << endl;
    while (n!= 0)
    {
        int bit = n & 1;
        float c = pow(10,i);
        answer = (bit * c) + answer;
        //answer = (bit*pow(10,i)) + answer --> problem for representing odd numbers 
        //as pow(10,1)=9.999999...... and when taken as an integer it takes 9 instead of 9.9999.... , same for pow(10,2)=99.99999...
        //so i took pow(10,i) separately and took it as float in order to use 9.9999...as a whole 
        n = n >> 1;
        i++;
    }
    cout<<answer;

    return 0;
}