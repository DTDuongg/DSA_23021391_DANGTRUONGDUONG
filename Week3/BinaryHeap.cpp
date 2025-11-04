#include <bits/stdc++.h>
using namespace std;

struct BinaryHeap {
    int heap[1000]; 
    int n;          
    bool isMaxHeap; 

    BinaryHeap(bool type = true) { 
        n = 0;
        isMaxHeap = type;
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    // So sánh theo loại heap
    bool compare(int a, int b) {
        if (isMaxHeap) return a > b;
        else return a < b;
    }

    // Đưa phần tử lên đúng vị trí
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (compare(heap[idx], heap[parent])) {
                swap(heap[idx], heap[parent]);
                idx = parent;
            } else break;
        }
    }

    // Đưa phần tử xuống đúng vị trí
    void heapifyDown(int idx) {
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int extreme = idx;

            if (left < n && compare(heap[left], heap[extreme]))
                extreme = left;
            if (right < n && compare(heap[right], heap[extreme]))
                extreme = right;

            if (extreme != idx) {
                swap(heap[idx], heap[extreme]);
                idx = extreme;
            } else break;
        }
    }

    // Thêm phần tử mới
    bool insert(int value) {
        if (n >= 1000) {
            cout << "Heap day, khong the chen them!\n";
            return false;
        }
        heap[n] = value;
        heapifyUp(n);
        n++;
        return true;
    }

    // Trả về phần tử gốc (max hoặc min)
    int top() {
        if (isEmpty()) {
            cout << "Heap rong!\n";
            return -999;
        }
        return heap[0];
    }

    // Xóa phần tử gốc
    int removeRoot() {
        if (isEmpty()) {
            cout << "Khong co phan tu de xoa!\n";
            return -999;
        }
        int rootVal = heap[0];
        heap[0] = heap[n - 1];
        n--;
        if (!isEmpty()) heapifyDown(0);
        return rootVal;
    }

    // Xây dựng heap từ mảng có sẵn
    void buildHeap(int arr[], int size) {
        n = size;
        for (int i = 0; i < n; i++) heap[i] = arr[i];
        for (int i = (n / 2) - 1; i >= 0; i--)
            heapifyDown(i);
    }

    // In heap ra màn hình
    void printHeap() {
        cout << (isMaxHeap ? "Max" : "Min") << "-Heap: ";
        for (int i = 0; i < n; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    cout << "===== TEST BINARY HEAP =====\n";

    // Max-Heap
    BinaryHeap maxHeap(true);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(40);
    maxHeap.insert(10);
    maxHeap.insert(30);

    maxHeap.printHeap();
    cout << "Root hien tai (max): " << maxHeap.top() << endl;

    cout << "Xoa root -> " << maxHeap.removeRoot() << endl;
    maxHeap.printHeap();

    // Min-Heap
    cout << "\n===== MIN-HEAP =====\n";
    BinaryHeap minHeap(false);
    int arr[] = {40, 25, 15, 10, 30};
    minHeap.buildHeap(arr, 5);
    minHeap.printHeap();
    cout << "Root hien tai (min): " << minHeap.top() << endl;

    cout << "Xoa root -> " << minHeap.removeRoot() << endl;
    minHeap.printHeap();

    return 0;
}
