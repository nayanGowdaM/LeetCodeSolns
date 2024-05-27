class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l=0, r=nums.size()-1;

        while( l<=r){
            int mid=l+(r-l)/2;
            if( nums[mid]==t) return mid;
            if(nums[l]<=nums[mid]){
                if( t<nums[mid] && t>=nums[l]) r=mid-1;
                else l=mid+1;
            }
            else{
                if( t<=nums[r] && t>nums[mid]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};