class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(1, poured);
        
        for (int r = 0; r < query_row; ++r) {
            vector<double> nxt(r + 2, 0.0);
            for (int c = 0; c < cur.size(); ++c) {
                if (cur[c] > 1.0) {
                    double extra = (cur[c] - 1.0) / 2.0;
                    nxt[c] += extra;
                    nxt[c + 1] += extra;
                }
            }
            cur = nxt;
        }
        
        return min(1.0, cur[query_glass]);
    }
};
