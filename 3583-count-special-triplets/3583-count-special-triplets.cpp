class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1000000007;
        long long ans = 0;

        unordered_map<long long, long long> rightFreq, leftFreq;

        for(long long x : nums){
            rightFreq[x]++;
        }

        for(int i = 0; i < n; i++){

            long long mid = nums[i];
            long long target = 2LL * mid;

            rightFreq[mid]--;

            long long l = leftFreq[target];
            long long r = rightFreq[target];

            ans = (ans + (l % mod) * (r % mod))%mod;

            leftFreq[mid]++;
        }
        return (int)ans;
    }
};