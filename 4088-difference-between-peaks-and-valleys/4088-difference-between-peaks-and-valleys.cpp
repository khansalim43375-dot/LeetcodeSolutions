class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peak = 0, valley = 0;
        int n = nums.size();
       for(int i = 1; i < n-1; i++){
          if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                peak += nums[i];
          if(nums[i] < nums[i-1] && nums[i] < nums[i+1])
                valley += nums[i];      
       }
    return peak-valley;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna