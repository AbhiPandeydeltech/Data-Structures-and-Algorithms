#include <iostream>
#include<cmath>
using namespace std;

int main(){
    
    //method 2 : using the knowledge of basics of conversion of decimal to binary 
    //edge cases : since we are storing the binary representation in int only , so after a certain range of n , it will exceed the int 
    //range --> so keep that in mind 
    //for eg n = 5 and answer came out be 101 --> which we know is the binary representaion of 5 but we have stored answer in int so..
    int n;
    cout << "Enter the decimal number : ";
    cin >> n;
    int answer = 0;
    int i = 0;
    cout << "Binary representation of the number is : " << endl;
    while (n!= 0)
    {
        int digit = n % 2;
        float c = pow(10,i);
        answer = (digit * c) + answer;
        //answer = (bit*pow(10,i)) + answer --> problem for representing odd numbers 
        //as pow(10,1)=9.999999...... and when taken as an integer it takes 9 instead of 9.9999.... , same for pow(10,2)=99.99999...
        //so i took pow(10,i) separately and took it as float in order to use 9.9999...as a whole 
        n /=2;
        i++;
    }
    cout<<answer;
    return 0;
}