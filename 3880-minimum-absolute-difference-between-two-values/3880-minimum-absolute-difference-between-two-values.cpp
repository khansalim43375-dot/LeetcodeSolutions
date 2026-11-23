
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int lastOne = -1;
        int lastTwo = -1;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1) {
                lastOne = i;

                if(lastTwo != -1) {
                    ans = min(ans, i - lastTwo);
                }
            }

            else if(nums[i] == 2) {
                lastTwo = i;

                if(lastOne != -1) {
                    ans = min(ans, i - lastOne);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna