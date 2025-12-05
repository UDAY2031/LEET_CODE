class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        int el = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        for(int i = 0; i < n; i++){
            el += nums[i];
            int res = 2 * el - sum;
            if(res % 2 == 0){
                cnt++;
            }
        }
        int ans = cnt - 1;
        if(ans < 0) return 0;
        return ans;
    }
};