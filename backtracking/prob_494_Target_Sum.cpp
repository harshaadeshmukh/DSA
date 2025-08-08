/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' 
before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' 
before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, 
which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int i , int sum , int target , vector<int> &nums , int &count)
// why &count? because we want to modify the count variable in the main function
{
    if(i==nums.size())
    {
        if(sum==target)
        //However, if you do this, you must also handle the case when i == nums.size() but sum != target, 
        //otherwise the function won't return, and the recursion will continue unnecessarily 
        //— leading to undefined behavior or wrong results.
        {
            count++;
        }
        return;
    }

    solve(i+1 , sum+nums[i] , target , nums , count );
    solve(i+1 , sum-nums[i] , target , nums , count );


}
int targetSum(vector<int> &nums , int target) 
{
    int count = 0;

    solve(0,0,target , nums , count);

    return count;

}

int main()
{
    int n ;
    cin >> n;
    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        nums[i] = temp;
    }

    int target ;
    cin >> target;

    int totalSum = targetSum(nums , target);

    cout << totalSum << endl;

    return 0;


}