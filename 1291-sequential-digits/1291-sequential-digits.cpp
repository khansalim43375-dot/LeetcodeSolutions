class Solution {
public:
    vector<int> sequentialDigits(int low, int high) { 
    vector<int> ans;    
    for(int start = 1; start <= 9; start++) {
    int num = 0;

    for(int dig = start; dig <= 9; dig++) {
        num = num * 10 + dig;

        if(num >= low && num <= high)
            ans.push_back(num);

        if(num > high)
            break;
    }
}
sort(ans.begin(),ans.end());
    return ans;
    }
};