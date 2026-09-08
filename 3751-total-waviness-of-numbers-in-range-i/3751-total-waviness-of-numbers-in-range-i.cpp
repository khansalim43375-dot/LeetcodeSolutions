class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wave = 0;
      for(int i = num1; i <= num2; i++){
        string s = to_string(i);
        int j = 1;
        while(j  < s.length()-1){
            if(s[j]> s[j-1] && s[j] > s[j+1])
                wave++;
            else if(s[j] < s[j-1] && s[j] < s[j+1])  
                wave++;
            j++;      
        }

      }
      return wave;  
    }
};