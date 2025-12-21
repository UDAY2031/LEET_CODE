class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int res = 0;

        for (int col = 0; col < m; col++) {
            bool bad = false;

            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                res++;
            } else {
                for (int row = 0; row < n - 1; row++) {
                    if (strs[row][col] < strs[row + 1][col]) {
                        sorted[row] = true;
                    }
                }
            }
        }
        return res;
    }
};