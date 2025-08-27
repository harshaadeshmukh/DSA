//Here we have to delete node at the middle of the linked list (follow 0 based indexing)
/*
Example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 

Example 2:
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
*/

#include<iostream>
#include "linked_list.h"
#include <bits/stdc++.h>
using namespace std;


// time complexity : O(2n) -> O(n)
// space complexity :O(1)
ListNode *removeMiddleLL(ListNode *head)
{
    if(head==NULL || head->next==NULL)
    {
        return nullptr;
    }

    ListNode *curr = head;
    int count = 0;
    while(curr!=NULL)
    {
        curr=curr->next;
        count++;
    }

    int halfCount = count/2;

    curr = head;
    for(int i=1;i<halfCount;i++)
    {   
        curr =curr->next;
    }
    curr->next = curr->next->next;

    return head;
}

// approach 2 using dummy node
// time complexity :O(n)
// space complexity :O(1)
ListNode *removeMiddleLL2(ListNode *head)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *start = dummy;
    ListNode *end = head;

    while(end!=NULL && end->next!=NULL)
    {
        start = start->next;
        end = end->next->next;
    }

    start->next = start->next->next;

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
        cin >> data;
        temp.addNodeAtEnd(data);
    }

    temp.display();
    //Approach 1 
    ListNode *result = removeMiddleLL(temp.head);

     while(result!=NULL)
    {
        cout<<result->data;
        if(result->next!=NULL){
            cout << " -> ";
        }
        result = result->next;
    }
    cout<<endl;
    //Approach 2
    result = removeMiddleLL2(temp.head);
      while(result!=NULL)
    {
        cout<<result->data;
        if(result->next!=NULL){
            cout << " -> ";
        }
        result = result->next;
    }
    return 0;
}