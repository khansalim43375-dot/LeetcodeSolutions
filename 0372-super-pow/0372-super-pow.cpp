class Solution {
public:
    int power(int a, int b) {
        int ans = 1;
        a %= 1337;

        while(b > 0) {
            if(b % 2 == 1)
                ans = (ans * a) % 1337;

            a = (a * a) % 1337;
            b /= 2;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a %= 1337;

        for(int digit : b) {
            ans = power(ans, 10) * power(a, digit) % 1337;
        }

        return ans;
    }
};