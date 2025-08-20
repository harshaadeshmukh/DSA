/*
Houses are arranged in a circle 🔄.
That means first and last house are also adjacent.
You can’t rob both the first and last house.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and 
then rob house 3 (money = 2), because they are adjacent houses.

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
    int firstHouse = solve(0 , n-2 , nums , dp);
    dp.clear();
    dp.assign(n,-1);
    int secondHouse = solve(1 , n-1 , nums , dp);

    return max(firstHouse , secondHouse);
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
    cout << countHouseRobber << endl;
}