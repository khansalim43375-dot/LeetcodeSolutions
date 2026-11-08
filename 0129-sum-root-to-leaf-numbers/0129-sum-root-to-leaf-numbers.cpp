class Solution {
public:
    void solve(TreeNode* root, int sum, int& ans) {

        if (root == nullptr)
            return;

        sum = sum * 10 + root->val;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            ans += sum;
            return;
        }

        solve(root->left, sum, ans);
        solve(root->right, sum, ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna