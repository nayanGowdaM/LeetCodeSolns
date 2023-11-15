class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            int mx=INT_MIN, mn=INT_MAX;
            for(int j=i;j<n;j++){
                mx=max(mx,nums[j]);
                mn=min(mn,nums[j]);
                ans+=mx-mn;
            }
        }
        return ans;
    }
};