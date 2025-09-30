class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int num = nums[n-1];
        for(int i = 0; i < k; i++){
            sum += num;
            num++;
        }
        return sum;
    }
};