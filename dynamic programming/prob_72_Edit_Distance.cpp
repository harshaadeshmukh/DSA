/*
Given two strings word1 and word2, return the minimum number of operations 
required to convert word1 to word2.
You have the following three operations permitted on a word:
1)Insert a character    2)Delete a character    3)Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int editDistanceSol(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + 1; // Deleting all characters from word1
    }

    for(int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] + 1; // Inserting all characters from word2
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
               int insert = dp[i][j - 1]; // Inserting a character
               int del = dp[i - 1][j];     // Deleting a character
               int replace = dp[i - 1][j - 1]; // Replacing a character

               dp[i][j] = 1 + min({insert, del, replace}); // Take the minimum of all operations
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string word1;
    string word2;

    cin >> word1;
    cin >> word2;

    int count = editDistanceSol(word1, word2);

    cout << count << endl;
    return 0;

}