class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
       int freq[256] = {0};
       for(char ch : s)
          freq[(unsigned char)ch]++;
       for(char ch : t)
          freq[(unsigned char)ch]--;
       for(char ch : s){
           if(freq[ch] != 0)
                return false;
       } 
       return true;      
    }
};