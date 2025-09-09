class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1,0);
        int duplicate = -1, missing = -1;
        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }

        for(int i = 0; i < hash.size(); i++){
            if(hash[i] == 2) duplicate = i;
            if(hash[i] == 0) missing = i;
        }
        return {duplicate,missing};
    }
};