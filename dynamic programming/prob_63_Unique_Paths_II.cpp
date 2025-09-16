/*
Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveUsingTabulationUPII(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if(grid[0][0]==1 || grid[m-1][n-1]==1)
    {
        return 1;
    }
    vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0] = 1;
    for(int i=0;i<m;i++)
    {
        
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                continue;
            }
            if(grid[i][j]==1)
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
    int m,n;
    cin >> m>>n;

    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }

    int result = solveUsingTabulationUPII(grid);

    cout<<result;
    return 0;
}