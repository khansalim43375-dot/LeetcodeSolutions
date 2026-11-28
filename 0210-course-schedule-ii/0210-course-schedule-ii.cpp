class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;

        // Push all zero indegree nodes
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neigh : adj[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

     if(ans.size() != V) return {};
     return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna