class Solution {
public:
    int longestBalanced(vector<int>& nums) {
    
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> even, odd;
            for (int j = i; j < n; ++j) {
                int v = nums[j];
                if ((v & 1) == 0) even.insert(v);
                else odd.insert(v);
                if (even.size() == odd.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};