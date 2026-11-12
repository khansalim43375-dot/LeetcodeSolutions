
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* curr = root;
        int prev = -1, dif = INT_MAX;
        while (curr != nullptr) {

            if (curr->left == nullptr) {
                 if(prev != -1)
                    dif = min(dif, abs(curr->val-prev));
        
                prev = curr->val;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;

                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    pred->right = nullptr;
                    if(prev != -1)
                        dif = min(dif, abs(curr->val-prev));
                    prev = curr->val;
                    
                    curr = curr->right;
                }
            }
        }
    return dif;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna