class Solution {
  public:  
    int findBottomLeftValue(TreeNode *root) {

       queue<TreeNode*> q;
       q.push(root);
       TreeNode* ans = nullptr;
       while(!q.empty()){
             int sz = q.size();

             for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                if(i == 0) ans = node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
             }
       }
    return ans->val; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna