class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0};
        int st = 0;
        int ans = 0;

        for(int end = 0; end < s.length(); end++) {
            freq[s[end] - 'a']++;

            while(freq[s[end] - 'a'] > 2) {
                freq[s[st] - 'a']--;
                st++;
            }

            ans = max(ans, end - st + 1);
        }

        return ans;
    }
};