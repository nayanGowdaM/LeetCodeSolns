int dp[100002][2][3];

class Solution {
    int solve(int i, bool buy, int m, vector<int>& st){
        if(i==st.size() || m==0) return 0;
        if(dp[i][buy][m]!=-1) return dp[i][buy][m];
        int profit;
        if(!buy){
            profit = max( -st[i] + solve(i+1,true, m, st), solve(i+1,false, m, st));
        } 
        else profit = max( +st[i] + solve(i+1,false, m-1,st), solve(i+1,true, m, st));
        return dp[i][buy][m]= profit;
    }
public:
    int maxProfit(vector<int>& st) {
        memset(dp,-1,sizeof(dp));
        return solve(0, false, 2, st);
    }
};