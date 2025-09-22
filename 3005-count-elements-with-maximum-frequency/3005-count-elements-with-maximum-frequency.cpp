class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxi = 0;
        for(int num : nums){
            mp[num]++;
        }

        for(auto i : mp){
            maxi = max(maxi, i.second);
        }
        int freq = 0;
        for(auto i : mp){
            if(i.second == maxi){
                freq += i.second;
            }
        }
        return freq;
    }
};