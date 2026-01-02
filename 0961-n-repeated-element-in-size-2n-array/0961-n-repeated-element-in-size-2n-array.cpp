class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hash;

        for(int x : nums){
            hash[x]++;
        }
        int res = 0;
        for(int i = 0; i < hash.size(); i++){
            if(hash[i] == n/2){
                res = i;
            }
        }
        return res;
    }
};