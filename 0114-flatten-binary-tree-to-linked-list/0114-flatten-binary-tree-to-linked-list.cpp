
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* pred = curr->left;

                while (pred->right != nullptr) {
                    pred = pred->right;
                }

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna