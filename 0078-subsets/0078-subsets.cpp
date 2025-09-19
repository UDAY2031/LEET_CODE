class Solution {
public:
    void sub(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& results){
        if(index == nums.size()){
            results.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        sub(nums, index+1, current, results);
        
        current.pop_back();
        sub(nums, index+1, current, results);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;
        sub(nums, 0, current, results);
        return results;
    }
};