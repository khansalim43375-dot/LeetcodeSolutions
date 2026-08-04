class Solution {
public:
    int findLucky(vector<int>& arr) {
      int freq[501] = {0};
      for(int x : arr){
        freq[x]++;
      } 
      int lar = 0;
      for(int x : arr){
        if(x == freq[x])
          lar = max(lar,x);
      }
    if(lar == 0)
       return -1;
    return lar;    
    }
};