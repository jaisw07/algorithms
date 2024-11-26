#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void exploreBFS(int node, vector<int> adj[], int vis[], 
queue<int> &bfs) {
    //pushes neighbours into bfs queue
    for(auto iter : adj[node]) {
        if(vis[iter] == 0) {
            bfs.push(iter);
            //mark as visited
            vis[iter] = 1;
        }
    }
    //prints front of bfs queue and recursively calls explore
    while(!bfs.empty()) {
        cout<<bfs.front()<<" ";
        int current = bfs.front();
        bfs.pop();
        exploreBFS(current, adj, vis, bfs);
    }
}

int main() {
    //adjacency list representing graph
    vector<int> adj[10] = {{}, {2, 6}, {1, 3, 4}, {2}, 
    {2, 5}, {4, 8}, {1, 7, 9}, {6, 8}, {5, 7}, {6}};

    //initialize visited arr with 0
    int vis[10] = {0};

    //queue which will store elements in bfs order
    queue<int> bfs;

    //visit starting node, push into bfs and vis[node] = 1
    //then explore adj[node]
    //if not visited, push into bfs and vis[node] = 1
    //recursively call with input node

    int start_node = 6;
    vis[start_node] = 1;
    bfs.push(start_node);
    exploreBFS(start_node, adj, vis, bfs);

    return 0;
}