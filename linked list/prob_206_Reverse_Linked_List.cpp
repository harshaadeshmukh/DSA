/*
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

#include<iostream>
#include "linked_list.h"
#include <bits/stdc++.h>
using namespace std;

//time complexity :O(n)
//space complexity :O(1)
ListNode* reverseLinkedList(ListNode *head)
{
    ListNode *RLL = NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;

    while(curr !=NULL)
    {
        RLL = curr->next;
        curr->next = prev;
        prev = curr;
        curr = RLL;
    }

    return prev;
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

    ListNode *result = reverseLinkedList(temp.head);

    while(result!=NULL)
    {
        cout << result->data;
        if(result->next!=NULL){
            cout << " -> ";
        }
        result = result->next;
    }


    return 0;
}