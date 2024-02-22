class Solution {
    const int M = 1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp( high+1,0);
        dp[0] = 1 ;
        for( int i=min(one, zero);i<=high;i++){
            int ct=0;
            if( i>=zero)  ct+=dp[i-zero];
            if(i>=one) ct+=dp[i-one];
            dp[i]= (dp[i]+ct)%M;
        }
        int ans=0;
        for( int i=low;i<=high;i++) ans= (ans+dp[i])%M;
        return ans;
    }
};