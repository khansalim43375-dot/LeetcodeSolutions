class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            ans.push_back(1);

            for(int j = i - 1; j >= 1; j--) {
                ans[j] = ans[j] + ans[j - 1];
            }

            result.push_back(ans);
        }

        return result;
    }
};