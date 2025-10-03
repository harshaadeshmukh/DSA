/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
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
int findMaxProfitsUsingMemorization(vector<int> &prices,int k)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    // index , buy(0,1) , cap(0,1,2)

    return solveMemo(0,1,k,prices,dp);
}


int findMaxProfitsUsingTabulation(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
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
    
    int k;
    cin >> k;

    cout <<"answer is : "<< endl;
    int result = findMaxProfitsUsingMemorization(prices,k);
    cout << result << endl;

    result = findMaxProfitsUsingTabulation(prices,k);
    cout << result << endl;
    
    return 0;
}