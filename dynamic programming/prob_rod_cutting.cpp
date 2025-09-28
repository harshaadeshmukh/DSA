/*
Given a rod of length n inches and an array price[], 
where price[i] denotes the value of a piece of length i. 
Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.
Note: n = size of price, and price[] is 1-indexed array.

Example 1:
Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

Example 2:
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.

Example 3:
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.

Reference: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveUsingTabulation(vector<int> &price)
{
    int n = price.size();

    vector<int>wt(n,0);

    for(int i =0;i<n;i++)
    {
        wt[i] = i+1;
    }
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(wt[i-1]<=j)
            {
                int taken = price[i-1] + dp[i][j-wt[i-1]];
                int notTaken = dp[i-1][j];

                dp[i][j] = max(taken,notTaken);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][n];
}

int main ()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    int result = solveUsingTabulation(price);
    cout<<"Maximum Obtainable Value is : "<<result<<endl;
    /*
    | i\j | 0 | 1 | 2 | 3 | 4  | 5  | 6  | 7  | 8  |
    | --- | - | - | - | - | -- | -- | -- | -- | -- |
    | 0   | 0 | 0 | 0 | 0 | 0  | 0  | 0  | 0  | 0  |
    | 1   | 0 | 1 | 2 | 3 | 4  | 5  | 6  | 7  | 8  |
    | 2   | 0 | 1 | 5 | 6 | 10 | 11 | 15 | 16 | 20 |
    | 3   | 0 | 1 | 5 | 8 | 10 | 13 | 16 | 18 | 21 |
    | 4   | 0 | 1 | 5 | 8 | 10 | 13 | 16 | 18 | 21 |
    | 5   | 0 | 1 | 5 | 8 | 10 | 13 | 16 | 18 | 21 |
    | 6   | 0 | 1 | 5 | 8 | 10 | 13 | 17 | 18 | 22 |
    | 7   | 0 | 1 | 5 | 8 | 10 | 13 | 17 | 18 | 22 |
    | 8   | 0 | 1 | 5 | 8 | 10 | 13 | 17 | 18 | 22 |
    */

    price = {4,5,7,9,11};
    result = solveUsingTabulation(price);
    cout<<"Maximum Obtainable Value is : "<<result<<endl;

    return 0;
}
