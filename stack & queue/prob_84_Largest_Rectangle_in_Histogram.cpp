/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Each bar in the histogram → can expand left and right until a smaller bar stops it.
So, for every bar:
Find Previous Smaller Element (PSE) = index of nearest smaller to the left.
Find Next Smaller Element (NSE) = index of nearest smaller to the right.
Area = height * (right - left - 1).
If you remember “previous smaller” and “next smaller”, you can always rebuild the code.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
int largest_rectangle_in_histogram(vector<int> &arr)
{
    int n = arr.size();

    vector<int>left(n,0);
    vector<int>right(n,0);

    stack<int> st;

    // right smaller index
    for(int i =n-1;i>=0;i--)
    {
        while(st.size() > 0 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            right[i] = n;
        }
        else{
            right[i] = st.top();
        }
        st.push(i);
    }

    for(int i =0;i<n;i++)
    {
        while(st.size() > 0 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            left[i] = -1;
        }
        else{
            left[i] = st.top();
        }
        st.push(i);
    }

    int result  =0;
    for(int i =0;i<n;i++)
    {
        int width = right[i] - left[i]  - 1;
        int height = arr[i];
        
        result = max(result , width*height);
    }
    return result;

}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    int result = largest_rectangle_in_histogram(arr);

    cout<<result;
    return 0;
}