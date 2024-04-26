class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for( int i=1;i<m;i++){
            for( int j=0;j<n;j++){
                if(j==0){
                    grid[i][j]+=*min_element(grid[i-1].begin()+1, grid[i-1].end());
                }
                else if( j==n-1){
                    grid[i][j] += *min_element( grid[i-1].begin(), grid[i-1].end()-1);
                }
                else{
                    int left = *min_element( grid[i-1].begin(), grid[i-1].begin()+j), right = *min_element( grid[i-1].begin()+j+1, grid[i-1].end());
                    grid[i][j] += min(left, right);
                }
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }

        // for( int i=0;i<m;i++){
        //     for( int j=0;j<n;j++) cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        return *min_element(grid[m-1].begin(), grid[m-1].end());
    }
};