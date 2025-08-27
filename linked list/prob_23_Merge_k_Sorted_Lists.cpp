/*
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input : lists = [[1 4 6] , [1 4 6 7 10] , [3 11 19 20]]
Output: 1 -> 1 -> 3 -> 4 -> 4 -> 6 -> 6 -> 7 -> 10 -> 11 -> 19 -> 20
*/
#include<iostream>
#include "linked_list.h"
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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

    ListNode *partitionList(vector<ListNode*> &lists , int low , int high)
    {
       if(low>high)
       {
        return NULL;
       }
       if(low==high)
       {
        return lists[low];
       }
       int mid = low + (high - low)/2;
       ListNode *l1 = partitionList(lists , low , mid);
       ListNode *l2 = partitionList(lists , mid+1 , high);

       return mergeTwoLL(l1,l2);

    }

    // time complexity : O(N log k) where N is total number of nodes and k is number of linked lists
    // space complexity : O(1)
    ListNode* mergeKSortedLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        return partitionList(lists , 0 , n-1);

    }
};


int main()
{
    int n;
    cin >> n;

    vector<ListNode*> lists;
    for(int i =0;i<n;i++)
    {
        int m;
        cin >> m;
        ListNode temp;
        for(int j =0;j<m;j++)
        {
            int data;
            cin >> data;
            temp.addNodeAtEnd(data);
        }
        lists.push_back(temp.head);
    }

    Solution obj;

    ListNode*result = obj.mergeKSortedLists(lists);

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

