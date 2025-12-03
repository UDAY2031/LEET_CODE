class Solution {
public:
    int mySqrt(int x) {
        if(x <= 2) return x;

        long long left = 1;
        long long right = x;

        long long res = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(mid <= x / mid){
                res = (int)mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
};