#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                set<int> s;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        s.insert(grid[x][y]);
                    }
                }

                if (s.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }

                int prev = -1e9, best = INT_MAX;
                bool first = true;

                for (int val : s) {
                    if (!first) best = min(best, val - prev);
                    prev = val;
                    first = false;
                }

                ans[i][j] = best;
            }
        }
        return ans;
    }
};