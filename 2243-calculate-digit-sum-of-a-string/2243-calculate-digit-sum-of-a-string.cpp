class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.length() > k){
            int i = 0, sum = 0;
            string str;
            while(i < s.length()){
                if(i != 0 && i % k == 0 ){
                    str += to_string(sum);
                    sum = 0;
                }
                sum += (s[i++]-'0');
            }
            str += to_string(sum);
            s = str;
        }
    return s;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna