class Solution {
public:
    bool isSafe(vector<string>& board, int n, int row, int col){

        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        for(int r = row-1, c = col-1; r >= 0 && c >= 0; r--,c--){
            if(board[r][c] == 'Q'){
                return false;
            }
        }
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void NQueens(vector<string>& board, int n, int row,vector<vector<string>>& results){
        if(row == n){
            results.push_back(board);
            return;
        }

        for(int j = 0;j < n; j++){
            if(isSafe(board,n,row,j)){
                board[row][j] = 'Q';
                NQueens(board,n,row+1,results);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> results;
        NQueens(board,n,0,results);
        return results;
    }
};