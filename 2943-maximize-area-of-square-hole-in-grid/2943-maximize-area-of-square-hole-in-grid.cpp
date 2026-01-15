class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 0, curH = 0;
        for (int i = 0; i < hBars.size(); i++) {
            if (i == 0 || hBars[i] != hBars[i - 1] + 1) curH = 1;
            else curH++;
            maxH = max(maxH, curH);
        }

        int maxV = 0, curV = 0;
        for (int i = 0; i < vBars.size(); i++) {
            if (i == 0 || vBars[i] != vBars[i - 1] + 1) curV = 1;
            else curV++;
            maxV = max(maxV, curV);
        }

        int side = min(maxH + 1, maxV + 1);
        return side * side;
    }
};