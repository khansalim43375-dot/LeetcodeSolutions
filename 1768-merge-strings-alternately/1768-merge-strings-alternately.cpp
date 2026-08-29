class Solution {
public:
    string mergeAlternately(string s1, string s2) {
    int i = 0,j = 0;
    string s;
    while(i<s1.length() && j < s2.length()){
        s.push_back(s1[i]);
        s.push_back(s2[j]);
        i++;j++;
    }
    while( i < s1.length()){
        s.push_back(s1[i]);
        i++;
    } 
    while(j < s2.length()){
        s.push_back(s2[j]);
        j++;
    }
    return s;  
    }
};