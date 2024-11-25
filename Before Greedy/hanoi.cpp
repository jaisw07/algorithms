#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char via) {
    if(n==1) {
        cout<<"Move disk 1 from "<<from<<" to "<<to<<endl;
    }
    else{
        hanoi(n-1, from, via, to);
        cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
        hanoi(n-1, via, to, from);
    }
}

int main() {
    hanoi(5, 'a', 'b', 'c');
}