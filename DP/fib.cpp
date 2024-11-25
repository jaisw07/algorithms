#include <iostream>
using namespace std;

void fib(int ser[], int n) {
    ser[0] = 0; ser[1] = ser[2] = 1;
    for(int i = 3; i <= n; i++) {
        ser[i] = ser[i-1] + ser[i-2];
    }
}

int main() {
    int arr[30];
    fib(arr, 29);
    for(auto iter : arr) {
        cout<<iter<<" ";
    }    
}