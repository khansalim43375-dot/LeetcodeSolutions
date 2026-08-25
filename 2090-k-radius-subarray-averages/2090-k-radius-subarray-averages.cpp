class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        int count1 = 0,count2 = n-1;
        long long sum = 0;
        for(int i = 0; i <= 2*k; i++){
            if(i < n)
              sum += nums[i];
        }
        for(int i = 0; i < n; i++){
            
            if(count1 >= k && count2 >= k){
                ans[i] = (sum)/(2*k+1);
                sum -= nums[i-k];
                if(i+k+1 < n)
                    sum += nums[i+k+1];
            }
            count1++;
            count2--;
        }
return ans;

    }
};