class Solution {

    bool fun(vector<int>& nums, int sum,int n, vector<vector<int>>& dp){
        if(sum==0) return dp[n][sum]=true;
        if(n==0) return false;
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(nums[n-1]<=sum) return dp[n][sum] = fun(nums,sum-nums[n-1],n-1,dp) || fun(nums,sum,n-1,dp);
        else return dp[n][sum] = fun(nums,sum,n-1,dp);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0),n=nums.size();
        
        if(sum%2) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
        return  fun(nums,sum/2,n,dp);
    }
};