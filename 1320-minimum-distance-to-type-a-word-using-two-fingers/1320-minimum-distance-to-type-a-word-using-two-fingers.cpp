#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> dp(27, vector<int>(27, INT_MAX));
        dp[26][26] = 0;

        for (char c : word) {
            int cur = c - 'A';
            vector<vector<int>> ndp(27, vector<int>(27, INT_MAX));

            for (int i = 0; i <= 26; i++) {
                for (int j = 0; j <= 26; j++) {
                    if (dp[i][j] == INT_MAX) continue;

                    ndp[cur][j] = min(ndp[cur][j], dp[i][j] + dist(i, cur));
                    ndp[i][cur] = min(ndp[i][cur], dp[i][j] + dist(j, cur));
                }
            }
            dp.swap(ndp);
        }

        int res = INT_MAX;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                res = min(res, dp[i][j]);
            }
        }
        return res;
    }
};