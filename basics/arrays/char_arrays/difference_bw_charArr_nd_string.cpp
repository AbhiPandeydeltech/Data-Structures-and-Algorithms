#include <iostream>
using namespace std;

int main()
{
    string s;
    char name[20];
    cout << "Enter your name : " << endl;
    cin >> name;
    name[3] = '\0';

    cout << "Your name through char array : " << name << endl;

    cout << "Enter your name again : " << endl;
    cin >> s;
    s[3] = '\0';
    s[6] = '\0';

    cout << "Your name through string is : " << s << endl;

    // output :
    /*
     Enter your name :
     Abhishek
     Your name through char array : Abh
     Enter your name again :
     Abhishek
     Your name through string is : Abhshk
    */
   

    return 0;
}