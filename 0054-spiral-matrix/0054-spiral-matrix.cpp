class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int srow = 0, scol = 0;
        int erow = n - 1, ecol = m - 1;
        vector<int> results;
        while(srow <= erow && scol <= ecol){
            for(int j = scol; j <= ecol; j++){
                results.push_back(matrix[srow][j]);
            }

            for(int i = srow + 1; i <= erow; i++){
                results.push_back(matrix[i][ecol]);
            }

            if(srow < erow){
                for(int j = ecol - 1; j >= scol; j--){
                results.push_back(matrix[erow][j]);
                }
            }

            if(scol < ecol){
                for(int i = erow - 1; i > scol; i--){
                results.push_back(matrix[i][scol]);
                }
            }

            srow++,scol++;
            erow--,ecol--;
        }
        return results;
    }
};