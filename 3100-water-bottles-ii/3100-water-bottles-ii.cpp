class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        int cost = numExchange;

        while(empty >= cost){
            empty -= cost;
            ans++;
            empty++;
            cost++;
        }
        return ans;
    }
};