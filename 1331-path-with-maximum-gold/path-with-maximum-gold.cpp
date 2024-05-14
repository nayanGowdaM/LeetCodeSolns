class Solution {
    int res = 0;
    int dir[4][2] = { {0,1}, {0,-1},{1,0} , {-1,0} } ;
    void solve( vector<vector<int>>& grid, int row, int col , int& ans){
        res = max( res, ans);
        for(int i=0;i<4;i++){
            int x = row + dir[i][0]  , y = col + dir[i][1];
            if( x>=0 && y>=0 && x< grid.size() && y<grid[0].size() && grid[x][y] ){
                int gold = grid[x][y] ;
                ans += gold;
                grid[x][y] = 0;
                solve(grid, x, y, ans);
                grid[x][y] = gold;
                ans-=gold;

            }
        }
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        for( int i=0;i<grid.size();i++){
            for( int j=0;j<grid[0].size();j++){
                int ans = grid[i][j];
                int temp = ans;
                 if(ans){
                    grid[i][j]= 0;
                    solve(grid, i, j, ans );
                    grid[i][j] = temp;
                 }

            }

        }
        return res;
        
    }
};