#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// time complexity : O(n*log(m))
// space complexity : O(1)
bool foundElementInMatrix(vector<int> &arr , int target)
{
    int low = 0;
    int high = arr.size() -1;

    while(low <= high)
    {
        int mid = low + (high - low ) /2;   //why low + (high - low) / 2 instead of (low + high) / 2?
        // because it prevents overflow in case of large values of low and high

        if(arr[mid]==target)
        {
            return true;
        }
        else if(arr[mid] < target)
        {
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return false;
}

// time complexity : O(n*log(m))
// space complexity : O(1)
bool inMatrixElementFound(vector<vector<int>> &mat , int target)
{
    int n = mat.size();

    for(int i =0;i<n;i++)
    {
        if(foundElementInMatrix(mat[i] , target))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    int m ;
    cin >> n >> m;

    vector<vector<int>> mat(n , vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }

    int target;
    cin >> target;

    if(inMatrixElementFound(mat , target))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}