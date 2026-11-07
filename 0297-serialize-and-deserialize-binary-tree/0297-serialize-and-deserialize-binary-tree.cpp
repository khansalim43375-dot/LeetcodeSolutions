class Codec {
public:

    // Serialize: Tree -> String
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                ans += "N,";
                continue;
            }

            ans += to_string(node->val) + ",";

            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    // Deserialize: String -> Tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string s;

        getline(ss, s, ',');

        TreeNode* root = new TreeNode(stoi(s));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(ss, s, ',')) {
                if (s != "N") {
                    node->left = new TreeNode(stoi(s));
                    q.push(node->left);
                }
            }

            // Right child
            if (getline(ss, s, ',')) {
                if (s != "N") {
                    node->right = new TreeNode(stoi(s));
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