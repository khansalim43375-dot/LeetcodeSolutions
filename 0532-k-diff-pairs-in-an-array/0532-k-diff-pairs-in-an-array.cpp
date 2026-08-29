class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

    unordered_map<int,int> freq;
    set<pair<int,int>> s2;

    for(int x : nums){
        if(!freq.count(x))
            freq[x] = 1;
        else    
            freq[x]++;
    }
    if(k == 0){
        int ans = 0;
        for(auto p : freq){
            if(p.second > 1)
               ans++;
        }
    return ans;    
    }        
    for(int x : nums){
        if(freq.count(x + k))
            s2.insert({x, x + k});
    }
    return s2.size();
    }
};