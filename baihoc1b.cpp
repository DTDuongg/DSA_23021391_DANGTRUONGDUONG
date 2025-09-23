#include <iostream>
using namespace std;

// Mỗi phần tử trong danh sách
struct Node {
    int data;       // giá trị
    Node* next;     // con trỏ sang phần tử sau
};

// Danh sách liên kết
struct LinkedList {
    Node* head;     // phần tử đầu tiên

    // Khởi tạo rỗng
    LinkedList() { head = NULL; }

    // Thêm vào đầu
    void insertFirst(int x) {
        Node* newNode = new Node;  // tạo node mới
        newNode->data = x;
        newNode->next = head;      // node mới trỏ tới head cũ
        head = newNode;            // cập nhật head
    }

    // Thêm vào cuối
    void insertLast(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) {        // nếu list rỗng
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) // đi đến cuối
            temp = temp->next;
        temp->next = newNode;
    }

    // Xóa đầu
    void deleteFirst() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next; // bỏ qua node đầu
        delete temp;
    }

    // Xóa cuối
    void deleteLast() {
        if (head == NULL) return;
        if (head->next == NULL) { // chỉ 1 phần tử
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) // dừng ở node kế cuối
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // Duyệt xuôi (in từ đầu đến cuối)
    void traverseForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
