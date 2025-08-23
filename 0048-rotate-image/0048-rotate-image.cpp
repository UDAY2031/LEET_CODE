class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            int left = 0, right = n - 1;
            while(left < right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};