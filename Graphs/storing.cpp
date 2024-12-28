#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    //for 1 based indexing of graphs
    vector<vector<int>> adj(n+1, m+1);

    //note-> m represents edges, so we iterate from i = 0 till m (just before m) which is eaxctly equal to m
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}