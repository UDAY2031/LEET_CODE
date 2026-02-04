class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 4;

        vector<long long> inc(n, NEG), dec(n, NEG), inc2(n, NEG);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc[i] = max(inc[i], (long long)nums[i - 1] + nums[i]);
                if (inc[i - 1] != NEG)
                    inc[i] = max(inc[i], inc[i - 1] + nums[i]);
            }

            if (nums[i] < nums[i - 1]) {
                if (inc[i - 1] != NEG)
                    dec[i] = inc[i - 1] + nums[i];
                if (dec[i - 1] != NEG)
                    dec[i] = max(dec[i], dec[i - 1] + nums[i]);
            }

            if (nums[i] > nums[i - 1]) {
                if (dec[i - 1] != NEG)
                    inc2[i] = dec[i - 1] + nums[i];
                if (inc2[i - 1] != NEG)
                    inc2[i] = max(inc2[i], inc2[i - 1] + nums[i]);
            }
        }

        long long ans = NEG;
        for (long long v : inc2)
            ans = max(ans, v);

        return ans;

    }
};