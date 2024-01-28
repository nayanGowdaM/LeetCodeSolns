int dp[502][502];

class Solution {
    int solve(int m, int n, string& a,string& b){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[m][n]!=-1) return dp[m][n];
        if(a[m-1]==b[n-1]) return dp[m][n]=solve(m-1,n-1,a,b);
        else return dp[m][n]= min(solve(m-1,n-1,a,b), min(solve(m-1,n, a,b),solve(m,n-1,a,b))) + 1;
    }
public:
    int minDistance(string a, string b) {
        // int m=a.size(),n=b.size();
        // memset(dp, -1,sizeof(dp));
        // return solve(a.size(),b.size(),a,b);

        int m=a.size(), n=b.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        for(int i=0;i<=n;i++) dp[0][i]=i;
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]= min( dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) +1 ;
            }
        }
        return dp[m][n];
    }
};