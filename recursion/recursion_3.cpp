// 2 files already made in previous dsa folder

//below is the code for a codestudio problem named as " Count Ways To Reach The N-th Stairs" --> code is correct
//just showing TLE for big no of n -> for that DP will be used which we will study later on 
#include <iostream>
#include <vector>
using namespace std;
int countDistinctWays(int nStairs)
{   
    //approach 1 : using recursion 
    /* recursion generating TLE :
        if(nStairs<=0)
        return 1;

        return (countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2));
    */

//approach 2 : 
    if(nStairs<=1)
    return 1;

    vector<int>arr(nStairs+1);
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= nStairs; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    return arr[nStairs];
}

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << countDistinctWays(n) << endl;
    }
    return 0;
}