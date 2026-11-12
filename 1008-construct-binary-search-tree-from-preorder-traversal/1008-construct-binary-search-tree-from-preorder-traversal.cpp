class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& idx, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left  = build(preorder, idx, root->val);  // left values must be < root
        root->right = build(preorder, idx, bound);      // right values must be < ancestor's bound
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder, idx, INT_MAX);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna