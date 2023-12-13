class Solution {
    bool check(int i, int r,int j,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    void dfs(int r,int c, vector<vector<int>>& vis, vector<vector<char>>& a){
        int m=a.size(),n=a[0].size();
        vis[r][c] = 1;
        if(check(r-1,m, c,n) && !vis[r-1][c]   && a[r-1][c]=='O') dfs(r-1,c,vis,a);
        if(check(r+1,m, c,n) && !vis[r+1][c]   && a[r+1][c]=='O') dfs(r+1,c,vis,a);
        if(check(r,m, c-1,n) && !vis[r][c-1]   && a[r][c-1]=='O') dfs(r,c-1,vis,a);
        if(check(r,m, c+1,n) && !vis[r][c+1]   && a[r][c+1]=='O') dfs(r,c+1,vis,a);
    }
public:
    void solve(vector<vector<char>>& a) {
        int m=a.size(), n=a[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(a[0][j]=='O'){
                dfs(0,j,vis,a);
            }
            if(a[m-1][j]=='O') dfs(m-1,j,vis,a);
        }
        for(int j=0;j<m;j++){
            if(a[j][0]=='O'){
                dfs(j,0,vis,a);
            }
            if(a[j][n-1]=='O') dfs(j,n-1,vis,a);
        }
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(!vis[i][j] && a[i][j]=='O' ) a[i][j]='X';
            }
        }
        
    }
};