class Solution {
    vector<vector<string>> ans;

    bool check( vector<string>& res, int row, int col){
        //row check 
        for( int i=0;i<row;i++)  if( res[i][col]=='Q') return false;
        //column check
        // for( int i=0;i<res.size();i++) if( res[row][i]=='Q' && i!=col) return false;
        int x = row-1, y = col-1 ;
        while( x>=0 && y>=0) {
            if(res[x][y]=='Q' ) return false;
            x--;
            y--;
        }
        x=row-1,y=col+1;
        while( x>=0 && y<res.size()){
            if( res[x][y]=='Q') return false;
            x--;
            y++;
        }
        return true;
    }

    void solve(int row, vector<string>& res){
        int n = res.size();
        if( row == n){
            ans.push_back(res);
            return ;
        }
        string s(n, '.');

        for( int i=0;i<n;i++){
            // s[i]='Q';
            res[row][i]='Q';
            if( check( res, row, i)){
                solve( row+1, res);
            }
            // s[i]='.';
            res[row][i]='.';
        }

    }

public:
    vector<vector<string>> solveNQueens(int n) {
        if( n==1) return {{"Q"}};
        else if( n==2 || n==3) return ans;
        vector<string> res(n,string ( n, '.'));
        solve( 0, res );
        return ans;
    }
};