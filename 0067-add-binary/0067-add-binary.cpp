class Solution {
  public:
    string addBinary(string s1, string s2) {
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        string s;

        while (i >= 0 || j >= 0 || carry) {
            int x = carry;
            if (i >= 0) x += s1[i--] - '0';
            if (j >= 0) x += s2[j--] - '0';
            s += char(x % 2 + '0');
            carry = x / 2;
        }

        // strip leading zeros (they are at the end right now, before reversing)
        while (s.size() > 1 && s.back() == '0') s.pop_back();

        reverse(s.begin(), s.end());
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna