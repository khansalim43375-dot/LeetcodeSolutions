class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int bestRow = 0, bestCount = 0;
        for (int i = 0; i < (int)mat.size(); i++) {
            int count = 0;
            for (int x : mat[i]) count += x;
            if (count > bestCount) {   // strict >, so ties keep the smaller index
                bestCount = count;
                bestRow = i;
            }
        }
        return {bestRow, bestCount};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna