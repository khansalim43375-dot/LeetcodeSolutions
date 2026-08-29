class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1, mid;

        while(st <= end) {
            mid = st + (end - st) / 2;

            if(nums[mid] == target)
                return true;

            // Duplicates: can't determine which half is sorted,so st and end can't be answer becoz st,end are equal to mid and we already checked mid so shrink.
            if(nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
                continue;
            }

            // Left half is sorted
            if(nums[st] <= nums[mid]) {
                if(nums[st] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            // Right half is sorted
            else {
                if(nums[mid] < target && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};