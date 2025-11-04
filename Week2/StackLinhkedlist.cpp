#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct StackLL {
    Node* head;

    void init() { // O(1)
        head = nullptr;
    }

    bool isEmpty() { // O(1)
        return head == nullptr;
    }

    int size() { // O(n)
        int cnt = 0;
        Node* tmp = head;
        while (tmp) { cnt++; tmp = tmp->next; }
        return cnt;
    }

    void push(int x) { // O(1)
        Node* p = new Node{x, head};
        head = p;
    }

    int pop() { // O(1)
        if (!head) {
            cout << "Stack rong!\n";
            return -1;
        }
        Node* tmp = head;
        int val = tmp->data;
        head = head->next;
        delete tmp;
        return val;
    }

    int top() { // O(1)
        if (!head) return -1;
        return head->data;
    }
};

int main() {
    StackLL st;
    st.init();
    st.push(5);
    st.push(15);
    st.push(25);

    cout << "Top = " << st.top() << endl;
    cout << "Pop = " << st.pop() << endl;
    cout << "Size = " << st.size() << endl;
}
