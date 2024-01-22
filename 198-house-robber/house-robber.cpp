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
        memset(dp,-1,sizeof(dp));
        return rob(nums,nums.size()-1);
    }
};