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
        // return  fun(nums,sum/2,n,dp);
        sum=sum/2;
        for(int i=0;i<=sum;i++) dp[0][i]=0;
        for( int i=0;i<=n;i++) dp[i][0]=1;
        for( int i=1;i<=n;i++){
            for( int  j =1 ; j<=sum;j++){
                if(nums[i-1]<=j) dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];

        
    }
};