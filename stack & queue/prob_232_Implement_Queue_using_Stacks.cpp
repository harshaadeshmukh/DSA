// In this problem we are going to implement a queue using two stacks.
// We will use the STL stack to implement the queue operations.
// The queue operations are push, pop, peek and empty.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Demo {
    stack<int> s1, s2;

public:
    void push(int x) {
        
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Demo *d = new Demo();

    d->push(10);
    d->push(20);
    d->push(30);
    d->push(40);

    cout << "Front element: " << d->peek() << endl;   // should print 10

    cout << "Popped: " << d->pop() << endl;           // should print 10
    cout << "Front element: " << d->peek() << endl;   // should print 20

    cout << "Is empty? " << (d->empty() ? "Yes" : "No") << endl; // should print No

    cout << "Popped: " << d->pop() << endl; // removes 20
    cout << "Popped: " << d->pop() << endl; // removes 30

    cout << "Is empty now? " << (d->empty() ? "Yes" : "No") << endl; // should print No

    d->pop(); // removes 40
    cout << "Is empty now? " << (d->empty() ? "Yes" : "No") << endl; // should print Yes

    return 0;
}
