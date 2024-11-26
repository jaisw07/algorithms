#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n+1; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        // path compression by storing ultimate parent at each step
        else return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int uPar_u = findUPar(u), uPar_v = findUPar(v);
        if(uPar_u == uPar_v) return;
        if(rank[uPar_u] < rank[uPar_v]) {
            parent[uPar_u] = uPar_v;
        }
        else if(rank[uPar_u] > rank[uPar_v]) {
            parent[uPar_v] = uPar_u;
        }
        else{
            parent[uPar_v] = uPar_u;
            rank[uPar_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int uPar_u = findUPar(u), uPar_v = findUPar(v);
        if(uPar_u == uPar_v) return; 
        if(size[uPar_u] > size[uPar_v]) {
            size[uPar_u] += size[uPar_v];
            parent[uPar_v] = uPar_u;

        }
        else {
            size[uPar_v] += size[uPar_u];
            parent[uPar_u] = uPar_v;
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    //if 3 and 7 belong to same comp
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout<<"Same comp\n";
    }
    else{
        cout<<"Diff comp\n";
    }

    ds.unionByRank(3, 7);

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout<<"Same comp\n";
    }
    else{
        cout<<"Diff comp\n";
    }
    
    return 0;
}