/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(int index , int sum , int target , vector<int> &nums , vector<int> &ans , vector<vector<int>> &result)
{
    if(sum ==target){
        result.push_back(ans);
        return;
    }

    if( index > nums.size() || sum > target)
    {
        return;
    }

    ans.push_back(nums[index]);
    solve(index , sum+nums[index] , target, nums , ans , result);
    ans.pop_back();
    solve(index +1 , sum , target , nums , ans , result);
}
vector<vector<int>> combinationSum1(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    vector<int> ans;

    solve(0 , 0 ,target , nums , ans , result);

    return result;
}

int main()
{
    int n , target;

    cin >> n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }

    cin >> target;

    vector<vector<int>> result = combinationSum1(nums , target);

    for( auto it : result)
    {
        cout << "[";
        for(auto num : it)
        {
            cout << num << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << endl;
    return 0;

}
