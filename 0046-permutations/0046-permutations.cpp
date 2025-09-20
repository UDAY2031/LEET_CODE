class Solution {
public:
    void helper(vector<int>& nums,vector<int>& path, vector<vector<int>>& results){
        int n = nums.size();
        if(n == 0){
            results.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            int a = nums[i];

            vector<int> temp;

            temp.insert(temp.begin(), nums.begin(), nums.begin()+i);
            temp.insert(temp.begin(), nums.begin() + i + 1, nums.end());

            path.push_back(a);
            helper(temp, path, results);
            path.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> path;
        helper(nums, path ,results);
        return results;
    }
};