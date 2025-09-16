class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(100001,0);

        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }

        for(int i = 0; i < hash.size(); i++){
            if(hash[i] == 1){
                return i;
            }
        }
        return -1;
    }
};