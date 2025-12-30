class Solution {
public:
    bool chk(vector<vector<int>>& g, int x, int y) {
        int s = 0;
        for (int i = 0; i < 3; i++) {
            int t = g[x][y] + g[x][y + 1] + g[x][y + 2];
            if (t != s && i == 0) s = t;
            else if (t != s) return false;
            x++;
        }
        x -= 3;
        for (int i = 0; i < 3; i++) {
            int t = g[x][y] + g[x + 1][y] + g[x + 2][y];
            if (t != s) return false;
            y++;
        }
        if (g[x][y - 3] + g[x + 1][y - 2] + g[x + 2][y - 1] != s) return false;
        if (g[x + 2][y - 3] + g[x + 1][y - 2] + g[x][y - 1] != s) return false;
        unordered_set<int> st;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int v = g[x + i][y + j - 3];
                if (v < 1 || v > 9 || st.count(v)) return false;
                st.insert(v);
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 3) return 0;
        int m = grid[0].size();
        if (m < 3) return 0;
        int ans = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (chk(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};