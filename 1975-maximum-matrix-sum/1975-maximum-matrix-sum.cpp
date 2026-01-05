class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long s = 0;
        int c = 0;
        int m = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int v = matrix[i][j];
                if (v < 0) c++;
                int t = abs(v);
                s += t;
                m = min(m, t);
            }
        }
        if (c % 2 == 1) s -= 2LL * m;
        return s;
    }
};