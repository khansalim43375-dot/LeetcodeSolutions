class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
    int mx = INT_MIN,sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        mx = max(mx,sum);
        if(sum <= 0){
            sum = 0;
        }
    }
    return mx;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna