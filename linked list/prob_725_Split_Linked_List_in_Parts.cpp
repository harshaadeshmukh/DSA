/*
Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, 
and earlier parts are a larger size than the later parts.
*/

#include<iostream>
#include<bits/stdc++.h>
#include "linked_list.h"
using namespace std;

vector<ListNode*> splitsLinkedListByK(ListNode *head , int k)
{
    int n =0;
    ListNode *curr = head;
    while(curr!=NULL)
    {
        n++;
        curr=curr->next;
    }

    int baseGroup = n/k;
    int extraGroup = n%k;

    vector<ListNode*>result(k,nullptr);
    curr = head;
    for(int i =0;i<k && curr ;i++)
    {
        result[i] = curr;
        int totalGroup = baseGroup;
        if(extraGroup!=0)
        {
            totalGroup+=1;
            extraGroup--;
        }

        for(int j=1;j<totalGroup;j++)
        {
            curr = curr->next;
        }

        ListNode *temp = curr->next;
        curr->next = nullptr;
        curr = temp;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    ListNode temp;
    for(int i=0;i<n;i++)
    {
        int data;
        cin >> data;
        temp.addNodeAtEnd(data);
    }

    temp.display();

    int k;  //for rotation
    cin >> k;

    vector<ListNode*>result = splitsLinkedListByK(temp.head , k);
    
    for(auto it : result)
    {
        if (it == NULL)   // empty list
        {
            cout << "[]";
        }
        else
        {
            cout << "[";
            while (it != NULL)
            {
                cout << it->data;
                if (it->next != NULL) cout << ",";
                it = it->next;
            }
            cout << "]";
        }
        cout << endl;
    }
    cout<<endl<<result.size();
    return 0;
}

