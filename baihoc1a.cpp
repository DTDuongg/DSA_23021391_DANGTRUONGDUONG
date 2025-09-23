#include <bits/stdc++.h>
using namespace std;

struct List {
    vector<int> arr; // dùng vector để dễ quản lý

    // Thêm phần tử vào đầu
    void insertFirst(int x) {
        arr.insert(arr.begin(), x);
    }

    // Thêm phần tử vào cuối
    void insertLast(int x) {
        arr.push_back(x);
    }

    // Thêm phần tử vào vị trí i
    void insertAt(int i, int x) {
        if (i < 0 || i > arr.size()) return;
        arr.insert(arr.begin() + i, x);
    }

    // Xóa đầu
    void deleteFirst() {
        if (!arr.empty()) arr.erase(arr.begin());
    }

    // Xóa cuối
    void deleteLast() {
        if (!arr.empty()) arr.pop_back();
    }

    // Xóa tại vị trí i
    void deleteAt(int i) {
        if (i < 0 || i >= arr.size()) return;
        arr.erase(arr.begin() + i);
    }

    // Truy cập phần tử i
    int getElement(int i) {
        if (i < 0 || i >= arr.size()) return -1;
        return arr[i];
    }

    // Duyệt xuôi
    void traverseForward() {
        for (int x : arr) cout << x << " ";
        cout << "\n";
    }

    // Duyệt ngược
    void traverseBackward() {
        for (int i = arr.size() - 1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    List lst;
    lst.insertFirst(1);
    lst.insertLast(2);
    lst.insertAt(1, 99);
    lst.traverseForward();
    lst.deleteAt(1);
    lst.traverseBackward();
}

