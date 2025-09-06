class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int cnt = 0;
        int prefix = 0;

        for(int num : nums){
            prefix += num;

            if(mp.find(prefix - k) != mp.end()){
                cnt += mp[prefix - k];
            }

            mp[prefix]++;
        }
        return cnt;
    }
};