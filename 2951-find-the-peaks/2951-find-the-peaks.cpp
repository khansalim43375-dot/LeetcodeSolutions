class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 1; i < n-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                 ans.push_back(i);
        }
        return ans;
    }
};