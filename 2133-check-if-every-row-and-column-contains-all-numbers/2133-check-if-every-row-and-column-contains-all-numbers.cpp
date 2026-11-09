class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            vector<bool> rowSeen(n + 1, false), colSeen(n + 1, false);

            for (int j = 0; j < n; j++) {
                int r = mat[i][j];   // row i, going across
                int c = mat[j][i];   // column i, going down

                if (r < 1 || r > n || rowSeen[r]) return false;
                if (c < 1 || c > n || colSeen[c]) return false;

                rowSeen[r] = true;
                colSeen[c] = true;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna