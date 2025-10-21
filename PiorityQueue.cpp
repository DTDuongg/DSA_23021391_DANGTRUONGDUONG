#include <bits/stdc++.h>
using namespace std;

struct MyPriorityQueue {
    int data[1000];
    int n; 

    MyPriorityQueue() {
        n = 0;
    }

    bool empty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    bool push(int x) {
        if (n >= 1000) {
            cout << "Hang doi da day!\n";
            return false;
        }
        data[n++] = x;
        return true;
    }

    int getMax() {
        if (empty()) {
            cout << "Hang doi rong!\n";
            return -999;
        }
        int best = data[0];
        for (int i = 1; i < n; i++)
            if (data[i] > best)
                best = data[i];
        return best;
    }

    int popMax() {
        if (empty()) {
            cout << "Khong co phan tu de xoa!\n";
            return -999;
        }
        int pos = 0;
        for (int i = 1; i < n; i++)
            if (data[i] > data[pos])
                pos = i;

        int maxVal = data[pos];
    
        data[pos] = data[n - 1];
        n--;
        return maxVal;
    }

    void printQueue() {
        cout << "Cac phan tu hien co: ";
        for (int i = 0; i < n; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    MyPriorityQueue pq;

    cout << "=== KIEM TRA PRIORITY QUEUE ===\n";

    pq.push(25);
    pq.push(60);
    pq.push(15);
    pq.push(45);
    pq.push(30);

    pq.printQueue();

    cout << "Phan tu lon nhat: " << pq.getMax() << endl;
    cout << "So luong phan tu: " << pq.size() << endl;

    cout << "Xoa phan tu lon nhat -> " << pq.popMax() << endl;
    pq.printQueue();

    cout << "Xoa tiep phan tu lon nhat -> " << pq.popMax() << endl;
    pq.printQueue();

    cout << "Phan tu lon nhat hien tai: " << pq.getMax() << endl;
    cout << "So luong hien tai: " << pq.size() << endl;

    return 0;
}
