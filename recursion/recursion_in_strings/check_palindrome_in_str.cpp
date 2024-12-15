#include <iostream>
using namespace std;

bool isPal(string s, int i)
{
    if (i > (s.length() - i - 1))
        return true; 
 // base case , agr ye condition true hogaya iska mtlb hai ki just neeche vala condition kabhi true hua hi nhi and so return true here

    if (s[i] != s[s.length() - i - 1])
        return false; // base case

    return isPal(s,i+1);
}

int main()
{
    string s;
    cout << "Enter the string : ";
    getline(cin, s);

    if (isPal(s, 0))
        cout << "Yes,given string is a Palindrome" << endl;
    else
        cout << "No,given string is not a Palindrome" << endl;
    return 0;
}