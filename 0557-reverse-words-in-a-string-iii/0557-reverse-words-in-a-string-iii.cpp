class Solution {
public:
    string reverseWords(string s) {
        int i = 0,j = 0;
        string S;
        while(j <= s.length()){
            if( j < s.length() && s[j] != ' ')
              j++;
            else{
               string current = s.substr(i,j-i);
                reverse(current.begin(),current.end());
                S = S+" "+current;
                i = j + 1;
                j++;
            }  
        }
        return S.substr(1);
    }
};