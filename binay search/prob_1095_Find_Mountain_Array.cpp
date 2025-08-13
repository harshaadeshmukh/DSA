/*
Example 1:
Input: mountainArr = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

Example 2:
Input: mountainArr = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    //private
    int findPeakElement(vector<int>&arr)
    {
        int low = 0;
        int high = arr.size() -1;
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(arr[mid] > arr[mid+1])
            {
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }

    int binarySearchProblem(vector<int> &arr , int low , int high , int target, bool flag)
    {
        while(low<=high)
        {
            int mid = low + (high - low) / 2;

            if(arr[mid] == target)
            {
                return mid;
            }

            if(flag)
            {
                if(arr[mid] < target)
                {
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                if(arr[mid] < target)
                {
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return -1;
    }

    public:
    // time complexity: O(log N)
    // space complexity: O(1)
    int findMountainArray(vector<int>& arr, int target )
    {
        int peak = findPeakElement(arr);

        if(peak==-1)
        {
            return -1;
        }
        if(arr[peak] ==target)
        {
            return peak;
        }

        int index1 = binarySearchProblem(arr, 0, peak - 1, target, true);
        int index2 = binarySearchProblem(arr, peak + 1, arr.size() - 1, target, false);

        if(index1==-1 && index2==-1)
        {
            return -1;
        }

        if(index1==-1)
        {
            return index2;
        }
        if(index2==-1)
        {
            return index1;
        }

        return min(index1, index2);
    }
};
int main()
{
    int n;
    cin >>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    Solution sol;
    int found = sol.findMountainArray(arr, target);

    if(found != -1)
    {
        cout << "Element found at index: " << found << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;

}