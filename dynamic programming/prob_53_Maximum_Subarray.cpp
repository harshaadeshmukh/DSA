/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }

    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0;i<n;i++)
    {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0)
        {
            currSum = 0;
        }
    }

    cout << maxSum << endl;
    return 0;
} 