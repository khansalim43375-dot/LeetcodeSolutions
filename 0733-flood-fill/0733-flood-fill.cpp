class Solution {
public:
    bool isSafe(vector<vector<int>>& image, int r, int c, int incolor){
        int n = image.size();
        int m = image[0].size();
        return (r >= 0 && r < n && c >= 0 && c < m && image[r][c] == incolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image; 
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int incolor = image[sr][sc];
        image[sr][sc] = color;
        vector<int> dRow = {-1, 0, 0, 1};
        vector<int> dCol = {0, -1, 1, 0};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int newRow = r + dRow[k];
                int newCol = c + dCol[k];
                if(isSafe(image, newRow, newCol, incolor)){
                    q.push({newRow, newCol});
                    image[newRow][newCol] = color;
                }
            }
        } 
    return image;          
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna