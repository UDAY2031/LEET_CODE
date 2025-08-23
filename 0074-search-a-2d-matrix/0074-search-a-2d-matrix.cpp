class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m-1;

        while(row < n && col >= 0){
            int start = matrix[row][col];

            if(start == target){
                return true;
            }else if(start > target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};