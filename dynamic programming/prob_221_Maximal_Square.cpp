/*
Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

Example 1:
Input: matrix = 
[["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]
]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveUsingMaximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxSide = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(matrix[i-1][j-1]=='1')
            {
                int up = dp[i-1][j];
                int left = dp[i][j-1];
                int diag = dp[i-1][j-1];

                dp[i][j] = 1+ min({up,left,diag});
                maxSide = max(maxSide,dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int result = solveUsingMaximalSquare(matrix);
    cout << result << endl;


}