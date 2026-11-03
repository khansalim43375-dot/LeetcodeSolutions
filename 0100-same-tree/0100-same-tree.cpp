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
    bool isSameTree(TreeNode* r1,TreeNode* r2) {
        // both empty -> identical
        if (r1 == NULL && r2 == NULL) return true;

        // only one empty -> not identical
        if (r1 == NULL || r2 == NULL) return false;

        // values differ -> not identical
        if (r1->val != r2->val) return false;

        // both subtrees must match
        return isSameTree(r1->left, r2->left) &&
               isSameTree(r1->right, r2->right);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna