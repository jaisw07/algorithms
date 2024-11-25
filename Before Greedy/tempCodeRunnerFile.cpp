#include <iostream>
#include <cmath>
using namespace std;

int mini(int a, int b) {
    if(a < b) return a;
    return b;
}
int maxi(int a, int b){
    if(a>b) return a;
    return b;
}

int get_size(long a);

long karatsuba(long x, long y) {
    //base case
    if(x < 10 && y < 10) return x*y;
    //get size
    int length = get_size(x);
    //set vars
    long a = x/pow(10, (length/2));
    long b = x - a*pow(10, (length/2));
    long c = y/pow(10, (length/2));
    long d = y - c*pow(10, (length/2));
    //
    long p = karatsuba(a, c);
    long q = karatsuba(b, d);
    long s = karatsuba(a+b, c+d);
    long r = s - p - q;
    //
    return p*pow(10, length) + pow(10, (length/2))*r + q;
}

int get_size(long a) {
    int counter = 0;
    while(a>0) {
        a/=10; counter++;
    }
    return counter;
}

int main() {
    long a = 145623; long b = 653324;
    cout<<karatsuba(a, b);
}