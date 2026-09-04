class Solution {
public:
    string removeStars(string s) {
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '*') {
                i--;
            } else {
                s[i++] = s[j];
            }
        }

        s.resize(i);
        return s;
    }
};