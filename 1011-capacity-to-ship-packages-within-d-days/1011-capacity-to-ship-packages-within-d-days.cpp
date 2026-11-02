class Solution {
  public:
    int shipWithinDays(vector<int>& arr, int d) {
        long long st = *max_element(arr.begin(), arr.end());
        long long end = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = end;

        while (st <= end) {
            long long mid = st + (end - st) / 2;

            int days = 1;
            long long load = 0;
            for (int x : arr) {
                if (load + x > mid) {   // current day is full
                    days++;
                    load = 0;
                }
                load += x;
            }

            if (days <= d) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return (int)ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna