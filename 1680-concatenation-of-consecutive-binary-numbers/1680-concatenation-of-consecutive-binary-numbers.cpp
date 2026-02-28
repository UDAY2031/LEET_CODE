class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1000000007;
        long long result = 0;
        int length = 0;
        
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++length;
            }
            result = ((result << length) % mod + i) % mod;
        }
        
        return (int)result;
    }
};