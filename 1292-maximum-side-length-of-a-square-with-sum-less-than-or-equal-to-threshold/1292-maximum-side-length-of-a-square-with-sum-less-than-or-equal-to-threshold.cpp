class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] = mat[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
            }
        }
        int low = 0, high = min(n, m), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool ok = false;
            for (int i = mid; i <= n && !ok; i++) {
                for (int j = mid; j <= m; j++) {
                    int sum = ps[i][j] - ps[i - mid][j] - ps[i][j - mid] + ps[i - mid][j - mid];
                    if (sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};