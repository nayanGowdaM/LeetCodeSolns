int dp[502];
class Solution {
    int solve( int n, int k , vector<int>& arr){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        int cur=INT_MIN;
        for( int i=1;i<=k;i++){
            
            if(n-i>=0){
                cur=max(cur, arr[n-i]);
                ans=max( ans, i * cur + solve(n-i, k, arr));
            }
            
        }
        return dp[n]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1,sizeof(dp));
        return solve( arr.size(), k, arr);
         
    }
};