/*
Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;

// time complexity: O(n)
// space complexity: O(n)
ListNode *removeDuplicatesFromLL(ListNode *head)
{
    map<int,int> mp;

    ListNode *temp = head;
    while(temp!=NULL)
    {
        mp[temp->data]++;
        temp = temp->next;
    }
    ListNode *dummy = new ListNode(-1);
    temp = dummy;
    for(auto it : mp)
    {
        if(it.second == 1)
        {
            ListNode *newNode = new ListNode(it.first);
            temp->next = newNode;
            temp = temp->next;
        }
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
        cin >> data;
        temp.addNodeAtEnd(data);
    }

    temp.display();

    ListNode *result = removeDuplicatesFromLL(temp.head);
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