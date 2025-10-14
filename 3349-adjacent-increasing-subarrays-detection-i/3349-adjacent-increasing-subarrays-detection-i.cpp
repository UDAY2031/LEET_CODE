class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if(n < 2 * k) return false;
        int currlen = 1;
        int prevlen = 0;

        for(int i = 1; i < n; ++i){
            if(nums[i] > nums[i-1]){
                currlen++;

                if(currlen >= 2 * k) return true;

                if(prevlen >= k && currlen >= k) return true;
            }else{
                if(currlen >= 2 * k) return true;

                if(prevlen >= k && currlen >= k) return true;

                prevlen = currlen;
                currlen = 1;
            }
        }
        if(currlen >= 2 * k) return true;
        if(currlen >= k && prevlen >= k) return true;
        return false;
    }
};