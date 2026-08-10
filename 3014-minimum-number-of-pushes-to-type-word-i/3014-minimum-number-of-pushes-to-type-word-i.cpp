class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n <= 8)
          return n;
        else if(n > 8 && n < 16)
          return (n%8)*3 + (8-n%8);
        else if(n >= 16 && n < 24)
          return (n%8)*6 + (8-n%8)*3;
        else
          return (n%8)*10 + (8-n%8)*6;
    return -1;            
    }
    
};