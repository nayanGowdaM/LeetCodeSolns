class Solution {
    vector<vector<int>> dir = {{ 0,1},{0,-1}, {1,0},{-1,0}};
    int m,n;
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, pair<int,int> src){
        vis[src.first][src.second] = true;
        
        for(int i=0;i<4 ;i++){
            int x = src.first + dir[i][0] , y=src.second + dir[i][1];

            if( x>=0 && x<m && y>=0 && y<n && !vis[x][y]  && grid[x][y]=='1') 
                dfs(grid, vis, {x,y});
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(m, vector<bool>( n,false));
        for( int i=0;i<m;i++){
            for( int j=0 ;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid, vis, {i,j});
                    ans++;
                }
            }
        }
        return ans;
    }
};