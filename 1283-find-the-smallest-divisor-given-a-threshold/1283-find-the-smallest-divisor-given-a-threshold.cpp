class Solution {
public:
    int ceil(int a, int b) {
        if(a % b == 0)
            return a / b;
        return a / b + 1;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1;
        int end = *max_element(nums.begin(), nums.end());

        while(st < end) {
            int mid = st + (end - st) / 2;

            int sum = 0;

            for(int x : nums) {
                sum += ceil(x, mid);
            }

            if(sum <= threshold)
                end = mid;
            else
                st = mid + 1;
        }

        return st;
    }
};