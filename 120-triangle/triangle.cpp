class Solution {
    int dp[202][202];
    int solve(int m,int n, int l, vector<vector<int>>& a){
        if(m==l) return a[m][n];
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=a[m][n]+min(solve(m+1,n,l,a),solve(m+1,n+1,l,a));
    }
public:
    int minimumTotal(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,a.size()-1,a);
    }
};