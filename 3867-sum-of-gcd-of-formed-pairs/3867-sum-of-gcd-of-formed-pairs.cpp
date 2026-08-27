class Solution {
public:
    int gcd(int a, int b) {
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
    return a;
    }
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        vector<int> prefixGcd(n,0);

        for(int i = 0; i < n; i++){
            mx = max(mx,nums[i]);
            prefixGcd[i] = gcd(mx,nums[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum = 0,i = 0,j = n-1;

        while(i < j){
            sum += gcd(prefixGcd[i],prefixGcd[j]);
            i++;j--;
        }

    return sum;    
    }
};