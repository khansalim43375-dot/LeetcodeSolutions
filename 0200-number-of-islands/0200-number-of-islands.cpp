class Solution {
public:
  bool isSafe(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1' && !visited[r][c]);
}

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int startR, int startC) {
    
    // Possible 4 directions (vertical, horizontal, and diagonal)
    vector<int> dRow = {-1, 0, 0, 1};
    vector<int> dCol = {0, -1, 1, 0};

    queue<pair<int, int>> q;
    q.push({startR, startC});
    visited[startR][startC] = true;

    // Explore all reachable land cells for this island
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        // Check all 4 neighbors of the current cell
        for (int k = 0; k < 4; k++) {
            int newR = r + dRow[k];
            int newC = c + dCol[k];
            if (isSafe(grid, newR, newC, visited)) {
                visited[newR][newC] = true;
                q.push({newR, newC});
            }
        }
    }
}

// Count the total number of islands in the grid
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int islandCount = 0;

    // Traverse every cell in the grid
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {

            // If an unvisited land cell is found, start BFS for that island
            if (grid[r][c] == '1' && !visited[r][c]) {
                bfs(grid, visited, r, c);
                islandCount++;
            }
        }
    }

    return islandCount;
}

};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna