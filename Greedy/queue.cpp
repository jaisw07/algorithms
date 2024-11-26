#include <iostream>
#include <queue>
using namespace std;

void showQueue(queue<int> q) {
    queue<int> temp = q;
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(11);
    q.push(12);
    showQueue(q);
    
}