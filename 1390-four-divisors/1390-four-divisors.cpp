class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int b = 0;
        for (int x : nums) {
            int c = 0;
            int d = 0;
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;
                    if (i == j) {
                        c++;
                        d += i;
                    } else {
                        c += 2;
                        d += i + j;
                    }
                    if (c > 4) break;
                }
            }
            if (c == 4) b += d;
        }
        return b;
    }
};