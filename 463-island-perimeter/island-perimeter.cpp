class Solution {

    int bfs( vector<vector<int>>& grid,int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = -1;
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int ans=0;
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            int ct = 4;
            for(int k =0 ;k<4;k++){
                int x=i+dir[k][0] , y = j+dir[k][1];
                if( x>=0 && x<m && y>=0 && y<n ) {
                    if( grid[x][y] != 0)
                    ct--;
                    if(grid[x][y] == 1){
                        grid[x][y] = -1;
                        q.push({x,y});
                    }
                }
            }
            // cout<<i<<" "<<j<<" "<< ct<<endl;
            ans += ct;

        }

        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for( int  i=0;i<grid.size();i++){
            for( int j=0;j<grid[0].size();j++){
                if( grid[i][j]) return bfs( grid ,i,j);
            }
        }
        return 0;
    }
};