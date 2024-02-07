const int M = 20*1000+1;
int dp[22][2*M];
class Solution {
    int solve(int n, int t, vector<int>& nums) {
        // cout << n << " " << t << endl;
        if (t == 0 && n < 0)
            return 1;

        if (n < 0)
            return 0;
        if(dp[n][t+M]!=-1) return dp[n][t+M];
        return  dp[n][t+M] = solve(n - 1, t - nums[n], nums) +
               solve(n - 1, t + nums[n], nums);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(n - 1, target, nums);
    }
};