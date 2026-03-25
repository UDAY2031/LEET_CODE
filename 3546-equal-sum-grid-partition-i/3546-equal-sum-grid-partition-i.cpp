class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long total = 0;

        for (auto &row : grid)
            for (int x : row)
                total += x;

        if (total % 2) return false;

        long long target = total / 2;

        long long curr = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++)
                curr += grid[i][j];
            if (curr == target) return true;
        }

        curr = 0;
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n; i++)
                curr += grid[i][j];
            if (curr == target) return true;
        }

        return false;
    }
};