class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            if((num & 1) == 0) {
                ans[i] = -1;
                continue;
            }
            bool found = false;
            for(int bit = 1; bit < 32; bit++) {
                if((num >> bit & 1) == 0) {
                    ans[i] = num ^ (1 << (bit - 1));
                    found = true;
                    break;
                }
            }
            if(!found) ans[i] = -1;
        }
        return ans;
    }
};