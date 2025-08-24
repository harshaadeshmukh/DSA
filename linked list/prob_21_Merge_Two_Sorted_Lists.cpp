/*
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
*/

#include<iostream>
#include "linked_list.h"
#include<bits/stdc++.h>
using namespace std;


// time complexity: O(n)
// space complexity: O(1)
ListNode* mergeTwoLL(ListNode *list1 , ListNode *list2)
{
    if(list1==NULL)
    {
        return list2;
    }
    if(list2==nullptr)
    {
        return list1;
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;

    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data <= list2->data)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else{
            curr->next = list2;
            list2 = list2->next;
        }

        curr =curr->next;
    }

    while(list1!=NULL)
    {
        curr->next = list1;
        list1 = list1->next;
        curr = curr->next;
    }
    
    while(list2!=NULL)
    {
        curr->next = list2;
        list2 = list2->next;
        curr = curr->next;
    }

    return dummy->next;
    
}

int main()
{
    int n;
    cin >> n;

    ListNode temp1;
    for(int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        temp1.addNodeAtEnd(data);
    }

    temp1.display();

    cin >> n;
    ListNode temp2;
    for(int i =0;i<n;i++)
    {
        int data;
         cin >> data;
         temp2.addNodeAtEnd(data);
    }

    temp2.display();

    
    ListNode *result = mergeTwoLL(temp1.head , temp2.head);

    while(result!=NULL)
    {
        cout << result->data;
        if(result->next!=NULL){
            cout << " -> ";
        }
        result = result->next;
    }

    cout << endl;

    return 0;
}