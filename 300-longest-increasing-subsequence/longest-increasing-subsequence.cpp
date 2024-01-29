int dp[2502][2502];

class Solution {
    int solve(int i, int prev, vector<int>& arr){
        if(i==arr.size()) return 0;
        if(prev==-1) return max( 1 + solve(i+1,i, arr) , solve(i+1, prev, arr));
        if(dp[i][prev]!=-1) return dp[i][prev];
        if(arr[prev] < arr[i]) return dp[i][prev] = max( 1 + solve(i+1,i, arr) , solve(i+1, prev, arr));
        else return dp[i][prev] = solve(i+1,prev, arr);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0,-1,nums);
    }
};