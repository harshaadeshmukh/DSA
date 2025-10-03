/*
Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveUsingTabulation(vector<int>& nums){

    set<int>s(nums.begin(),nums.end());
    vector<int>arr(s.begin(),s.end());

    int m = nums.size();
    int n = arr.size();

    vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(nums[i-1] == arr[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}


int solveUsingTabulation2(vector<int>& nums)
{
    int n = nums.size();
    vector<int>dp(n,1);

    int maxi = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = max(dp[i] , 1+dp[j]);
                maxi = max(maxi,dp[i]);
            }
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin >>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
    }

    cout <<solveUsingTabulation(arr) <<endl;

    cout<<solveUsingTabulation2(arr)<<endl;
    return 0;
}