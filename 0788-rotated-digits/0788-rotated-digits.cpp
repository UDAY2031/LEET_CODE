class Solution {
public:
    int rotatedDigits(int n) {
        unordered_set<int> same = {0, 1, 8};
        unordered_set<int> diff = {2, 5, 6, 9};
        int count = 0;

        for (int i = 1; i <= n; i++) {
            int x = i;
            bool valid = true;
            bool changed = false;

            while (x > 0) {
                int d = x % 10;
                if (!same.count(d) && !diff.count(d)) {
                    valid = false;
                    break;
                }
                if (diff.count(d)) changed = true;
                x /= 10;
            }

            if (valid && changed) count++;
        }

        return count;
    }
};