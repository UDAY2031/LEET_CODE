class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left <= right){
            nums[left] = nums[left] * nums[left];
            left++;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};