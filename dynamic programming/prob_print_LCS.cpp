/*
Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "bdgek" 
Output: "bde"
Explanation: The longest common subsequence is "bde" and its length is 3.

Example 2:
Input: text1 = "abcde", text2 = "eadc"
Output: "ad"
Explanation: The longest common subsequence is "ad" and its length is 2.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;




string LCSusingTabulation(string &s1, string &s2)
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
   

   int len = dp[n][m];

   string result (len , ' ');
   int i = n , j = m;

   int index = len - 1;

   // o(n + m)
   while(i > 0 && j>0)
   {
    if(s1[i-1]==s2[j-1])
    {
        result[index--] = s1[i-1];
        i--;
        j--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
    {
        i--;
    }
    else{
        j--;
    }
   }

   return result;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;



    string result = LCSusingTabulation(s1 , s2);
    cout << result << endl;
    return 0;
}

