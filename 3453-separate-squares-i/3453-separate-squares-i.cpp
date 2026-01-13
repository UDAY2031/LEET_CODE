class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double lo = 0, hi = 1e9;
        double total = 0;
        for (auto &q : squares) total += 1.0 * q[2] * q[2];

        for (int i = 0; i < 80; i++) {
            double mid = (lo + hi) / 2;
            double below = 0;
            for (auto &q : squares) {
                double y = q[1], l = q[2];
                if (mid <= y) continue;
                if (mid >= y + l) below += l * l;
                else below += l * (mid - y);
            }
            if (below * 2 >= total) hi = mid;
            else lo = mid;
        }
        return lo;
    }
};