/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

    return 1 + max(left, right);    
    }
    bool isleaf(TreeNode* node){
      return node->left == nullptr && node->right == nullptr;}

    TreeNode* solve(TreeNode* root, int d, int md){

        if(!root) return nullptr;
        if(isleaf(root) && d < md) return nullptr;
        if(isleaf(root) && d == md) return root;

        d++;
        TreeNode* left = solve(root->left,d, md);
        TreeNode* right = solve(root->right, d, md);

        if(right == nullptr) return left;
        else if(left == nullptr) return right;
        else return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int md = height(root);
        
       return solve(root, 1, md);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna