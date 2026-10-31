class Solution {
  public:
    int partition(vector<int>& arr, int sum){
        int arrays = 1, assign = 0;

        for(int x : arr){
            if(assign + x <= sum){
                assign += x;
            }else{
                arrays++;
                assign = x;
            }
        }
    return arrays;    
    }

    int splitArray(vector<int>& arr, int k) {

        // code here
         int st = *max_element(arr.begin(), arr.end());
         int end = accumulate(arr.begin(), arr.end(), 0);

         while(st <= end){
             int mid = st+ ( end - st)/2;

             int arrays = partition(arr, mid);

             if(arrays <= k){
                 end = mid-1;
             }else{
                 st = mid+1;
             }
         }
    return st;     
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna