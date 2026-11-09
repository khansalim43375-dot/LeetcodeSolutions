
class Solution {
  public:
    TreeNode* searchBST(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
      
        if(root->val == key)
           return root;
        if(key < root->val)
            return searchBST(root->left, key);
        else
            return searchBST(root->right, key);
             
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna