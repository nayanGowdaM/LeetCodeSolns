class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        if(amt==0) return 0;
        if(n==0 ) return -1; 
        int dp[n+1][amt+1];
        for(int i=0;i<=amt;i++) dp[0][i]=INT_MAX-1;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amt;j++){
                if(coins[i-1]<=j) dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amt]>=INT_MAX-1 ? -1 : dp[n][amt];
    }
};