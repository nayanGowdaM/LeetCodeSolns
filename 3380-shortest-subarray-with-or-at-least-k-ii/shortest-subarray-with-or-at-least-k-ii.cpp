class Solution {
    void performOrOperation( vector<int>& bits, int& orVal, int n){
        orVal = orVal|n;
        for( int i=0;i<32;i++){
            if( n & ( 1<<i)) bits[i]++;
        }
    }

    void nullifyOr(vector<int>& bits, int& orVal, int n){
        for( int i=0;i<32;i++){
            if( n& (1<<i)){
                bits[i]--;
                
            }
            if( bits[i] == 0) orVal = orVal & (~(1<<i));
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int orVal=0, start=0,end=0, n=nums.size(), ans = n+1;
        vector<int>bits(33, 0);
        while( end<n){
            performOrOperation(bits, orVal, nums[end]);

            while( start<=end && orVal >= k){
                nullifyOr(bits, orVal, nums[start]);
                ans = min( ans, end-start+1);
                start++;

            }
            end++;
        }
        return ans==n+1? -1: ans;
    }
};