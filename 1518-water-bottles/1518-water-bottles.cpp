class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange){
            int n  = numBottles / numExchange;
            int remainder = numBottles % numExchange;
            ans += n;
            numBottles = n + remainder;
        }
        return ans;
    }
};