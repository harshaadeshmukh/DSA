#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ans(m , vector<int>(n));

    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j] = mat[j][i];
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int m ;
    cin >> m;

    vector<vector<int>> mat(n , vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> ans = transposeMatrix(mat);

    cout << endl;
    int n2 = ans.size();
    int m2 = ans[0].size();
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<m2;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}