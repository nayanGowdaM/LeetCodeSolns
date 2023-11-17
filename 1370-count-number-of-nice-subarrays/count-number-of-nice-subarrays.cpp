class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size(),sum=0,ct=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]&1;
            if(sum==k) ct++;
            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                ct+=mp[rem];
            }
            mp[sum]++;
        }
        return ct;
    }
};