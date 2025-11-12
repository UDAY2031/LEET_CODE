class Solution {
public:
    bool isPalindrome(int x) {
        int d = x;
        int r = 0;
        while( x > 0){
            int l = x % 10;
            if(r > INT_MAX / 10 || r < INT_MIN) 
                return 0;
            r = (r * 10) + l;
            x = x / 10;
        }
        return (d == r);
    }
};