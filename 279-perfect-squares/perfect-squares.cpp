class Solution {
    int dp[101][10002];
    int solve( int i, int target){
        if( target==0) return 0;
        if( i*i>target) return INT_MAX-1;
        if(dp[i][target]!=-1) return dp[i][target];
        int take= 1 + solve(i, target-i*i );
        int notTake=solve(i+1, target);
        return dp[i][target] = min(take, notTake);
    }
public:
    int numSquares(int n) {
        memset(dp, -1,sizeof(dp));
        return solve(1, n);
    }
};