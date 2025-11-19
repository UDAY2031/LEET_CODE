class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());

        for(int i = 0; i < st.size(); i++){
            if(st.find(original) != st.end()){
                original = original * 2;
            }
        }
        return original;
    }
};