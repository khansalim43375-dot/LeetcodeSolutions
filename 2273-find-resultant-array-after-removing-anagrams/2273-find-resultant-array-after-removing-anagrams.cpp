class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int freq[256] = {0};

        for (char ch : s)
            freq[(unsigned char)ch]++;

        for (char ch : t)
            freq[(unsigned char)ch]--;

        for (char ch : s) {
            if (freq[(unsigned char)ch] != 0)
                return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (!isAnagram(ans.back(), words[i]))
                ans.push_back(words[i]);
        }

        return ans;
    }
};