#include <iostream>
using namespace std;

int main()
{

    int a = 1, b = 2;

    if (a-- > 0 && ++b > 2)   // a-- > 2 is checked first(if it is true)and then ++b>2 is checked , if true then ....
                              // both a and b will be changed
        cout << "Hi" << endl; // if a-- > 2 is checked first and it came out to be false then no need to check further for ++b > 2
                              // because in case of and operator if one becomes false then the overall logic will be false only
    else
        cout << "Hello" << endl;
    cout << a << " and " << b << endl;
   /* output of above : 
    {here since a-- > 2 ---> true then check for the second logic as well and since ++b > 2 is true , then the if block will be 
    executed and both a and b will undergo value change}
   */

    cout << endl;

    int c = 1, d = 2;
    if (c-- > 0 || ++d > 2) // similarly in case of or operator , check for c-- > 0 , and if it came out to be true then no need to check
                            // for the second logic as if one of the logic is true then the whole logic will be true as well
        cout << "Hi" << endl;
    else
        cout << "Hello" << endl;
    cout << c << " and " << d << endl;

    /*output of above : 
   {here since c-- > 0 then there is no need to check for the seconf condition as if one of the logic is true then the 
    whole logic will be true as well in case of or operator and so ++d > 2 is untouched , hence only c will undergo value change 
    and d will remain as it is }*/
    return 0;
}