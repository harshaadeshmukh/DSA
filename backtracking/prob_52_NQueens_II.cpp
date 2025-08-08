/*
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// not an optimal code
// basically we just check all the rows and columns for each queen placement and return the count
bool isSafeFunc(int row , int col , int n , vector<string> &ans)
{
    //check horizontally
    for(int i =0;i<n;i++)
    {
        if(ans[row][i] == 'Q')
        {
            return false;
        }
    }

    //check vertically
    for(int i=0;i<n;i++)
    {
        if(ans[i][col]=='Q')
        {
            return false;
        }
    }

    //check diagoanl upwards to left
    for(int i=row , j=col ; i>= 0 && j>=0 ;i--,j--)
    {
        if(ans[i][j]=='Q')
        {
            return false;
        }
    }


    
    //check diagoanl upwards to right
    for(int i=row , j=col ; i>= 0 && j<n ;i--,j++)
    {
        if(ans[i][j]=='Q')
        {
            return false;
        }
    }

    return true;
}

void nqueensSol(int row , int n , vector<string> &ans , vector<vector<string>> &result)
{
    if(row==n)
    {
        result.push_back(ans);
        return;
    }


    for(int i =0;i<n;i++)
    {
        if(isSafeFunc(row , i ,n , ans))
        {
            ans[row][i] = 'Q';
            nqueensSol(row + 1, n, ans, result);
            ans[row][i] = '.'; //backtrack
        }
    }
}


//time complexity : O(N!)
//space complexity : O(N^2)
int solveNQueensProblem(int n)
{
    vector<string>ans (n,string(n,'.'));

    vector<vector<string>>result;

    nqueensSol(0,n,ans, result);


    return result.size(); // return the count of distinct solutions
}

int main()
{
    int n;
    cin >> n;

    int result =  solveNQueensProblem(n);

    cout << result << endl;

    return 0;
}