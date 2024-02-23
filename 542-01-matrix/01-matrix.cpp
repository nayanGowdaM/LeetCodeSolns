class Solution {
typedef  pair<pair<int,int>, int> ppi;
bool is_valid( int row, int col , int m,int n){
    return row>=0 && row<m && col>=0 && col<n;
}
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int loc[][2]={{-1,0},{0,1},{1,0}, {0,-1}};
        vector<vector<int>>  ans(m, vector<int>(n,-1));
        queue<ppi> q;
        for( int i=0;i<m;i++) {
            for( int j=0;j<n;j++) {
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto x=q.front().first.first, y=q.front().first.second, dist=q.front().second;
            q.pop();
            for( auto& move: loc){
                int row=x+move[0], col=y+move[1];
                if(is_valid(row, col,m, n) && ans[row][col] == -1){
                    ans[row][col] = dist+1;
                    q.push({{row,col}, dist+1});
                }
            }
        }
        return ans;
    }
};