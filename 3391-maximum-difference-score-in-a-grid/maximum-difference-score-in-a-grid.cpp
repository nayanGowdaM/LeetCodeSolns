class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int m=grid.size(), n = grid[0].size();
        vector<vector<int>> hash( m, vector<int>(n,0));
        for( int i=m-1;i>=0;i--){
            for( int j=n-1;j>=0;j--){
                if( i==m-1 && j==n-1) hash[i][j] = grid[i][j];
                else {
                    int temp=INT_MIN;
                    if( i+1 < m) temp = max( temp, hash[i+1][j]);
                    if( j+1 < n) temp = max( temp, hash[i][j+1]);
                    ans = max( ans, temp-grid[i][j]);
                    hash[i][j] = max( grid[i][j] ,temp );
                }
            }
        }

        

        return ans;
    }
};