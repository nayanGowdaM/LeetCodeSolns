class Solution {
    int dp[367];
    int solve( int n , vector<int>& day, vector<int>& costs){
        if( n>365) return 0;
        if(dp[n]!=-1) return dp[n];
        if(day[n]==0) return dp[n] =  solve(n+1, day,costs);
        return dp[n] = min(costs[0] + solve(n+1,day, costs) , 
            min( costs[1] + solve(n+7,day,costs), costs[2]+ solve(n+30,day, costs)));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>day(366);
        memset(dp,-1, sizeof(dp));
        for(auto& x: days) day[x]=1;
        return solve(1,day, costs);
    }
};