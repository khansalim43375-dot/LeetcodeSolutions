class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int prefix = 0;

        unordered_map<int, int> s;
        s[0] = 1;

        for(int x : nums) {
            prefix += x;

            if(s.find(prefix - goal) != s.end())
                count += s[prefix - goal];

            s[prefix]++;
        }

        return count;
    }
};