class Solution {
public:
    int maxProfit(vector<int>& prices) {

    int buy = prices[0],ans = 0;

    for(int i = 1; i < prices.size(); i++){
        int profit = prices[i]-buy;
        if(profit > 0)
            ans += profit;
        buy = prices[i];    
    }
    return ans;  
    }
};