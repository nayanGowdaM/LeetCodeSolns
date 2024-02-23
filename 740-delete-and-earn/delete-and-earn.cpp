class Solution {
    int dp[20002];
    int solve(vector<int>& nums, int idx){
        if(idx<0) return 0;
        if(dp[idx]!=-1)return dp[idx];
        int prev=idx-1;
        int ans=0;
        while(prev>=0 && nums[prev]==nums[idx]) prev--;
        ans=(idx-prev)*nums[idx];
        while(prev>=0 && nums[prev]==nums[idx]-1) prev--;
        return dp[idx]= max( solve(nums, idx-1) , ans+solve(nums, prev));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(dp, -1,sizeof(dp));
        sort(nums.begin(), nums.end());
        return solve(nums, nums.size()-1);
    }
};