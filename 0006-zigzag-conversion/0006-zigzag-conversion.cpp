class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int r = 0;
        bool down = true;

        for (char c : s) {
            rows[r].push_back(c);
            if (r == 0) down = true;
            else if (r == numRows - 1) down = false;
            r += down ? 1 : -1;
        }

        string result;
        for (auto &row : rows) result += row;
        return result;
    }
};