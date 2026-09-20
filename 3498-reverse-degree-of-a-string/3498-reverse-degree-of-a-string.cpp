class Solution {
public:
    int reverseDegree(string s) {
        int value[26] = {0};
        
        for(char ch : s){
            value[ch-'a'] = 26 - (ch-'a');
        }
        int sum = 0;

        for(int i = 0; i < s.length(); i++){
            sum += (i+1)*value[s[i]-'a'];
        }
    return sum;
    }
};