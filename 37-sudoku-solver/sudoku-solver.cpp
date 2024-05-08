class Solution {
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == val) return false;
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col){
        if( row == 9) return true;
        if( col == 9) { return solve( board, row+1,0); }
        if( board[row][col]!='.' ){
            return solve( board, row, col+1);
        }
        for(char c='1';c<='9';c++){
            if( check(board, row,col, c)){
                board[row][col]=c;
                if(solve( board, row , col+1)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve( board, 0,0);
        
    }
};