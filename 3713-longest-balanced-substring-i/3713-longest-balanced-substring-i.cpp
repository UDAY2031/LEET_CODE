class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            unordered_map<int,int> cnt;
            
            for (int j = i; j < n; j++) {
                int c = s[j] - 'a';
                int f = freq[c];
                
                if (f > 0) {
                    cnt[f]--;
                    if (cnt[f] == 0) cnt.erase(f);
                }
                
                freq[c]++;
                cnt[freq[c]]++;
                
                if (cnt.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};