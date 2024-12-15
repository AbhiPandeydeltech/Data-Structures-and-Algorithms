#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter the binary number : ";
    cin>>n;
    //yahan dhyan rhe ki jo hm input pe derhe hai vo hme pta hai ki binary hai lekin usko as an int derhe hai to ye sb dhyan rhe
    //neeche operation krte vkt
    //for eg n=110 , we know it is the binary representation of decimal 6, but since n is an int so inside the system 110 will be
    //represented in 32 bits and agr digit nikalne ke liye hmne yahan n&1 lga diya to gdbd hojaega

    int i=0;
    int answer=0;
    cout<<"The decimal no for given binary representation "<<n<<" is : ";
    while(n!=0){
        int digit=n%10;
        if(digit)
        {
            float c = pow(2,i);
            answer=(digit*c)+answer;
        }
        i++;
        n/=10;
    }
    cout<<answer;
    
    return 0;
}