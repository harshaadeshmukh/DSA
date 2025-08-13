/*
Example
Input: arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 150, 160, 200, 240}
target = 160
Output: 13
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Demo{
    private:
    int binarySearchAlgo(vector<int> &arr , int low , int high , int target)
    {
        while(low <=high)
        {
            int mid = low + (high - low)/2;

            if(arr[mid] == target)
            {
                return mid;
            }
            else if(arr[mid] < target )
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
    public:
        int infiniteSortedArray(vector<int> &arr , int target)
        {
            int low = 0;
            int high = 1;
            int n = arr.size();

            while(target > arr[high] && high < n)
            {
                int temp = high +1;
                high += (high - low + 1) *2;
                low = temp;
            }

            if(high >=n)
            {
                high = n-1;
            }

            return binarySearchAlgo(arr , low , high , target);

        }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i =0; i <n;i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    Demo d;
    
    int temp = d.infiniteSortedArray(arr , target);

    if(temp == -1)
    {
        cout << "Element not found" << endl;
    }
    else{
        cout << "Element found at index: " << temp << endl;
    }
    return 0;
}