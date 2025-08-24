/*
Input: head = [7,4,5,6], val = 6
Output: [1,2,3,4,5]
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
ListNode * removeValFromLL(ListNode *head , int value)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    ListNode *temp = head;

    while(temp!=NULL)
    {
        if(temp->data == value)
        {
            curr->next = temp->next;
        }
        else{
            curr->next=  temp;
            curr = curr->next;
        }
        temp = temp->next;
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

    ListNode *result = removeValFromLL(temp.head  ,value);

    while(result!=NULL)
    {
        cout<<result->data;
        if(result->next!=NULL)
        {
            cout<<" -> ";
        }
        result = result->next;
    }

}