class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), prev=n-1;
        for( int i=n-1;i>=0;i--){
            if( prev <= nums[i] + i) prev = i;
        }
        return prev==0;
    }
};