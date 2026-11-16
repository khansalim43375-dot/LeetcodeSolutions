
class Solution {
  public:
    int maxLevelSum(TreeNode* root) {
    
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        int i = 0, level,mx = INT_MIN;
        
        while(!q.empty()){
            int sz = q.size();
            i++;
            int sum = 0;
            for(int j = 0; j < sz; j++){
                TreeNode* node = q.front();
                sum += node->val;
                   
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
           if(sum > mx){
            mx = sum;
            level = i;
           }
        
        }
    return level;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna