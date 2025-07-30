#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n^2)
// space complexity : O(1)
int diagonalSumMatrix1(vector<vector<int>> &mat)
{
    int n = mat.size();

    int sum = 0;
    for(int i =0 ; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                sum +=mat[i][j];
            }
            if(i+j==n-1)
            {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

// time complexity : O(n)
// space complexity : O(1)
int diagonalSumMatrix2(vector<vector<int>> &mat)
{
    int sum = 0;
    int n = mat.size();
    for(int i = 0; i < n; i++)
    {
        sum += mat[i][i]; // Primary diagonal

        if(i!= n-i-1)
        {
            sum += mat[i][n-i-1]; // Secondary diagonal
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    int sum = diagonalSumMatrix1(mat);

    cout << sum << endl;

    int sum2 = diagonalSumMatrix2(mat);
    cout << sum2 << endl;
    return 0;
}