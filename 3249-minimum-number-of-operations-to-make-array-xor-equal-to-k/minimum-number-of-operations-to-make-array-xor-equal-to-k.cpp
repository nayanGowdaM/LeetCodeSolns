class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for( auto x: nums){
            ans^=x;
        }
        ans ^= k;
        return __builtin_popcount(ans);
    }
};