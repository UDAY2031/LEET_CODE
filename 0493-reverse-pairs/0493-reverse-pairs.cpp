class Solution {
public:
    void mergenums(vector<int>& nums, int si, int mid, int ei){
        int i = si;
        int j = mid + 1;
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
    int cnt(vector<int>& nums, int si, int mid, int ei){
        int j = mid + 1;
        int cnt = 0;


        for(int i = si; i <= mid; i++){
            while(j <= ei && (long long)nums[i] > 2LL * nums[j]){
                j++;
            }
            cnt += (j - (mid+1));
        }

        return cnt;
    }
    int mergesort(vector<int>& nums, int si, int ei){
        int mid = si + (ei - si) / 2;

        if(si >= ei){
            return 0;
        }

        int left = mergesort(nums, si, mid);
        int right = mergesort(nums, mid+1, ei);
        int crosscount = cnt(nums, si, mid, ei);
        
        mergenums(nums,si,mid,ei);
        return left + right + crosscount;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums, 0, n - 1);
    }
};