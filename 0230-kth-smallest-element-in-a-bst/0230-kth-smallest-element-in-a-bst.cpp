class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                k--;
                if (k == 0) ans = curr->val;
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
                    k--;
                    if (k == 0) ans = curr->val;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna