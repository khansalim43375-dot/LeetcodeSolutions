class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxCount = 0;
       for(string s : sentences){
        int count  = 1;
        int i = 0;
        while(i < s.length()){
            if(s[i] == ' ')
              count++;
              i++;
        }
        maxCount = max(maxCount,count);
       } 
       return maxCount;
    }
};