class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n);
        nums[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for(int i = 1; i < n; i++) {
            int next = min(nums[i2] * 2,
                       min(nums[i3] * 3, nums[i5] * 5));

            nums[i] = next;

            if(next == nums[i2] * 2)
                i2++;

            if(next == nums[i3] * 3)
                i3++;

            if(next == nums[i5] * 5)
                i5++;
        }

        return nums[n - 1];
    }
};