class Solution {
    int dp[2002][4002];
    int solve( int idx, int r,vector<int>& a){
        if( idx == a.size()){
            return 0;
        }
        if( dp[idx][r]!=-1) return dp[idx][r];
        int take =0;
        if( a[idx]>r){
            take = a[idx] + solve( idx+1 , r+a[idx] , a);
        }
       int notTake = solve( idx+1, r, a);
        return  dp[idx][r] = max( take, notTake);
    }
public:
    int maxTotalReward(vector<int>& reward) {
        // int n=reward.size();
        memset( dp, -1, sizeof(dp));
        sort( reward.begin(), reward.end());
        return solve( 0,0, reward);
    }
};