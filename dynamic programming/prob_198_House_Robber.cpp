/*
Houses are in a straight line.
You can’t rob two adjacent houses (no circular only in one direction).
Goal: maximize sum.
Example 1:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int i , int n , vector<int>& nums , vector<int>& dp)
{
    if(i >= n)
    {
        return 0;
    }
    if(dp[i] != -1)
    {
        return dp[i]; // Return the cached result
    }

    int takenRob = nums[i] + solve(i + 2, n, nums, dp);
    int notTakenRob = solve(i + 1, n, nums, dp);

    return dp[i] = max(takenRob, notTakenRob);
}

// Approach : Recursive + Memoization
// time complexity : O(n)
// space complexity : O(n)
int houseRobberProblem(vector<int>& nums)
{
    int n = nums.size();
    if(n==1)
    {
        return nums[0];
    }
    vector<int>dp(n,-1);

    return solve(0, n, nums , dp);
}

// Tabulation
// time complexity : O(n)
// space complexity : O(n)
int houseRobberProblem2(vector<int> &nums)
{
    int n = nums.size();
    if(n==1)
    {
        return nums[0];
    }

    vector<int>dp(n,0);

    dp[0] = nums[0];

    dp[1] = max(dp[0] , nums[1]);

    for(int i =2 ; i < n;i++)
    {
        dp[i] = max(dp[i-1] , nums[i] + dp[i-2]);
    }
    return dp[n-1];
}
int main()
{
    int n ;
    cin >> n;

    vector<int> nums(n);
    for(int i =0;i<n;i++)
    {
        cin >> nums[i];
    }

    int countHouseRobber = houseRobberProblem(nums);
    cout <<"Recursion + Memoization: "<< countHouseRobber << endl;

    int countHouseRobber2 = houseRobberProblem2(nums);
    cout <<"Tabulation: "<< countHouseRobber2 << endl;

    return 0;
}