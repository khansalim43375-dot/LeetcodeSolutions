class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ans;
        int mx = 0;
        for(int x : nums){
            freq[x]++;
            mx = max(mx,freq[x]);
        }
        vector<vector<int>> bucket(mx+1);
            for(auto p : freq){
                bucket[p.second].push_back(p.first);
            }
        
        for(int i = mx; ans.size() != k; i--){
            for(int x : bucket[i])
               ans.push_back(x);
        }
        
    return ans;    
    }
};