#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateSpiralMatrix(int n)
{
    vector<vector<int>>mat(n , vector<int>(n));

    int total = n * n;
    int left = 0;
    int right = n-1;
    int top = 0;
    int bottom = n-1;

    int count = 1;

    while(left <=right && top<= bottom && count<=total)
    {
        for(int i=left ;i<=right;i++)
        {
            mat[top][i] = count++;
        }
        top++;

        for(int i=top;i<=bottom;i++)
        {
            mat[i][right] = count++;
        }

        right--;

        if(top<=bottom)
        {
            for(int i=right ;i >=left ;i--)
            {
                mat[bottom][i] = count++;
            }
            bottom--;
        }

        if(left <=right)
        {
            for(int i=bottom ;i>=top ;i--)
            {
                mat[i][left] = count++;
            }
            left++;
        }
    }
        return mat;
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = generateSpiralMatrix(n);


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;


}