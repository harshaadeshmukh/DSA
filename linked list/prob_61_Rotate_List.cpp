/*
Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;

//time complexity : O(n)
//space complexity : O(1)
ListNode *rotationListbyK(ListNode *head , int k)
{
    if(head==NULL || head->next==NULL || k==0)
    {
        return head;
    }

    int n = 0;
    ListNode *curr = head;
    while(curr!=NULL)
    {
        n++;
        curr=curr->next;
    }

    k = k%n;
    if(k==0)    return head;

    int looper = n-k;
    ListNode *result = head;
    curr = head;
    int j =0;
    
    while(curr!=NULL)
    {
        j++;
        if(j==looper)
        {
            result = curr->next;
            curr->next = nullptr;
            break;
        }
        curr = curr->next;
    }

    curr =result;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }

    curr->next = head;

    return result;
}

int main()
{
    int n;
    cin >> n;

    ListNode temp;
    for(int i=0;i<n;i++)
    {
        int data;
        cin >> data;
        temp.addNodeAtEnd(data);
    }

    temp.display();

    int k;  //for rotation
    cin >> k;

    ListNode *result = rotationListbyK(temp.head , k);

    while(result!=NULL)
    {
        cout<<result->data;
        if(result->next!=NULL)
        {
            cout<<"->";
        }
        result = result->next;
    }
    return 0;
}