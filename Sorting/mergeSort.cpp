#include <iostream>
using namespace std;

static void swap(int a[], int i, int j) {
        int temp = a[i]; 
        a[i] = a[j];
        a[j] = temp;
}

void merge(int arr[], int sol[], int low, int mid, int high) {
    int i = low, j = mid+1, k = 0;
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) sol[k++] = arr[i++];
        sol[k++] = arr[j++]; 
    }
    while(i<=mid) sol[k++] = arr[i++];
    while(j<=high) sol[k++] = arr[j++];
}

void mergeSort(int a[], int sol[], int low, int high) {
    if(high>low) {
        int mid = (high+low)/2;
        mergeSort(a, sol, low, mid);
        mergeSort(a, sol, mid+1, high);
        merge(a, sol, low, mid, high);
    }
}

int main() {
    int arr[] = {23, 21, 100, 1, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sol[size];
    mergeSort(arr, sol, 0, size-1);
    for(auto iter : sol) {
        cout<<iter<<" ";
    }
}