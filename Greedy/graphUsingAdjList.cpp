#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<int> adjList[n+1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cout<<"Edge from: ";
        cin>>u;
        cout<<" to ";
        cin>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return 0;
}