class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-3;
        while(i >= 0){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a+b>c && a+c>b && b+c>a)
               return a+b+c;
            i--;        
                  
        }
    return 0;    
    }
};