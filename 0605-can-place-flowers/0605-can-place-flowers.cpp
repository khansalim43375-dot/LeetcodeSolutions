class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                bool left = (i == 0) || (nums[i - 1] == 0);
                bool right = (i == nums.size() - 1) || (nums[i + 1] == 0);

                if (left && right) {
                    nums[i] = 1;
                    count++;
                }
            }
        }

        return count >= n;
    }
};