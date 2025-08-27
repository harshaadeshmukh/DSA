/*
Example 1:
Input: head = [2,1,5]
Output: [5,5,0]

Example 2:
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
*/
// You can refer https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// for better understanding of next greater element in array 

#include<iostream>
#include "linked_list.h"
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
vector<int> nextGreaterElementFromLL(ListNode *head)
{
    vector<int> ans;
    stack<int> st;

    ListNode *temp = head;
    while(temp!=NULL)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }

    int n = ans.size();
    vector<int> result(n,0);

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top() <= ans[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            result[i] = 0;
        }
        else{
            result[i] = st.top();
        }
        st.push(ans[i]);
    }

    return result;
}
int main()
{
    int n;
    cin >> n;

    ListNode temp;
    for(int i =0;i<n;i++)
    {
        int data;
        cin >> data;
        temp.addNodeAtEnd(data);
    }

    temp.display();

    vector<int> result = nextGreaterElementFromLL(temp.head);

    for(int i=0;i<result.size();i++)
    {
        cout << result[i]<< " ";
    }
    return 0;
}