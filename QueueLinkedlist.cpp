#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct QueueLL {
    Node* front;
    Node* rear;

    void init() { // O(1)
        front = rear = nullptr;
    }

    bool isEmpty() { // O(1)
        return front == nullptr;
    }

    int size() { // O(n)
        int cnt = 0;
        Node* tmp = front;
        while (tmp) { cnt++; tmp = tmp->next; }
        return cnt;
    }

    void enqueue(int x) { // O(1)
        Node* p = new Node{x, nullptr};
        if (!rear) {
            front = rear = p;
        } else {
            rear->next = p;
            rear = p;
        }
    }

    int dequeue() { // O(1)
        if (!front) {
            cout << "Queue rong!\n";
            return -1;
        }
        Node* tmp = front;
        int val = tmp->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete tmp;
        return val;
    }

    int peek() { // O(1)
        if (!front) return -1;
        return front->data;
    }
};

int main() {
    QueueLL q;
    q.init();
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);

    cout << "Front = " << q.peek() << endl;
    cout << "Dequeue = " << q.dequeue() << endl;
    cout << "Size = " << q.size() << endl;
}
