// int dp[30002][2];

class Solution {
    // int solve(int n, vector<int>& st  ,  bool sold){
    //     if(n==0) return 0;
    //     if(n==1) {
    //         if(!sold) return 0;
    //         else return -st[0];
    //     }
    //     if(dp[n][sold]!=-1) return dp[n][sold]; 
    //     int profit;
    //     if(!sold){
    //         profit =  max(st[n-1] + solve(n-1, st, true), solve(n-1,st, false));
    //     }
    //     else {
    //         profit = max(-st[n-1] + solve(n-1,st, false), solve(n-1, st, sold));
    //     }
    //     return dp[n][sold] = profit;
    // }
public:
    int maxProfit(vector<int>& st, int fee) {
        // memset(dp,-1,sizeof(dp));
        // int n=st.size();
        // return solve(n, st, 0);


        int n=st.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        dp[n][0]=dp[n][1]=0;
        int buy=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[i][buy] = max( -st[i] + dp[i+1][0] , dp[i+1][1]);
                    
                } 
                else dp[i][buy] = max( st[i]-fee + dp[i+1][1] , dp[i+1][0]);
            }
        } 
        return dp[0][1];
    }
};