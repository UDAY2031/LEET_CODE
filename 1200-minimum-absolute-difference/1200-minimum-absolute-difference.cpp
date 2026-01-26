class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mn = INT_MAX;
        for(int i = 1; i < n; i++) {
            int d = arr[i] - arr[i - 1];
            if(d < mn) mn = d;
        }
        vector<vector<int>> res;
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] == mn) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;        
    }
};