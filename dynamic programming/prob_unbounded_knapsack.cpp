/*
Given a set of items, each with a weight and a value, represented by the array wt and val respectively. 
Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. 
Return the maximum profit.
Note: Each item can be taken any number of times.

Example 1:
Input: val = [1, 1], wt = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.

Example 2:
Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.

Example 3:
Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 11
Output: 200
Explanation: We can't pick any element .hence, total profit is 0.

Reference: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveUsingRecursion(vector<int>& val, vector<int>& wt, int n, int capacity)
{
    if(n==0 || capacity==0)
    {
        return 0;
    }

    if(wt[n-1]<=capacity)
    {
        int taken = val[n-1] + solveUsingRecursion(val,wt,n,capacity-wt[n-1]);
        int notTaken = solveUsingRecursion(val,wt,n-1,capacity);

        return max(taken,notTaken);
    }
    else{
        return solveUsingRecursion(val,wt,n-1,capacity);
    }    
}
// time complexity: O(n*capacity)
// space complexity: O(n*capacity)
int solveUsingTabulation(vector<int>& val, vector<int>& wt, int capacity)
{
    int n = val.size();
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            if(wt[i-1]<=j)
            {
                int taken = val[i-1] + dp[i][j-wt[i-1]];
                int notTaken = dp[i-1][j];

                dp[i][j] = max(taken,notTaken);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][capacity];
}
int main()
{
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;

    

    int result = solveUsingTabulation(val, wt, capacity);
    cout<<result<<endl;

    val = {6, 8, 7, 100};
    wt = {2, 3, 4, 5};
    capacity = 11;

    result = solveUsingTabulation(val, wt, capacity);
    cout<<result<<endl;

    return 0;

}