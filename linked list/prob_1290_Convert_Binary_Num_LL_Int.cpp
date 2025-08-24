/*
Example 1:
Input : head = [1,0,0,1,1]
Output: 19
Explanation: (10011) in base 2 = (19) in base 10

Example 2:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
*/

#include<iostream>
#include "linked_list.h"
#include<bits/stdc++.h>

// Optimal Approach 
// Time complexity O(n)
// Space complexity O(1)
int convertBinarytoInteger(ListNode *head)
{
    int result = 0;
    while(head!=NULL)
    {
        result = (result << 1) | head->data;
        head = head->next;
    }
    return result;
}

//brute force approach
// time complexity O(n)
// space complexity O(n)
int convertBinarytoInteger2(ListNode *head)
{
    vector<int> ans;
    ListNode *curr = head;
    while(curr!=NULL)
    {
        ans.push_back(curr->data);
        curr = curr->next;
    }
    
    int result = 0;
    for(int it : ans)
    {
        result = result * 2 + it;
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

    int result = convertBinarytoInteger(temp.head);
    cout << result << endl;

    int result2 = convertBinarytoInteger2(temp.head);
    cout << result2 << endl;
    return 0;
}