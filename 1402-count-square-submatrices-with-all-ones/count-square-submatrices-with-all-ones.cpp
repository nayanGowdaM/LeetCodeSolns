class Solution {
public:
    int countSquares(vector<vector<int>>& dp) {
        int m =dp.size(), n=dp[0].size();
        // vector<vector<int>> dp(m, vector<int> (n,0));
        for(int i=1;i<m;i++){
            for( int j=1;j<n;j++){
                if(dp[i][j])
                dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1;
            }
        }
        int sum=0;
        for(auto& x: dp) for( auto& y:x) sum+=y;
        return sum;
    }
};