#include <iostream>
using namespace std;

int main()
{

    int num = 5;


    //  char *ch="abcde";
    const char *ch="abcde"; // --> use this instead of above one 
    // cout << num << endl;
    // cout << &num << endl;
    // cout << *(&num) << endl;
    // cout << "Size of pointer is : " << sizeof(&num) << endl; // 4 bytes

    // int *ptr = 0;
    // cout << *ptr << endl;   ---> here segmentation fault is there, segmentation fault ke neeche ke codes nhi chlenge

    cout << (num++) << endl; // so (num++) and num++ is same

    int i = 3;
    int *t = &i;

    cout << (*t)++ << endl; // op => *t=3 (pehle print kro phir update kro) , after printing *t=3+1=4
    cout << i << endl;      // 4
    cout << *t << endl;     // 4

    cout << ((*t)++) << endl; // op=4 then increement *t=4+1=5
    // ((*t)++) = *t++ or better (*t)++ , bahr bracket lgane se wont change ki first print *t then increement

    cout << *t++ << endl; // op=5 then increement t, i.e t=t+1 ---> will now point the next memory location of previous address
    cout << *t << endl;   // as t changed,, now it wont be pointing to i, and now it will give some garbage value
    // op=6422280

    cout << *(t++) << endl; // op = 6422284 --> here abnormal--> bad practice bcs we dont know ki t ab kisko point krrha hai, it might
    // be some read only memory , ya phir kuch bhi hoskta hai so that's why not getting here what expected
    cout << *t << endl; // op = 6  (as t is now again increemented and now again it will give some garbage value )

    // *t++ != (*t)++
    // but *t++ = *(t++)
    // 1. t will be increemented here i.e t=t+1--> again next mem location
    // 2.now print *t --> which will be again some garbage value

    /*
        //t has now increementeed twice by 1 so to make t point again to i
        cout<<*--t<<endl; // 6422280  --> *--t = same to *(--t) , but for better readability and understanding use the later

        cout<<*--t<<endl; //5
    */

    cout << *t-- << endl;
    cout << *t << endl;
    cout << *t-- << endl; // here also abnormal--> bad practice bcs we dont know ki t ab kisko point krrha hai, it might
                          // be some read only memory , ya phir kuch bhi hoskta hai so that's why not getting here what expected

    cout << *t << endl;

    cout<<ch<<endl;



    return 0;
}