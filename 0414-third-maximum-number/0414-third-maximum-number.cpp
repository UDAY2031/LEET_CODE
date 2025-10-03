class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> st(nums.begin(), nums.end());
        vector<int> v(st.begin(), st.end());
        if(v.size() < 3){
            return v[0];
        }
        return v[2];
    }
};