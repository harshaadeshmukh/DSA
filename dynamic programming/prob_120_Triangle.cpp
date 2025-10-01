/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
2
3 4
6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveMemo(int i , int j , vector<vector<int>> &triangle , vector<vector<int>>&dp)
{
    if(i==triangle.size()-1)
    {
        return triangle[i][j];
    }
    if(dp[i][j]!=INT_MAX)
    {
        return dp[i][j];
    }

    int left = solveMemo(i+1,j+1,triangle,dp);
        int down = solveMemo(i+1,j , triangle,dp);


        return dp[i][j] = triangle[i][j] + min(left,down);
}
int findMinPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    vector<vector<int>>dp(n,vector<int>(m,INT_MAX));

    return solveMemo(0,0,triangle,dp);
}

int main()
{
    vector<vector<int>>triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    int minSum = findMinPathSum(triangle);
    cout << minSum << endl;
}