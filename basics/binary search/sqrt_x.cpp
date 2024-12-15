#include <iostream>
#include<cmath>
using namespace std;

int binary_search(int n)
{
    int start = 0;
    int end = n;
    long long int mid = -1;
    int ans = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        long long int square = mid * mid;
        if (square == n)
            return mid;
        else if (square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else 
        end=mid-1;
    }
    return ans;
}

double moreprecision(int n,int precision){
    //int precision is given for determining upto what decimal number i want to answer 
    double d=binary_search(n);
    for(int i=1;i<=precision;i++){
        double e=pow(10,-i);
        for(double j=d;j*j<=n;j=j+e)
        d=j;
    }
    return d;
}

int main()
{
    int n;
    cout<<"Enter a number whose square root need to be found : ";
    cin>>n;
    // cout<<"sqrt of "<<n<<" is "<<binary_search(n);
    // int integral_part=binary_search(n);

    cout<<"sqrt of "<<n<<" is "<<moreprecision(n,3); //upto 3 precision pooint i want answer
    
    return 0;
}