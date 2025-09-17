/*
Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.
Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solveUsingTabulation(vector<int>&arr)
{
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    if(sum%2 != 0)
    {
        return false;
    }
    int target = sum/2;
    vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

    for(int i=0;i<=n;i++)
    {
        dp[i][0] = true;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(arr[i-1] <= j)
            {
                int taken = dp[i-1][j-arr[i-1]];
                int notTaken = dp[i-1][j];
                dp[i][j] = taken || notTaken;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
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

    bool flag = solveUsingTabulation(arr);
    if(flag){
        cout <<"true"<<endl;
    }
    else{
        cout <<"false"<<endl;
    }
}

