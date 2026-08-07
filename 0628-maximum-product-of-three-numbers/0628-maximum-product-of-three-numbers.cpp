class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int min1 = INT_MAX,min2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }else if(nums[i] < min2)
                min2 = nums[i];
        }
        for(int i = 0; i < nums.size(); i++){        
            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }else if (nums[i] > second){
                third = second;
                second = nums[i];
                
            }else if(nums[i] > third){
                third = nums[i];
            }
        }
        return max(first * second * third,first*min1*min2);
    }
};