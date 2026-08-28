class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = min(suffix[i + 1], nums[i]);

        int prefixMax = nums[0];

        for (int i = 1; i < n - 1; i++) {

            // Beauty = 2
            if (prefixMax < nums[i] && nums[i] < suffix[i + 1])
                sum += 2;

            // Beauty = 1
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                sum += 1;

            prefixMax = max(prefixMax, nums[i]);
        }

        return sum;
    }
};