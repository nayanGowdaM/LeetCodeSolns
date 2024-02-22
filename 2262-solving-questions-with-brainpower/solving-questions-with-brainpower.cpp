class Solution {
    long long  dp[100002];
    long long  solve(int n, vector<vector<int>>& q){
        if(n>q.size()) return 0;
        if(dp[n]!=-1) return dp[n];
        long long notTake =  solve(n+1, q);
        long long  take =  q[n-1][0] + solve( n+ q[n-1][1]+1, q);
        return dp[n] =  max( notTake, take );
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
        memset(dp, -1,sizeof(dp));
        return solve( 1, q);
    }
};