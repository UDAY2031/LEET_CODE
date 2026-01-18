class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> d1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> d2(m + 2, vector<int>(n + 2, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i + 1][j + 1] = row[i + 1][j] + grid[i][j];
                col[i + 1][j + 1] = col[i][j + 1] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j + 1] = d2[i][j + 2] + grid[i][j];
            }
        }

        int ans = 1;
        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int s = row[i + 1][j + k] - row[i + 1][j];
                    bool ok = true;
                    for (int r = 0; r < k && ok; r++) {
                        if (row[i + r + 1][j + k] - row[i + r + 1][j] != s) ok = false;
                        if (col[i + k][j + r + 1] - col[i][j + r + 1] != s) ok = false;
                    }
                    if (!ok) continue;
                    if (d1[i + k][j + k] - d1[i][j] != s) continue;
                    if (d2[i + k][j + 1] - d2[i][j + k + 1] != s) continue;
                    ans = k;
                }
            }
        }
        return ans;
    }
};
