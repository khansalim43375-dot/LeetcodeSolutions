class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
       vector<int> arr1;
       vector<int> arr2;
       vector<int> result;
       arr1.push_back(nums[0]);
       arr2.push_back(nums[1]);
       int i = 2;
       while(i < nums.size()){
        if(arr1.back() > arr2.back())
           arr1.push_back(nums[i]);
        else
            arr2.push_back(nums[i]);
        i++;
       }
    result = arr1;
    result.insert(result.end(),arr2.begin(),arr2.end());
    return result;   
    }
};