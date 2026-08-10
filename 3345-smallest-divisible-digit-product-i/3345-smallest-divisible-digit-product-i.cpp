class Solution {
public:
    int smallestNumber(int n, int t) {
      int dig,orig = n;
      while(1){
      n = orig;
      int prod = 1;  
      while( n!= 0){
        dig = n % 10;
        prod = prod*dig;
        n /= 10;
      }
      if( prod % t == 0)
        return orig;
      orig++; 
      }   
    return -1;     
    }
};