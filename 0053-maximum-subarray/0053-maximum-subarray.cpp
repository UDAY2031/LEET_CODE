class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max1 = nums[0];
        int currsum = nums[0];
        for(int i = 1; i < nums.size();i++){
            currsum = max(nums[i],currsum + nums[i]);
            max1 = max(max1,currsum);
        }
        return max1;
    }

};