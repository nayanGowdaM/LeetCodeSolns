class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int m=a.size(), n=a[0].size(),ans=0;
        vector<vector<int>> dp(m, vector<int> ( n));
        for( int i=0;i<m;i++) dp[i][0] = a[i][0]=='0' ? 0: 1; 
        for( int j=0;j<n;j++) dp[0][j] =  a[0][j]=='0' ? 0:1;
        for( int i=1;i<m;i++){
            for( int j=1;j<n;j++){
                if( a[i][j]=='1' ) dp[i][j] = 1 + min( dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
                ans=max(ans, dp[i][j]);
            }
        }
        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++) ans=max(ans, dp[i][j]);
        }
        return ans*ans;
    }
};