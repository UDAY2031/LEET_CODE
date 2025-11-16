class Solution {
public:
    int numSub(string s) {
        const int mod = 1e9+7;
        long long cnt = 0;
        long long ans = 0;

        for(char c : s){
            if(c == '1'){
                cnt++;
                ans = (ans + cnt) % mod;
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
};