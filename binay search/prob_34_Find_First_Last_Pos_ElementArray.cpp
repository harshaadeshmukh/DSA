/*
Example 1:
Array: [1, 2, 2, 2, 3, 4]
Target: 2
Output: [1, 3]


Example 2:
Array: [1, 1, 1, 1, 1]
Target: 1
Output: [0, 4]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:

        // finding first occurance and use high = mid - 1 when target found
        int findFirstOccurance(vector<int> &nums , int target)
        {
            int low = 0;
            int high = nums.size() - 1;
            int ans = -1;
            while(low <=high)
            {
                int mid = low + (high - low) / 2;

                if(nums[mid] == target)
                {
                    ans = mid;
                    high = mid-1;
                }
                else if(nums[mid]  <  target)
                {
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }

            return ans;
        }
         // finding last occurance and use low = mid + 1 when target found
        int findLastOccurance(vector<int> &nums , int target)
        {
            int low = 0;
            int high = nums.size() - 1;
            int ans = -1;

            while(low <=high)
            {
                int mid = low + (high - low)/2;
                if(nums[mid] == target)
                {
                    ans = mid;
                    low = mid+1;
                }
                else if(nums[mid] < target)
                {
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            return ans;
        }

    public:
    // time complexity O(log n)
    // space complexity O(1)
        vector<int> searchRanges(vector<int> &nums , int target)
        {
            if(nums.empty())
            {
                return {-1,-1};
            }

            int firstOcc = findFirstOccurance(nums , target);

            if(firstOcc == -1)
            {
                return {-1,-1};
            }

            int lastOcc = findLastOccurance(nums , target);

            return {firstOcc , lastOcc};
        }

};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int target ;
    cin >> target;
    Solution d;

    vector<int>result = d.searchRanges(arr, target);

    cout<<"[";
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<"]";

    return 0;
}
