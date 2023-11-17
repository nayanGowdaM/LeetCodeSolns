class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int l=0,r=0,sum=0,ct=0,n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(l<=r && sum>goal){
                sum-=nums[l];
                l++;
            }
            ct+=r-l+1;
            r++;
        }
        return ct;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};