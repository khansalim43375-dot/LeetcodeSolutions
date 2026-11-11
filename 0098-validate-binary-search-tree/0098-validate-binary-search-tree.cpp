class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        TreeNode* curr = root;
        bool valid = true;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                if (curr->val <= prev)
                    valid = false;

                prev = curr->val;
                curr = curr->right;
            }
            else {
                TreeNode* IP = curr->left;

                while (IP->right && IP->right != curr)
                    IP = IP->right;

                if (IP->right == nullptr) {
                    IP->right = curr;
                    curr = curr->left;
                }
                else {
                    IP->right = nullptr;

                    if (curr->val <= prev)
                        valid = false;

                    prev = curr->val;
                    curr = curr->right;
                }
            }
        }

        return valid;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna