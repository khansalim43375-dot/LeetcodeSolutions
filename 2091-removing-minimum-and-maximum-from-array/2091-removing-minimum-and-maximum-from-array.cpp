class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        int idx1, idx2;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] < mn) {
                mn = nums[i];
                idx1 = i;
            }

            if(nums[i] > mx) {
                mx = nums[i];
                idx2 = i;
            }
        }

        int l = min(idx1, idx2);
        int r = max(idx1, idx2);

        int ans1 = r + 1;          // both from left
        int ans2 = n - l;          // both from right
        int ans3 = l + 1 + n - r;  // left + right

        return min(ans1, min(ans2, ans3));
    }
};