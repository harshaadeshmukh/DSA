/*
Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int perfectSquaresMethod(int n)
{
    if(n==0)
    {
        return 0;
    }

    int mini = INT_MAX;

    for(int i =1 ; i*i <=n; i++)
    {
        int result = perfectSquaresMethod(n - i*i)+1;
        mini = min(mini , result);
    }
    return mini;
}

int main()
{
    int n;
    cin >> n;

    int totalCount = perfectSquaresMethod(n);

    cout << totalCount << endl; 
    return 0;
}