class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,
                    int& preIndex, int start, int end,
                    unordered_map<int, int>& mp) {

        if (start > end)
            return nullptr;

        // Create root
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // If only one node is left
        if (start == end)
            return root;

        // Find left subtree root in postorder
        int leftRoot = preorder[preIndex];

        int idx = mp[leftRoot];

        // Number of nodes in left subtree
        int leftSize = idx - start + 1;

        // Build left subtree
        root->left = solve(preorder, postorder, preIndex,
                           start, idx, mp);

        // Build right subtree
        root->right = solve(preorder, postorder, preIndex,
                            idx + 1, end - 1, mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        unordered_map<int, int> mp;

        for (int i = 0; i < postorder.size(); i++)
            mp[postorder[i]] = i;

        int preIndex = 0;

        return solve(preorder, postorder, preIndex,
                     0, postorder.size() - 1, mp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna