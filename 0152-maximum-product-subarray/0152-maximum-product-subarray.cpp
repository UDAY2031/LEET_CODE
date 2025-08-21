class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct = INT_MIN;
        int currproduct = 0;
        for(int i = 0; i < nums.size(); i++){
            currproduct = max(nums[i], currproduct * nums[i]);
            maxproduct = max(maxproduct, currproduct);
        }
        return maxproduct;
    }
};