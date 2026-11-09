class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
      
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }               
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                     if(row[i] == 1 && col[j] == 1){
                        cnt++;
                     }
                }               
            }
        }

    return cnt;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna