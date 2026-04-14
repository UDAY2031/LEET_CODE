class Solution {
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        sort(r.begin(), r.end());
        sort(f.begin(), f.end());
        
        int n = r.size(), m = f.size();
        const long long INF = 1e18;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));
        
        for (int j = 0; j <= m; j++) dp[0][j] = 0;
        
        for (int j = 1; j <= m; j++) {
            int pos = f[j - 1][0];
            int cap = f[j - 1][1];
            
            for (int i = 0; i <= n; i++) {
                dp[i][j] = dp[i][j - 1];
            }
            
            for (int i = 1; i <= n; i++) {
                long long cost = 0;
                for (int k = 1; k <= cap && k <= i; k++) {
                    cost += abs(r[i - k] - pos);
                    if (dp[i - k][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};