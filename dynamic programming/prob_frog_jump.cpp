/*
problem is that the frog can jump 1 or 2 steps at a time
and we have to find the minimum cost to reach the last stone
Example 1:
Input: heights = [10, 30, 20, 40]
Output: 30
Example 2:
Input: heights = [30, 10, 60, 10, 60, 50]
Output: 40
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &heights, int n , vector<int> &dp)
{
    if(n==0)
    {
        return 0; // Base case: no cost to jump from the first stone
    }

    if(dp[n] != -1)
    {
        return dp[n]; // Return the cached result
    }

    int oneStep = solve(heights , n-1, dp) + abs(heights[n] - heights[n-1]);

    int twoStep = INT_MAX;
    if(n > 1)
    {
        twoStep = solve(heights, n - 2, dp) + abs(heights[n] - heights[n - 2]);
    }

    return dp[n] = min(oneStep, twoStep);
}

// time complexity: O(2^n)
// space complexity: O(n)
int frogJumpSolution1(vector<int>& heights)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    int result = solve(heights, n - 1, dp);

    return result;
}

// time complexity: O(n)
// space complexity: O(n)
int frogJumpSolution2(vector<int>& heights)
{
    int n = heights.size();
    vector<int> dp(n);
    dp[0] = 0; // Base case: no cost to stay on the first stone

    for(int i = 1; i < n; i++)
    {
        int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoStep = INT_MAX;
        if(i > 1)
        {
            twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(oneStep, twoStep);
    }

    return dp[n - 1];
}


int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);

    for(int i =0;i<n;i++)
    {
        cin >> heights[i];
    }

    int result = frogJumpSolution1(heights);

    cout << result << endl;

    int result2 = frogJumpSolution2(heights);

    cout << result2 << endl;

    return 0;
}
