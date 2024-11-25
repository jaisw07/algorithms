#include <iostream>
using namespace std;

int exp(int x, int y) {
    if(y == 0) return 1;
    else if(y%2 == 0) {
        int a = exp(x, y/2);
        return a*a;
    }
    else return x*exp(x, y-1);
}

int main() {
    cout<<exp(2, 3);
}