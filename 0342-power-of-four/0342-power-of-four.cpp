class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n > 0 && n == 1) return true;
        if((n & (n - 1)) == 0) return true;
        return false;
    }
};