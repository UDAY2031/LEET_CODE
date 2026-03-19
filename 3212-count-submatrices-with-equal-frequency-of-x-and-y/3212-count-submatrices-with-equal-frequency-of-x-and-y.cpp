class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> xPref(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> yPref(rows + 1, vector<int>(cols + 1, 0));
        int validCount = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                xPref[i + 1][j + 1] = xPref[i][j + 1] + xPref[i + 1][j] - xPref[i][j] + (grid[i][j] == 'X');
                yPref[i + 1][j + 1] = yPref[i][j + 1] + yPref[i + 1][j] - yPref[i][j] + (grid[i][j] == 'Y');

                if (xPref[i + 1][j + 1] > 0 && xPref[i + 1][j + 1] == yPref[i + 1][j + 1]) {
                    validCount++;
                }
            }
        }

        return validCount;
    }
};