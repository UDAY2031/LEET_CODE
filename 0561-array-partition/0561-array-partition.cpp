class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0, curr = 0;
        for(int i = 0; i < n; i += 2){
            for(int j = 1 + i; j < n; j++){
                curr = min(nums[i], nums[j]);
            }
            sum += max(sum, curr);
        }
        return sum;
    }
};