class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int l=0, r = nums.size()-1;
        while( l<=r){
            int mid= l+ ( r-l)/2;
            if(nums[mid]==tar){
                int i=mid, j=mid;
                while(i>=0 && nums[i]==tar)i--;
                while( j<nums.size() && nums[j]==tar) j++;
                return {i+1, j-1};
            }
            else if( nums[mid]>tar) r=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
};