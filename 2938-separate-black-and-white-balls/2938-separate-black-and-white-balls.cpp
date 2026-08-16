class Solution {
public:
    long long minimumSteps(string s) {
        int count = 0;
        long long ans = 0;
      for(int i = s.length()-1; i >= 0; i--){
         if(s[i] == '1'){
            count++;
            ans += (s.length()-i) - count;//add dist of 1's from right most zero.
                                        //ex:1001 dist of first 1 is s.length()-0-1.
         }
      }
return ans;
    }
};