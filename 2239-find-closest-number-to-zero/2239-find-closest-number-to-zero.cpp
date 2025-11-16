class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];

        for(auto i : nums){
            if(abs(i) < abs(ans)){
                ans = i;
            }else if(abs(i) == abs(ans) && i > ans){
                ans = i;
            }
        }
        return ans;
    }
};