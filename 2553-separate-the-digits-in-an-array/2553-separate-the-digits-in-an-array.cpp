class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
       for(int i = 0; i < nums.size(); i++){
        string x = to_string(nums[i]);
        int j = 0;
        while(j < x.length()){
            
            int d = x[j++]-'0';
            ans.push_back(d);
        }

       } 
       return ans;
    }
};