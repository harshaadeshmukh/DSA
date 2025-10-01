/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
However, you can sell and buy the stock multiple times on the same day, ensuring you never hold than one share of the stock.
Find and return the maximum profit you can achieve.



Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMemo(int index , int buy ,vector<int> &prices ,vector<vector<int>>&dp)
{
    if(index==prices.size())
    {
        return 0;
    }
    if(dp[index][buy]!=-1)
    {
        return dp[index][buy];
    }
    int profit = 0;

    if(buy){
        int taken = -prices[index] + solveMemo(index+1,0,prices,dp);
        int not_taken = solveMemo(index+1,1,prices,dp);

        profit = max(taken , not_taken);
    }
    else{
        int taken = +prices[index] + solveMemo(index+1,1,prices,dp);
        int not_taken = solveMemo(index+1,0,prices,dp);

        profit = max(taken , not_taken);   
    }

    return dp[index][buy] = profit;
}
// time complexity : O(n*2)
// space complexity : O(n*2) + O(n)  //dp array + recursive
int findMaxProfitUsingMemorization(vector<int> &prices)
{
    vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
    return solveMemo(0,1,prices,dp);       //indexing , buy(0,1)
}

// time complexity : O(n*2)
// space complexity : O(n*2) + O(n)  //dp array + recursive
int findMaxProfitUsingTabulaton(vector<int>&prices)
{
    int n = prices.size();
    vector<vector<int>>dp(n+1, vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int buy = 0;buy<2;buy++)
        {
            int profit = 0;
            if(buy)
            {
                int taken = -prices[i] + dp[i+1][0];
                int not_taken = dp[i+1][1];

                profit = max(taken , not_taken);
            }
            else{
                int taken = +prices[i] + dp[i+1][1];
                int not_taken = dp[i+1][0];

                profit = max(taken , not_taken);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}

// time complexity : O(n)
// space complexity : O(1)
int findMaxProfit2(vector<int> &prices)
{
    int profit = 0;
    int n = prices.size();
    for(int i=1;i<n;i++)
    {
        if(prices[i] > prices[i-1])
        {
            profit+= (prices[i] - prices[i-1]);
        }
    }

    return profit;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i=0;i<n;i++)
        cin >> prices[i];

    //Approach 1: Recursion + Memorization
    int maxProfit = findMaxProfitUsingMemorization(prices);
    cout << maxProfit << endl;

    //Approach 2: Tabulation
    maxProfit = findMaxProfitUsingTabulaton(prices);
    cout<<maxProfit<<endl;

    //Approach 3: Greedy
    maxProfit = findMaxProfit2(prices);
    cout<<maxProfit<<endl;

    return 0;
}