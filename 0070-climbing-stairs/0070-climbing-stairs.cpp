class Solution {
public:
    int climbStairs(int n) {
    long long ways = 1;
    long long ans = 1;

        for (int k = 1; 2 * k <= n; k++) {
            ways = ways * (n - 2*k + 2) * (n - 2*k + 1)
                   / (k * (n - k + 1));

            ans += ways;
        }

        return ans;  
    }
};