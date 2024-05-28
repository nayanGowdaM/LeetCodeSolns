class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;
        while( r-l >1){
            int mid=l + (r-l)/2;
            if( nums[mid] == target) return true;
            if( nums[mid]==nums[l] && nums[r]==nums[mid]){
                l++;
                r--;
            }
            else{
                if( nums[l]<=nums[mid]){
                    if( nums[mid]>target && nums[l] <= target) r = mid-1;
                    else l=mid+1;
                }
                else {
                    if( nums[mid]<target && nums[r]>=target) l=mid+1;
                    else r = mid-1;
                }
            }

        }
        if( nums[l]==target || target==nums[r]) return true;
        return false;
    }
};