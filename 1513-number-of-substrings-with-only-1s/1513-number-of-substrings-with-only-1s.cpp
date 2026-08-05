class Solution {
public:
    int numSub(string s) {
        long long mod = pow(10,9)+ 7;
        long long ans = 0;
        for(int i = 0; i < s.length(); i++){
            long long count = 0;
            while(i < s.length() && s[i] == '1'){
                count++;
                i++;
            }
            ans = (ans + count*(count + 1)/2)%mod;
        }
        return ans;
    }
};