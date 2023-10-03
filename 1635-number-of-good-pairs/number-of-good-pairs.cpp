class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> v(102,0);
        for( auto x: nums) v[x]++;
        int ct=0;
        for(auto x: v) ct+=x*(x-1)/2;
        return ct;
    }
};