class Solution {
    int dp[100002][2][3];
    int solve( int n, bool buy, vector<int>& a,int ct){
        if(n>a.size()||ct==0) return 0;
        if(dp[n][buy][ct]!=-1) return dp[n][buy][ct];
        if(buy){
            return dp[n][buy][ct] = max( -a[n-1] + solve(n+1,!buy, a,ct), solve(n+1, buy, a, ct));
        }
        else return dp[n][buy][ct] = max(a[n-1] + solve(n+1,!buy, a,ct-1), solve(n+1, buy,a,ct));
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(1,true, prices, 2);
    }
};