class Solution {
public:
    vector<int> helper(int n){
        long long ans = 1;
        vector<int> ansrow;
        ansrow.push_back(1);
        for(int i = 1; i < n; i++){
            ans = ans * (n - i);
            ans = ans / i;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<int> getRow(int rowIndex) {
        return helper(rowIndex+1);
    }
};