class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        for(int i = 0; i < n - 1; i++){
            int mini = prices[i];
            int profit = 0;
            if(prices[i+1] > mini){
                profit = prices[i+1] - mini;
            }
            maxi += profit;
        }
        return maxi;
    }
};