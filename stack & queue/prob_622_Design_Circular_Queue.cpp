#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> ans;
    int front , rear , capacity , currentSize;

    MyCircularQueue(int k) {
        capacity = k;
        ans.assign(k,0);
        currentSize  =0;
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(capacity == currentSize)
            return false;
        
        if(currentSize==0)
            front = 0;
        
        rear = (rear+1) % capacity;
        ans[rear] = value;
        currentSize++;
        return true;
    }
    
    bool deQueue() {
        if(currentSize == 0)
            return false;
        
        if(currentSize == 1) {
            front = -1;
            rear = -1;
        } else {
            front = (front+1) % capacity;
        }
        currentSize--;
        return true;
    }
    
    int Front() {
        return (front == -1) ? -1 : ans[front];
    }
    
    int Rear() {
        return (rear == -1) ? -1 : ans[rear];
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == capacity;
    }

    void printQueue() {
        if(isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for(int i=0; i<currentSize; i++) {
            int index = (front + i) % capacity;
            cout << ans[index] << " ";
        }
        cout << endl;
    }
};


int main() {
    cout << "Creating Circular Queue of size 4\n";
    MyCircularQueue cq(4);

    cout << "\n--- Enqueue Operations ---\n";
    cq.enQueue(10); cq.printQueue();
    cq.enQueue(20); cq.printQueue();
    cq.enQueue(30); cq.printQueue();
    cq.enQueue(40); cq.printQueue();

    cout << "Try Enqueue 50 (should fail, queue is full) -> "
         << (cq.enQueue(50) ? "Success" : "Fail") << endl;

    cout << "Front: " << cq.Front() << " | Rear: " << cq.Rear() << endl;

    cout << "\n--- Dequeue Operations ---\n";
    cq.deQueue(); cq.printQueue();
    cq.deQueue(); cq.printQueue();

    cout << "Enqueue 50 -> " << (cq.enQueue(50) ? "Success" : "Fail") << endl; 
    cq.printQueue();
    
    cout << "Enqueue 60 -> " << (cq.enQueue(60) ? "Success" : "Fail") << endl;
    cq.printQueue();

    cout << "\nFront: " << cq.Front() << " | Rear: " << cq.Rear() << endl;
    cout << "isFull? " << (cq.isFull() ? "Yes" : "No") << endl;

    cout << "\n--- Emptying queue completely ---\n";
    while (!cq.isEmpty()) {
        cout << "Dequeued: " << cq.Front() << endl;
        cq.deQueue();
        cq.printQueue();
    }
    cout << "Queue empty? " << (cq.isEmpty() ? "Yes" : "No") << endl;


    cq.enQueue(70); 
    cq.enQueue(100);
    cq.enQueue(80);

    cout << "Front: " << cq.Front() << " | Rear: " << cq.Rear() << endl;
    cout << "isFull? " << (cq.isFull() ? "Yes" : "No") << endl;

    return 0;
}
