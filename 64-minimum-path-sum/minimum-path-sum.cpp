class Solution {
    int dp[202][202];
    int solve(vector<vector<int>>& a,int m,int n){
        if(m==0 && n==0) return a[m][n];
        int ct1=INT_MAX,ct2=INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        if(n) ct1=dp[m][n-1]=solve(a,m,n-1);
        if(m) ct2=dp[m-1][n]=solve(a,m-1,n);
        return dp[m][n]=a[m][n]+ min(ct1,ct2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,grid.size()-1,grid[0].size()-1);
    }
};