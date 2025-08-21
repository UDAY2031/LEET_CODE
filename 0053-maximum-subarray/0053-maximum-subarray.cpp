class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max1 = INT_MIN;
        int currsum = 0;
        for(int i = 0; i < nums.size();i++){
            currsum += nums[i];

            if(currsum<0){
                currsum = 0;
            }
            max1 = max(max1,currsum);
        }
        return max1;
    }

};