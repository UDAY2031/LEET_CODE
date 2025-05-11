class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> players(n);

        for(int i = 0;i<n;i++){
            players[i] = {ages[i], scores[i]};
        }
        sort(players.begin(), players.end());

        vector<int> dp(n);
        int result = 0;
        for(int i = 0; i < n; i++){
            dp[i] = players[i].second;
            for(int j = 0; j < i; j++){
                if(players[j].second <= players[i].second){
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};