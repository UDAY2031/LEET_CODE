class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> res;

        for(int it : nums){
            freq[it]++;
        }
        for(auto i : freq){
            if(i.second > n/3){
                res.push_back(i.first);
            }
        }
        return res;
    }
};