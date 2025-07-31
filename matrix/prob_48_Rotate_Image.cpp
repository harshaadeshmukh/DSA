//rotate the image by 90 degrees (clockwise).

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity: O(n^2)
// space complexity: O(1)
void rotate90degreeMatrix1(vector<vector<int>>& mat)
{
    int n = mat.size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}


// time complexity: O(n^2)
// space complexity: O(n)
void rotate90degreeMatrix2(vector<vector<int>>& mat)    
{
    int n = mat.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[j][n-i-1] = mat[i][j];
        }
    }
    mat = ans; // copy the rotated matrix back to the original matrix
}
int main()
{
    int n;
    cin>>n;

    vector<vector<int>> mat(n , vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    rotate90degreeMatrix1(mat);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    rotate90degreeMatrix2(mat);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}