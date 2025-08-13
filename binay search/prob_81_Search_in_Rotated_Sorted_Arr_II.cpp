/*
Example 1:
nums = [1, 0, 1, 1, 1] , target = 1
output = 0

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: 3
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public :
    int findSearchRotatedSortedArray2(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low<= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
            {
                return mid;
            }

            if(nums[low]==nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            if(nums[low] <= nums[mid]) // left side is sorted
            {
                if(nums[low] <= target && target < nums[mid])
                {
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else // right side is sorted
            {
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;
    int found = obj.findSearchRotatedSortedArray2(arr, target);

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