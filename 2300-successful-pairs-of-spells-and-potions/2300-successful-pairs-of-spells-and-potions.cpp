class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;
        for(auto spell : spells){

            long long minpotions = (success + spell - 1) / spell;

            int idx = lower_bound(potions.begin(), potions.end(), minpotions) - potions.begin();
            res.push_back(m - idx);
        }
        return res;
        
    }
};