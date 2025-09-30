class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int num = INT_MIN;
        for(int i = 0; i < n; i++){
            num = max(num, nums[i]);
        }
        for(int i = 0; i < k; i++){
            sum += num;
            num++;
        }
        return sum;
    }
};