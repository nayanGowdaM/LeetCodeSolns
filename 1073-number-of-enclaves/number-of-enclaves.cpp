class Solution {
    bool check(int i, int r, int j, int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    void dfs(int r, int c , vector<vector<int >>& a, vector<vector<int>>& vis){
        int m=a.size(), n=a[0].size();
        vis[r][c]=1;
        if(check(r-1,m, c, n) && !vis[r-1][c] && a[r-1][c]) dfs(r-1,c , a, vis);
        if(check(r+1,m,c,n)  && !vis[r+1][c] && a[r+1][c])  dfs(r+1,c,a,vis);
        if(check(r,m,c-1,n)  && !vis[r][c-1] &&  a[r][c-1]) dfs(r,c-1,a,vis);
        if(check(r , m,c+1,n) && !vis[r][c+1] && a[r][c+1]) dfs(r,c+1,a,vis);
    }
    // void dfs(int r,int c, vector<vector<int>>& vis, vector<vector<int>>& a){
    //     int m=a.size(),n=a[0].size();
    //     vis[r][c] = 1;
    //     if(check(r-1,m, c,n) && !vis[r-1][c]   && a[r-1][c]) dfs(r-1,c,vis,a);
    //     if(check(r+1,m, c,n) && !vis[r+1][c]   && a[r+1][c]) dfs(r+1,c,vis,a);
    //     if(check(r,m, c-1,n) && !vis[r][c-1]   && a[r][c-1]) dfs(r,c-1,vis,a);
    //     if(check(r,m, c+1,n) && !vis[r][c+1]   && a[r][c+1]) dfs(r,c+1,vis,a);
    // }
public:
    int numEnclaves(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size(), ct=0;
        if(m<=2 || n<=2) return ct;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int j=0;j<n;j++){
            if(!vis[0][j] && a[0][j] ) dfs(0,j, a,vis);
            if(!vis[m-1][j] && a[m-1][j] ) dfs(m-1,j,a, vis);
        }
        for(int i=0;i<m;i++){
            if(!vis[i][0] && a[i][0]) dfs(i, 0, a, vis);
            if(!vis[i][n-1] && a[i][n-1]) dfs(i,n-1,a, vis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] ) ct+=a[i][j];
            }
        }
        return ct;
        // int m=a.size(), n=a[0].size(),ct=0;
        // vector<vector<int>>vis(m,vector<int>(n,0));
        // for(int j=0;j<n;j++){
        //     if(a[0][j]){
        //         dfs(0,j,vis,a);
        //     }
        //     if(a[m-1][j]) dfs(m-1,j,vis,a);
        // }
        // for(int j=0;j<m;j++){
        //     if(a[j][0]){
        //         dfs(j,0,vis,a);
        //     }
        //     if(a[j][n-1]) dfs(j,n-1,vis,a);
        // }
        // for(int i=0;i<m;i++){
        //     for (int j=0;j<n;j++){
        //         if(!vis[i][j] && a[i][j] ) ct++;
        //     }
        // }
        // return ct;
    }
};