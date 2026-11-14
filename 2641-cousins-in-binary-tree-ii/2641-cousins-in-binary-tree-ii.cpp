
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;

        while (!q.empty()) {
            int sz = q.size();
            int levelSum = 0;

            // Calculate sum of next level
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    levelSum += node->left->val;

                if (node->right)
                    levelSum += node->right->val;

                q.push(node); // Store current-level node
            }

            // Update children using original values
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                int siblingSum = 0;

                if (node->left)
                    siblingSum += node->left->val;

                if (node->right)
                    siblingSum += node->right->val;

                if (node->left) {
                    node->left->val = levelSum - siblingSum;
                    q.push(node->left);
                }

                if (node->right) {
                    node->right->val = levelSum - siblingSum;
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna