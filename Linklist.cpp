#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    void init() { // O(1)
        head = nullptr;
    }

    void push_front(int x) { // O(1)
        Node* p = new Node{x, head};
        head = p;
    }

    void push_back(int x) { // O(n)
        Node* p = new Node{x, nullptr};
        if (!head) { head = p; return; }
        Node* tmp = head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = p;
    }

    void insert(int i, int x) { // O(n)
        if (i == 0) { push_front(x); return; }
        Node* tmp = head;
        for (int k = 0; k < i - 1 && tmp; k++) tmp = tmp->next;
        if (!tmp) return;
        Node* p = new Node{x, tmp->next};
        tmp->next = p;
    }

    void erase_front() { // O(1)
        if (!head) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    void erase_back() { // O(n)
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* tmp = head;
        while (tmp->next->next) tmp = tmp->next;
        delete tmp->next;
        tmp->next = nullptr;
    }

    void erase(int i) { // O(n)
        if (i == 0) { erase_front(); return; }
        Node* tmp = head;
        for (int k = 0; k < i - 1 && tmp; k++) tmp = tmp->next;
        if (!tmp || !tmp->next) return;
        Node* del = tmp->next;
        tmp->next = del->next;
        delete del;
    }

    void print_forward() { // O(n)
        Node* tmp = head;
        while (tmp) { cout << tmp->data << " "; tmp = tmp->next; }
        cout << endl;
    }

    void print_backward(Node* p) { // O(n), thêm chi phí ngăn xếp đệ quy
        if (!p) return;
        print_backward(p->next);
        cout << p->data << " ";
    }
};

int main() {
    LinkedList lst;
    lst.init();

    lst.push_back(10);
    lst.push_back(20);
    lst.push_front(5);
    lst.insert(1, 15);

    cout << "Duyet xuoi: ";
    lst.print_forward();

    cout << "Duyet nguoc: ";
    lst.print_backward(lst.head);
    cout << endl;

    lst.erase_front();
    lst.erase_back();
    lst.erase(0);

    cout << "Sau khi xoa: ";
    lst.print_forward();
}
