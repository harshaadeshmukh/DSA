/*
Given an integer array nums that may contain duplicates, 
return all possible subsets (the power set).
The solution set must not contain duplicate subsets. 
Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int index, vector<int>& ans, set<vector<int>>& result)
{
   if(index == nums.size())
   {
        result.insert(ans);
        return;
   }

   for(int i = index ; i<nums.size(); i++)
   {
        if(i > index && nums[i] == nums[i-1])
        {
            continue;
        }
        ans.push_back(nums[i]);
        solve(nums, i + 1, ans, result);
        ans.pop_back();
        solve(nums, i + 1, ans, result);
   }
}
// time complexity: O(2^n)
// space complexity: O(n)
vector<vector<int>> subsets2(vector<int>& nums) 
{
    set<vector<int>> result;
    vector<int> ans;
    sort(nums.begin(), nums.end());

    solve(nums, 0, ans, result);
    return vector<vector<int>>(result.begin(), result.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n);

    for(int i=0;i<n;i++)
    {
        cin >> ans[i];
    }

    vector<vector<int>> result = subsets2(ans);

    for(auto& subset : result)
    {
        cout << "[";
        for(auto &num : subset)
        {
            cout << num << " ";
        }
        cout << "] " <<endl;
    }
    cout << endl;
    return 0;

}