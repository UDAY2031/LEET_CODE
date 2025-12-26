class Solution {
public:
    int bestClosingTime(string customers) {
                int n = customers.size();
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }
        int cntY = totalY;
        int cntN = 0;
        int best = 0;
        int minP = cntY;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                cntY--;
            } else {
                cntN++;
            }
            int p = cntN + cntY;
            if (p < minP) {
                minP = p;
                best = i + 1;
            }
        }
        return best;
    }
};