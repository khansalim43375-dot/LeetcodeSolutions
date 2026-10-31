class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> res;
        n++;
        long long ans = 1;
        res.push_back(ans);
        for(int i = 1; i < n; i++){
            ans = (ans*(n-i))/i;
            res.push_back(ans);
        }
        

        return res;
    }
};