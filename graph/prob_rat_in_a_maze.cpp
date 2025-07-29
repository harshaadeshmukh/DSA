#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs( vector<vector<int>> &maze , int i ,int j, int n,set<string> &ans , string path)
{
    if(i < 0 || j<0 || i>=n || j>=n || maze[i][j]==0)
    {
        return;
    }
    if(i==n-1 && j==n-1)
    {
        ans.insert(path);
        return;
    }

    maze[i][j]=0;   //mark as that box is visited

    dfs(maze , i+1,j,n,ans, path + "D");    //DOWN
    dfs(maze , i-1,j,n,ans,path+"U");    //UP
    dfs(maze , i,j+1,n,ans,path+"R");    //RIGHT
    dfs(maze , i,j-1,n,ans,path+"L");    //LEFT

    maze[i][j] = 1;   //backtrack to original state

}
int main()
{
    int n;
    cin >>n;

    vector<vector<int>> maze(n,vector<int>(n,0));


    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    
    if (maze[0][0] == 0 || maze[n-1][n-1] == 0) 
    {
        cout << "No path available" << endl;
        return 0;
    }
    set<string> ans;
    string path = "";
    dfs(maze , 0, 0, n , ans , path);
    cout<<endl;
    for(auto it: ans)
    {
        cout << it << endl;
    }

    return 0;
}

// In this code, we define dfs with backtracking to explore all possible paths in the maze.
// We use a set to store unique paths that lead to the destination.
// and we print all unique paths found in the maze.
// The maze is represented as a 2D vector, where 1 indicates a valid cell and 0 indicates an obstacle.
// Time Complexity: O(4^(n^2))
// Space Complexity: O(n^2) for the recursion stack and the set to store paths.
// Note: The code assumes that the maze is square (n x n) and that the starting point is at (0, 0) and the destination is at (n-1, n-1).

//Test Case 1:
//  4     // Size of the maze
// 1 0 0 0
// 1 1 0 1
// 1 1 0 0
// 0 1 1 1

// DDRDRR   //possible path 1
// DRDDRR   //possible path 2


