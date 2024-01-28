int dp[2002][2002];

class Solution {
    bool solve(int m, int n, string& a, string& b){
        if(n==0 && m==0) return true;
        if(n==0) return false;
        if(m==0){
            if(b[n-1]=='*' ) return solve(m,n-1,a,b);
            else return false;
        }
        if(dp[m][n]!=-1) return dp[m][n] ;
        if(a[m-1]==b[n-1] ) return  dp[m][n] = solve(m-1,n-1,a,b);
        else if(b[n-1] >='a'  && b[n-1] <= 'z') return dp[m][n] =  false;
        else if(b[n-1]=='?') return  dp[m][n] = solve(m-1,n-1,a,b);
        return dp[m][n] =  ( solve(m-1,n,a,b)  ||  solve(m, n-1,a,b));
    }
public:
    bool isMatch(string a, string b) {
        // memset(dp,-1,sizeof(dp));
        // return solve(s.size(),p.size(),s,p);

        int m=a.size(), n=b.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) {
            if(b[i-1]=='*') dp[0][i]=dp[0][i-1];
            else dp[0][i]=0;
        }
        for(int i=1;i<=m ;i++) dp[i][0] = 0 ;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1] ) dp[i][j] = dp[i-1][j-1];
                else if(b[j-1]>='a' && b[j-1]<='z') dp[i][j]=0;
                else if(b[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[m][n];


    }
};