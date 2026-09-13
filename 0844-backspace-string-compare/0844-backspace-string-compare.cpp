class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;

        for(int j = 0; j < s.length(); j++){
            if(s[j] != '#'){
                s[i++] = s[j];
            }
            else if(i > 0){
                i--;
            }
        }
        s.resize(i);

        i = 0;

        for(int j = 0; j < t.length(); j++){
            if(t[j] != '#'){
                t[i++] = t[j];
            }
            else if(i > 0){
                i--;
            }
        }
        t.resize(i);

        return s == t;
    }
};