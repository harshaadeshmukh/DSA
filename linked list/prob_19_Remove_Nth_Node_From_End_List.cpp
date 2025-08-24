/*
Example 1: 
Input: head = [1,2,3,4,5], n = 2 // n is index from the end that start from 1
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;

// time complexity: O(L) 
// space complexity: O(1)
ListNode *removeNthNodeAtEndOfLL(ListNode *head , int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;

    ListNode *temp = head;
    int size = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        size++;
    }

    int subIndex = size - n;
    temp = head;
    int i =0;
    while(temp!=NULL)
    {
        if(i==subIndex)
        {
            curr->next = temp->next;
        }
        else{
            curr->next = temp;
            curr = curr->next;
        }
        temp = temp->next;
        i++;
    }
    return dummy->next;
}
int main()
{
    int n;
    cin >> n;

    ListNode temp;
    for(int i =0;i<n;i++)
    {
        int data;
        cin>>data;
        temp.addNodeAtEnd(data);
    }

    int value;
    cin >> value;

    temp.display();

    ListNode *result = removeNthNodeAtEndOfLL(temp.head  ,value);
    while(result!=NULL)
    {
        cout<<result->data;
        if(result->next!=NULL)
        {
            cout<<" -> ";
        }
        result = result->next;
    }
    return 0;
}