int dp[10002];
class Solution {
    int solve( int sum,int target){
        if( sum== target ) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ans=INT_MAX;
        for( int i=1;i*i<= ( target-sum) ;i++){
            ans =  min( ans, solve( sum + i*i, target));
        }
        return dp[sum] = ans + 1;
    }
public:
    int numSquares(int n) {
        memset( dp,-1,sizeof(dp));
        return solve( 0,n);
    }
};