class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort( nums.begin() , nums.end());

        int i=0,j=0, ans=0, n=nums.size();
        while( i<n){
            if( nums[i]>=j){
                
                j=nums[i]+1;
                i++;
            }
            else{
                ans+=( j-nums[i]);
                j++;
                i++;
            }
        }
        return ans;
    }
};