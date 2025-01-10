#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSortBFS(int V, vector<int> adj[]){
    int indegree[V] = {0};

    //constructing the indegree array
    for(int i = 0; i<V; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    //pushing all nodes with indegree zero to the queue
    for(int i = 0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //iterating the queue
    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    return topo;

}