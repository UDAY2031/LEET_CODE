class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_buy = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < prices.size(); i++){
            best_buy = min(best_buy, prices[i]);
            maxprofit = max(maxprofit, prices[i] - best_buy);
        }
        return maxprofit;
    }
};