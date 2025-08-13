/*
Example 1:
nums   = [6, 7, 0, 1, 2, 4, 5] , target = 4
output = 5

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
    int findSearchRotatedSortedArray(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low<=high)
        {
            int mid = low + (high - low )/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            // check left sorted
            if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid+1;
                }
            }
            //check right sorted
            else
            {
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution s;
    
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;


    int flag = s.findSearchRotatedSortedArray(nums, target);

    if(flag != -1)
    {
        cout << "Element found at index: " << flag << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}