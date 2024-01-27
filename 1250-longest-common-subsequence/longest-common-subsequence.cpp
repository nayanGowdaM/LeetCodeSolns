int dp[1002][1002];

int solve( int m , int n, string& a, string& b){
    if(!m || !n) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(a[m-1]==b[n-1]) return dp[m][n] = 1+solve(m-1,n-1,a,b);
    else return dp[m][n] = max( solve(m-1,n, a, b) , solve(m,n-1,a,b));
}

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {

        memset(dp,-1,sizeof(dp));
        return solve(a.size(), b.size(),a,b);
    }
};