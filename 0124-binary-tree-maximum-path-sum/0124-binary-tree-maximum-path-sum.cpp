class Solution {
  public:
    int Sum(TreeNode* root, int &sum) {
        if (root == nullptr)
            return 0;

        int left = max(0, Sum(root->left, sum));
        int right = max(0, Sum(root->right, sum));

        sum = max(sum, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        Sum(root, sum);
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna