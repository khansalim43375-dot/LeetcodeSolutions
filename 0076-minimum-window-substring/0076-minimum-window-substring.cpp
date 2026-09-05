class Solution {
public:
    string minWindow(string s, string t) {
        int freq1[256] = {0};
        int freq2[256] = {0};

        for(char ch : t)
            freq1[ch]++;

        int left = 0;
        int count = 0;
        int start = 0;
        int ans = INT_MAX;

        for(int right = 0; right < s.length(); right++) {

            freq2[s[right]]++;

            if(freq2[s[right]] <= freq1[s[right]])
                count++;

            while(count == t.length()) {

                if(right - left + 1 < ans) {
                    ans = right - left + 1;
                    start = left;
                }

                freq2[s[left]]--;

                if(freq2[s[left]] < freq1[s[left]])
                    count--;

                left++;
            }
        }

        if(ans == INT_MAX)
            return "";

        return s.substr(start, ans);
    }
};