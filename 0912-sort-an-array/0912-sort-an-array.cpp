class Solution {
public:
    void mergenums(vector<int>& nums, int si, int mid, int ei){
        int i = si;
        int j = mid+1;
        vector<int> temp;

        while(i <= mid && j <= ei){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= ei){
            temp.push_back(nums[j++]);
        }

        for(int i = si, x = 0; i <= ei; i++){
            nums[i] = temp[x++];
        }
    }
    void mergesort(vector<int>& nums, int si, int ei){
        if(si >= ei){
            return;
        }

        int mid = si + (ei - si) / 2;

        mergesort(nums, si, mid);
        mergesort(nums, mid + 1, ei);

        return mergenums(nums, si, mid, ei);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n - 1);
        return nums;
    }
};