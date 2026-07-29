class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int n = nums2.size();
        unordered_map<int,int> m;

        for(int i = 0; i < nums1.size(); i++)
            m[nums1[i]] = i;
        
        for(int i = n-1; i >= 0; i--){

            while(s.size() > 0 && s.top() <= nums2[i]){
                s.pop();
            }
           if(m.count(nums2[i])){

            if(s.empty())
                nums1[m[nums2[i]]] = -1;
            else
                nums1[m[nums2[i]]] = s.top();

           }
            s.push(nums2[i]);   
        }
        return nums1;
    }
};