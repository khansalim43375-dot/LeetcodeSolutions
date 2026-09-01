class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;

        int r = rStart;
        int c = cStart;
        int step = 1;

        result.push_back({r, c});

        while (result.size() < rows * cols) {

            // Move right
            for (int i = 0; i < step; i++) {
                c++;
                if (r >= 0 && r < rows && c >= 0 && c < cols)
                    result.push_back({r, c});
            }

            // Move down
            for (int i = 0; i < step; i++) {
                r++;
                if (r >= 0 && r < rows && c >= 0 && c < cols)
                    result.push_back({r, c});
            }

            step++;

            // Move left
            for (int i = 0; i < step; i++) {
                c--;
                if (r >= 0 && r < rows && c >= 0 && c < cols)
                    result.push_back({r, c});
            }

            // Move up
            for (int i = 0; i < step; i++) {
                r--;
                if (r >= 0 && r < rows && c >= 0 && c < cols)
                    result.push_back({r, c});
            }

            step++;
        }

        return result;
    }
};