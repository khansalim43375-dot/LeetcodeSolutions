
class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& board,
             vector<vector<bool>>& vis) {

        int n = board.size();
        int m = board[0].size();

        vis[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               board[nr][nc] == 1 && !vis[nr][nc]) {

                dfs(nr, nc, board, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        if(n == 0 || m == 0) return 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // First column
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 1 && !vis[i][0])
                dfs(i, 0, board, vis);
        }

        // Last column
        for(int i = 0; i < n; i++) {
            if(board[i][m-1] == 1 && !vis[i][m-1])
                dfs(i, m-1, board, vis);
        }

        // First row
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 1 && !vis[0][j])
                dfs(0, j, board, vis);
        }

        // Last row
        for(int j = 0; j < m; j++) {
            if(board[n-1][j] == 1 && !vis[n-1][j])
                dfs(n-1, j, board, vis);
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }
    return count;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna