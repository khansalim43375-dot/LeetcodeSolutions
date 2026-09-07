class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int,int> m;
    vector<int> ans;
    for(int x : nums1){
        if(m.count(x))
            m[x]++;
        else
            m[x] = 1;    
    }
    for(int x : nums2){
        if(m.count(x) && m[x] > 0){
            ans.push_back(x);
            m[x]--;
        }    
    }
    return ans;

    }
};