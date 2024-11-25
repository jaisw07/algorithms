#include <iostream>
#include <cmath>
using namespace std;

static void swap(int a[], int i, int j) {
        int temp = a[i]; 
        a[i] = a[j];
        a[j] = temp;
}

void heapifyDown(int a[], int n, int i);

void heapify(int a[], int n) {
    for(int i = (n-1)/2; i >= 0; i--) {
        heapifyDown(a, n, i);
    }
}

void heapifyDown(int a[], int n, int i) {
    int largest = i;
    int lc = 2*largest + 1;
    int rc = 2*largest + 2;
    if(a[lc] > a[largest] && lc < n) largest = lc;
    if(a[rc] > a[largest] && rc < n) largest = rc;
    if(largest!=i) {
        swap(a, largest, i);
        heapifyDown(a, n, largest);
    }
}

void deleteFromHeap(int a[], int n, int &last) {
    swap(a, 0, last--);
    heapifyDown(a, last+1, 0);
}

void heapSort(int a[], int n, int& last)  {
    heapify(a, n);
    last = n-1;
    for(int i = 0; i < n; i++) {
        deleteFromHeap(a, n, last);
    }
}

int main() {
    // int arr[] = {23, 21, 100, 1, 8, 121};
    int arr[] = {283, 12555, 52, 0, 12, -2, 69, 69};
    int size = sizeof(arr)/sizeof(arr[0]);
    // heapify(arr, size);
    // for(auto iter : arr) {
    //     cout<<iter<<" ";
    // }
    // int last = size-1;
    // cout<<endl;
    // deleteFromHeap(arr, size, last);
    // for(auto iter : arr) {
    //     cout<<iter<<" ";
    // }
    int last = -1;
    heapSort(arr, size, last);
    for(auto iter : arr) {
        cout<<iter<<" ";
    }
}