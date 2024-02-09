class Solution {
    int dp[102];
    int rob(vector<int>& nums, int n){
        if(n<0) return 0;
        // if(n==0 || n==1) return nums[n];
        if(dp[n]!=-1) return dp[n];  
        return dp[n]=max(nums[n]+rob(nums,n-2),rob(nums,n-1));
    }
public:
    int rob(vector<int>& nums) {

         int n=nums.size();
         if(n==1) return nums[0];
         vector<int>dp(n+1);
         dp[0] = nums[0];
         dp[1] = max( nums[0] , nums[1]);
         for( int i=2;i<n;i++){
             dp[i] = max( nums[i] + dp[i-2] , dp[i-1]);
         }
         return dp[n-1];
    }
};