/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, 
such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(int i,int j, int n, int m, string &s1, string &s2, string &s3, vector<vector<bool>>&dp)
{
    if(i==n && j==m && i+j==s3.size())
    {
        return true;
    }

    if(i+j>=s3.size())
    {
        return false;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    bool ans = false;

    if(i<n && s1[i]==s3[i+j])
    {
        ans = ans || solve(i+1,j,n,m,s1,s2,s3,dp);
    }

    if(j<m && s2[j]==s3[i+j])
    {
        ans = ans || solve(i,j+1,n,m,s1,s2,s3,dp);
    }

    return dp[i][j] = ans;
}

// time complexity: O(n*m)
// space complexity: O(n*m) + O(n+m)  (dp array + recursion stack)
bool solveUsingMemoritation(string &s1, string &s2, string &s3)
{
    int n = s1.size();
    int m = s2.size();
    int len = s3.size();

    if(n + m != len)
    {
        return false;
    }

    vector<vector<bool>>dp(n+1,vector<bool>(m+1,-1));

    return solve(0,0,n,m,s1,s2,s3,dp);

}


bool solveUsingTabulation(string &s1 , string &s2 , string &s3)
{
    int n = s1.size();
    int m = s2.size();
    int len = s3.size();

    if(n + m != len)
    {
        return false;
    }

    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));

    dp[0][0] = true;

    for(int i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
    }

    for(int j=1;j<=m;j++){
        dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int k = i+j-1;

            bool  comparasion1 = dp[i-1][j] && (s1[i-1] == s3[k]);

            bool comparasion2 = dp[i][j-1] && (s2[j-1] == s3[k]);

            dp[i][j] = comparasion1 || comparasion2;

        }
    }

    return dp[n][m];
}

int main()
{
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    bool result = solveUsingMemoritation(s1,s2,s3);

    if(result){
        cout << "Ans: true" << endl;
    }
    else{
        cout << "Ans: false" << endl;
    }

    result = solveUsingTabulation(s1,s2,s3);
    cout<< (result ? "true" : "false") << endl;

    return 0;
}