/*
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(1)
int singleNumber(vector<int>& nums) 
{
    int result = 0;
    for(int num : nums)
    {
        result ^= num; 
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }

    int ans = singleNumber(nums);

    cout << ans << endl;
}