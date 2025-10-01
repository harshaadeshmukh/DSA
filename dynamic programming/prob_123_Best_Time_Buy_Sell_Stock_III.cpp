/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMemo(int index , int buy , int cap ,vector<int> &prices ,vector<vector<vector<int>>>&dp)
{
    if(index==prices.size() || cap==0)
    {
        return 0;
    }
    if(dp[index][buy][cap]!=-1)
    {
        return dp[index][buy][cap];
    }
    int profit = 0;

    if(buy){
        int taken = -prices[index] + solveMemo(index+1,0,cap,prices,dp);
        int not_taken = solveMemo(index+1,1,cap,prices,dp);

        profit = max(taken , not_taken);
    }
    else{
        int taken = +prices[index] + solveMemo(index+1,1,cap-1,prices,dp);
        int not_taken = solveMemo(index+1,0,cap,prices,dp);

        profit = max(taken , not_taken);   
    }

    return dp[index][buy][cap] = profit;
}

// time complexity : O(n*2*3)
// space complexity : O(n*2*3) + O(n)  //dp array + recursive
int findMaxProfitsUsingMemorization(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // index , buy(0,1) , cap(0,1,2)

    return solveMemo(0,1,2,prices,dp);
}


int findMaxProfitsUsingTabulation(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // index , buy(0,1) , cap(0,1,2)

    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<2;buy++)
        {
            for(int cap=1;cap<3;cap++)
            {
                int profit = 0;

                if(buy){
                    int taken = -prices[index] + dp[index+1][0][cap];
                    int not_taken = dp[index+1][1][cap];

                    profit = max(taken , not_taken);
                }
                else{
                    int taken = +prices[index] + dp[index+1][1][cap-1];
                    int not_taken = dp[index+1][0][cap];

                    profit = max(taken , not_taken);   
                }

                dp[index][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}
int main()
{
    int n;
    cin >> n;
    vector<int>prices(n);

    for(int i=0;i<n;i++)
        cin >> prices[i];
    

    int result = findMaxProfitsUsingMemorization(prices);
    cout << result << endl;

    result = findMaxProfitsUsingTabulation(prices);
    cout << result << endl;
    
    return 0;
}