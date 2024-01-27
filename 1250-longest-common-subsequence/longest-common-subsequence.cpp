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

        // memset(dp,-1,sizeof(dp));
        // return solve(a.size(), b.size(),a,b);

        int m=a.size(), n=b.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++)  dp[i][0]=0;
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1] ) dp[i][j] = 1 +dp[i-1][j-1];
                else dp[i][j] =  max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};