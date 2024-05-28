class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort( nums.begin(),nums.end());
        int n=nums.size();
        if( n==0) return 0;
        int ans = 1, temp=1;
        for(int i=1;i<nums.size();i++){

            while(i<nums.size() && nums[i-1]==nums[i]) i++;
            if( i<nums.size()){
                if( nums[i-1]+1 == nums[i]) temp++;
                else{
                    temp=1;
                }
                ans = max( ans, temp);
            }
            
        }
        return ans;
    }
};