#include "linked_list.h"

int main()
{
    ListNode *head = new ListNode();

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