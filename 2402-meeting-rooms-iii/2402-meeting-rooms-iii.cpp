class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        priority_queue<int, vector<int>, greater<int>> free;
        
        for (int i = 0; i < n; ++i) free.push(i);
        
        for (auto& m : meetings) {
            int s = m[0], d = m[1] - s;
            
            while (!busy.empty() && busy.top().first <= s) {
                free.push(busy.top().second);
                busy.pop();
            }
            
            int r;
            if (!free.empty()) {
                r = free.top(); free.pop();
            } else {
                auto [t, rr] = busy.top(); busy.pop();
                s = t;
                r = rr;
            }
            
            cnt[r]++;
            busy.emplace((long long)s + d, r);
        }
        
        int best = 0;
        for (int i = 1; i < n; ++i) {
            if (cnt[i] > cnt[best]) best = i;
        }
        return best;
    }
};