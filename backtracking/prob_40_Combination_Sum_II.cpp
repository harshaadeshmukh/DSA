/*
Given a collection of candidate numbers (candidates) 
and a target number (target), find all unique combinations in candidates 
where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;    

void solve(int index , int sum , int target , vector<int> &nums , vector<int> &ans , vector<vector<int>> &result)
{
    if(sum==target)
    {
        result.push_back(ans);
        return;
    }
    if(index >= nums.size() || sum > target)
    {
        return;
    }

    for(int i = index ; i< nums.size() ;i++)
    {
        if(i > index && nums[i] == nums[i-1])
        {
            continue; 
        }

        if(sum + nums[i] > target)
        {
            break;
        }

        ans.push_back(nums[i]);
        solve(i + 1, sum + nums[i], target, nums, ans, result);
        ans.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &nums , int target)
{
    vector<vector<int>> result;
    vector<int> ans;
    sort(nums.begin() , nums.end());

    solve(0 , 0 , target , nums , ans , result);

    return result;

}
int main()
{
    int n, target;
    cin >>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        nums[i] = temp;
    }

    cin >> target;

    vector<vector<int>> result = combinationSum2(nums , target);

    for(auto it : result)
    {
        cout << "[";
        for(auto i : it)
        {
            cout << i << " ";
        }
        cout << "]"<<endl;
    }
    return 0;
}