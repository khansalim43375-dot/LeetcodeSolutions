class Solution {
public:
    int reverse(int x) {
    
        long reversed = 0;
        while(x!=0){
           int last_digit = x%10;
            reversed=reversed*10+last_digit;
            x/=10;
        }
        if(reversed>=INT_MIN && reversed<=INT_MAX){
        return reversed;
        }else{
            return 0;
            }
    }
};