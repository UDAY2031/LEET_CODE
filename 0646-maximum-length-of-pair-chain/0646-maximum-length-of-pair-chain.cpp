class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int cnt = 1;
        
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int currend = pairs[0][1];
        for(int i = 1; i < n; i++){
            if(pairs[i][0] > currend){
                cnt++;
                currend = pairs[i][1];
            }
        }
        return cnt;
    }
};