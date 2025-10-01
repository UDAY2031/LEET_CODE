class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        res.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                res.pop_back();
                res.push_back(nums[i]);
            }else{
                res.push_back(nums[i]);
            }
        }
        return res.size();
    }
};