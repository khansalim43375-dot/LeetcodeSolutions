class Solution {
  public:
    vector<int> majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int x : arr){
            m[x]++;
        }
        for(auto a : m){
            if(a.second > n/3){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};