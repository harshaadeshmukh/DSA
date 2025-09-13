// In this min stack problem we are going to implement a stack which in addition to push and pop operations,
// also supports a getMin operation that returns the minimum element in the stack in constant time.
// We will use a stack and put 2 values in it. One is the actual value and the other is the minimum value
// at the time of pushing the actual value.
// operations: push, pop, top, getMin


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// All operations are in O(1) time complexity
// space complexity : O(n)
class Demo {
    stack<pair<int,int>> st;
    
    public:
    void push(int val) {
        
        if(st.empty())
        {
            st.push(make_pair(val,val));
        }
        else{
            int mini = min(val , st.top().second);
            st.push(make_pair(val , mini));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main()
{
    Demo* d = new Demo();

    d->push(10);
    d->push(20);
    d->push(-5);
    d->push(5);
    d->push(15);

    cout << "Top element: " << d->top() << endl;       // should print 15
    cout << "Minimum element: " << d->getMin() << endl; // should print -5

    d->pop();
    cout << "Top element after pop: " << d->top() << endl;       // should print 5
    cout << "Minimum element after pop: " << d->getMin() << endl; // should print -5

    d->pop();
    d->push(-10);
    cout << "Top element after another pop: " << d->top() << endl;       // should print -10
    cout << "Minimum element after another pop: " << d->getMin() << endl; // should print -10

    d->push(100);
    cout << "Top element after pushing 100: " << d->top() << endl;       // should print 100
    cout << "Minimum element after pushing 100: " << d->getMin() << endl; // should print -10

    return 0;
}
