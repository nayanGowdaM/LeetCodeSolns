class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),t=n-1;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=t-i;
            if(nums[i]>=ans[i]) t=i;
        }
        return nums[0]>=ans[0];
    }
};