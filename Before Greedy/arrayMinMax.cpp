#include <iostream>
using namespace std;

int mini(int a, int b) {
    if(a < b) return a;
    return b;
}
int maxi(int a, int b){
    if(a>b) return a;
    return b;
}

void minMax(int arr[], int size, int &max, int&min) {
    min = arr[0], max = arr[0];
    for(int i = 0; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        else if(arr[i] < min) {
            min = arr[i];
        }
    }
}

pair<int,int> recMinMax(int arr[], int size, int low, int high) {
    if(low == high) {
        return make_pair(low, low);
    }
    else if(high - low == 1) {
        return make_pair(mini(arr[low], arr[high]), maxi(arr[low], arr[high]));
    }
    else{
        int mid = (high+low)/2;
        pair<int, int> o1 = recMinMax(arr, size, low, mid);
        pair<int, int> o2 = recMinMax(arr, size, mid+1, high);
        return make_pair(min(o1.first, o2.first), max(o1.first, o2.first));
    }
}

int main() {
    int arr[] = {1, -2, 300, 4, 5, 10, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min, max;
    minMax(arr, size, max, min);
    cout<<"Min: "<<min<<endl<<"Max: "<<max<<endl;
    recMinMax(arr, size, 0, size-1);
    cout<<"Min: "<<min<<endl<<"Max: "<<max;
}