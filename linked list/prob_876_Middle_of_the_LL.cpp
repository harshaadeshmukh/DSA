/*
Example 1:  
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"


// time complexity :O(n) 
// space complexity :O(1)
ListNode *findMiddleLL(ListNode *head)
{
    ListNode *start = head;
    ListNode *end = head;

    while(end!=NULL && end->next!=NULL)
    {
        start = start->next;
        end = end->next->next;

        if(start == end)
        {
            break;
        }
    }
    return start;
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

    ListNode *result = findMiddleLL(temp.head);
    while(result!=NULL)
    {
        cout << result->data;
        if(result->next!=NULL)
        {
            cout << "->";
        }
        result = result->next;
    }

    return 0;

}