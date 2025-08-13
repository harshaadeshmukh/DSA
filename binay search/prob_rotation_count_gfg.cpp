/*
Example 1 -> Input: arr[] = [15, 18, 2, 3, 6, 12]
Output: 2

Example 2 -> Input: arr[] = [7, 9, 11, 12, 5]
Output: 4

Example 3 -> Input: arr[] = [7, 9, 11, 12, 15]
Output: 0
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int findcountRotationArray(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() -1;

    while(low < high)
    {
        int mid = low + (high - low )/2;

        if(nums[mid] > nums[high])
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return low; // low will be the index of the smallest element
}


int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // gfg question which you have to return index of rotation
    int index = findcountRotationArray(arr);
    cout << index << endl;

    // leetcode question which you have to return the index of the element
    // link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
    int target = arr[index];
    cout << target;

    return 0;
}
