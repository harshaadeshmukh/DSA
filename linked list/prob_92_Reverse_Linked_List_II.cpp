/*
Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;


ListNode *reverseLLwithLandR(ListNode *head , int left , int right)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *prev = dummy;

    for(int i =1;i<left;i++)
    {
        prev = prev->next;
    }

    ListNode *curr = prev->next;

    for(int i =0;i<right-left;i++)
    {
        ListNode *temp = prev->next;
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next= temp;
    }
    return  dummy->next;
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

    cout<<endl;

    int left , right;
    cin >> left >> right;

    ListNode *result = reverseLLwithLandR(temp.head , left , right);

    while(result!=NULL)
    {
        cout<<result->data;
        if(result->next!=NULL)
        {
            cout<<" ";
        }
        result = result->next;
    }
    return 0;
}