class Solution {
    int dp[20];
    int solve( int n){
        if(n<1) return 1;
        if(n==1 || n==2) return n;
        int ans=0;
        if(dp[n]!=-1) return dp[n];
        for( int k=0;k<n;k++){
            ans += solve( k) * solve(n-k-1);
        }
        return dp[n]=ans;
    }
public:
    int numTrees(int n) {
        // memset(dp, -1,sizeof(dp));
        // return solve(n);

        vector<int > dp( n+1, 0);
        dp[0]=dp[1]=1;
        for( int i=2;i<=n;i++){
            for( int j=1;j<=i;j++){
                dp[i]+=dp[j-1] * dp[i-j];
            }
        }
        return dp[n];

    }
};