int dp[502][502];

class Solution {
    int solve(int m, int n, string& a,string& b){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[m][n]!=-1) return dp[m][n];
        if(a[m-1]==b[n-1]) return dp[m][n]=solve(m-1,n-1,a,b);
        else return dp[m][n]= min(solve(m-1,n-1,a,b), min(solve(m-1,n, a,b),solve(m,n-1,a,b))) + 1;
    }
public:
    int minDistance(string a, string b) {
        // int m=a.size(),n=b.size();
        memset(dp, -1,sizeof(dp));
        return solve(a.size(),b.size(),a,b);
    }
};