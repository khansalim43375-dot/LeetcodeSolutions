class Solution {
public:
    void solve(TreeNode* root, int& sum) {
        if (!root) return;

        solve(root->right, sum);

        sum += root->val;
        root->val = sum;

        solve(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna