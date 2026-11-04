/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int row, int col,
               map<int, map<int, multiset<int>>>& mp) {

        if(root == NULL) return;

        mp[col][row].insert(root->val);

        solve(root->left, row + 1, col - 1, mp);

        solve(root->right, row + 1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> mp;

        solve(root, 0, 0, mp);

        vector<vector<int>> ans;

        for(auto col : mp) {

            vector<int> temp;

            for(auto row : col.second) {

                for(auto val : row.second) {
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna