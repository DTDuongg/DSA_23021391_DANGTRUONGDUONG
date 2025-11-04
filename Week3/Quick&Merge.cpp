#include <bits/stdc++.h>
using namespace std;

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


void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = a[left + i];
    for(int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}


int partitionQS(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partitionQS(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

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

    int b1[n], b2[n], b3[n], b4[n], b5[n];
    copy(arr, arr + n, b1);
    copy(arr, arr + n, b2);
    copy(arr, arr + n, b3);
    copy(arr, arr + n, b4);
    copy(arr, arr + n, b5);

   
    bubbleSort(b1, n);
    cout << "\nSau Bubble Sort: ";
    printArray(b1, n);
    cout << "Trung vi: " << b1[n / 2] << endl;

   
    selectionSort(b2, n);
    cout << "\nSau Selection Sort: ";
    printArray(b2, n);
    cout << "Trung vi: " << b2[n / 2] << endl;

   
    insertionSort(b3, n);
    cout << "\nSau Insertion Sort: ";
    printArray(b3, n);
    cout << "Trung vi: " << b3[n / 2] << endl;

    
    mergeSort(b4, 0, n - 1);
    cout << "\nSau Merge Sort: ";
    printArray(b4, n);
    cout << "Trung vi: " << b4[n / 2] << endl;

   
    quickSort(b5, 0, n - 1);
    cout << "\nSau Quick Sort: ";
    printArray(b5, n);
    cout << "Trung vi: " << b5[n / 2] << endl;

    return 0;
}
