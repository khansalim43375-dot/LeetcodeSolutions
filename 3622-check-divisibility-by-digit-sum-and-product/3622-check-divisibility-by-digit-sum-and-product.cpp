class Solution {
public:
    bool checkDivisibility(int n) {
        int orig = n,sum = 0,prod = 1;
       while(n != 0){
        int dig = n % 10;
        sum += dig;
        prod *= dig;
        n /= 10;
       } 
    return orig%(sum+prod) == 0;   
    }
};