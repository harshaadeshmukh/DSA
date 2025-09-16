/*
Example 1:
Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

Example 2:
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).

Example 3:
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) 
and the last item (value 50, weight 3) for a total value of 80.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int algorithm_01_knapsack(int capacity , int n, vector<int> &weights , vector<int> &values)
{
    vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));

    for(int i =1;i<=n;i++)
    {
        for(int j = 1;j<=capacity;j++)
        {
            if(weights[i-1]<=j)
            {
                int taken = values[i-1] + dp[i-1][j-weights[i-1]];
                int not_taken = dp[i-1][j];

                dp[i][j] = max(taken, not_taken);
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
    int capacity = 7;
    int n = 5;

    vector<int> weights{2, 5, 1, 3, 4};
    vector<int> values{15, 14, 10, 45, 30};

    int count = algorithm_01_knapsack(capacity, n, weights, values);

    cout << count << endl;


    capacity = 5;
    n = 4;
    weights = {5, 4, 2, 3};
    values = {10, 40, 30, 50};

    count = algorithm_01_knapsack(capacity, n, weights, values);
    cout << count << endl;
}