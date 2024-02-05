int dp[302][302];

class Solution {
    int solve( int  i, int j, vector<int>& nums){
        if(dp[i][j] != -1) return dp[i][j];
        if( j<=i+1) return 0;
        // if( j==i) return nums[i];
        int ans=INT_MIN;
        for( int k = i+1; k<j;k++){
            int temp;
            temp = solve(i,k, nums) + nums[i]*nums[k]*nums[j] + solve( k, j, nums);
            ans=max( temp, ans);
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        memset( dp, -1, sizeof(dp));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solve( 0, nums.size()-1, nums);
    }
};

