/*
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n*m)
// space complexity : O(n*m)
int solveUsingTabulation(vector<int> &coins, int amount)
{
    int maxi = INT_MAX - 1;

    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int> (amount+1,0));

    for(int j=1;j<=amount;j++)
    {
        dp[0][j] = maxi;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(coins[i-1]<=j)
            {
                int taken = 1+ dp[i][j-coins[i-1]];
                int notTaken = dp[i-1][j];

                dp[i][j] = min(taken,notTaken);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    return dp[n][amount]==maxi?-1:dp[n][amount];
}

int main()
{
    vector<int> coins = {1,2,5};

    int amount = 11;

    int result = solveUsingTabulation(coins, amount);

    cout<<result<<endl;

    coins = {5,1,5,2};
    amount = 7;

    result = solveUsingTabulation(coins, amount);
    cout<<result<<endl;

    return 0;

}