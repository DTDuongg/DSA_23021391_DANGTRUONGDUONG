#include <iostream>
#include <vector>
using namespace std;

// Cấu trúc List sử dụng vector (mảng động trong C++)
struct List {
    vector<int> data;  // lưu trữ toàn bộ phần tử
};

// 1. Truy cập phần tử tại vị trí i
int getAt(List &L, int i) {
    // Truy cập trực tiếp: O(1)
    return L.data[i];
}

// 2. Chèn vào đầu danh sách
void insertHead(List &L, int x) {
    // insert(begin, x): dịch toàn bộ phần tử sang phải → O(n)
    L.data.insert(L.data.begin(), x);
}

// 3. Chèn vào cuối danh sách
void insertTail(List &L, int x) {
    // push_back: thêm cuối mảng → O(1) trung bình
    L.data.push_back(x);
}

// 4. Chèn vào vị trí i
void insertAt(List &L, int i, int x) {
    // insert(begin + i, x): dịch phần tử từ i → cuối → O(n)
    L.data.insert(L.data.begin() + i, x);
}

// 5. Xóa phần tử đầu
void deleteHead(List &L) {
    // erase(begin): xóa đầu, dịch phần tử còn lại → O(n)
    L.data.erase(L.data.begin());
}

// 6. Xóa phần tử cuối
void deleteTail(List &L) {
    // pop_back: xóa cuối → O(1)
    L.data.pop_back();
}

// 7. Xóa phần tử tại vị trí i
void deleteAt(List &L, int i) {
    // erase(begin + i): dịch các phần tử sau i → O(n)
    L.data.erase(L.data.begin() + i);
}

// 8. Duyệt xuôi (in từ đầu đến cuối)
void traverseForward(List &L) {
    for (int x : L.data) cout << x << " "; // O(n)
    cout << "\n";
}

// 9. Duyệt ngược (in từ cuối về đầu)
void traverseBackward(List &L) {
    for (int i = L.data.size() - 1; i >= 0; i--)
        cout << L.data[i] << " "; // O(n)
    cout << "\n";
}
