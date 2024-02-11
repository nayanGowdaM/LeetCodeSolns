int dp[1002][1002];

class Solution {
    int sumascii(int m, string& a){
        int ans=0;
        for( int i=0;i<m;i++) ans+=a[i];
        return ans;
    }
    int solve(int m, int n, string& a, string& b){
        if( m==0) return sumascii( n, b);
        if( n==0) return sumascii( m, a);
        if( dp[m][n]!=-1) return dp[m][n];
        int match=INT_MAX;
        if( a[m-1]==b[n-1])  match = solve( m-1,n-1, a,b);
        int notMatch =  min( solve(m, n-1, a,b) + b[n-1], solve( m-1,n, a,b)+a[m-1]);
        return dp[m][n] =  min( match, notMatch);
    }
public:
    int minimumDeleteSum(string a, string b) {
        memset( dp, -1, sizeof(dp));
        return solve( a.size(), b.size(), a, b);
    }
};