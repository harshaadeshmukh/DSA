#ifndef LINKED_LIST_H 
// ifndef means "if not defined" - check if LINKED_LIST_H macro doesn't exist yet

#define LINKED_LIST_H 
// define means "define a macro" - create a macro called LINKED_LIST_H to mark this header as processed
// we use UPPERCASE letters for macro names (lowercase would look like variables)
// macro is a way to give a name to a piece of code
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class ListNode{
     public:
        int data;
        ListNode *next;
        ListNode *head;
    int size;
        ListNode()
        {
            head = nullptr;
            size = 0;
        }
        ListNode(int data)
        {
            this->data = data;
            this->next = nullptr;
        }

         //add node at the beginning of the linked list
        void addNodeAtBeginning(int data)
        {
            ListNode *newNode = new ListNode(data);
            newNode->next = head;
            head = newNode;
            size++;
        }

        //add node at the middle of the linked list
        void addNodeAtMiddle(int data , int index)
        {
            if(index < 0 || index > size) // if index out of bound
            {
                cout<<"Invalid index";
                return ;
            }

            if(index==0)
            {
                addNodeAtBeginning(data);
                return;
            }
            if(index==size)
            {
                addNodeAtEnd(data);
                return;
            }

            ListNode *temp = head;
            for(int i=0;i<index-1;i++)
            {
                temp = temp->next;
            }

            ListNode *curr = new ListNode(data);
            curr->next = temp->next;
            temp->next = curr;
            size++;
        }

        // add node to the end of list
        void addNodeAtEnd(int data)
        {
            ListNode *newNode = new ListNode(data);
            if(head == nullptr)
            {
                head = newNode;
                size++;
                return;
            }
            ListNode *temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            size++;
        }

        // display linked list
        void display()
        {
            ListNode *temp = head;

            if(temp == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }
            while(temp!=NULL)
            { 
                cout<<temp->data;
                if(temp->next!=NULL)
                {
                    cout<<" -> ";
                }
                temp = temp->next;
            }
            // for displaying the size of linked list
            cout << "\nSize of linked list: " << size << endl; 
        }
};

#endif // LINKED_LIST_H

/*
int main()
{
  
MyLinkedList *head = new MyLinkedList();


    while(1)
    {
        int op;
        cin >> op;
        
        switch(op)
        {
            case 1:
            {
                int data;
                cin >> data;
                head->addNodeAtBeginning(data);
                break;
            }
            
            case 2:
            {
                int data;
                int position; // following from 0th index 
                cin >> data >> position;
                head->addNodeAtMiddle(data,position);
                break;
            }
            
            case 3:
            {
                int data;
                cin >> data;
                head->addNodeAtEnd(data);
                break;
            }
            
            case 4:
            head->display();
            break;
            
            case -1:
            {
                // exit(0); --> basically it stops the program
                // to break the loop use break;
                break;
            }
            default:
            cout << "Invalid operation" << endl;
        }
        if(op==-1)
        {
            break;
        }
    }
    delete head;
    
    return 0;
}
*/