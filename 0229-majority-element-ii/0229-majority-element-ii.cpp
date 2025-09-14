class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        set<int> st;
        
        for(int i = 0; i < n; i++){
            if(st.count(nums[i])) continue;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }
            if(cnt > n/3){
                ans.push_back(nums[i]);
                st.insert(nums[i]);
            }
        }
        return ans;
    }
};