class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        vector<int> hash(n+1, 0);

        for(auto i : nums){
            hash[i]++;
        }

        for(int i = 1; i < hash.size(); i++){
            if(hash[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};