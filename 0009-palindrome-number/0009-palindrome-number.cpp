class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int dup = x;
        int reverse_num = 0;
        while(x != 0){
            if (reverse_num > 214748364 || reverse_num < -214748364)
                return 0;
            int last_digit = x % 10;
            reverse_num = (reverse_num * 10) + last_digit;
            x = x / 10;
        }
        return (reverse_num == dup);
    }
};