class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
    pair<int,int> p = {-1,-1};
    int n = nums1.size();
    vector<int> nums2(n,0);
    sort(nums1.begin(),nums1.end());
    for(int i = 0; i < n; i++){
        if(nums1[i] % 2 != 0){
            p.first = nums1[i];
            p.second = i;
            break;
        }
    }
    if(p.first == -1)
      return true;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(nums1[i] % 2 == 0){
            if(p.second < i){
               nums2[i] = nums1[i] - p.first;
               count++;
            }   
              
        }else
           count++;
    }
    if(count == n)
       return true;
    fill(nums2.begin(),nums2.end(),0);  
    count = 0;   
    for(int i = 0; i < n; i++){
        if(nums1[i] % 2 != 0){
            if(p.second < i){
               nums2[i] = nums1[i] - p.first;
               count++;
            }   
        }else
            count++;
    }
    if(count == n)
        return true;
    return false;      
    }
};