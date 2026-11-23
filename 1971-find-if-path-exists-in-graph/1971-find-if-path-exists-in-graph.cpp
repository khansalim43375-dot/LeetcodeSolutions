class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            
        vector<vector<int>> adj(n);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination) return true;
            for(int x : adj[node]){
                
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    return false;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna