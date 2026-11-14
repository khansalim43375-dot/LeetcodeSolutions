class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mnSum = INT_MAX;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int sum = 0,len = 0;
            for(int j = i; j < n; j++){
                len++;
                sum += nums[j];
                if(sum > 0 && len >= l && len <= r)
                    mnSum = min(mnSum, sum);
            }
        }
    return (mnSum == INT_MAX) ? -1 : mnSum;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna