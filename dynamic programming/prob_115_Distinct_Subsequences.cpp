/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabb b it
ra b bbit
rab b bit

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
ba //b// g bag
ba //bgba// g
b //abgb// ag
ba b //gb// ag
babg bag
*/
 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMemo(int i , int j , string &s1 , string &s2 , vector<vector<int>>&dp)
{
    if(j<0)        // why j<0? because if j becomes -1 that means we have found the subsequence
    {
        return 1;
    }
    if(i<0)     // why i<0? because if i becomes -1 that means we have exhausted the string s1 and haven't found the subsequence
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(s1[i]==s2[j])
    {
        return dp[i][j] = solveMemo(i-1,j-1,s1,s2,dp) + solveMemo(i-1,j,s1,s2,dp);
    }
    else
    {
        return dp[i][j] = solveMemo(i-1,j,s1,s2,dp);
    }
}

// time complexity: O(n*m)
// space complexity: O(n*m) + O(n+m)  (dp array + recursion stack)
int solveUsingMemoritation(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    return solveMemo(n-1,m-1,s1,s2,dp);

}

int solveUsingTabulation(string &s1 , string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;   // if t is empty string then there is one subsequence of s which is empty string
    }

    int mod = 1e9+7;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
            else
            {
                dp[i][j] = dp[i-1][j]%mod;
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;

    int result = solveUsingMemoritation(s1,s2);
    cout << result << endl;


    result = solveUsingTabulation(s1,s2);
    cout << result << endl;
}