class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> ans(n,0);
        int window = 0;
        if(k > 0){
        for(int i = 0; i < k; i++){
            window += code[i];
        }
        for(int i = 0; i < n; i++){
            ans[i] = window-code[i]+code[(i+k)%n];
            window = window-code[i]+code[(i+k)%n];
        }
        }
        else if(k < 0){
            for(int i = n-1; i >= n+k; i--)
                window += code[i];
            for(int i = n-1; i >= 0; i--){
                ans[i] = window + code[(i+k+n)%n]-code[i];
                window = window + code[(i+k+n)%n]-code[i];
            }
        }
    return ans;    
    }
};