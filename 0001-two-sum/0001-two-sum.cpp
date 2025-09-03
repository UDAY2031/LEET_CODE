class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int num;

        for(int i = 0; i < n; i++){
            num = nums[i];
            for(int j = i+1; j < n; j++){
                if((num + nums[j]) == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};