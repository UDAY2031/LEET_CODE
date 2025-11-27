class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        long long prefix = 0;

        vector<long long> best_prefix(k, LLONG_MAX);
        best_prefix[0] = 0;

        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int mod = ((i+1) % k + k) % k;

            if(best_prefix[mod] != LLONG_MAX){
                ans = max(ans, prefix - best_prefix[mod]);
            }

            best_prefix[mod] = min(best_prefix[mod], prefix);
        }
        return ans;
    }
};