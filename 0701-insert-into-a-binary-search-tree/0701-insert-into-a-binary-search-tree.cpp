class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int key) {
        TreeNode* newNode = new TreeNode(key);

        if(root == nullptr)
            return newNode;

        TreeNode* node = root;

        while(true) {
          
            if(key < node->val) {
                if(node->left == nullptr) {
                    node->left = newNode;
                    break;
                }
                node = node->left;
            }
            else {
                if(node->right == nullptr) {
                    node->right = newNode;
                    break;
                }
                node = node->right;
            }
        }

        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna