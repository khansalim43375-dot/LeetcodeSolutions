class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> m;vector<int> ans;
        for(int x : nums){
            m[x]++;
        }
        for(int x : nums){
            if(m[x] == 1){
                if(m.count(x-1) || m.count(x+1))
                   continue;
                else
                   ans.push_back(x);   
            }
        }
        return ans;
    }
};