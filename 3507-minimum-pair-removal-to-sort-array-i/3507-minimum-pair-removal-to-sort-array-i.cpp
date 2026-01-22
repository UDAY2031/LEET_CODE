class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while (true) {
            bool sorted = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i-1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) break;

            int idx = 0;
            long long best = (long long)nums[0] + nums[1];
            for (int i = 1; i + 1 < nums.size(); i++) {
                long long s = (long long)nums[i] + nums[i+1];
                if (s < best) {
                    best = s;
                    idx = i;
                }
            }

            nums[idx] = (int)best;
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }
        return ops;
    }
};