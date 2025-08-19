//basically in this probram it is similar to frog jump like we can jump 1 or 2 times
// but here we have to jump up to k distance

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &heights, int n, int k , vector<int> &dp)
{
    if( n==0)
    {
    return 0;
   }

   if(dp[n] != -1)
   {
       return dp[n]; // Return the cached result
   }

   
   int miniDistance = INT_MAX;
   
   for(int i=1;i<=k;i++)
   {
       if( n- i >= 0)
    {
        int count =  solve(heights , n- i , k , dp) + abs( heights[n] - heights[n- i]);
        miniDistance = min(miniDistance, count);
    }
}
return dp[n] = miniDistance;
}

// time complexity: O(n * k)
int frogJumpWithKDistance(vector<int> &heights , int k)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    int result = solve(heights, n - 1, k,  dp);
    return result;
}

// time complexity: O(n * k)
int frogJumpWithKDistance2(vector<int> &heights, int k)
{
    int n = heights.size();

    vector<int>dp(n);

    dp[0] = 0; // Base case: no cost to stay on the first stone

    for(int i =1;i<n;i++)
    {
        dp[i] = INT_MAX; // Initialize with a large value
        for(int j = 1 ; j<=k ; j++)
        {
            if(i - j >= 0)
            {
                int count = dp[i-j] + abs(heights[i] - heights[i - j]);
                dp[i] = min(dp[i], count);
            }
        }
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

    int k;
    cin >> k;

   
    int result = frogJumpWithKDistance(heights, k);

    cout << result << endl;

    int result2 = frogJumpWithKDistance2(heights, k);

    cout << result2 << endl;

    return 0;

}