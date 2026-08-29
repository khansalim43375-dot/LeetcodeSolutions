class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(int x : nums)
            freq[x]++;

        int ans = 0;

        for(auto p : freq) {
            int x = p.first;

            if(k == 0) {
                if(p.second > 1)
                    ans++;
            }
            else {
                if(freq.count(x + k))
                    ans++;
            }
        }

        return ans;
    }
};