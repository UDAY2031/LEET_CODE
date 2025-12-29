class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> trans;
        for (auto& s : allowed) {
            trans[s.substr(0, 2)].insert(s[2]);
        }
        
        unordered_map<string, bool> memo;
        function<bool(string)> dfs = [&](string row) -> bool {
            if (row.size() == 1) return true;
            if (memo.count(row)) return memo[row];
            
            string next = "";
            function<bool(int)> build = [&](int i) -> bool {
                if (i == row.size() - 1) {
                    return dfs(next);
                }
                string key = row.substr(i, 2);
                if (!trans.count(key)) return false;
                for (char c : trans[key]) {
                    next.push_back(c);
                    if (build(i + 1)) return true;
                    next.pop_back();
                }
                return false;
            };
            
            bool res = build(0);
            return memo[row] = res;
        };
        
        return dfs(bottom);
    }
};