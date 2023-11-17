class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int , int>mp;
        int sum=0,n=nums.size(),maxL=0,ct=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==goal) ct++;
            int rem=sum-goal;
            if(mp.find(rem)!=mp.end()){
                ct+=mp[rem];
            }
            mp[sum]++;
        }
        return ct;
    }
};