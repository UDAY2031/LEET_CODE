class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 0) return 0;
        int ln = 1;
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]+1){
                cnt++;
            }else if(nums[i] != nums[i-1]){
                cnt = 1;
            }

            ln = max(ln, cnt);
        }
        return ln;
    }
};