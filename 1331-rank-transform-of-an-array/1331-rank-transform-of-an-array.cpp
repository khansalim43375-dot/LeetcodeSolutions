class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        unordered_map<int,int> m;
        int n = 1;
   
    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size(); i++){
        if(!m.count(arr[i])){
           m[arr[i]] = n;n++;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        ans[i] = m[ans[i]];
    }  
    return ans;
    }
};