class Solution {
public:
    bool isSafe(int r, int c, int n, int m,
                vector<vector<bool>>& visited) {
        return (r >= 0 && r < n && c >= 0 && c < m &&
                !visited[r][c]);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> mat(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        // Push all cells containing 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];

                if (isSafe(newR, newC, n, m, visited)) {
                    mat[newR][newC] = mat[r][c] + 1;

                    visited[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }

        return mat;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna