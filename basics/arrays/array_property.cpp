#include <iostream>
using namespace std;

int main()
{   
    //reason of the below is cited in word file made by me 
    int a[5] = {1, 2, 3, 4, 5};
    if (a == &a[0])
    {
        cout << "TRUE" << endl;
    }

    /*
        if(a==&a){           since a and &a are not same so this will be an error
                cout<<"TRUE"<<endl;
            }
    */
    /*
        if(&a==&a[0]){   --> &a and &a[0] are also not same
            cout<<"TRUE"<<endl;
        }
    */
    cout<<&a<<endl;
    cout<<a<<endl;   //11-13---> output is same but a and &a are not same
    cout<<&a[0]<<endl;

    cout<<sizeof(a)<<endl;  //---> o/p = 20
    cout<<sizeof(&a)<<endl; //---> o/p=4

    int b[5]={1};
    for(int i=0;i<5;i++)
    cout<<b[i]<<" ";
    cout<<endl;

    int c[5];
    c[0]=2;
    for(int i=0;i<5;i++)
    cout<<c[i]<<" ";
    cout<<endl;

    

    return 0;
}