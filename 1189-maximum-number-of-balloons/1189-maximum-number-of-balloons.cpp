class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";

    int textFreq[256] = {0};
    int targetFreq[256] = {0};

    for(char ch : text)
        textFreq[(unsigned char)ch]++;

    for(char ch : target)
        targetFreq[(unsigned char)ch]++;

    int ans = INT_MAX;

    for(int i = 0; i < 256; i++) {
        if(targetFreq[i] > 0)
             ans = min(ans, textFreq[i] / targetFreq[i]);
    }

    return ans;
    }
};