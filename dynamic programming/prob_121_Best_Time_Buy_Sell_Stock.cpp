/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and 
choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on 
day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMaxProfit(vector<int>&prices)
{
    int profit = 0;
    int mini = prices[0];
    int n = prices.size();
    for(int i=0;i<n;i++)
    {
        int diff = prices[i] - mini;
        profit = max(profit , diff);
        mini = min(mini , prices[i]);
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

    int maxProfit = findMaxProfit(prices);
    cout << maxProfit << endl;
}