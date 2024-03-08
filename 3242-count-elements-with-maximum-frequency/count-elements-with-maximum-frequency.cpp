class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0,ct=0;
        unordered_map<int,int> mp;
        for( int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int mx=INT_MIN;
        for(auto it=mp.begin();it!=mp.end();it++){
            mx=max(mx, (*it).second);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if((*it).second==mx) ans+=mx;
        }
        return ans;
    }
};