class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        for( int i=m-1;i>=0;i--){
            for( int j=n-1;j>=0;j--){
                if( i+1 <m && grid[i][j]!=grid[i+1][j]) return false;
                if( j+1 <n && grid[i][j]==grid[i][j+1]) return false;
            }
        }
        return true;
    }
};