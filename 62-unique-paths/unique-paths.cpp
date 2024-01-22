class Solution {
    int dp[101][101];
    int path(int i,int j){
        if(i==0 && j==0) return 0;
        if((i==0 && j==1)  || (j==0 && i==1)) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ct1=0,ct2=0;
        if(i>0) ct1=path(i-1,j);
        if(j>0) ct2=path(i,j-1);
        return dp[i][j]=ct1+ct2;
    }
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        // memset(dp,-1,sizeof(dp));
        // return path(m-1,n-1);
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++) {
            dp[i][0] = 0;
            dp[i][1]= 1;
        }
        for(int i=0;i<=n;i++) {
            dp[0][i]=0;
            dp[1][i]=1;

        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];

    }
};