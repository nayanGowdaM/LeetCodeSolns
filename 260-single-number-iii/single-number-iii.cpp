class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<long long int> ones, zeros;
        long long int temp=0;
        for( auto x : nums) temp^=x;
        long long int prev = temp-1;
        long long int firstSetBit = ( temp & prev) ^ temp;
        for( auto x: nums){
            if( x & firstSetBit) ones.push_back(x);
            else zeros.push_back( x);
        }
        int  a=0, b=0;
        for( auto x: ones) a^=x;
        for( auto x: zeros) b^=x;
        return {a, b};
    }
};