
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;

        while (curr != nullptr) {

            if (curr->right == nullptr) {
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
            }
            else {
                TreeNode* pred = curr->right;

                while (pred->left != nullptr && pred->left != curr) {
                    pred = pred->left;
                }

                if (pred->left == nullptr) {
                    pred->left = curr;
                    curr = curr->right;
                }
                else {
                    pred->left = nullptr;
                    sum += curr->val;
                    curr->val = sum;
                    curr = curr->left;
                }
            }
        }

        return root;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna