class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1;

        while(row < n && col >= 0){
            int mid = matrix[row][col];

            if(mid == target){
                return true;
            }else if(mid > target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};