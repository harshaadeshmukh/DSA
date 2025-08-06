/*
Given an integer array nums of unique elements, 
return all possible subsets (the power set).
The solution set must not contain duplicate subsets. 
Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(int index , vector<int> &nums, vector<int> &ans, vector<vector<int>> &result , int &count)
{
    if(index == nums.size())
    {
        result.push_back(ans);
        count++;
        return;
    }

    ans.push_back(nums[index]);
    solve(index + 1, nums, ans, result , count);
    ans.pop_back();
    solve(index + 1, nums, ans, result,count);
}
// time complexity : O(2^n)
// space complexity : O(n)
vector<vector<int>> subsets1(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> ans;
    int count = 0;
    solve(0 , nums , ans , result,count);   //1st zero for index and 2nd for count which is not used here

    cout << count << endl; 

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout<<endl;
    vector<vector<int>> ans = subsets1(nums);

    for(auto &subset : ans)
    {
        cout << "[";
        for(auto &num : subset)
        {
            cout << num << " ";
        }
        cout << "]";
        cout << endl;
    
    }
    return 0;

}

