class Solution {
public:
    int magicalString(int n) {
        if(n <= 3)
            return 1;

        string s = "122";

        int i = 2;
        char num = '1';
        int count = 1;

        while(s.length() < n) {
            int times = s[i] - '0';

            while(times-- && s.length() < n) {
                s += num;

                if(num == '1')
                    count++;
            }

            num = (num == '1') ? '2' : '1';
            i++;
        }

        return count;
    }
};