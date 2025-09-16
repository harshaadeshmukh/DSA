/*
Example 1:
Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 
2s to the right end of the list, and 1s in between. The final list will be:

Example 2:
Input: head = 2 → 2 → 0 → 1
Output: 0 → 1 → 2 → 2
Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be:
*/

#include<iostream>
#include "linked_list.h"
#include<bits/stdc++.h>

// time complexity : O(n)
// space complexity : O(1)
ListNode *sort_zeros_ones_twos(ListNode *head)
{
    if(head==nullptr)
    {
        return head;
    }

    int zeros = 0;
    int ones = 0;
    int twos = 0;

    ListNode *temp = head;

    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            zeros++;
        }
        else if(temp->data == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
        temp = temp->next;
    }

    temp = head;
    while(zeros)
    {
        temp->data = 0;
        temp = temp->next;
        zeros--;
    }

    while(ones)
    {
        temp->data = 1;
        temp = temp->next;
        ones--;
    }
    while(twos)
    {
        temp->data = 2;
        temp = temp->next;
        twos--;
    }
    return head;
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

    ListNode *result =  sort_zeros_ones_twos(temp.head);

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