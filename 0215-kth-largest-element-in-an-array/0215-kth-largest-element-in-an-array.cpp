class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int first = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            first = max(first, nums[i]);
        }
        int sam = INT_MIN;
        for(int i = nums.size()-1; i >= 0; i--){
            sam = nums[i+(k+1)];
        }
        return sam;
    }
};