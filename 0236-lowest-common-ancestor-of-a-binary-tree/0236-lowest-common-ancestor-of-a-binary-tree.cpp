class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        //  code here
        if(root == NULL || root == n1 || root == n2)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, n1, n2);
        TreeNode* right = lowestCommonAncestor(root->right, n1, n2);
        
        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna