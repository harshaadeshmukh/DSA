/*
Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int findKthSmallest(vector<vector<int>>& matrix, int k) 
{
    int n = matrix.size();
    priority_queue<int> pq;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            pq.push(matrix[i][j]);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    return pq.top();
}
int main()
{   
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> mat[i][j];
        }
    }

    int k;
    cin >> k;

    int ans = findKthSmallest(mat, k);
    cout << ans << endl;
    return 0;
}