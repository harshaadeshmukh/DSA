#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n*m)
// space complexity : O(n+m)
void setMatrixZeroes(vector<vector<int>> &mat , int n , int m)
{
    vector<int> row(n,0);
    vector<int> col(m,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i]==1 || col[j]==1)
            {
                mat[i][j] = 0;
            }
        }
    }
}
int main()
{
    int n;
    int m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i=0; i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> matrix[i][j];
        }
    }

    setMatrixZeroes(matrix , n , m);

    for(int i=0; i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}