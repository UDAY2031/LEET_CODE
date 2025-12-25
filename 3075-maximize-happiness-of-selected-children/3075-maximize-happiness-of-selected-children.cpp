class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        if (k <= 0 || happiness.empty()) return 0LL;
        nth_element(happiness.begin(), happiness.begin() + min<size_t>(k, happiness.size()), happiness.end(), greater<int>());
        long long res = 0;
        for (int i = 0; i < k && i < (int)happiness.size(); ++i) {
            long long val = (long long)happiness[i] - i;
            if (val > 0) res += val;
        }
        return res;
    }
};