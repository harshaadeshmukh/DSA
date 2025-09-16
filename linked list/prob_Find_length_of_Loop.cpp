/*
Example 1:
Input: pos = 2,
Output: 4
Explanation: There exists a loop in the linked list and the length of the loop is 4.

Example 2:
Input: pos = 3,
Output: 3
Explanation: The loop is from 19 to 10. So length of loop is 19 → 33 → 10 = 3.

Example 3:
Input: pos = 0,    
Output: 0
Explanation: There is no loop.
*/

#include<iostream>
#include "linked_list.h"
#include<bits/stdc++.h>
using namespace std;


int findLengthOfLoop(ListNode *head)
{
    if(head==nullptr)
    {
        return 0;
    }

    ListNode *low = head;
    ListNode *high = head;

    while(high!=NULL && high->next!=NULL)
    {
        low = low->next;
        high = high->next->next;

        if(low == high){
            ListNode *temp = low->next;
            int count = 1;
            while(temp!=low)
            {
                temp = temp->next;
                ++count;
            }
            return count;
        }
    }
    return 0;
}
int main ()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);

    head->next->next->next->next->next = head->next; // 60 points to 20, creating a loop
    // Imagination : 10 -> 20 -> 30 -> 40 -> 50 -> 60
    //                      ^                       |
    //                      |                       |
    //                      +-----------------------+


    int result = findLengthOfLoop(head);
    cout << "Length of the loop is: " << result << endl;


}