class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(), temp=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for( int i=0;i<n;i++){
            temp = ( temp+nums[i])%k;
            if( mp.find( temp)!=mp.end() && ( i-mp[temp]>1)) return  true;
            if( mp.find( temp)==mp.end()) mp[temp]=i;
        }
        return false;
    }
};