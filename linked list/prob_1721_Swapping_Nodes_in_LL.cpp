/*
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

Example 3:
Input: head = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k=3
Output: 1 -> 2 -> 6 -> 4 -> 5 -> 3 -> 7 -> 8
*/


#include<iostream>
#include "linked_list.h"
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(1)
ListNode *SwappingLLwithK(ListNode *head , int k)
{
    ListNode *start = head;
    ListNode *end = head;
    for(int i =1;i<k;i++)
    {
        start = start->next;
    }
    ListNode *temp = start;

    while(temp->next!=NULL)
    {
        end = end->next;
        temp = temp->next;
    }

    swap(start->data , end->data);

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
    int k;
    cin >> k;
    ListNode *result =  SwappingLLwithK(temp.head , k);

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