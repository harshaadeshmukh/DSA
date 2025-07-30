#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n*m)
// space complexity : O(1)
vector<int> generateSpiralMatrix(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    while(left <=right && top <= bottom)
    {
        for(int i=left; i<=right ;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <=bottom)
        {   
            for(int i=right;i>=left ;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right)
        {
            for(int i=bottom ; i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>>mat(n , vector<int>(n));

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = generateSpiralMatrix(mat);

    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;

}