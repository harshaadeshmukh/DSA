// In this problem we are going to implement a stack using two queues.
// We will use the STL queue to implement the stack operations.
// The stack operations are push, pop, top and empty.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Demo{

    private:
    queue<int>q1,q2;
    public:
    void push(int x)
    {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int x = q1.front();  //!=-1?q1.front():-1;
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();  //!=NULL?q1.front():-1;
    }

    bool empty()
    {
        return q1.empty()==true;
    }
};

int main()
{
    Demo* d = new Demo();

    
    d->push(10);
    d->push(20);
    d->push(30);
    d->push(40);


     cout << "Top element: " << d->top() << endl;   // should print 40
    
    cout << "Popped: " << d->pop() << endl;       // should print 40
    cout << "Top element: " << d->top() << endl;   // should print 30
    
    cout << "Is empty? " << (d->empty() ? "Yes" : "No") << endl; // should print No
    
    cout<<"Popped: " << d->pop()<<endl; // removes 30
    cout<<"Popped: "<< d->pop()<<endl; // removes 20
    
    cout << "Is empty now? " << (d->empty() ? "Yes" : "No") << endl; // should print No

    d->pop(); // removes 10
    cout << "Is empty now? " << (d->empty() ? "Yes" : "No") << endl; // should print Yes

    return 0;
    

}