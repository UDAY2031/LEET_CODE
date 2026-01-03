class Solution {
public:
    int numOfWays(int n) {
        const int m = 1000000007;
        long long a = 6, b = 6;
        for (int x = 2; x <= n; x++) {
            long long na = (a * 3 + b * 2) % m;
            long long nb = (a * 2 + b * 2) % m;
            a = na;
            b = nb;
        }
        return (a + b) % m; 
    }
};