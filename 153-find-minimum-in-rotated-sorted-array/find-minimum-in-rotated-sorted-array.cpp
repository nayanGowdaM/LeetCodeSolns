class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while( r-l > 1){
            int mid = l +(r-l)/2;
            if( nums[mid]>nums[l])  l  = mid;
            else r = mid;
        }
        return nums[l]>nums[r]?nums[r]: nums[0];
    }
};