#include <iostream>
#include<cstring>
#include <vector>
using namespace std;

//memoisation 
int f(int n,vector<int>& dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = f(n-1,dp)+f(n-2,dp);
}

int main(){
    int n ;
    cin>>n;

/*
    int dp[n+1];
    memset(dp,-1,sizeof dp);
*/

    //by usinf vector 
    vector<int>dp(n+1,-1);

    int ans = f(n,dp);
    cout<<ans<<endl;

//tabulation with space complexity constant 
   int prev2 = 0;
   int prev = 1;
   int curri = -1;
   for(int i=2;i<=n;i++){
      curri = prev + prev2;
      prev2 = prev;
      prev = curri;
   }

   cout<<prev;

    return 0;
}