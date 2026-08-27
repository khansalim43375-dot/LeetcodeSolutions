class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
    int count1 = 1,mx1 = 1;
    for(int i = 0 ; i < arr.size()-1; i++){
        if(i % 2 != 0){
            if(arr[i] < arr[i+1]){
            count1++;
            mx1 = max(mx1,count1);}
            else
              count1 = 1;
        }else{
            if(arr[i] > arr[i+1]){
              count1++;
              mx1 = max(mx1,count1);}
            else
              count1 = 1;  
        }

    }
     int count2 = 1,mx2 = 1;
    for(int i = 0 ; i < arr.size()-1; i++){
        if(i % 2 != 0){
            if(arr[i] > arr[i+1]){
            count2++;
            mx2 = max(mx2,count2);}
            else
              count2 = 1;
        }else{
            if(arr[i] < arr[i+1]){
              count2++;
              mx2 = max(mx2,count2);}
            else
              count2 = 1;  
        }

    }
    return max(mx1,mx2);    
    }
};