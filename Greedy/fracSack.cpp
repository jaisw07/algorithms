#include <iostream>
#include <algorithm>
using namespace std;

struct item{
    double profit, weight;
};

static bool comp(item a, item b) {
    double ratio1 = a.profit/a.weight;
    double ratio2 = b.profit/b.weight;
    return ratio1>ratio2;
}

double sack(int sackSize, item arr[], int numItems) {
    sort(arr, arr+numItems, comp);
    //comp is false for all i+1, i
    int remWt = sackSize;
    double finalProf = 0;
    //if w < sackSize, add full item
    for(int i = 0; i < numItems; i++) {
        if(arr[i].weight <= remWt) {
            remWt -= arr[i].weight;
            finalProf += arr[i].profit;
            cout<<"Item "<<(i+1)<<". Weight: "<<arr[i].weight
            <<". Profit: "<<arr[i].profit<<endl;
        }
        //add frac part
        else{
            finalProf += arr[i].profit * (remWt/arr[i].weight);
            cout<<"Item "<<i<<". Weight: "<<remWt<<". Profit: "<<(arr[i].profit * (remWt/arr[i].weight))<<endl;
            return finalProf;
        }
    }
    return finalProf;
}

int main() {
    int w = 50;
    item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout<<sack(w, arr, N);
}