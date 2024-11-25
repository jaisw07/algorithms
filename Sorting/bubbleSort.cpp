#include <iostream>
using namespace std;

static void swap(int a[], int i, int j) {
        int temp = a[i]; 
        a[i] = a[j];
        a[j] = temp;
}

void bubbleSort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                swap(a, j, j+1);
            }
        }
    }
}

int main() {
    int arr[] = {23, 21, 100, 1, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    for(auto iter : arr) {
        cout<<iter<<" ";
    }
}