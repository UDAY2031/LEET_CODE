class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++) {
            char x = (i % 2) ? '1' : '0';
            char y = (i % 2) ? '0' : '1';
            if (s[i] != x) a++;
            if (s[i] != y) b++;
        }
        return min(a, b);
    }
};