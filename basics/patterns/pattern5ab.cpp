#include <iostream>
using namespace std;

int main()
{
    // pattern 5:
    // 1
    // 2 3
    // 3 4 5
    // 4 5 6 7

    // method 1 :
    int n;
    cin >> n;
    int k = 1;
    while (k <= n)
    {
        int l = 1;
        int count1 = k;
        while (l <= k)
        {
            cout << count1 << " ";
            count1++;
            l++;
        }
        cout << endl;
        k++;
    }

    // method 2(a) :
    
    cout << endl;
    int i = 1;   
    while (i <=n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << j + i-1 << " ";
            j++;
        }
        cout << endl;
        i++;
    }

    //method 2(b) : 
    cout<<endl;
    int m=0;
    while(m<n){
        int o=0;
        while(o<=m){
            cout<<m+o+1<<" ";
            o++;
        }
        cout<<endl;
        m++;
    }
    return 0;
}