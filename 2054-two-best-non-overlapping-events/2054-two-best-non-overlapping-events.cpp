class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> b;
        int c = 0, d = 0;

        for (auto &e : events) {
            int f = e[0], g = e[1], h = e[2];

            while (!b.empty() && b.top().first < f) {
                c = max(c, b.top().second);
                b.pop();
            }

            d = max(d, c + h);
            b.push({g, h});
        }

        return d;
    }
};