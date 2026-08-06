class Solution {
public:
    int reverseBits(int n) {
        int bits[32];
        for (int i = 31; i >= 0; i--) {
            
            bits[31 - i] = n & 1;
            n >>= 1;
        }
        int num = 0;

        for (int i = 0; i < 32; i++) {
            num = (num << 1) | bits[i];
        }
return num;
    }
};