class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, best = 0;
        for (int r = 0; r < n; r++) {
            while (1LL * nums[l] * k < nums[r]) {
                l++;
            }
            best = max(best, r - l + 1);
        }
        return n - best;
    }
};