class Solution {
public:
    int search(vector<int>& nums, int target) {
        int j;
        for(int i = 0;i<nums.size();i++){
            if(target == nums[i]){
                return i;
            }
        }
        return -1;
    }
};