class Solution {
public:
    void pushAll(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> ans;

        pushAll(root1, s1);
        pushAll(root2, s2);

        while (!s1.empty() && !s2.empty()) {
            TreeNode* node1 = s1.top();
            TreeNode* node2 = s2.top();

            if (node1->val <= node2->val) {
                ans.push_back(node1->val);
                s1.pop();
                pushAll(node1->right, s1);
            }
            else {
                ans.push_back(node2->val);
                s2.pop();
                pushAll(node2->right, s2);
            }
        }

        // Process remaining nodes of BST 1
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();

            ans.push_back(node->val);
            pushAll(node->right, s1);
        }

        // Process remaining nodes of BST 2
        while (!s2.empty()) {
            TreeNode* node = s2.top();
            s2.pop();

            ans.push_back(node->val);
            pushAll(node->right, s2);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna