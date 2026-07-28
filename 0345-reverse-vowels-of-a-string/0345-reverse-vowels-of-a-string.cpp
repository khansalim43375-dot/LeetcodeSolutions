class Solution {
public:
    bool isVowel(char ch){
        char ch1 = tolower(ch);
        if(ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 =='u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int st = 0, end = s.length()-1;

        while( st <= end){

            if(isVowel(s[st]) && isVowel(s[end])){
                swap(s[st],s[end]);
                st++;end--;
            }    
            else if(isVowel(s[st]) && !isVowel(s[end]))
                end--;
            else if(!isVowel(s[st]) && isVowel(s[end]))
                st++;
            else{
                st++;end--; 
            }           
        }
        return s;
    }
};