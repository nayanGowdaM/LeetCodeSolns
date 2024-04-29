class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for( auto x: nums){
            ans^=x;
        }
        ans ^= k;
        int res=0;
        while(ans) {
            res+=ans%2;
            ans/=2;
        }
        return res;
    }
};