class Solution {
    vector<vector<string>> ans;
    
    bool check( int row, int col,vector<string>& res){
        //check col

        for( int i=0;i<row;i++) if( res[i][col]=='Q') return false;
        //left upside
        for( int i=row-1,j=col-1 ;i>=0 && j>=0 ;i--, j--) if( res[i][j]=='Q') return false;

        //rightside upside
        for( int i=row-1, j=col+1;i>=0 && j<res[0].size();i--, j++) if( res[i][j]=='Q') return false;
        return true;
    }

    void solve( int row,vector<string>& res){
        if( row == res.size()){
            ans.push_back( res);
            return ;
        }
        for( int i=0;i<res.size();i++){
            if( check( row, i, res)){
                res[row][i] = 'Q';
                solve( row+1, res);
                res[row][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string x = "";
        for( int i=0;i<n;i++) x.push_back('.');
        vector<string> res( n, x);
        solve( 0, res);
        return ans;

    }
};