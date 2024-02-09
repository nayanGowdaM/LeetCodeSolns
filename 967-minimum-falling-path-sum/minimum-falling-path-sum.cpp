class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& dp) {
        int m=dp.size(), n=dp[0].size();
        for( int i=1;i<m;i++){
            for ( int j=0;j<n;j++){
                if( j>0 && j+1<n) dp[i][j] += min( dp[i-1][j-1],min( dp[i-1][j],dp[i-1][j+1]));
                else if( j>0) dp[i][j]+= min( dp[i-1][j],dp[i-1][j-1]);
                else dp[i][j] += min(dp[i-1][j], dp[i-1][j+1]); 
            }
        }
        return *min_element( dp[m-1].begin(), dp[m-1].end());
    }
};