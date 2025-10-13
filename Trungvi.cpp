#include <bits/stdc++.h>
using namespace std;

// ===== Các hàm sắp xếp =====
void bubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// ===== Hàm in mảng =====
void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

// ===== Hàm chính =====
int main() {
    int n;
    cout << "Nhap so phan tu (n le): ";
    cin >> n;

    if(n % 2 == 0) {
        cout << "Vui long nhap so le de co mot trung vi ro rang!\n";
        return 0;
    }

    int arr[n];
    cout << "Nhap " << n << " so nguyen:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    // Tạo 3 bản sao mảng ban đầu
    int b1[n], b2[n], b3[n];
    copy(arr, arr + n, b1);
    copy(arr, arr + n, b2);
    copy(arr, arr + n, b3);

    // Bubble Sort
    bubbleSort(b1, n);
    cout << "\nSau Bubble Sort: ";
    printArray(b1, n);
    cout << "Trung vi: " << b1[n / 2] << endl;

    // Selection Sort
    selectionSort(b2, n);
    cout << "\nSau Selection Sort: ";
    printArray(b2, n);
    cout << "Trung vi: " << b2[n / 2] << endl;

    // Insertion Sort
    insertionSort(b3, n);
    cout << "\nSau Insertion Sort: ";
    printArray(b3, n);
    cout << "Trung vi: " << b3[n / 2] << endl;

    return 0;
}
