/*
Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n*m)
// space complexity : O(n*m)
int findLongestSubarray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            } else {
                dp[i][j] = 0; // Reset if elements do not match
            }
        }
    }
    // Debug: Print the DP table
    cout << "DP Table:" << endl;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;
    return maxLength;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    for(int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    int m;
    cin >> m;
    vector<int> nums2(m);
    for(int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    int result = findLongestSubarray(nums1, nums2);
    cout << result << endl;
    return 0;
}