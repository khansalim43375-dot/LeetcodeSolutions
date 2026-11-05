class Solution {
public:
    void solve(TreeNode* root, string path, vector<string>& result) {
        if(root == nullptr)
            return;

        if(!path.empty())
            path += "->";

        path += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
            return;
        }

        solve(root->left, path, result);
        solve(root->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        solve(root, "", result);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna