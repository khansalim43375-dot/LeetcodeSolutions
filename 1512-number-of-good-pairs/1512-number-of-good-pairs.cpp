class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
      int ans = 0,freq[101] = {0};
      for(int i = 0 ; i < nums.size(); i++){
          freq[nums[i]]++;
      }

      for(int i = 1; i <= 100; i++){
        ans += (freq[i]*(freq[i]-1))/2;
      }
      return ans;
    }
};