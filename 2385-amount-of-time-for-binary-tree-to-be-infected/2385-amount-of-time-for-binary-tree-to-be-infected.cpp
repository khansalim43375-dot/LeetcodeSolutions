class Solution {
  public:
    void mark(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& m) {
        if(node == nullptr)
            return;

        if(node->left) {
            m[node->left] = node;
            mark(node->left, m);
        }

        if(node->right) {
            m[node->right] = node;
            mark(node->right, m);
        }
    }

    TreeNode* find(TreeNode* node, int target) {
        if(node == nullptr)
            return nullptr;

        if(node->val == target)
            return node;

        TreeNode* left = find(node->left, target);
        if(left) return left;

        return find(node->right, target);
    }

    int amountOfTime(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> m;
        mark(root, m);

        TreeNode* tar = find(root, target);

        if(!tar) return 0;

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(tar);
        visited.insert(tar);

        int time = 0;

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(m.count(node) && !visited.count(m[node])) {
                    q.push(m[node]);
                    visited.insert(m[node]);
                }
            }

            time++;
        }

        return time - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna