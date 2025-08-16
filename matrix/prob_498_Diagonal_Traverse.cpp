/*
Given an n x n matrix mat, 
return an array of all the elements of the array in a diagonal order.

Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n^2)
// space complexity: O(n)
vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
    int n = mat.size();
    map<int, vector<int>> mp;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mp[i+j].push_back(mat[i][j]);
        } 
    }

    bool flag = true;

    vector<int> ans;
    for(auto it: mp)
    {
        if(flag)
        {
            reverse(it.second.begin(), it.second.end());
        }
        for(auto x: it.second)
        {
            ans.push_back(x);
        }
        flag = !flag;
    }

    return ans;
    
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

    vector<int> ans = findDiagonalOrder(mat);

    for(auto x: ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}