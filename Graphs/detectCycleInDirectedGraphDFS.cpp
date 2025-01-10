#include<iostream>
using namespace std;


bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, pathVis)
        }
    }

    pathVis[node] = 0;
    return false;
}

bool isCycleDirectedDFS(int V, vector<int> adj[]){
    int vis[V] = {0};
    int pathVis[V] = {0};

    for(int i = 0; i<V; i++){
        if(!vis[i]){
            if(dfsCheck(i, adj, vis, pathVis) == true) return true;
        }
    }

    return false;
}
