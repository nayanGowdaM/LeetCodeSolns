class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0,j=0;
        for( int k=0;k<n-1;k+=2){
           while(nums[i]<0 || nums[j]>0){
               if(nums[i]<0) i++;
               if(nums[j]>0) j++;

           }
           ans[k]=nums[i];
           ans[k+1]=nums[j];
           i++;
           j++;
        }
        return ans;
    }
};