int dp[1002][1002];

class Solution {
    int solve( int m, int n, string& a, string& b){
        if( n==0 ) return 1;
        if( m==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int notTake=solve(m-1,n,a,b), take=0;
        if(a[m-1]==b[n-1]) take=solve( m-1,n-1,a,b);
        return dp[m][n] = notTake+take;
    }
public:
    int numDistinct(string s, string t) {
        memset( dp, -1,sizeof(dp));
        return solve( s.size(), t.size() , s, t);
    }
};