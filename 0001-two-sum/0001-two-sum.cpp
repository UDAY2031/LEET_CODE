class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nmap;

        for(int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];

            if(nmap.find(complement) != nmap.end()){
                return {nmap[complement],i};
            }
            nmap[nums[i]] = i;
        }
        return {};
    }
};