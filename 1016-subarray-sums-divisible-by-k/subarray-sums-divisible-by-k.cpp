class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> v(k,0);
        v[0] = 1;
        int ans=0;
        int temp = 0;
        for( int i=0;i<nums.size();i++){
            temp = (temp + nums[i])%k;
            if( temp<0) temp=(temp+k)%k;
            cout<<temp<<" ";
            ans+= v[temp];
            v[temp]++;
        }
        return ans;
    }
};