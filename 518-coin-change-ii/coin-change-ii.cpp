int dp[302][5002];

class Solution {
    int solve(int n, int amt, vector<int>& coins){
        if(amt==0) return 1;
        if(n<0) return 0;
        if(dp[n][amt]!=-1) return dp[n][amt]; 
        if(amt>=coins[n]) return  dp[n][amt] = solve(n,amt-coins[n],coins) + solve(n-1,amt, coins);
        else return dp[n][amt] = solve(n-1,amt,coins);
    }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(coins.size()-1,amount, coins);
    }
};