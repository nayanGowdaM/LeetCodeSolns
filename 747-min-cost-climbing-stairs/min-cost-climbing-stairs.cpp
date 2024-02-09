class Solution {
    int solve( int n, vector<int>& a){
        if( n==0 || n==1) return a[n];
        return a[n] + min( solve( n-1,a), solve(n-2,a));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // return min(solve( cost.size()-1, cost) , solve( cost.size()-2, cost));

        int n=cost.size();
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1]= cost[1];
        for( int i=2;i<n;i++){
            dp[i] = cost[i] + min( dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};