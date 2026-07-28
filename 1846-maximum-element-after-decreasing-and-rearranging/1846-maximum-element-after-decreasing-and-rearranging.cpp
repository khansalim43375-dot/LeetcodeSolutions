class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        arr[0] = 1;
          int i = 0,j = 1;
        while(j < arr.size()){
            if(arr[j] - arr[i] > 1){
                arr[j++] = arr[i++] + 1;
            }else{
               j++;i++;}
        }
        int maxn = 0;
            for(int i = 0; i < arr.size(); i++){
            maxn = max(maxn,arr[i]);
        }
        return maxn;
    }
};