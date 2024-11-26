#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void explore(int node, int vis[], vector<int> adj[], queue<int> &dfs) {
    vis[node] = 1;
    dfs.push(node);
    for(auto itr : adj[node]) {
        if(!vis[itr]) {
            explore(itr, vis, adj, dfs);
        }
    }
}

int main() {
    vector<int> adj[9] = {{},{2, 3},{1, 5, 6},{1, 4, 7},{3, 8},{2},{2},{3, 8},{4, 7}};
    int vis[9] = {0};
    queue<int> dfs;

    int start = 3;
    explore(start, vis, adj, dfs);
    
    while(!dfs.empty()) {
        cout<<dfs.front()<<" ";
        dfs.pop();
    }
}