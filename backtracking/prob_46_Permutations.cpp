/*
Given an array nums of distinct integers, 
return all the possible permutations. 
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int idx , vector<int> &nums, vector<vector<int>> &result)
{
    if(idx == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for(int i=idx;i<nums.size();i++)
    {
        swap(nums[idx] , nums[i]);
        solve(idx+1, nums , result);
        swap(nums[idx] , nums[i]);
    }
}


// time complexity : O(n!)
// space complexity : O(n)
vector<vector<int>> permutationProblem(vector<int> &nums)
{
    vector<vector<int>> result;

    solve(0,nums,result);
    return result;
}
int main()
{
    int n ;
    cin >>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> result = permutationProblem(nums);
    cout<<endl;

    for( auto it : result)
    {
        for( auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}