class Solution {
    int solve(int n){
        if(n==0 || n==1 || n==2) return n;
        if(dp[n]!=-1) return dp[n];
        if(dp[n-1]==-1) dp[n-1]=solve(n-1);
        if(dp[n-2]==-1) dp[n-2]=solve(n-2);
        return dp[n]=dp[n-1]+dp[n-2];
    }
public:
    int dp[46];
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);

    }
};