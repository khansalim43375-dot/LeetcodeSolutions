class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for(char ch : s)
            freq[ch - 'a']++;

        string half = "";
        char mid = '\0';

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 != 0)
                mid = char(i + 'a');

            for(int j = 0; j < freq[i] / 2; j++)
                half += char(i + 'a');
        }

        string ans = half;

        if(mid != '\0')
            ans += mid;

        reverse(half.begin(), half.end());
        ans += half;

        return ans;
    }
};