class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        
        while(r-l > 1){
            int mid = l + (r-l)/2;
            if( nums[mid-1] < nums[mid] && nums[mid]>nums[mid+1]) return mid;

            if(nums[mid]>nums[mid-1]) l = mid+1;
            else r = mid-1;
        }
        return nums[l]>nums[r] ? l:r;
    }
};