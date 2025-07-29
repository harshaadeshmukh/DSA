#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<char>> &board , string word , int i ,int j ,int m, int n ,int idx)
{
    if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[idx])
    {
        return false;
    }

    if(idx == word.length() -1)
    {
        return true;
    }

    char temp = board[i][j];
    board[i][j] = '@';      //mark as that the box is visited

    bool flag = dfs(board , word , i+1,j,m,n,idx+1) ||
    dfs(board , word , i-1,j,m,n,idx+1) ||
    dfs(board , word , i,j+1,m,n,idx+1) ||
    dfs(board , word , i,j-1,m,n,idx+1);

    board[i][j] = temp;     //backtrack to original state
    return flag;
}
int main()
{
    int m,n;        // m for rows , n for columns
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    bool flag = false;
    // Check if the word can be found in the board

     for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
           if(dfs(board, word, i, j, m, n, 0)) {
               flag = true;
               break;
            }
        }
        if(flag) break;  
        // Exit outer loop if word is found
    }
   // bool flag = dfs(board , word , 0 , 0 ,  m, n , 0);

    if(flag){
        cout<<"Word found!";
    }
    else{
        cout<<"Word not found!";
    }
    return 0;

}

// This code implements a depth-first search (DFS) algorithm to find a word in a 2D board of characters.
// The board is represented as a vector of vectors, and the word is searched by recursively exploring adjacent cells.
// The function marks cells as visited by changing their value temporarily and backtracks to restore the original
// state after exploring all possible paths.
// The main function initializes the board, reads the word, and calls the DFS function to check
// if the word can be found starting from any cell in the board.
// If the word is found, it prints "Word found!", otherwise it prints "Word not found!".

//Time : O(m * n * 4^k) where k is the length of the word
//Space: O(m * n) for the recursion stack 

// Test Cases 1:
// 3 4      // Input dimensions of the board
// A B C E
// S F C S
// A D E E
// ABCCEDA  // Word to find
// Word found!      //actual output

// Test Cases 2:
// 3 4
// A B C E
// S F C S
// A D E E
// ASAE  // Word to find
// Word not found!      //actual output
