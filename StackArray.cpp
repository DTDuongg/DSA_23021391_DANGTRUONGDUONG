#include <iostream>
using namespace std;

const int MAX = 100;

struct Stack {
    int arr[MAX];
    int topIndex;

    void init() { // O(1)
        topIndex = -1;
    }

    bool isEmpty() { // O(1)
        return topIndex == -1;
    }

    int size() { // O(1)
        return topIndex + 1;
    }

    void push(int x) { // O(1)
        if (topIndex < MAX - 1) arr[++topIndex] = x;
        else cout << "Stack day!\n";
    }

    int pop() { // O(1)
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top() { // O(1)
        if (isEmpty()) return -1;
        return arr[topIndex];
    }
};

int main() {
    Stack st;
    st.init();
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top = " << st.top() << endl;
    cout << "Pop = " << st.pop() << endl;
    cout << "Size = " << st.size() << endl;
}
