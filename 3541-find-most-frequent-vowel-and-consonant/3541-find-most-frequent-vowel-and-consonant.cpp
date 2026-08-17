class Solution {
    public: 
    int maxFreqSum(string s) {
        int freq[26] = {0};
        int vowel = 0, consonant = 0;

        for(char ch : s)
            freq[ch - 'a']++;

        for(char ch : string("aeiou"))
            vowel = max(vowel, freq[ch -'a']);

        for(char ch : s){
            if(ch != 'a' && ch != 'e' && ch != 'i' && ch!= 'o' && ch !='u'){
                consonant = max(consonant,freq[ch-'a']);
            }
        }

    return vowel + consonant;
    }
};   
