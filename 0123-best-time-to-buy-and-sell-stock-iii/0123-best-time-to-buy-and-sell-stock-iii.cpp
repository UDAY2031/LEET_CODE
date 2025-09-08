class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int first_buy = INT_MIN, second_buy = INT_MIN;
        int first_sell = 0, second_sell = 0;

        for(auto price : prices){
            first_buy = max(first_buy, -price);
            first_sell =  max(first_sell, first_buy + price);

            second_buy = max(second_buy, first_sell - price);
            second_sell = max(second_sell, second_buy + price);
        }
        return second_sell;
    }
};