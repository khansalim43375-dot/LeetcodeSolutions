class Solution {
  public:
   
    int countMerge(vector<int>& arr, vector<int>& temp, int left, int right){
        if(left >= right) return 0;
            int mid = left + (right - left)/2;
            int count = 0;
            
            count += countMerge(arr, temp, left, mid);
            count += countMerge(arr, temp, mid+1, right);
            
            int i = left;
            for(int j = mid+1; j <= right; j++){
                while(i <= mid && arr[i] <= 2LL*arr[j]) i++;
                count += mid - i +1;
            }
            i = left; int j = mid+1, k = left;
            while(i <= mid && j <= right){
                if(arr[i] <= arr[j]){
                    temp[k++] = arr[i++];
                }else{
                   
                    temp[k++] = arr[j++];
                }
            }
            while(i <= mid) temp[k++] = arr[i++];
            while(j <= right) temp[k++] = arr[j++];
            
            for (int p = left; p <= right; p++) arr[p] = temp[p];
        
    return count;    
    }
    int reversePairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<int> temp(n);
        return countMerge(arr, temp, 0, n-1);
    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna