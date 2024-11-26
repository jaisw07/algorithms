#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    int adj[n+1][n+1];

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < n+1; j++) {
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cout<<"Enter edge vertices(space separated): ";
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(adj[i][j] != 0) {
                cout<<"Edge: "<<i<<" --> "<<j<<endl;
            }
        }
    }
    return 0;
}