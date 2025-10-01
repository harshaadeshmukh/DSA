/*
Given an integer array nums, find a subarray that has the largest product, 
and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findLeftMaxProduct(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);

    int maxProd = 1;
    for(int i=0;i<n;i++)
    {
        maxProd = maxProd * nums[i];
        result[i] = maxProd;
        if(maxProd == 0)
        {
            maxProd = 1;
        }
    }
    return result;
}

vector<int> findRightMaxProduct(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);

    int maxProd = 1;
    for(int i=0;i<n;i++)
    {
        maxProd *= nums[n-i-1];
        result[n-i-1] = maxProd;
        if(maxProd == 0)
        {
            maxProd = 1;
        }
    }

    //or 
    /*
    for(int i=n-1;i>=0;i--)
    {
        maxProd *= nums[i];
        result[i] = maxProd;
        if(maxProd == 0)
        {
            maxProd = 1;
        }
    }
    */

    return result;
}
// time complexity: O(n)
// space complexity: O(n)
int findMaximumProductSubarray(vector<int>&nums)
{
    vector<int>leftArr = findLeftMaxProduct(nums);
    vector<int>rightArr = findRightMaxProduct(nums);

    int result = INT_MIN;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        result = max(result, max(leftArr[i], rightArr[i]));
    }
    return result;
    
}

// time complexity: O(n)
// space complexity: O(1)
int findMaximumProductSubarray2(vector<int>&nums)
{
    int left = 1;
    int right = 1;
    int result = INT_MIN;
    int n = nums.size();

    for(int i=0;i<n;i++)
    {
        left = left==0?1:left;
        right = right==0?1:right;

        left = left * nums[i];
        right = right * nums[n-i-1];

        result = max({result, left, right});

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
    //1st approach
    int result = findMaximumProductSubarray(nums);
    cout << result << endl;

    //2nd approach
    result = findMaximumProductSubarray2(nums);
    cout << result << endl;
    return 0;
}