class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;

        for(int num : nums2){
            while(!s.empty() && num >= s.top()){
                mp[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        while(!s.empty()){
            mp[s.top()] = -1;
            s.pop();
        }
        vector<int> res;
        for(int num : nums1){
            res.push_back(mp[num]);
        }
        return res;
    }
};