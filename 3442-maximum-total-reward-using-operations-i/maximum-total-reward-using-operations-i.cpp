class Solution {
    // int dp[2002][4002];
    // int solve( int idx, int r,vector<int>& a){
    //     if( idx == a.size()){
    //         return 0;
    //     }
    //     if( dp[idx][r]!=-1) return dp[idx][r];
    //     int take =0;
    //     if( a[idx]>r){
    //         take = a[idx] + solve( idx+1 , r+a[idx] , a);
    //     }
    //    int notTake = solve( idx+1, r, a);
    //     return  dp[idx][r] = max( take, notTake);
    // }
public:
    int maxTotalReward(vector<int>& reward) {
        int n=reward.size();
        // memset( dp, -1, sizeof(dp));
        sort( reward.begin(), reward.end());
        // return solve( 0,0, reward);

        vector<vector<int>> dp( n+1, vector<int>(4002));
        for( int i=0;i<4002;i++) dp[n][i] = 0;

        for(int i=n-1;i>=0;i--){
            for( int j=4000;j>=0;j--){
                int take = 0;
                if( reward[i] > j){
                    take = reward[i] + dp[i+1][j+reward[i]];
                }
                int notTake = dp[i+1][j];
                dp[i][j] = max( take , notTake );
            }
        }
        return dp[0][0] ;
    }
};