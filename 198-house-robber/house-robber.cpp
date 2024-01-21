class Solution {
    int dp[102];
    int rob(vector<int>& nums, int n){
        if(n<0) return 0;
        if(n==0 || n==1) return nums[n];
        if(dp[n]!=-1) return dp[n];  
        return dp[n]=nums[n]+max(rob(nums,n-2),rob(nums,n-3));
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return max(rob(nums,nums.size()-2),rob(nums,nums.size()-1));
    }
};