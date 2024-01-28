int dp[2002][2002];

class Solution {
    bool solve(int m, int n, string& a, string& b){
        if(n==0 && m==0) return true;
        if(n==0) return false;
        if(m==0){
            if(b[n-1]=='*' ) return solve(m,n-1,a,b);
            else return false;
        }
        if(dp[m][n]!=-1) return dp[m][n] ;
        if(a[m-1]==b[n-1] ) return  dp[m][n] = solve(m-1,n-1,a,b);
        else if(b[n-1] >='a'  && b[n-1] <= 'z') return dp[m][n] =  false;
        else if(b[n-1]=='?') return  dp[m][n] = solve(m-1,n-1,a,b);
        return dp[m][n] =  ( solve(m-1,n,a,b)  ||  solve(m, n-1,a,b));
    }
public:
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s.size(),p.size(),s,p);
    }
};