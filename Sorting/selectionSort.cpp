#include <iostream>
using namespace std;

static void swap(int a[], int i, int j) {
        int temp = a[i]; 
        a[i] = a[j];
        a[j] = temp;
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            } 
        }
        swap(a, i, min);
    }
}

int main() {
    int arr[] = {23, 21, 100, 1, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    for(auto iter : arr) {
        cout<<iter<<" ";
    }
}