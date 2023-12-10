class Solution {
    bool check(int i, int r, int j, int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j] =1;
                    q.push({{i,j},0});
                    
                }
            }
        vector<vector<int>> ans(m, vector<int> (n,0));
        while(!q.empty()){
            int i=q.front().first.first, j=q.front().first.second, f=q.front().second;
            q.pop();
            if(check(i-1,m, j, n) && !vis[i-1][j]){
                ans[i-1][j]=f+1;
                q.push({{i-1,j},f+1});
                vis[i-1][j]=1;
            }
            if(check(i+1,m, j, n) && !vis[i+1][j]){
                ans[i+1][j]=f+1;
                q.push({{i+1,j},f+1});
                vis[i+1][j]=1;
            }
            if(check(i,m, j-1, n) && !vis[i][j-1]){
                ans[i][j-1]=f+1;
                q.push({{i,j-1},f+1});
                vis[i][j-1]=1;
            }
            if(check(i,m, j+1, n) && !vis[i][j+1]){
                ans[i][j+1]=f+1;
                q.push({{i,j+1},f+1});
                vis[i][j+1]=1;
            }
        }
        return ans;
    }
};