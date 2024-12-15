#include <iostream>
using namespace std;

int main(){
    //1.'a' is typecasted to integer, 'a' a character is assigned with an integer 97 
    //'a'--> character with ASCII number 97 that is why output is 97
    int a='a';
    cout<<a<<endl;

    //2. 98 is an integer which is an ASCII value of character b , so here it is typecasted to character b 
    char ch=98;
    cout<<ch<<endl;  //output --> 'b'

    char d=255;
    cout<<d<<endl;  //1 Byte = 8 bits --> Max value : 2^8-1=255 --> this is the highest possible ASCII integer given to a character
    //that character we dont know 

    unsigned int b=-112;
    cout<<b<<endl;   //4294967294    


    return 0;
}