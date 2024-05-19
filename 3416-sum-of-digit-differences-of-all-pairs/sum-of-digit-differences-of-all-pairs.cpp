class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans=0;
        int n = nums.size();
        while( nums[0]){
            vector<int> dp(10,0);
            for( auto &x : nums){
                int temp = x%10;
                x/=10;
                dp[temp]++;
            }
            for( int i=0;i<10;i++){
                int atI = dp[i];
                int possComb = n-atI;
                ans += atI * possComb;
            }

        }
        return ans/2;
    }
};