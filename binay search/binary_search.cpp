#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool binarySearchCode(vector<int> &arr , int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while(low <=high)
    {
        int mid = low + (high - low) / 2;
        //use low + (high - low) / 2 instead of (low + high) / 2 to 
        //avoid integer overflow when low and high are large. 
        //It’s a best-practice pattern in binary search

        if(arr[mid] == target)
        {
            return true;
        }

        else if(arr[mid ] >  target)
        {
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }

    return false;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    bool found = binarySearchCode(arr , target);

    if(found)
    {
        cout << "Element found";
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}