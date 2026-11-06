class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(root == NULL) return;

        if(root->left) {
            parent[root->left] = root;
            markParent(root->left, parent);
        }

        if(root->right) {
            parent[root->right] = root;
            markParent(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int level = 0;
        vector<int> ans;

        while(!q.empty() && level <= k) {

            int sz = q.size();

            for(int i = 0; i < sz; i++) {

                TreeNode* node = q.front();
                q.pop();

                if(level == k) {
                    ans.push_back(node->val);
                    continue;
                }

                if(node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parent[node] && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }

            level++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna