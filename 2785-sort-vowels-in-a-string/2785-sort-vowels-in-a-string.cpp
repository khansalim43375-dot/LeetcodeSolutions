class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        if( ch =='a' || ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u'){
            return true;
        }
        return false;
    }
    
    string sortVowels(string s) {
    int freq[256] = {0};
    
    for(char ch : s){
        if(isVowel(ch)){
            freq[ch]++;
        }
    }
    for(int i = 0; i < s.length(); i++){
      if(isVowel(s[i])){
          for(int j = 65; j < 120; j++){
             if(freq[j] > 0){
                   s[i] = (char)j;
                   freq[j]--;
                   break;
             }    
          }
      }
           
    } 
    return s;
    }
};