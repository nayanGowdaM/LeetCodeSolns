int dp[2502][2502];

class Solution {
    int solve(int n, int next, vector<int>& arr){
        if(n<0) return 0;
        // if(next==arr.size()) return max( 1 + solve(n-1,n, arr) , solve(n-1, next, arr));
        if(dp[n][next]!=-1) return dp[n][next];
        if(next == arr.size() || arr[next] > arr[n]) return dp[n][next] = max( 1 + solve(n-1,n, arr) , solve(n-1, next, arr));
        else return dp[n][next] = solve(n-1,next, arr);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums.size()-1,nums.size(),nums);



    }
};