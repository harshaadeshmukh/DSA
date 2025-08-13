/*
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

// in leetcode 162 and 852 both are completely same. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DemoSolu
{
    public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i =0;i<n;i++)
    {
        cin >> nums[i];
    }
    
    DemoSolu d;
    int peakIndex = d.findPeakElement(nums);
    cout << peakIndex << endl;

    return 0;

}
