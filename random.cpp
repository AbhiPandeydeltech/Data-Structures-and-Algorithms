#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> func(vector<int> &arr, int window)
{
    vector<int> ans;
    int n = arr.size();
    queue<pair<int, int>> q; //{element,index}

    int j = 0;
    while (j < window)
    {
        if (arr[j] < 0)
        {
            q.push({arr[j], j});
        }
        j++;
    }

    if (q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        int ind = q.front().second;
        if (ind < j && ind >= (j - window))
        {
            ans.push_back(q.front().first);
        }
    }

    while (j < n)
    {
        if (arr[j] < 0)
        {
            q.push({arr[j], j});
        }
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int ind = q.front().second;
            while(!q.empty() && !(ind <= j && ind >= (j - window+1))){
                q.pop();
                ind = q.front().second;
            }
            if(!q.empty()){
                ans.push_back(q.front().first);
            }
            else{
                ans.push_back(0);
            }
        }
        j++;
    }

    return ans;
}

int main()
{

    vector<int>arr={11,-2,19,37,64,-18};
    vector<int>ans = func(arr,3);

    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}