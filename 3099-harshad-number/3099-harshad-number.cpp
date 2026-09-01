class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
    int orig = x,sum = 0;
    while(x != 0){
        int dig = x % 10;
        sum += dig;
        x /= 10;
    }
    if(orig % sum == 0)
      return sum;
    return -1;     
    }
};