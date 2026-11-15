
class Solution {
public:
    bool findPath(TreeNode* root, int target, string& path) {
        if (!root) return false;

        if (root->val == target)
            return true;

        // Try left subtree
        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;

        path.pop_back();

        // Try right subtree
        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string destPath = "";

        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        int i = 0;

        // Find common prefix
        while (i < startPath.size() &&
               i < destPath.size() &&
               startPath[i] == destPath[i]) {
            i++;
        }

        // Move upward from start node to LCA
        string ans(startPath.size() - i, 'U');

        // Move downward from LCA to destination
        ans += destPath.substr(i);

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna