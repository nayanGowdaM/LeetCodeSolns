class Solution {
public:
    bool check(int i, int r, int j, int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int good=0,m=grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>, int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 ) good++;
                else if(grid[i][j]==2){ q.push({{i,j},0}); }
            }
        }
        int i,j,t=0;
        while(!q.empty()){
            i=q.front().first.first;
            j=q.front().first.second;
            t=q.front().second;
            q.pop();
            if(check(i-1,m,j,n) && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({{i-1,j},t+1});
                good--;
            }
            if(check(i+1,m,j,n) && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({{i+1,j},t+1});
                good--;
            }
            if(check(i,m,j-1,n) && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({{i,j-1},t+1});
                good--;

            }
            if(check(i,m,j+1,n) && grid[i][j+1] == 1){
                grid[i][j+1]=2;
                q.push({{i,j+1},t+1});
                good--;
            }
        }
        if(good) return -1;
        return t;
    }
};