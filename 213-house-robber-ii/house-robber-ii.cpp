class Solution {
    int dp[102][2];
    int rob(vector<int>& nums, int s,int e){
        if(s>e) return 0;
        // if(n==0 || n==1) return nums[n];
        if(dp[s][e==nums.size()-1]!=-1) return dp[s][e==nums.size()-1];  
        return dp[s][e==nums.size()-1]=max(nums[s]+rob(nums,s+2,e),rob(nums,s+1,e));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int c1=rob(nums,1,n-1);
        int c2=rob(nums,0,n-2);
        return max(c1,c2);
    }
};