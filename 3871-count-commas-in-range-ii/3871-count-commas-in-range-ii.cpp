class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long p = 1000; p <= n; ) {
            long long end = min(n, p * 1000 - 1);
            long long commas = 0;

            // Find number of commas for this block
            long long x = p;
            while (x >= 1000) {
                x /= 1000;
                if (x > 0) commas++;
            }

            ans += (end - p + 1) * commas;

            if (p > n / 1000) break;
            p *= 1000;
        }

        return ans;
    }
};