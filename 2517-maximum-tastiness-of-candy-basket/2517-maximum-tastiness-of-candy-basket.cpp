class Solution {
public:
    bool possible(vector<int>& price, int k, int d) {
        int count = 1;
        int last = price[0];

        for (int i = 1; i < price.size(); i++) {
            if (price[i] - last >= d) {
                count++;
                last = price[i];
            }

            if (count >= k)
                return true;
        }

        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int low = 0;
        int high = price.back() - price.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(price, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};