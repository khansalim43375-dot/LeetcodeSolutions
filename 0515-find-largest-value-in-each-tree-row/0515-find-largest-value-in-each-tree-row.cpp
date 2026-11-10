/* Node class of the binary tree
class Node
{
    int data;
    Node* left, right;
    Node(int key)
    {
        data = key;
        left = right = nullptr;
    }
}
*/

class Solution {
  public:
    vector<int> largestValues(TreeNode* root) {
        // code here
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        
        while(!q.empty()){
            int sz = q.size();
            int mx = INT_MIN;
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                mx = max(mx, node->val);
                   
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            ans.push_back(mx);
        }
    return ans;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna