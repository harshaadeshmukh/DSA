/*
Example 1:
Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

Example 2:
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

Example 3:
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.

Example 4:
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.

Example 5:
Input : 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
target : 15
Output : 155117520
Using recursion : 155117520

reference: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// solve using recursion + memoization
int solveUsingRecursion(int i, int target, const vector<int>&arr)
{
    if(target == 0)
    {
        return 1;
    }
    if(i==0)
    {
        return (arr[0] == target);
    }


    int taken = 0;
    if(arr[i]<=target)
    {
        taken = solveUsingRecursion(i-1, target-arr[i], arr);
    }
    int not_taken = solveUsingRecursion(i-1, target, arr);

    return  taken + not_taken;
}


// time complexity : O(n*target)
// space complexity : O(n*target)
int solveUsingTabulation(vector<int>&arr , int target)
{
    int n = arr.size();
    int mod = 1000000007;       
    // why mod because the answer can be very large
    // we have to return the answer % mod
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));

    for(int i =0;i<n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=target;j++)      
        // why starts from 0 because we have to count the subsets when target is 0 also
        // and in another problem we have to find whether the target is possible or not so we start from 1
        {
            if(arr[i-1]<=j)
            {
                int taken = dp[i-1][j-arr[i-1]];
                int not_taken = dp[i-1][j];

                dp[i][j] = (taken + not_taken) %mod;
            }
            else{
                int not_taken = dp[i-1][j];
                dp[i][j] = (not_taken) %mod;
            }
        }
    }

    return dp[n][target];
}
int main()
{
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int countResult = solveUsingTabulation(arr,target);

    cout<<"Using tabulation : "<<countResult<<endl;

    countResult = solveUsingRecursion(n-1,target,arr);
    cout<<"Using recursion : "<<countResult;

    return 0;
}
