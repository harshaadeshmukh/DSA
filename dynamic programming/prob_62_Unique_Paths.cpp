/*
A robot is on an m x n grid, initially at the top-left corner. 
It aims to move to the bottom-right corner, moving either down or right at any time. 
Given m and n, determine the number of unique paths the robot can take to reach the bottom-right corner.
Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int i , int j , int m , int n , vector<vector<int>>& dp)
{
    if(i==m-1 && j==n-1) 
    {
        return 1;
    }
    if(i>=m || j>=n) 
    {
        return 0;
    }
    if(dp[i][j] != -1) 
    {
        return dp[i][j];
    }

    int down = solve(i+1,j,m,n,dp);
    int right = solve(i,j+1,m,n,dp);

    return dp[i][j] = down + right;
}

// time complexity: O(m*n)
// space complexity: O(m*n)
int uniquePathsUsingRecursion(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0,0,m,n,dp);
}

// time complexity: O(m*n)
// space complexity: O(m*n)
int uniquePathsUsingTabulation(int m, int n)
{
    vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0] = 1;

    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                continue;
            }

            int right = 0;
            int down = 0;

            if(i>0)
            {
                right = dp[i-1][j];
            }
            if(j>0)
            {
                down = dp[i][j-1];
            }

            dp[i][j] = right+down;
        }
    }

    return dp[m-1][n-1];
}

int main()
{
    int m ;
    int n;
    cin >> m >> n;

    int countPath = uniquePathsUsingRecursion(m, n);

    cout <<"Using recursion + memoization: " <<countPath << endl;

    countPath = uniquePathsUsingTabulation(m, n);
    cout <<"Using tabulation: " <<countPath << endl;
    return 0;
}