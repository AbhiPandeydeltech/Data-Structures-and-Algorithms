#include <iostream>
using namespace std;

int main()
{
    int b = 1;   //global variable of all block
    cout << b << " a global variable of all " << endl;

    if (true)
    {
        int b = 2;  //global value of this block aur inke neeche sbhi blocks ka global variable
        if (true)
        {    
            cout << b << endl;  //present block me there is no local variable as b, so iska global variable print hojaega
            if (true)
            {   b=3;  //global value changed 
                // cout << b << endl;
                if(true)
                {
                    cout<<b<<endl;   //no local variable , global will be printed 
                }
            }
        }
    }

    return 0;
}