class Solution {
    bool exist( string& s, int n, int i, int j, vector<vector<char>>& a){
        if(n==0) return true;
        if(a[i][j]!=s[n-1]) return false;
        a[i][j]='-';
        int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
        bool ans=false;
        for( int d=0;d<4;d++){
            int ii=i+dir[d][0], jj=j+dir[d][1];
            if( (ii>=0 && ii<a.size()) && ( jj>=0 && jj<a[0].size())) {
                if(exist(s,n-1,ii,jj,a)){
                    a[i][j]=s[n-1];
                    return true;
                }
            }
        }
        a[i][j]=s[n-1];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // vector<vector<int>>v;
        int n=word.size();
        bool ans = false;
        if(n==1){
        for( int i=0;i<board.size(); i++){
            for( int j=0;j<board[0].size();j++){
                if( board[i][j]==word[0]) return true;
            }
        }
        return false;
        }
        for( int i=0;i<board.size(); i++){
            for( int j=0;j<board[0].size();j++){
                if( exist(word,n, i,j,board)) return true;
            }
        }
        return false;
    }
};