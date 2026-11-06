class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int& preIndex, int start, int end,
                    unordered_map<int, int>& mp) {

        if (start > end)
            return nullptr;

        // First element of preorder is the root
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int pos = mp[rootVal];

        // Construct left and right subtrees
        root->left = solve(preorder, inorder, preIndex,
                           start, pos - 1, mp);

        root->right = solve(preorder, inorder, preIndex,
                            pos + 1, end, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int preIndex = 0;

        return solve(preorder, inorder, preIndex,
                     0, inorder.size() - 1, mp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna