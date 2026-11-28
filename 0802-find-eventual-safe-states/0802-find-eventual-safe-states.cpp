
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1; // Currently visiting

        for (int neigh : adj[node]) {

            if (vis[neigh] == 1) {
                return false; // Cycle detected
            }

            if (vis[neigh] == 0) {
                if (!dfs(neigh, adj, vis)) {
                    return false;
                }
            }
        }

        vis[node] = 2; // Mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (vis[i] == 0) {
                dfs(i, graph, vis);
            }

            if (vis[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna