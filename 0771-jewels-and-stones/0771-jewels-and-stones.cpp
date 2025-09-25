class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int newstone = 0;
        set<char> st;
        for(int i = 0; i < jewels.size(); i++){
            st.insert(jewels[i]);
        }
        for(int i = 0; i < stones.size(); i++){
            if(st.count(stones[i])){
                newstone++;
            }
        }
        return newstone;
    }
};