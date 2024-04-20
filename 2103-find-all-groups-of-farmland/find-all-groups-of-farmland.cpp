class Solution {
    vector<int> ans={-1,-1,-1,-1};
    vector<vector<int>> dir={{0,1}, {0,-1}, {1,0},{-1,0}};
    bool topLeft(int x,int y, vector<vector<int>>& land){
        if((x==0 && y==0) || (x==0 && y>0 && land[x][y-1]==0) || ( x>0 && y==0 && land[x-1][y]==0) ||( x>0 && y>0 && land[x][y-1] == 0 && land[x-1][y] == 0) ) return true;
        else return false;
    }

    bool bottomRight(int x,int y, vector<vector<int>>& land){
        int m=land.size() , n=land[0].size();
        if((x==m-1 && y==n-1) || (x==m-1 && y<n-1 && land[x][y+1]==0) || ( x<m-1 && y==n-1 && land[x+1][y]==0) ||( x<m-1 && y<n-1 && land[x+1][y] == 0 && land[x][y+1]==0) ) return true;
        else return false;
    }
    void dfs( vector<vector<int>>& land, vector<vector<bool>>& vis, pair<int,int>src){
        int i=src.first, j=src.second;
        vis[i][j]=true;
        if(topLeft(i,j, land)) {
            ans[0]=i;
            ans[1]=j;
        }
        if(bottomRight(i,j, land)){
            ans[2]=i;
            ans[3]=j;
        }
        for( int k=0;k<4;k++){
            int x = i+dir[k][0] , y=j+dir[k][1];
            if(x>=0 && y>=0 && x<land.size()&& y<land[0].size() && land[x][y] && !vis[x][y] ){
                dfs( land, vis, {x,y});
            }
        }

    } 
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size(), n=land[0].size();
        vector<vector<bool>>vis( m, vector<bool>(n, false));
        vector<vector<int>>res;
        for( int i=0; i<m;i++){
            for( int j=0;j<n;j++){
                if( !vis[i][j] && land[i][j]){
                    dfs( land, vis, {i,j});
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};