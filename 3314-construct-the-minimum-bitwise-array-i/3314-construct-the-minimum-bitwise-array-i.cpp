class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (x == 2) {
                ans[i] = -1;
                continue;
            }
            for (int bit = 1; bit < 32; ++bit) {
                if ((x >> bit & 1) == 0) {
                    ans[i] = x ^ (1 << (bit - 1));
                    break;
                }
            }
        }
        return ans;
    }
};