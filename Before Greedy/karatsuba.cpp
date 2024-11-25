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
    if(x < 10 || y < 10) return x*y;
    //get size
    int length = maxi(get_size(x), get_size(y));
    int hlen = length/2;
    int p10 = 1;
    for(int i = 0; i < hlen;i++) {p10*=10;}
    //set vars
    long a = x/p10;
    long b = x%p10;
    long c = y/p10;
    long d = y%p10;
    //
    long p = karatsuba(a, c);
    long q = karatsuba(b, d);
    long s = karatsuba(a+b, c+d);
    long r = s - p - q;
    //
    return p*p10*p10 + p10*r + q;
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
    // cout<<a*b;
}