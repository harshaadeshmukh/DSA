/*
You are given an array of integers nums, 
there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


 Example 2:
 Input: nums = [1], k = 1
 Output: [1]
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> &arr , int k)
{
    int n = arr.size();

    deque<int>dq;

    for(int i =0;i<k;i++)
    {
        while(!dq.empty() && arr[dq.back()]  <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    vector<int>result;

    for(int i =k;i<n;i++)
    {
        result.push_back(arr[dq.front()]);

        while(!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    result.push_back(arr[dq.front()]);

    return result;

}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i =0;i<n;i++)
        cin >> arr[i];

    int k;
    cin >> k;

    vector<int> result = solve(arr , k);


    for(auto x: result)
        cout<<x<<" ";

    return 0;
}
 