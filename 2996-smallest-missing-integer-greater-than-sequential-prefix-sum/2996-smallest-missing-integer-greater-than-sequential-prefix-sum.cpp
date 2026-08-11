class Solution {
public:
    int missingInteger(vector<int>& nums) {
    int sum = nums[0],n = nums.size();

    for(int i = 1; i < n; i++){

        if(nums[i] == nums[i-1] + 1)
           sum += nums[i];
        else
           break;   
    }

    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(nums[i]);
    }

    while(s.count(sum)) 
       sum++;
       
    return sum; 
    }
};