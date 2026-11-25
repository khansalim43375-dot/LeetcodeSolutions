
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        if(root->left == NULL)
            return 1 + minDepth(root->right);

        if(root->right == NULL)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna