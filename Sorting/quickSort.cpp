#include <iostream>
using namespace std;

static void swap(int a[], int i, int j) {
        int temp = a[i]; 
        a[i] = a[j];
        a[j] = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int left = low+1; int right = high;
    while(true) {
        while(left <= high && a[left] <= pivot) left++;
        while(right > low && a[right] >= pivot) right--;
        if(left > right) break;
        swap(a, left, right);
    }
    swap(a, low, right);
    return right;
}

void quickSort(int a[], int low, int high) {
    if(high > low) {
        int pivotIndex = partition(a, low, high);
        quickSort(a, low, pivotIndex-1);
        quickSort(a, pivotIndex+1, high);
    }
}

int main() {
    int arr[] = {23, 21, 100, 1, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    for(auto iter : arr) {
        cout<<iter<<" ";
    }
}