/*
Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// recursion + memoization
int solveUsingRecursion(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
        return grid[0][0];

    if(dp[i][j] != -1)
        return dp[i][j];

    int up = INT_MAX, left = INT_MAX;

    if(i > 0)
        up = grid[i][j] + solveUsingRecursion(i-1, j, grid, dp);
    if(j > 0)
        left = grid[i][j] + solveUsingRecursion(i, j-1, grid, dp);

    return dp[i][j] = min(up, left);
}

// time complexity: O(m*n)
// space complexity: O(m*n)
int solveUsingTabulations(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    for(int i =0;i<m;i++)
    {
        int right = INT_MAX;
        int down = INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                continue;
            }

            if(i>0)
            {
                right = grid[i-1][j];
            }
            if(j>0)
            {  
                down = grid[i][j-1];
            }

            grid[i][j] = grid[i][j] + min(down,right);
        }
    }
    
    return grid[m-1][n-1];
}
int main()
{
    int n , m;
    cin >> m >> n;

    vector<vector<int>>grid(m,vector<int>(n));

    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = solveUsingTabulations(grid);

    cout<<result<<endl;



    return 0;


}