/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) 
results in the string s.

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solveUsingShortestCommonSupersequence(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    // o(n*m)
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
   
   int i = n , j = m;

   string result = "";

   // o(n + m)
   while(i > 0 && j>0)
   {
    if(s1[i-1]==s2[j-1])
    {
        result += s1[i-1];
        i--;
        j--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
    {
        result += s1[i-1];
        i--;
    }
    else
    {
        result += s2[j-1];
        j--;
    }
   }

   while(i > 0)
   {
    result += s1[i-1];
    i--;
   }

   while(j > 0)
   {
    result += s2[j-1];
    j--;
   }

   reverse(result.begin(),result.end());

   return result;
}

int main()
{
    string word1;
    string word2;

    cin >> word1;
    cin >> word2;

    string result = solveUsingShortestCommonSupersequence(word1, word2);
    cout<<"Shortest Common Supersequence is : ";
    cout << result << endl;
}
