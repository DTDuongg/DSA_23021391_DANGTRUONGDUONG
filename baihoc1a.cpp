#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int arr[MAX];
    int size;

    void init() { // O(1)
        size = 0;
    }

    void push_back(int x) { // O(1)
        if (size < MAX) arr[size++] = x;
    }

    void push_front(int x) { // O(n)
        if (size < MAX) {
            for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
            arr[0] = x;
            size++;
        }
    }

    void insert(int i, int x) { // O(n)
        if (i < 0 || i > size || size >= MAX) return;
        for (int j = size; j > i; j--) arr[j] = arr[j - 1];
        arr[i] = x;
        size++;
    }

    void erase_front() { // O(n)
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) arr[i] = arr[i + 1];
        size--;
    }

    void erase_back() { // O(1)
        if (size > 0) size--;
    }

    void erase(int i) { // O(n)
        if (i < 0 || i >= size) return;
        for (int j = i; j < size - 1; j++) arr[j] = arr[j + 1];
        size--;
    }

    void print_forward() { // O(n)
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void print_backward() { // O(n)
        for (int i = size - 1; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    List lst;
    lst.init();
    lst.push_back(10);
    lst.push_back(20);
    lst.push_front(5);
    lst.insert(1, 15);

    cout << "Duyet xuoi: ";
    lst.print_forward();

    cout << "Duyet nguoc: ";
    lst.print_backward();

    lst.erase_front();
    lst.erase_back();
    lst.erase(0);

    cout << "Sau khi xoa: ";
    lst.print_forward();
}
