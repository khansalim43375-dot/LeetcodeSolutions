class NodeDetails {
public:
    int mn, mx, maxDiff;

    NodeDetails(int mn, int mx, int maxDiff) {
        this->mn = mn;
        this->mx = mx;
        this->maxDiff = maxDiff;
    }
};

class Solution {
public:
    NodeDetails solve(TreeNode* root) {
        if (!root)
            return NodeDetails(INT_MAX, INT_MIN, 0);

        auto left = solve(root->left);
        auto right = solve(root->right);

        int mn = min(root->val, min(left.mn, right.mn));
        int mx = max(root->val, max(left.mx, right.mx));
        int diff = max(left.maxDiff, right.maxDiff);

        if (root->left) {
        diff = max(diff, abs(root->val - left.mn));
        diff = max(diff, abs(root->val - left.mx));
        }

        if (root->right) {
            diff = max(diff, abs(root->val - right.mn));
            diff = max(diff, abs(root->val - right.mx));
        }

        return NodeDetails(mn, mx, diff);
    }

    int maxAncestorDiff(TreeNode* root) {
        return solve(root).maxDiff;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna