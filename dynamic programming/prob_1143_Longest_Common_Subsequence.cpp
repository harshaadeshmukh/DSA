/*
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abcasfe", text2 = "def"
Output: 1
Explanation: The longest common subsequence is "d" and its length is 1.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2, int i, int n, int j, int m , vector<vector<int>>&dp)
{
    if(i>= n || j>= m)
    {
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(s1[i]==s2[j])
    {
        return dp[i][j] = 1+solve(s1, s2, i+1, n, j+1, m, dp);
    }

    int increase_s1 = solve(s1, s2, i+1, n, j, m, dp);
    int increase_s2 = solve(s1, s2, i, n, j+1, m, dp);

    return dp[i][j] = max(increase_s1, increase_s2);
}

// time complexity : O(n*m)
// space complexity : O(n*m)
int LCSusingRecursion(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(s1, s2, 0, n, 0, m , dp);
}

// time complexity : O(n*m)
// space complexity : O(n*m)
int LCSusingTabulation(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int result = LCSusingRecursion(s1 , s2);
    cout << result << endl;

    result = LCSusingTabulation(s1 , s2);
    cout << result << endl;
    return 0;
}

