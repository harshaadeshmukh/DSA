/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' 
before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 
and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

Example 3:
Input: nums = [1], target = -1
Output: 1

Example 4:
Input: nums = [1,1,1,1,1,1,1,1,1,1,1,1] , target = 5
Output: 0
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveUsingTabulation(vector<int>& nums, int target);
int main()
{
    int n;
    cin >>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
    }

    int target;
    cin >>target;

    cout <<solveUsingTabulation(arr,target) <<endl;
    return 0;
}

 int solveUsingTabulation(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin() , nums.end(),0);

        if(abs(target) > sum )  return 0;  
        // because if target is greater than sum then it is not possible to achieve that target

        target = sum+target;
        if(target%2!=0)
        {
            return 0;
        }

        target /=2;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++)
        {
                dp[i][0] = 1;
        } 

        for(int i =1;i<=n;i++)
        {
            for(int j =0;j<=target;j++)
            {
                if(nums[i-1]<=j)
                {
                    int taken = dp[i-1][j-nums[i-1]];
                    int not_taken = dp[i-1][j];
                    dp[i][j] = taken + not_taken;

                }
                else{
                    int not_taken = dp[i-1][j];
                    dp[i][j] = not_taken;
                }
            }
        }

        return dp[n][target];
    }
