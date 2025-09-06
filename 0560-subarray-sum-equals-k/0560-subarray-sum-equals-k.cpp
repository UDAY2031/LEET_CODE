class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int s = 0; s < n; s++){
            int currsum = 0;
            for(int e = s; e < n; e++){
                currsum += nums[e];

                if(currsum == k){
                cnt++;
                }
            }
        }
        return cnt;
    }
};