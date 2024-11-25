#include <iostream>
using namespace std;

int bs(int a[], int low, int high, int x) {
    if(low == high) {
        if(x == a[low]) return low;
        return -1;
    }
    
    if(low < high) {
    int mid = (low+high)/2;
    if(a[mid] == x) return mid;
    else if(x > a[mid]) return bs(a, mid+1, high, x);
    else if(x < a[mid]) return bs(a, low, mid-1, x);
    else return -1;}

    if(low > high) return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 10, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<bs(arr, 0, size-1, 0);
}