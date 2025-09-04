class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el = nums[0];
        int cnt = 0;
        int res;

        for(int i = 0; i < n; i++){
            if(nums[i] == el){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                el = nums[i];
            }
            res = nums[i];
        }
        return res;
    }
};