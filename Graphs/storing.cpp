#include<iostream>
#include<vector>
using namespace std;

int main(){

   
    //1. adjacency matrix method -> Undirected graph

    int n, m;
    cin >> n >> m;

    //for 1 based indexing of graphs
   int adj[n+1][m+1];

    //note-> m represents edges, so we iterate from i = 0 till m (just before m) which is eaxctly equal to m
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //2. adjacency matrix method -> Directed graph

    int n, m;
    cin >> n >> m;

    //for 1 based indexing of graphs
   int adj[n+1][m+1];

    //note-> m represents edges, so we iterate from i = 0 till m (just before m) which is eaxctly equal to m
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }


    //3. adjacency list method -  Undirected graph

    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //4. adjacency list method -  Directed graph

    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    //5. adjacency matrix method -> weighted undirected graph

    int n, m;
    cin >> n >> m;

    //for 1 based indexing of graphs
   int adj[n+1][m+1];

    //note-> m represents edges, so we iterate from i = 0 till m (just before m) which is eaxctly equal to m
    for(int i = 0; i<m; i++){
        int u, v, wt
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }


    //6. adjacncy list method -> weighted undirected graph

    int n,m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i<m; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    //7. adajcency matrix method -> weighted directed

    int n, m;
    cin >> n >> m;

    // Adjacency matrix for a 1-based indexing graph
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0)); // Initialize with 0 (no edge)

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt; // Add edge u -> v with weight wt
    }

    //8. adjacncy list method -> weighted directed graph

    int n,m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i<m; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }




}