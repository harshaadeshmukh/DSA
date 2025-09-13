/*
Example 1:
Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

Example 2:
Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

Example 3:
Input: arr[] = [1, 2, 3, 5]
Output: [2, 3, 5, -1]
Explanation: For a sorted array, the next element is next greater element also except for the last element.

Example 4:
Input: arr[] = [5, 4, 3, 1]
Output: [-1, -1, -1, -1]
Explanation: There is no next greater element for any of the elements in the array, so all are -1.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
vector<int> findNextGreaterElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> st; // Stack to keep track of elements

    for (int i = n - 1; i >= 0; --i) {

        // Pop elements from the stack that are less than or equal to the current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is not empty, the top element is the next greater element
        if(st.empty())
        {
            result[i] = -1;
        }
        else{
            result[i] = st.top();
       }

        // Push the current element onto the stack
        st.push(arr[i]);
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
        cin >> arr[i];
    }

    vector<int> result = findNextGreaterElements(arr);

    for(int i =0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}


// Refer this : https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1