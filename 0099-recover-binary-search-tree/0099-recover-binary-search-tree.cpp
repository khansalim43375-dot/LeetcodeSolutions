class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev1 = nullptr;
        TreeNode* prev2 = nullptr;
        bool isfound = false;
        while (curr != nullptr) {

            if(curr->left == nullptr){
                if(!prev1) prev1 = curr;
                else if(curr->val > prev1->val && !isfound)
                    prev1 = curr;
                else if(curr->val < prev1->val){
                    prev2 = curr;
                    isfound = true;
                }
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
                    if(curr->val > prev1->val && !isfound)
                        prev1 = curr;
                    else if(curr->val < prev1->val){
                    prev2 = curr;
                    isfound = true;
                    }
                    
                    curr = curr->right;
                }
            }
        }
    swap(prev1->val, prev2->val);  
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna