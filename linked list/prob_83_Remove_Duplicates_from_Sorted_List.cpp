/*
Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/

#include "linked_list.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// time complexity: O(n)
// space complexity: O(1)
ListNode* removeDuplicatesFromLL(ListNode* head)
{
    if(head==NULL)
    {
        return NULL;
    }

    ListNode *curr = head;

    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->data == curr->next->data)
        {
            ListNode *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    int n;
    cin >> n;

    ListNode temp;

    for(int i =0; i < n;i++)
    {
       int data;
        cin >> data;
        temp.addNodeAtEnd(data);
    
    }

    temp.display();

    ListNode *result = removeDuplicatesFromLL(temp.head);

    cout << "After removing duplicates from sorted linked list: ";
    ListNode *curr = result;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

}