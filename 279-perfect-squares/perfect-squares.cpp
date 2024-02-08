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

        vector<int> dp(n+1,-1);
        dp[n]=0;
        for( int i=n-1;i>=0;i--){
            int ans= INT_MAX;
            for( int j=1;j*j<=(n-i);j++){
                ans=min(ans, 1+dp[i+j*j]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};