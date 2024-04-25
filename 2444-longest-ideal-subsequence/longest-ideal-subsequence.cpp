class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        int ans=0;
        for( auto x: s){
            int i=x-'a';
            dp[i]++;
            for( int j=max( 0,i-k);j<=min(25, i+k) ;j++){
                if( i!=j){
                    dp[i] = max( dp[i] , dp[j]+1);
                }
            }
            ans = max( ans, dp[i]);
        }
        return ans;
    }
};