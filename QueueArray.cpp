#include <iostream>
using namespace std;

const int MAX = 100;

struct Queue {
    int arr[MAX];
    int front, rear, count;

    void init() { // O(1)
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() { // O(1)
        return count == 0;
    }

    int size() { // O(1)
        return count;
    }

    void enqueue(int x) { // O(1)
        if (count < MAX) {
            rear = (rear + 1) % MAX;
            arr[rear] = x;
            count++;
        } else cout << "Queue day!\n";
    }

    int dequeue() { // O(1)
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % MAX;
        count--;
        return val;
    }

    int peek() { // O(1)
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    Queue q;
    q.init();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front = " << q.peek() << endl;
    cout << "Dequeue = " << q.dequeue() << endl;
    cout << "Size = " << q.size() << endl;
}
