class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        unordered_set<int> bob;
        int sum1 = 0, sum2 = 0;

        for (int x : aliceSizes) {
            sum1 += x;
        }

        for (int x : bobSizes) {
            sum2 += x;
            bob.insert(x);
        }

        int diff = (sum2 - sum1) / 2;

        for (int x : aliceSizes) {
            if (bob.count(x + diff)) {
                return {x, x + diff};
            }
        }

        return {};
    }
};