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
    int maxProfit(vector<int>& st,int fee) {
        // memset(dp,-1,sizeof(dp));
        // int n=st.size();
        // return solve(n, st, 0);


        int n=st.size();
        // vector<vector<int>> dp(n+1,vector<int>(3,-1));
        vector<int> cur(3,-1),next(3,0);
        int buy=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    cur[buy] = max( -st[i] + next[0] , next[1]);
                    
                } 
                else cur[buy] = max( st[i] - fee + next[1] , next[0]);
            }
            next=cur;
        } 
        return cur[1];
    }
};