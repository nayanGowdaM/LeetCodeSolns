class Solution {
    int dp[2002][2002];
    int solve( int m , int n, vector<int>& nums1, vector<int>& nums2){
        if(m>=nums1.size()|| n>=nums2.size()) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int take=0,notTake=0;
        if(nums1[m]==nums2[n]) take=1 + solve(m+1,n+1, nums1, nums2);
        notTake = max(solve(m, n+1,nums1, nums2), solve(m+1, n,nums1, nums2));
        return dp[m][n] = max(take, notTake);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0, nums1, nums2);
    }
};