class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        // vector<vector<int>>vis(m, vector<int>(n,0));
        queue<pair<int,int>>nq,q;
        int ans = 0;
        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++) if( grid[i][j]==2) nq.push( {i,j});
        }

        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        while(!nq.empty()){
            // queue<pair<int,int>> q;
            while(!nq.empty()){
                auto node = nq.front();
                nq.pop();
                for( int i=0;i<4;i++){
                    int x = node.first + dir[i][0] , y = node.second + dir[i][1];
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty()){
                ans++;
            }
            swap( q, nq);
        }
        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++) if( grid[i][j]==1) return -1;
        }
        return ans;
    }
};