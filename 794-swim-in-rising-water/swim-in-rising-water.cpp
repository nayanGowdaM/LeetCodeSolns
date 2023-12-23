
typedef pair<int,pair<int,int>> ppi;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<ppi,vector<ppi>, greater<ppi>>q;
        int n=grid.size();
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        q.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty()){
            int mx=q.top().first ,i=q.top().second.first,j=q.top().second.second;
            q.pop();
            if(i==n-1 && j==n-1) return mx;
            for(int k=0;k<4;k++){
                int newR=i+dir[k][0],newC=j+dir[k][1];
                if(newR>=0 && newR<n && newC<n && newC>=0 && !vis[newR][newC]){
                    int maxVal=max(grid[newR][newC], mx);
                    q.push({maxVal,{newR,newC}});
                    vis[newR][newC]=1;
                }
            }
        }
        return 0;
    }
};