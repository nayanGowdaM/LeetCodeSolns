class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(), l=0,r=0,ct=0;
        while(r<n-1){
            int far=0;
            for( int i=l;i<=r;i++){
                far = max( far, nums[i] + i);
            }
            l=r+1;
            r=far;
            ct++;

        }
        return ct;
    }
};