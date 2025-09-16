
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// using dp tabulation
int findMaximumRuns(int n , int W, vector<int> &balls , vector<int> &runs)
{
    int capacity = W;

    vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));

    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if(balls[i-1] <= j)
            {
                int taken = runs[i-1] + dp[i-1][j-balls[i-1]];      // taken with run value
                int notTaken = dp[i-1][j];  // not taken

                dp[i][j] = max(taken, notTaken);    
            }
            else{
                dp[i][j] = dp[i-1][j];  // not taken
            }
        }
    }

    return dp[n][capacity];

}

// using recursion
int findMaximumRunsUsingRecursion(int n , int W , vector<int> &balls , vector<int> &runs)
{
    if(n<0 || W==0)
    {
        return 0;
    }

    int taken = 0;
    if(balls[n-1] <= W)
    {
        taken = runs[n-1] + findMaximumRunsUsingRecursion(n-1, W-balls[n-1], balls, runs);
    }

    int notTaken = findMaximumRunsUsingRecursion(n-1, W, balls, runs);

    return max(taken, notTaken);


}
int main()
{
    int n = 5;                        // number of items
    int W = 7;                        // capacity (total balls)
    vector<int>balls{ 2, 5, 1, 3, 4}; // 1-based indexing
    vector<int>runs{15, 14, 10, 45, 30};

    int maximumRuns = findMaximumRuns(n,W ,balls, runs);
    cout<<"Maximum Runs that can be scored using dp = "<<maximumRuns<<endl;

    // int maximumRuns2 = findMaximumRunsUsingRecursion(n,W ,balls, runs);
    // cout<<"Maximum Runs that can be scored using recursion = "<<maximumRuns2<<endl;

    balls.clear();
    runs.clear();

    n = 4;
    W = 6;
    balls = {2, 3, 4, 5};
    runs = {20, 30, 10, 50};

    maximumRuns = findMaximumRuns(n,W ,balls, runs);
    cout<<"Maximum Runs that can be scored using dp = "<<maximumRuns<<endl;

    return 0;
}

/*
Example 1:
dry run of tabulation method
DP Table:
w:     0   1   2   3   4   5   6   7
i=1    0   0  15  15  15  15  15  15
i=2    0   0  15  15  15  15  15  29
i=3    0  10  15  25  25  25  25  29
i=4    0  10  15  45  55  60  70  70
i=5    0  10  15  45  55  60  70  75


ExMple 2:
DP Table:
w:     0   1   2   3   4   5   6
i=1    0   0  20  20  20  20  20
i=2    0   0  20  30  30  50  50
i=3    0   0  20  30  30  50  50
i=4    0   0  20  30  30  50  50
Maximum Runs that can be scored using dp = 50
*/

