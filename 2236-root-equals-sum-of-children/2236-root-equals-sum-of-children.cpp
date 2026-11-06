class Solution {
public:
    bool leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    bool checkTree(TreeNode* root) {
        if (root == nullptr || leaf(root))
            return true;

        if (root->left == nullptr) {
            if (root->right->val != root->val)
                return false;
        }
        else if (root->right == nullptr) {
            if (root->left->val != root->val)
                return false;
        }
        else {
            if (root->left->val + root->right->val != root->val)
                return false;
        }

        return checkTree(root->left) && checkTree(root->right);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna