class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size();
        vector<vector<int>>dp(m+3,vector<int>(n+4,INT_MAX));
        for(int i=0;i<=n+1;i++) dp[0][i]=0;
        for(int i=1;i<=m ; i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=a[i-1][j-1] + min(dp[i-1][j-1], min(dp[i-1][j],dp[i-1][j+1]));
            }
        }
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return *min_element(dp[m].begin(),dp[m].end());
    }
};