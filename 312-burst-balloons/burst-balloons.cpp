int dp[302][302];
class Solution {

    int solve(int i , int j,  vector<int>& nums){
        if(j<i) return 0;
        if( i==j) return nums[i-1] * nums[i] * nums[j+1];
        if(dp[i][j] != -1) return dp[i][j];
        int ans=INT_MIN;
        for( int k=i;k<=j;k++){
            int temp = nums[i-1] * nums[k] * nums[j+1];
            temp+=solve(i,k-1,nums ) + solve( k+1,j,nums);
            ans=max(ans, temp);
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return solve(1,nums.size()-2,nums);
    }
};