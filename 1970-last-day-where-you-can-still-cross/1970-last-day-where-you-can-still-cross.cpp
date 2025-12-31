class Solution {
public:
    int n, m;
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool ok(int k, vector<vector<int>>& c) {
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for (int i = 0; i < k; i++)
            a[c[i][0]-1][c[i][1]-1] = 1;
        
        queue<pair<int,int>> q;
        
        for (int j = 0; j < m; j++) {
            if (a[0][j] == 0) {
                q.push({0, j});
                a[0][j] = 1;
            }
        }
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.first, y = p.second;
            
            if (x == n - 1) return true;
            
            for (auto &i : d) {
                int r = x + i[0];
                int s = y + i[1];
                if (r >= 0 && r < n && s >= 0 && s < m && a[r][s] == 0) {
                    a[r][s] = 1;
                    q.push({r, s});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row; m = col;
        int l = 1, h = cells.size(), ans = 0;
        
        while (l <= h) {
            int mid = (l + h) / 2;
            if (ok(mid, cells)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};