//https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

class Solution {
  public:
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        

        vector<vector<int>> adj(V);
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        vector<vector<int>> result;
        

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);
                result.push_back(component);
            }
        }
        
        return result;
    }
};