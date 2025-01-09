#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Helper function for topological sort
void topologicalSortHelper(int node, stack<int> &s, int vis[], vector<int> adj[]) {
    vis[node] = 1; // Mark the current node as visited

    for (auto neighbor : adj[node]) {
        if (!vis[neighbor]) {
            topologicalSortHelper(neighbor, s, vis, adj);
        }
    }

    // Push the current node to the stack after processing its neighbors
    s.push(node);
}

// Function to perform topological sort
vector<int> topologicalSort(int V, vector<int> adj[]) {
    stack<int> s;          // Stack to store the order
    vector<int> topsort;   // Result vector
    int vis[V] = {0};      // Visited array initialized to 0

    // Call the helper function for all unvisited nodes
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            topologicalSortHelper(i, s, vis, adj);
        }
    }

    // Extract elements from the stack to get the topological order
    while (!s.empty()) {
        topsort.push_back(s.top());
        s.pop();
    }

    return topsort;
}

// Example usage
int main() {
    int V = 6;
    vector<int> adj[V];
    
    // Example graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSort(V, adj);

    // Print the topological order
    cout << "Topological Sort: ";
    for (auto node : result) {
        cout << node << " ";
    }

    return 0;
}
