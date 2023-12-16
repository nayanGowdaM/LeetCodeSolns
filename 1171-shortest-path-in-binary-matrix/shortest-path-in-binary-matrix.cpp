class Solution {
    bool check(int i, int r, int j, int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[n-1][n-1]||grid[0][0])return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        while(!q.empty()){
            int d=q.top().first,x=q.top().second.first,y=q.top().second.second;
            q.pop();
            if(check(x-1,n,y,n) && !grid[x-1][y] && 1+d<dist[x-1][y]){
                dist[x-1][y]=d+1;
                q.push({1+d,{x-1,y}});
            }
            if(check(x+1,n,y,n) && !grid[x+1][y] && 1+d<dist[x+1][y]){
                dist[x+1][y]=d+1;
                q.push({1+d,{x+1,y}});
            }
            if(check(x,n,y-1,n) && !grid[x][y-1] && 1+d<dist[x][y-1]){
                dist[x][y-1]=d+1;
                q.push({1+d,{x,y-1}});
            }
            if(check(x,n,y+1,n) && !grid[x][y+1] && 1+d<dist[x][y+1]){
                dist[x][y+1]=d+1;
                q.push({1+d,{x,y+1}});
            }
            if(check(x-1,n,y-1,n) && !grid[x-1][y-1] && 1+d<dist[x-1][y-1]){
                dist[x-1][y-1]=d+1;
                q.push({1+d,{x-1,y-1}});
            }
            if(check(x+1,n,y-1,n) && !grid[x+1][y-1] && 1+d<dist[x+1][y-1]){
                dist[x+1][y-1]=d+1;
                q.push({1+d,{x+1,y-1}});
            }
            if(check(x-1,n,y+1,n) && !grid[x-1][y+1] && 1+d<dist[x-1][y+1]){
                dist[x-1][y+1]=d+1;
                q.push({1+d,{x-1,y+1}});
            }
            if(check(x+1,n,y+1,n) && !grid[x+1][y+1] && 1+d<dist[x+1][y+1]){
                dist[x+1][y+1]=d+1;
                q.push({1+d,{x+1,y+1}});
            }
        }

        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;
    }
};