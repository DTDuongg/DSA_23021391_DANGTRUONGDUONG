#include <iostream>
using namespace std;

// Cấu trúc Node của DSLK đơn
struct Node {
    int data;   // dữ liệu
    Node* next; // con trỏ trỏ tới Node tiếp theo
};

// Cấu trúc LinkedList (chỉ cần con trỏ đầu danh sách)
struct LinkedList {
    Node* head = nullptr; // ban đầu rỗng
};

// 1. Truy cập phần tử tại vị trí i
int getAt(LinkedList &L, int i) {
    Node* p = L.head;
    // Duyệt từ đầu đến vị trí i → O(n)
    for (int k = 0; k < i && p; k++) p = p->next;
    return (p ? p->data : -1); // trả về -1 nếu i không hợp lệ
}

// 2. Chèn vào đầu danh sách
void insertHead(LinkedList &L, int x) {
    Node* p = new Node{x, L.head}; // tạo node mới, next trỏ đến head cũ
    L.head = p; // cập nhật head → O(1)
}

// 3. Chèn vào cuối danh sách
void insertTail(LinkedList &L, int x) {
    Node* p = new Node{x, nullptr}; // node mới, next = nullptr
    if (!L.head) { // nếu danh sách rỗng
        L.head = p;
        return;
    }
    Node* q = L.head;
    while (q->next) q = q->next; // duyệt đến node cuối → O(n)
    q->next = p;
}

// 4. Chèn vào vị trí i
void insertAt(LinkedList &L, int i, int x) {
    if (i == 0) { insertHead(L, x); return; }
    Node* q = L.head;
    // tìm node ở vị trí i-1
    for (int k = 0; k < i-1 && q; k++) q = q->next;
    if (!q) return; // nếu i quá lớn → bỏ qua
    Node* p = new Node{x, q->next}; // node mới, next = node tại i
    q->next = p;
}

// 5. Xóa phần tử đầu
void deleteHead(LinkedList &L) {
    if (!L.head) return; // danh sách rỗng
    Node* p = L.head;
    L.head = L.head->next; // head nhảy sang node tiếp theo
    delete p; // giải phóng node đầu
}

// 6. Xóa phần tử cuối
void deleteTail(LinkedList &L) {
    if (!L.head) return; // rỗng
    if (!L.head->next) { // chỉ có 1 node
        delete L.head;
        L.head = nullptr;
        return;
    }
    Node* q = L.head;
    while (q->next->next) q = q->next; // tìm node kế cuối → O(n)
    delete q->next; // xóa node cuối
    q->next = nullptr;
}

// 7. Xóa phần tử tại vị trí i
void deleteAt(LinkedList &L, int i) {
    if (i == 0) { deleteHead(L); return; }
    Node* q = L.head;
    // tìm node tại i-1
    for (int k = 0; k < i-1 && q; k++) q = q->next;
    if (!q || !q->next) return; // không tồn tại
    Node* p = q->next;
    q->next = p->next; // bỏ qua node tại i
    delete p; // giải phóng node
}

// 8. Duyệt xuôi
void traverseForward(LinkedList &L) {
    for (Node* p = L.head; p; p = p->next)
        cout << p->data << " ";
    cout << "\n"; // O(n)
}

// 9. Duyệt ngược (dùng đệ quy)
void traverseBackward(Node* p) {
    if (!p) return;        // điểm dừng
    traverseBackward(p->next); // gọi lùi đến cuối danh sách
    cout << p->data << " "; // in khi quay ngược lại
}
