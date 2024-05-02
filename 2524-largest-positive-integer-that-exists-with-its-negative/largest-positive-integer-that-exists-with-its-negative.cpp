class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1, ans = -1;
        while(i<j && nums[i]<0 && nums[j]>0){
            if( -nums[i] == nums[j]){
                ans = max( ans, nums[j]);
                i++;
                j--;
                
            }
            else if( -nums[i] < nums[j]) j--;
            else i++;
        }
        return ans;
    }
};