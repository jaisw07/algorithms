#include <iostream>
using namespace std;

static void swap(int a[], int i, int j) {
        int temp = a[i]; 
        a[i] = a[j];
        a[j] = temp;
}

void insertionSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int key = a[i];
        while(i-1 >= 0 && a[i-1] > key) {
            a[i] = a[--i];
        }
        a[i] = key;
    }
}

int main() {
    int arr[] = {23, 21, 100, 1, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);
    for(auto iter : arr) {
        cout<<iter<<" ";
    }
}