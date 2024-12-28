#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//the code is for 0 based indexing graph
vector<int> bfs(int V, vector<vector<int>> adj){
    int vis[V] = {0};
    vis[0] = 1;
    q.push(0);

    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}