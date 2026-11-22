
class Solution {
public:
    void DFS(int start, vector<bool>& visited,
             const vector<vector<int>>& adj) {

        visited[start] = true;

        for(int it : adj[start]) {
            if(!visited[it]) {
                DFS(it, visited, adj);
            }
        }
    }

    int dfs(int V, const vector<vector<int>>& adj) {
        int count = 0;
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DFS(i, visited, adj);
                count++;
            }
        }

        return count;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        return dfs(n, adj);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna