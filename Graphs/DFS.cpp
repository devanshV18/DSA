#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//o based indexing code

void(int node, vector<int> adj[], int vis[], vector<int> &dfs){
    vis[node] = 1;
    dfs.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}


vector<int> dfs(int V, vector<vector<int>> adj){
    int vis[V] = {0};
    vis[0] = 1;
    int start = 0;

    vector<int> dfs;
    dfsRecursive(start, adj, vis, dfs);

    return dfs;
}