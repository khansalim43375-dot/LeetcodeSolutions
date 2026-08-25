class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }

        vector<long long> ans(nums.size(), 0);

        for(auto &p : m) {
            vector<int>& v = p.second;
            int n = v.size();

            vector<long long> prefix(n + 1, 0);

            for(int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }

            for(int i = 0; i < n; i++) {
                long long left = 1LL * v[i] * i - prefix[i];

                long long right = (prefix[n] - prefix[i + 1])
                                - 1LL * v[i] * (n - i - 1);

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};