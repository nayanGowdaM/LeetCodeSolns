int dp[1002][1002];
class Solution {
    int solve(int n, int next, vector<vector<int>>& a){
        if(n==0) return 0;
        if(dp[n][next]!=-1) return dp[n][next];
        if(next==a.size() || a[next][0]> a[n-1][1]) 
        return dp[n][next] = max( solve(n-1, n-1,a)+1, solve( n-1,next, a));
        return dp[n][next] = solve( n-1,next,a);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(), pairs.end());
        return solve( pairs.size(), pairs.size(), pairs);
    }
};