#include <bits/stdc++.h>
using namespace std;

struct MyPriorityQueue {
    int heap[1000];
    int n; // số lượng phần tử hiện có

    MyPriorityQueue() {
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    // Trả về phần tử lớn nhất (ưu tiên cao nhất)
    int max() {
        if (isEmpty()) {
            cout << "Hang doi rong!\n";
            return -999;
        }
        return heap[0];
    }

    // Hàm đẩy phần tử lên vị trí đúng
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[idx] > heap[parent]) {
                swap(heap[idx], heap[parent]);
                idx = parent;
            } else break;
        }
    }

    // Hàm đẩy phần tử xuống vị trí đúng
    void heapifyDown(int idx) {
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != idx) {
                swap(heap[idx], heap[largest]);
                idx = largest;
            } else break;
        }
    }

    // Thêm phần tử mới
    bool insert(int val) {
        if (n >= 1000) {
            cout << "Hang doi day!\n";
            return false;
        }
        heap[n] = val;
        heapifyUp(n);
        n++;
        return true;
    }

    // Xóa phần tử lớn nhất (ưu tiên cao nhất)
    int delMax() {
        if (isEmpty()) {
            cout << "Khong co phan tu de xoa!\n";
            return -999;
        }
        int maxVal = heap[0];
        heap[0] = heap[n - 1];
        n--;
        if (!isEmpty()) heapifyDown(0);
        return maxVal;
    }

    // In heap ra màn hình
    void print() {
        cout << "Heap hien tai: ";
        for (int i = 0; i < n; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MyPriorityQueue pq;

    cout << "===== TEST PRIORITY QUEUE (HEAP) =====\n";

    pq.insert(45);
    pq.insert(20);
    pq.insert(60);
    pq.insert(10);
    pq.insert(35);

    pq.print();
    cout << "Max hien tai: " << pq.max() << endl;
    cout << "Size: " << pq.size() << endl;

    cout << "\nXoa phan tu lon nhat -> " << pq.delMax() << endl;
    pq.print();

    cout << "Xoa tiep phan tu lon nhat -> " << pq.delMax() << endl;
    pq.print();

    cout << "Max sau khi xoa: " << pq.max() << endl;
    cout << "Size hien tai: " << pq.size() << endl;

    return 0;
}
