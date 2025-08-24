/*
Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;

ListNode* reverseLL(ListNode *head)
{
    ListNode *RLL =NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;

    while(curr!=NULL)
    {
        RLL = curr->next;
        curr->next = prev;
        prev = curr;
        curr = RLL;
    }
    return prev;

}


// time complexity: O(max(m,n)) where m and n are the lengths of the two linked lists
// space complexity: O(max(m,n)) for the new linked list 
// why max because in case of carry we may need an extra node
ListNode *addTwoNumberLL(ListNode *list1 , ListNode *list2)
{
    list1 = reverseLL(list1);
    list2 = reverseLL(list2);
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    int carry =0;
    while(list1!=NULL || list2!=NULL ||carry)
    {
        int sum = 0;
        if(list1!=NULL)
        {
            sum+=list1->data;
            list1=list1->next;
        }
        if(list2!=NULL)
        {
            sum+=list2->data;
            list2=list2->next;
        }

        sum +=carry;
        carry = sum/10;        
        ListNode *temp = new ListNode(sum%10);
        curr->next = temp;
        curr = curr->next;
    }
    return reverseLL(dummy->next);
}
int main()
{
    ListNode list1 , list2;
    int n;

    cin >> n;
    for(int i =0;i<n;i++)
    {
        int data;
        cin >> data;
        list1.addNodeAtEnd(data);
    }
    
    cin >> n;
    for(int i =0;i<n;i++)
    {
        int data;
        cin >> data;
        list2.addNodeAtEnd(data);
    }

    cout<<endl;
    list1.display();
    cout<<endl;
    list2.display();


    ListNode *result = addTwoNumberLL(list1.head , list2.head);

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