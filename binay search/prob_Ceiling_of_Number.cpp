//Example usage
// Input: 5 1 2 8 10 12
//      target  11
// Output: 12

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int findCeilingNumber(vector<int> &arr , int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(low < arr.size())
    {
        return low;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int findIndex = findCeilingNumber(arr , target);

    cout << findIndex << endl;

    return 0;
   
}