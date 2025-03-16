class Solution {
public:
    int reverse(int x) {
        int reverse_digit = 0;
        while (x != 0) {
            int l = x % 10;
            if (reverse_digit > 214748364 || reverse_digit < -214748364)
                return 0;
            reverse_digit = (reverse_digit * 10) + l;
            x = x / 10;
        }
        return reverse_digit;
    }
};