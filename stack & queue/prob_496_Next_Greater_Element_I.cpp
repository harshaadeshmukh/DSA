/*
Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
vector<int> nextGreaterElement(vector<int> nums1 , vector<int> nums2)
{
    int n = nums2.size();
    vector<int> result(n,-1);

    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(st.size() > 0 && st.top() <= nums2[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            result[i] = -1;
        }
        else{
            result[i] = st.top();
        }
        st.push(nums2[i]);
    }

    unordered_map<int,int>mp;

    for(int i =0;i<n;i++)
    {
        mp[nums2[i]] = result[i];
    }

    vector<int> ans(nums1.size() , -1);
    for(int i =0;i<nums1.size();i++)
    {
        ans[i] = mp[nums1[i]];
    }

    return ans;


}
int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    
    vector<int>result;

    result = nextGreaterElement(nums1, nums2);

    for(auto x: result)
        cout<<x<<" ";

    nums1 = {3,5, 2,6 ,4};
    nums2 = {6, 5, 7, 4, 3, 2, 1};
    result = nextGreaterElement(nums1, nums2);
    cout<<endl;
    for(auto x: result)
        cout<<x<<" ";

    return 0;
}
