class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        if(a[m-1][n-1] || a[0][0]) return 0;
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(!i && !j && !a[i][j]) dp[i][j]=1;
                else if(!a[i][j]){
                    if(i) dp[i][j]+=dp[i-1][j];
                    if(j) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};