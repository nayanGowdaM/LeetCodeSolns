class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        // if( r==0)
        while( r>l){
            int mid = l + ( r-l )/2;
            // if( nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) 
            if( nums[mid]==nums[mid-1]){
                if( (mid-l)%2) l=mid+1;
                else r = mid;
            }
            else if( nums[mid]==nums[mid+1]){
                if( (r-mid)%2) r = mid-1;
                else l=mid;
            }
            else return nums[mid];
        }
        return nums[l];
    }
};