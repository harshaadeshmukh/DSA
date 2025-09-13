/*
Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
vector<int> nextGreaterElements2(vector<int> nums)
{
    int n = nums.size();
    vector<int> result(n , -1);

    stack<int>st;
    for(int i =2*n-1;i>=0;i--)
    {
        int idx = i%n;
        while(st.size() > 0 && st.top() <= nums[idx])
        {
            st.pop();
        }

        if(st.empty())
        {
            result[idx] = -1;
        }
        else{
            result[idx] = st.top();
        }

        st.push(nums[idx]);
    }

    return result;
}
int main() 
{
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i =0;i<n;i++)
    {
        cin>>nums[i];
    }

    vector<int>result = nextGreaterElements2(nums);
    for(auto x : result)
    {
        cout<<x<<" ";
    }
    return 0;
}