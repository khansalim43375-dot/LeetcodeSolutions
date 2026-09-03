class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int k = low + (high - low) / 2;

            long long hours = 0;

            for(int x : piles) {
                hours += (x + k - 1) / k;
            }

            if(hours <= h) {
                high = k - 1;
            }
            else {
                low = k + 1;
            }
        }

        return low;
    }
};