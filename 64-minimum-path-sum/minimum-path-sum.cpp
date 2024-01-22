class Solution {
    int dp[202][202];
    int solve(vector<vector<int>>& a,int m,int n){
        if(m==0 && n==0) return a[m][n];
        int ct1=INT_MAX,ct2=INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        if(n) ct1=dp[m][n-1]=solve(a,m,n-1);
        if(m) ct2=dp[m-1][n]=solve(a,m-1,n);
        return dp[m][n]=a[m][n]+ min(ct1,ct2);
    }
public:
    int minPathSum(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int dp[m+1][n+1];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=a[i][j];
                else {
                    if(j && i) dp[i][j]=a[i][j] + min(dp[i-1][j],dp[i][j-1]);
                    else if(j) dp[i][j]=a[i][j]+dp[i][j-1];
                    else dp[i][j]=a[i][j]+dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];


    }
};